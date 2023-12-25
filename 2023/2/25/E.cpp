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
#define mod 998244353
#define maxn 10000000
using namespace std;

int t, n, a[maxn + 5], s[maxn + 5], as = 0, b[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int gcd(int x, int y){return y ? gcd(y, x % y) : x;}

int main(){
	// freopen("in.txt", "r", stdin);
    read(t);
    while(t--){
        as = 0;
        read(n);
        For(i, 1, n) read(a[i]);
        For(i, 1, a[n]) s[i] = b[i] = 0;
        For(i, 1, n) s[a[i]]++;
        For(i, 1, a[n]) s[i] += s[i - 1];
        For(i, 1, n) b[gcd(a[i], a[n])]++;
        For(i, 1, a[n]) if(b[i]){
            For(j, 1, i){
                if(1ll * j * j > i) break;
                if(i % j == 0){
                    if(j != i) b[j] += b[i];
                    if(j != 1 && 1ll * j * j != i) b[i / j] += b[i];
                }
            }
        }
        For(i, 1, a[n]){
            int now = a[n] / i, to = a[n] / now, asi = n;
            For(j, 0, now - 1){
                if(1ll * now * j + j > a[n]) break; 
                asi = (asi - (s[min(a[n], now * (j + 1) - 1)] - s[now * j + j]) + mod) % mod;
                // if(i == 3) cout << asi << endl;
            }
            int tem;
            if(a[n] % to == 0){
                tem = 1ll * (i + to - 1) * (to - 1- i + 1) / 2 % mod;
                as = (as + 1ll * to * b[now] % mod) % mod;
                // cout << to << " " << b[now] << endl;
            }
            else tem = 1ll * (i + to) * (to - i + 1) / 2 % mod;
            as = (as + 1ll * tem * asi % mod) % mod;
            // cout << as << endl;
            i = to;
        }
        printf("%d\n", as);
    }
    return 0;
}
