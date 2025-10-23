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

LL x[4], y[4];
LL com(LL tmp) {
    if(tmp > 0) return 1;
    if(tmp == 0) return 0;
    return -1;
}

LL mul(int i, int j) {
    return 1ll * x[i] * y[j] - 1ll * y[i] * x[j];
}

DD get_len(int i) {
    return sqrt(1ll * x[i] * x[i] + 1ll * y[i] * y[i]);
}

void mian() {
    For(i, 0, 2) read(x[i]), read(y[i]);
    For(i, 1, 2) x[i] -= x[0], y[i] -= y[0];
    x[3] = y[2] - y[1]; y[3] = -x[2] + x[1];
    DD res = INFINITY;
    // For(i, 1, 3) cout << x[i] << " " << y[i] << endl;
    // cout << mul(3, 1) << " " << mul(3, 2) << endl;
    if(com(mul(3, 1)) == com(mul(3, 2))) {
        if(com(mul(3, 1)) == 0) {
            if(x[1] * x[2] + y[1] * y[2] > 0) {
                res = min(get_len(1), get_len(2));
            }
            else res = 0;
        }
        else res = min(get_len(1), get_len(2));
    }
    else {
        res = (DD)abs(x[1] * x[3] + y[1] * y[3]) / get_len(3);
    }
    printf("%.3lf\n", res);
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
