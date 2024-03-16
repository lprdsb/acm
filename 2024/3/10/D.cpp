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

#define mod 998244353
#define maxn 200000
int pw[maxn + 5];
int main() {
    //freopen("in", "r", stdin);
    pw[0] = 1;
    For(i, 1, maxn) pw[i] = 2ll * pw[i - 1] % mod;
    int T;
    read(T);
    while(T--) {
        int n;
        read(n);
        int cnt = 0, pre = -1, res = 0;
        For(i, 1, n) {
            char c; cin >> c;
            int x = c - '0';
            if(x != pre) cnt = 1;
            else cnt++;
            res = (res + pw[cnt - 1]) % mod;
            pre = x;
        }
        printf("%d\n", res);
    }
}
