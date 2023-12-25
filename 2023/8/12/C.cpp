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
using namespace std;

int t, n;
vector<int> ok[255];
set<int> se;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int main(){
	//freopen("in", "r", stdin);
    read(t);
    while(t--){
        read(n);
        LL as = 0;
        Rof(o, n * n, 1){
            For(i, 1, n) ok[i].resize(0);
            se.clear();
            For(i, 1, n) ok[min(n, o / i)].pb(i);
            LL res = 0;
            int fl = 0;
            Rof(i, n, 1){
                for(auto j : ok[i]) se.insert(-j);
                if(!se.size()){
                    fl = 1;
                    break;
                }
                res += 1ll * (-*se.begin()) * i;
                se.erase(se.begin());
            }
            if(!fl) as = max(as, res - o);
        }
        printf("%lld\n", as);
    }
    return 0;
}
