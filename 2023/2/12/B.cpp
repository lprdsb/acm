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

int t, n, a[maxn + 5];
vector<int> vec[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int st[2][maxn + 5], top[2], r[maxn + 5];
bool chk(int o, int x){
    if(o) return x < a[st[o][top[o]]];
    return x > a[st[o][top[o]]];
}

int main(){
	//freopen("in", "r", stdin);
    read(t);
    while(t--){
        read(n);
        For(i, 1, n) r[i] = 0, vec[i].clear();
        For(i, 1, n) read(a[i]);
        top[0] = top[1] = 0;
        For(o, 0, 1) st[o][0] = inf;
        Rof(i, n, 1){
            For(o, 0, 1){
                while(top[o] && chk(o, a[i])) top[o]--;
                r[i] = max(r[i], st[o][top[o]]);
                st[o][++top[o]] = i;
            }
        }
        // For(i, 1, n) cout << r[i] << " "; cout << endl;
        top[0] = top[1] = 0;
        For(o, 0, 1) st[o][0] = 0;
        int fl = 0;
        For(i, 1, n){
            int to = inf;
            For(o, 0, 1){
                while(top[o] && chk(o, a[i])) top[o]--;
                to = min(to, st[o][top[o]]);
                st[o][++top[o]] = i;
            }
            // cout << to << " ";
            vec[to].pb(i);
        }
        int mn = 0;
        r[0] = inf;
        For(i, 1, n){
            if(r[i] < r[mn]) mn = i;
            for(auto j : vec[i]) if(r[mn] <= j){
                printf("%d %d\n", mn, j);
                fl = 1;
                break;
            }
            if(fl) break;
        }
        if(!fl) puts("-1");
    }
    return 0;
}
