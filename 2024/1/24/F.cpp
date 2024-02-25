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
#define eps 1e-8
using namespace std;

template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

#define maxn 50
int T, n, a[maxn + 5];

int main() {
    // cout << log2(8) << endl;
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        read(n);
        For(i, 1, n) read(a[i]);
        int res = 0;
        For(i, 1, n - 1) {
            int tem = ((DD)max(a[i], a[i + 1]) / min(a[i], a[i + 1]) - eps);
            // if(i == 9) cout << log2(2) << endl;
            if(tem >= 2) res += log2(tem);
        }
        printf("%d\n", res);
    }
}