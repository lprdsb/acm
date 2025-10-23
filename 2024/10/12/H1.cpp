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

template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

#define maxn 100000
int T, f[maxn + 5], g[maxn + 5][15], n, m;
char s[maxn + 5], t[maxn + 5] = " 1145141919810";

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        scanf("%s", s + 1);
        n = strlen(s + 1); m = strlen(t + 1);
        For(i, 1, n) {
            int cnt = 0;
            For(j, 1, min(m, n - i + 1)) {
                cnt += s[i + j - 1] == t[j];
                g[i][j] = cnt;
            }
        }
        For(i, 1, n) f[i] = 0;
        f[0] = 0;
        For(i, 0, n - 1) {
            For(j, 1, min(m, n - i + 1)) f[i + j] = max(f[i + j], f[i] + g[i + 1][j]);
        }
        cout << f[n] << endl;
    }
}
