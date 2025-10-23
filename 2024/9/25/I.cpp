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

int n, m;

#define mod 1000000007
struct Mat {
    int a[200][200];
} A, B;
Mat operator * (cst Mat &x, cst Mat &y) {
    Mat res = {};
    For(i, 1, n) For(j, 1, n) {
        int tmp = x.a[i][j];
        For(p, 1, n) res.a[i][p] = (res.a[i][p] + 1ll * tmp * y.a[j][p] % mod) % mod;
    }
    return res;
}

Mat fp(Mat x, int y) {
    Mat res = {};
    For(i, 1, n) res.a[i][i] = 1;
    while(y) {
        if(y & 1) res = res * x;
        x = x * x;
        y >>= 1;
    }
    return res;
}

int main() {
    //freopen("in", "r", stdin);
    int T; read(T);
    while(T--) {
        read(n); read(m);
        For(i, 1, n) For(j, 1, n) read(A.a[i][j]);
        For(i, 1, n) For(j, 1, n) read(B.a[i][j]);
        Mat res = fp(A * B, m);
        For(i, 1, n) {
            For(j, 1, n) cout << res.a[i][j] << " ";
            cout << endl;
        }
    }
}
