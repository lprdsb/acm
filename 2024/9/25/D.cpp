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
int T, n, m, a[maxn + 5], b[maxn + 5], c[maxn + 5];

char s[maxn + 5];

void mian() {
    scanf("%s", s + 1); n = strlen(s + 1);
    For(i, 1, n) a[n - i] = s[i] - '0';
    scanf("%s", s + 1); m = strlen(s + 1);
    For(i, 1, m) b[m - i] = s[i] - '0';
    For(i, 0, n + m - 1) c[i] = 0;
    For(i, 0, n - 1) For(j, 0, m - 1) c[i + j] += a[i] * b[j];
    For(i, 0, n + m - 2) c[i + 1] += c[i] / 10, c[i] %= 10;
    int now = n + m - 1;
    while(now >= 0 && !c[now]) now--;
    if(now == -1) puts("0");
    else {
        Rof(i, now, 0) printf("%d", c[i]);
        puts("");
    }
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
