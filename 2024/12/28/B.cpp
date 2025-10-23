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

#define maxn 400000

int n, L[maxn + 5], R[maxn + 5], a[maxn + 5], b[maxn + 5];

void mian() {
    read(n);
    For(i, 1, 2 * n) a[i] = b[i] = 0;
    For(i, 1, n) read(L[i]), read(R[i]);
    For(i, 1, n) if(L[i] == R[i]) a[L[i]] = 1, b[L[i]]++;
    For(i, 1, 2 * n) a[i] += a[i - 1];
    For(i, 1, n) {
        if(L[i] == R[i] && b[L[i]] == 1) printf("1");
        else if(a[R[i]] - a[L[i] - 1] == R[i] - L[i] + 1) printf("0");
        else printf("1");
    }
    puts("");
}

int main() {
    //freopen("in", "r", stdin);
    int T; read(T);
    while(T--) {
        mian();
    }
}
