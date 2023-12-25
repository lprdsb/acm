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

int main() {
    //freopen("in", "r", stdin);
    int T; read(T);
    while(T--) {
        char s[10]; scanf("%s", s + 1); int n = strlen(s + 1);
        int a = 0, b = 0, fl = 0;
        For(i, 1, n) {
            if(i != 1 && s[i] != '0') fl = 1;
            if(fl) b = b * 10 + s[i] - '0';
            else a = a * 10 + s[i] - '0';
        }
        if(a < b) printf("%d %d\n", a, b);
        else puts("-1");
    }
}
