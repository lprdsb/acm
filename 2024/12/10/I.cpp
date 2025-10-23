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

#define maxn 400000
int T, a[maxn + 5], N, f[maxn + 5];
vector<int> vec[maxn + 5];
char s[maxn + 5], t[maxn + 5];

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        read(N);
        scanf("%s", s + 1);
        int n = strlen(s + 1), m;
        For(i, 1, n) vec[i].resize(0), f[i] = inf;
        For(o, 1, N) {
            scanf("%s", t + 1); m = strlen(t + 1);
            For(i, 2, m) {
                a[i] = a[i - 1];
                while(a[i] && t[a[i] + 1] != t[i]) a[i] = a[a[i]];
                if(t[a[i] + 1] == t[i]) a[i]++;
            }
            int now = 0;
            t[m + 1] = '#';
            For(i, 1, n) {
                while(now && t[now + 1] != s[i]) now = a[now];
                if(t[now + 1] == s[i]) now++;
                if(now == m) vec[i].pb(i - m);
            }
        }
        f[0] = 0;
        For(i, 1, n) for(auto j : vec[i]) f[i] = min(f[i], f[j] + 1);
        if(f[n] == inf) f[n] = -1;
        printf("%d\n", f[n]);
    }
}
