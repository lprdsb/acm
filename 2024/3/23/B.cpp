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

#define maxn 100
int T, n, a[maxn + 5];

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        read(n);
        For(i, 1, n) read(a[i]);
        sort(a + 1, a + n + 1);
        if(n == 2) {
            puts(a[1] == a[2] ? "0" : "1");
        }
        else if(n == 3) {
            if(a[1] == a[2] && a[2] == a[3]) puts("0");
            else if(a[1] == a[2] || a[2] == a[3]) puts("1");
            else puts("2");
        }
        else {
            if(a[1] == a[2] && a[n] == a[n - 1]) puts("0");
            else if(a[1] == a[2] || a[n] == a[n - 1]) puts("1");
            else if(a[2] == a[3] || a[n - 2] == a[n - 1]) puts("1");
            else puts("2");
        }
    }
    return 0;
}
