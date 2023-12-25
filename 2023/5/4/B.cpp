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

int n, m, as = inf;
vector<pair<LL, int> > f[2];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

vector<pair<LL, int> > vec;
unordered_map<LL, int> ma;
int main(){
	// freopen("in.txt", "r", stdin);
	read(n); read(m); m *= 2;
    f[0].pb({0, 0});
    f[1].pb({0, 0});
    For(i, 1, n){
        LL x; read(x);
        LL y = x * 2;
        int o = i > 15;
        vec.clear();
        for(auto j : f[o]) vec.pb(j);
        f[o].clear();
        for(auto j : vec){
            f[o].pb(j);
            f[o].pb({j.fir + y, j.sec});
            f[o].pb({j.fir + x, j.sec + 1});
        }
        // cout << f[1].size() << endl;
    }
    // cout << "asd" << endl;
    for(auto i : f[1]) if(ma.find(i.fir) == ma.end() || ma[i.fir] > i.sec) ma[i.fir] = i.sec;
    for(auto i : f[0]){
        if(ma.find(m - i.fir) != ma.end()) as = min(as, i.sec + ma[m - i.fir]);
    }
    printf("%d\n", as == inf ? -1 : as);
    return 0;
}
