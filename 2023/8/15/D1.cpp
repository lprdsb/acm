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
#define maxn 3000
using namespace std;

int T, lhs[maxn + 5][maxn + 5], rhs[maxn + 5][maxn + 5], a[maxn + 5], N, K;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int f[maxn + 5];
int main(){
	// freopen("in.txt", "r", stdin);
    memset(f, -inf, sizeof f);
    read(T);
    while(T--){
        read(N); read(K);
        For(i, 1, N){
            char c; cin >> c;
            a[i] = c - '0';
        }
        For(i, 1, N){
            For(j, 0, K) lhs[i][j] = lhs[i - 1][j];
            int now = 0;
            Rof(j, i, 1){
                if(!a[j]) now++;
                if(now > K) break;
                lhs[i][now] = max(lhs[i][now], i - j + 1);
            }
            For(j, 1, K) lhs[i][j] = max(lhs[i][j], lhs[i][j - 1]);
        }
        Rof(i, N, 1){
            For(j, 0, K) rhs[i][j] = rhs[i + 1][j];
            int now = 0;
            For(j, i, N){
                if(!a[j]) now++;
                if(now > K) break;
                rhs[i][now] = max(rhs[i][now], j - i + 1);
            }
            For(j, 1, K) rhs[i][j] = max(rhs[i][j], rhs[i][j - 1]);
        }
        // cout << rhs[2][0] << endl;

        For(i, 1, N){
            int now = 0;
            f[0] = max(f[0], max(lhs[i][K], rhs[i][K]));
            Rof(j, i, 1){
                if(a[j]) now++;
                if(now > K) break;
                f[i - j + 1] = max(f[i - j + 1], max(lhs[j - 1][K - now], rhs[i + 1][K - now]));
            }
        }
        For(i, 1, N){
            LL res = 0;
            For(j, 0, N) res = max(res, 1ll * i * j + f[j]);
            printf("%lld ", res);
        }
        puts("");
        For(i, 0, N) For(j, 0, K) lhs[i][j] = rhs[i][j] = 0;
        For(i, 0, N) f[i] = -inf;
    }
    return 0;
}
