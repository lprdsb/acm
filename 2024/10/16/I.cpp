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
int n;
LL f[2][5];
char s[maxn + 5];

int main() {
    //freopen("in", "r", stdin);
    scanf("%s", s + 1);
    n = strlen(s + 1);
    int o = 0;
    f[o][0] = 1;
    For(i, 1, n) {
        o ^= 1;
        For(o1, 0, 4) f[o][o1] = f[o ^ 1][o1];
        if(s[i] == 'b') {
            f[o][1] += f[o ^ 1][0];
        }
        if(s[i] == 'u') {
            f[o][2] += f[o ^ 1][1];

        }
        if(s[i] == 'a') {
            f[o][3] += f[o ^ 1][2];
            f[o][4] += f[o ^ 1][3];
        }
        For(o1, 0, 4) f[o ^ 1][o1] = 0;
    }
    printf("%lld\n", f[o][4]);
}
