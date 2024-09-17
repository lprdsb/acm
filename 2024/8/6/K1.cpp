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

#define maxn 1000000
int n, m, a[maxn + 5], b[maxn + 5], st[maxn + 5];
char s[maxn + 5];
#define mod 1000000007
LL f[60];

int c[2 * maxn + 5];

void up(int &a, int b) { if(a < b) a = b; }

int F[2 * maxn + 5], G[2 * maxn + 5];
int main() {
    // freopen("in.txt", "r", stdin);
    read(n); read(m);
    scanf("%s", s + 1); n = strlen(s + 1);
    For(i, 1, n) a[i] = s[i] - 'a' + 1;
    scanf("%s", s + 1); m = strlen(s + 1);
    For(i, 1, m) b[i] = s[i] - 'a' + 1;
    int now = 1;
    int S = -1, T = -1;
    // c
    memset(st, -1, sizeof st);
    st[0] = 0;
    For(i, 1, n) {
        if(now <= m && a[i] == b[now]) now++;
        if(st[now - 1] == -1) st[now - 1] = i;
        if(now == m + 1 && S == -1) S = i;
    }
    now = 1;
    Rof(i, n, 1) {
        if(now <= m && a[i] == b[now]) now++;
        if(now == m + 1 && T == -1) T = i;
    }
    // cout << S << " " << T << endl;
    if(S == -1 || T == -1) {
        puts("0");
        return 0;
    }
    // cout << S << " " << T << endl;
    LL res = 0;
    if(S < T) {
        f[0] = 1;
        LL sum = 1;
        For(i, S + 1, T - 1) {
            LL tem = (sum - f[a[i]] + mod) % mod;
            f[a[i]] = (f[a[i]] + tem) % mod;
            sum = (sum + tem) % mod;
        }
        res = sum;
    }
    // cout << res << endl;


    For(i, 1, m) c[i << 1] = b[i], c[i << 1 | 1] = -1;
    c[0] = -2; int M = (m + 1) << 1; c[M] = -3; c[1] = -1;
    F[1] = 1;
    for(int r = 0, p = 0, i = 2; i < M; ++i) {
        for(F[i] = r > i ? min(r - i, F[p * 2 - i]) : 1; c[i - F[i]] == c[i + F[i]]; F[i]++);
        if(i + F[i] > r) r = i + F[i], p = i;
    }
    for(int i = 0; i <= M; ++i) G[i] = 0;
    for(int i = 2; i < M; ++i) up(G[i - F[i] + 1], i + 1);
    for(int i = 1; i <= M; ++i) up(G[i], G[i - 1]);
    for(int i = 2; i < M; i += 2) {
        if((i / 2) + (G[i] - i) - 1 == m && st[(i / 2) - 1] != -1) res += st[(i / 2) - 1] < T;
        // cout << G[i] - i << " ";
    }
    // cout << endl;
    cout << res % mod << endl;
}
