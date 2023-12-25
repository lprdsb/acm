#include<bits/stdc++.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define Tra(u, i) for(int i = hd[u]; ~i; i = e[i].net)
#define cst const
#define LL long long
#define DD double
#define LD long double
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define inf 0x3f3f3f3f
#define Inf 0x3f3f3f3f3f3f3f3f
#define eps 1e-12
#define maxn 200000
using namespace std;

int t, n, m, k, pos[maxn + 5], ok[maxn + 5], l[maxn + 5], r[maxn + 5];
set<int> se;
set<pair<int, int> > opt;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int tr[maxn + 5];
void ins(int x){
    while(x <= n) tr[x]++, x += x & -x;
}
int que(int x){
    int asi = 0;
    while(x) asi += tr[x], x -= x & -x;
    return asi;
}

int main(){
	freopen("in.txt", "r", stdin);
    read(t);
    while(t--){
        se.clear();
        opt.clear();
        read(n); read(m); read(k);
        For(i, 1, n){
            int x; read(x);
            pos[x] = i;
            ok[i] = tr[i] = 0;
        }
        For(i, 1, m){
            int x; read(x);
            ok[x] = 1;
        }
        For(i, 1, k){
            int x; read(x);
            auto it = opt.lower_bound(mp(x, 0));
            if(it == opt.end() || it->fir != x) opt.insert(mp(x, 1));
            else{
                pair<int, int> tem = *it;
                opt.erase(it);
                tem.sec++;
                opt.insert(tem);
            }
        }
        Rof(i, n, 1){
            if(!ok[i]){
                auto it = se.lower_bound(pos[i]);
                if(it != se.end()) r[i] = (*it) - 1;
                else r[i] = n;
                if(it != se.begin()){
                    it--;
                    l[i] = (*it) + 1;
                }
                else l[i] = 1;
                // cout << i << " " << l[i] << " " << r[i] << endl;
            }
            else se.insert(pos[i]), ins(pos[i]);
        }
        // cout << "asd" << endl;
        int fl = 1;
        For(i, 1, n) if(!ok[i]){
            if(!opt.size()){
                fl = 0;
                break;
            }
            int len = que(r[i]) - que(l[i] - 1) + 1;
            auto it = opt.lower_bound(mp(len + 1, 0));
            if(it != opt.begin()) it--;
            if(it->fir > len){
                fl = 0;
                break;
            }
            else{
                pair<int, int> tem = *it;
                opt.erase(it);
                tem.sec--;
                if(tem.sec) opt.insert(tem);
            }
            ins(pos[i]);
        }
        if(fl) puts("YES");
        else puts("NO");
    }
    return 0;
}
