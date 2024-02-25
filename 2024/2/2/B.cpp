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

int T, n;
map<int, int> ma[2];

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        read(n);
        For(i, 1, n) {
            int x, y; read(x); read(y);
            ma[x - 1][y] = 1;
        }
        int resl = 2, resr = 2;
        for(auto [k, v] : ma[0]) {
            if((ma[0][k] || ma[0][k - 1]) && (ma[1][k] || ma[1][k - 1])) {
                if(k < 0) resl = 0;
                if(k > 0) resr = 0;
            }
            if((ma[0][k] || ma[1][k])) {
                if(k < 0 && resl > 1) resl = 1;
                if(k > 0 && resr > 1) resr = 1;
            }
        }
        for(auto [k, v] : ma[1]) {
            if((ma[0][k] || ma[0][k - 1]) && (ma[1][k] || ma[1][k - 1])) {
                if(k < 0) resl = 0;
                if(k > 0) resr = 0;
            }
            if((ma[0][k] || ma[1][k])) {
                if(k < 0 && resl > 1) resl = 1;
                if(k > 0 && resr > 1) resr = 1;
            }
        }
        int res = 3;
        if(ma[1][0]) {
            resl = min(resl, 1), resr = min(resr, 1);
            if(ma[0][-1]) resl = 0;
            if(ma[0][1]) resr = 0;
        }
        else {
            if(ma[0][-1] && ma[0][1]) res = min(res, 1);
            if(ma[0][-1] || ma[0][1]) res = min(res, 2);
        }
        printf("%d\n", min(res, resl + resr));
        For(o, 0, 1) ma[o].clear();
    }
    return 0;
}
