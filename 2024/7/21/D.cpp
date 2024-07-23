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
int T, n, a[maxn + 5];

int f[maxn + 5][3];
void mian() {
    read(n);
    For(i, 1, n) read(a[i]);
    if(n == 1) {
        if(a[1]) puts("1");
        else puts("0");
        return;
    }
    f[0][0] = 0; f[0][1] = f[0][2] = inf;
    For(i, 0, n - 1) {
        For(o, 0, 2) f[i + 1][o] = inf;
        if(f[i][0] != inf) {
            f[i + 1][0] = min(f[i + 1][0], f[i][0] + (a[i + 1] != 0));
            if(a[i + 1] <= 2) f[i + 1][1] = min(f[i + 1][1], f[i][0] + 1);
            else f[i + 1][1] = min(f[i + 1][1], f[i][0] + 2);
            f[i + 1][2] = min(f[i + 1][2], f[i][0] + 1 + (a[i + 1] != 0));
        }
        if(f[i][1] != inf) {
            if(a[i + 1] <= 2) f[i + 1][0] = min(f[i + 1][0], f[i][1]);
            else f[i + 1][0] = min(f[i + 1][0], f[i][1] + 1);
            if(a[i + 1] <= 2) f[i + 1][1] = min(f[i + 1][1], f[i][1] + 1);
            else f[i + 1][1] = min(f[i + 1][1], f[i][1] + 2);
            if(a[i + 1] <= 4) f[i + 1][2] = min(f[i + 1][2], f[i][1] + 1);
            else f[i + 1][2] = min(f[i + 1][2], f[i][1] + 2);
        }
        if(f[i][2] != inf) {
            f[i + 1][0] = min(f[i + 1][0], f[i][2] + (a[i + 1] != 0));
            if(a[i + 1] <= 4) f[i + 1][1] = min(f[i + 1][1], f[i][2] + 1);
            else f[i + 1][1] = min(f[i + 1][1], f[i][2] + 2);
            f[i + 1][2] = min(f[i + 1][2], f[i][2] + 1 + (a[i + 1] != 0));
        }
    }
    // cout << f[3][0] << endl;
    printf("%d\n", f[n][0]);
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
