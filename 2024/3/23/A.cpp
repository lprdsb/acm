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

#define maxn 200000
int n, a[maxn + 5], b[maxn + 5];

int main() {
    //freopen("in", "r", stdin);
    read(n);
    For(i, 1, n) read(a[i]);
    if(a[1] == 0) {
        b[1] = b[2] = 0;
        For(i, 2, n - 1) b[i + 1] = a[i] - b[i] - b[i - 1];
    }
    else if(a[1] == 1) {
        b[1] = 0; b[2] = 1;
        For(i, 2, n - 1) b[i + 1] = a[i] - b[i] - b[i - 1];
        int fl = b[n] + b[n - 1] == a[n];
        For(i, 1, n) if(b[i] != 0 && b[i] != 1) {
            fl = 0;
            break;
        }
        if(!fl) {
            b[1] = 1; b[2] = 0;
            For(i, 2, n - 1) b[i + 1] = a[i] - b[i] - b[i - 1];
        }
    }
    else {
        b[1] = b[2] = 1;
        For(i, 2, n - 1) b[i + 1] = a[i] - b[i] - b[i - 1];
    }
    For(i, 1, n) printf("%d ", b[i]);
}
