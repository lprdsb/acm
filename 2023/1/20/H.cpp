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

int n, m;
LL l, r;
vector<int> vec[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

set<pair<int, int> > se;

void mdy(int x, int val){
    for(auto i : vec[x]){
        multiset<pair<int, int> >::iterator it = se.lower_bound(mp(i, 0));
        if(it == se.end() || it->fir != i) se.insert(mp(i, 1));
        else{
            pair<int, int> pa = *it;
            se.erase(it);
            pa.sec += val;
            if(pa.sec) se.insert(pa);
        }
    }
}

int main(){
	//freopen("in", "r", stdin);
    For(i, 1, maxn){
        int tem = i;
        while(tem <= maxn){
            vec[tem].pb(i);
            tem += i;
        }
    }
    read(n); read(m); read(l); read(r);
    int nl = min(1ll * m, r) + 1, nr = nl - 1;
    For(i, 1, n){
        while(nl > 1 && 1ll * (nl - 1) * i >= l) mdy(--nl, 1);
        while(nr >= nl && 1ll * nr * i > r) mdy(nr--, -1);
        // cout << i << " " << nl << " " << nr << endl;
        int fl = 0;
        for(auto j : vec[i]){
            multiset<pair<int, int> >::iterator it = se.lower_bound(mp(j + 1, 0));
            if(it != se.end()){
                LL b = it->fir;
                if(1ll * i / j * b <= n){
                    fl = 1;
                    int x2 = i / j * b, y1 = ceil((DD)l / i / b) * b, y2 = 1ll * i * y1 / x2;
                    printf("%d %d %d %d\n", i, y1, x2, y2);
                    break;
                }
            }
        }
        if(!fl) puts("-1");
    }
    return 0;
}
