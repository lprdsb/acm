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
#define maxn 2000000
using namespace std;

int n, m;
char s[2][maxn + 5], ts[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int gcd(int x, int y){return y ? gcd(y, x % y) : x;}

int to[maxn + 5];
vector<int> vec[maxn + 5], net[maxn + 5];

int main(){
	// freopen("in.txt", "r", stdin);
    while(scanf("%s%s", s[0], s[1]) != EOF){
        int fl = 0;
        n = strlen(s[0]);
        m = strlen(s[1]);
        if(n < m){
            fl = 1;
            For(i, 0, n - 1) ts[i] = s[0][i];
            For(i, 0, m - 1) s[0][i] = s[1][i];
            For(i, 0, n - 1) s[1][i] = ts[i];
            swap(n, m);
        }
        int gc = gcd(n, m);
        For(i, 0, gc - 1){
            int now = i;
            while(666){
                vec[i].pb(now);
                to[now] = vec[i].size() - 1;
                now = (now + m) % n;
                if(now < gc) break;
            }
            For(j, 0, vec[i].size() - 1) vec[i].pb(vec[i][j]);
            net[i].resize(vec[i].size(), 0);
            net[i][net[i].size() - 1] = inf;
            Rof(j, net[i].size() - 2, 0){
                if(s[0][vec[i][j]] == s[0][vec[i][j + 1]]) net[i][j] = net[i][j + 1];
                else net[i][j] = j + 1;
            }
        }
        LL mn = inf, ok = 0;
        For(i, 0, m - 1){
            if(s[0][i] != s[1][i]){
                if(i < mn) mn = i, ok = s[0][i] < s[1][i];
            }
            else{
                if(net[i % gc][to[i]] != inf){
                    LL now = i + 1ll * (net[i % gc][to[i]] - to[i]) * m;
                    if(now < mn) mn = now, ok = s[0][now % n] < s[1][now % m];
                }
            }
        }
        if(fl) ok ^= 1;
        if(mn == inf) puts("=");
        else puts(ok ? "<" : ">");
        For(i, 0, gc - 1) vec[i].resize(0);
    }
    return 0;
}
