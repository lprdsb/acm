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

#define maxn 1000
int n, m, tot = 0, sz[maxn * maxn + 5], ch[maxn * maxn + 5][2];
LD p, f[maxn + 5][maxn + 5];

char s[maxn + 5];

int main() {
    // freopen("in.txt", "r", stdin);
    read(n); read(m); scanf("%Lf", &p);
    f[0][0] = 1;
    For(i, 0, maxn) For(j, 0, maxn) if(i != 0 || j != 0) {
        if(i <= j) {
            if(i) f[i][j] += (1 - p) * f[i - 1][j];
            if(j) f[i][j] += p * f[i][j - 1];
        }
        else {
            if(i) f[i][j] += p * f[i - 1][j];
            if(j) f[i][j] += (1 - p) * f[i][j - 1];
        }
    }
    tot = 1;
    For(i, 1, n) {
        int now = 1;
        scanf("%s", s + 1);
        For(j, 1, m) {
            int o = s[j] - '0';
            if(!ch[now][o]) ch[now][o] = ++tot;
            now = ch[now][o];
            sz[now]++;
        }
    }
    LD res = 1;
    For(i, 1, tot) res *= f[sz[ch[i][0]]][sz[ch[i][1]]];
    printf("%.20Lf\n", res);
    return 0;
}
