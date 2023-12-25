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
#define mod 998244353
using namespace std;

int t, n, a[maxn + 5], b[maxn + 5], ma[2 * maxn + 5];
LL as = 0;
vector<int> vec[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int main(){
	// freopen("in.txt", "r", stdin);
    read(t);
    while(t--){
        read(n);
        For(i, 1, n) read(a[i]);
        For(i, 1, n) read(b[i]);
        For(i, 1, n) vec[a[i]].pb(b[i]);
        // if(n == 200000){
        //     int sum = 0;
        //     For(i, 1, n) sum += ma[i].size();
        //     cout << sum << endl;
        // }
        For(i, 1, n){
            if(1ll * i * i > 2 * n) break;
            for(auto p : vec[i]) ma[p]++;
            For(j, i + 1, n){
                if(1ll * i * j > 2 * n) break;
                for(auto p : vec[j]) if(i * j - p <= n && i * j - p > 0) as += ma[i * j - p];
            }
            LL tem = 0;
            for(auto p : vec[i]){
                int to = i * i - p;
                if(to < p) continue;
                if(to == p) tem += ma[p] - 1;
                else as += ma[to];
            }
            as += tem / 2;
            for(auto p : vec[i]) ma[p]--;
        }
        printf("%lld\n", as);
        For(i, 1, n) vec[i].clear();
        as = 0;
    }
	return 0;
}
