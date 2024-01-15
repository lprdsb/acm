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

#define maxn 5000
#define mod 998244353

int T, c[maxn + 5][maxn + 5], n, a[maxn + 5], num[maxn + 5];

void mian() {
    read(n);
    For(i, 1, n) read(a[i]);
    a[++n] = 0;
    sort(a + 1, a + n + 1);
    For(i, 1, n) num[maxn + a[i]]++;
    if(n == 1) {
        printf("%d\n", abs(a[1]) == 1);
        return;
    }
    int res = 0;
    For(i, a[1], a[n]) {
        For(j, a[1], 0) num[maxn + j]--;
    }
    printf("%d\n", res);
}

int main() {
    freopen("in.txt", "r", stdin);
    c[0][0] = 1;
    For(i, 1, maxn) {
        c[i][0] = 1;
        For(j, 1, i) c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
    }
    // cout << c[3][2] << endl;
    read(T);
    while(T--) {
        mian();
        For(i, 1, n) num[maxn + a[i]] = 0;
    }
}
/*
1
5
-1 0 0 1 1
1
0
1
1
3
-1 1 2
5
-4 -3 -3 -2 -1

*/