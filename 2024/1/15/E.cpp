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

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        int h, w, xa, ya, xb, yb; read(h); read(w); read(xa); read(ya); read(xb); read(yb);
        if(xa < xb) {
            if(ya == yb) puts(((xa - xb) & 1) ? "Alice" : "Bob");
            else if((xb - xa) & 1) {
                if(abs(ya - yb) == 1) puts("Alice");
                else {
                    if(ya < yb) {
                        if((w - 1 - ya) * 2 + 1 <= xb - xa) puts("Alice");
                        else puts("Draw");
                    }
                    else {
                        if((ya - 2) * 2 + 1 <= xb - xa) puts("Alice");
                        else puts("Draw");
                    }
                }
            }
            else {
                if(ya > yb) {
                    if(2 * (w - yb) <= xb - xa) puts("Bob");
                    else puts("Draw");
                }
                else {
                    if(2 * (yb - 1) <= xb - xa) puts("Bob");
                    else puts("Draw");
                }
            }
        }
        else puts("Draw");
    }
}
