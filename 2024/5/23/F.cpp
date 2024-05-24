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

int T;
char s[1000000];

int chk() {
    if(strlen(s + 1) != 5) return 0;
    if(s[3] != s[5]) return 0;
    For(i, 1, 4) For(j, i + 1, 4) if(s[i] == s[j]) return 0;
    return 1;
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    int res = 0;
    while(T--) {
        scanf("%s", s + 1);
        res += chk();
    }
    printf("%d\n", res);
}
