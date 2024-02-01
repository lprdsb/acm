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

#define maxn 25
char s[3][maxn + 5];

void mian() {
    int n; read(n);
    For(o, 0, 2) scanf("%s", s[o] + 1);
    For(i, 1, n) {
        if(s[0][i] == s[1][i]) {
            if(s[2][i] != s[0][i]) {
                puts("YES");
                return;
            }
        }
        else {
            if(s[2][i] != s[0][i] && s[2][i] != s[1][i]) {
                puts("YES");
                return;
            }
        }
    }
    puts("NO");
}

int main() {
    //freopen("in", "r", stdin);
    int T; read(T);
    while(T--) {
        mian();
    }
}
