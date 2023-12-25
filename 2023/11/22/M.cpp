#include<bits/stdc++.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define Tra(u, i) for(int i = hd[u]; ~i; i = e[i].net)
#define cst const
#define U unsigned
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
#define maxn 1000000
#define maxm 2500
#define mod 998244353
using namespace std;

int n, m;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

vector<int> a[maxn + 5];

namespace c1{
    vector<U LL> b[maxm + 5];
    void work(){
        // assert(n <= maxm);
        For(i, 0, n - 1){
            b[i].resize((m - 1) / 64 + 1);
            For(j, 0, m - 1) b[i][j / 64] |= (U LL)a[i][j] << (j % 64);
        }
        int res = 0;
        For(i, 0, n - 1) For(j, i + 1, n - 1){
            int tem = ((U LL)0 - 1) % mod + 1, pw = 1, val = 0;
            For(p, 0, (m - 1) / 64){
                val = (val + 1ll * (b[i][p] ^ b[j][p]) % mod * pw) % mod;
                pw = 1ll * pw * tem % mod;
            }
            res = (res + 1ll * val * val) % mod;
        }
        printf("%d\n", res);
    }
}

namespace c2{
    int cnt[maxm + 5];
    vector<U LL> b[maxm + 5];
    void work(){
        // assert(m <= maxm);
        For(j, 0, m - 1){
            b[j].resize((n - 1) / 64 + 1);
            For(i, 0, n - 1) if(a[i][j]){
                cnt[j]++;
                b[j][i / 64] |= ((U LL)1 << (i % 64));
            }
        }
        int pw = 1, res = 0;
        For(i, 0, m - 1){
            res = (res + 1ll * cnt[i] * (n - cnt[i]) % mod * pw) % mod;
            pw = 4ll * pw % mod;
        }
        pw = 1;
        For(i, 0, m - 1){
            int pw1 = 2ll * pw * pw % mod;
            For(j, i + 1, m - 1){
                int c00 = 0, c01 = 0, c10 = 0, c11 = 0;
                For(p, 0, (n - 1) / 64){
                    if(p == (n - 1) / 64) c00 -= 63 - ((n - 1) % 64);
                    c00 += __builtin_popcountll((~b[i][p]) & (~b[j][p]));
                    c01 += __builtin_popcountll((~b[i][p]) & (b[j][p]));
                    c10 += __builtin_popcountll((b[i][p]) & (~b[j][p]));
                    c11 += __builtin_popcountll((b[i][p]) & (b[j][p]));
                }
                res = (res + 2ll * (1ll * c00 * c11 + 1ll * c01 * c10) * pw1) % mod;
                pw1 = 2ll * pw1 % mod;
            }
            pw = 2ll * pw % mod;
        }
        printf("%d\n", res);
    }
}

int main(){
	// freopen("in.txt", "r", stdin);
    read(n); read(m);
    For(i, 0, n){
        a[i].resize(m);
        For(j, 0, m - 1){
            char c; cin >> c;
            a[i][m - 1 - j] = c - '0'; 
        }
    }
    if(n <= m) c1::work();
    else c2::work();
    return 0;
}
