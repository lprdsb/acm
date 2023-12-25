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

int m, num[30];

template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

int main() {
    //freopen("in", "r", stdin);
    read(m);
    while(m--) {
        int t, v; read(t); read(v);
        if(t == 1) num[v]++;
        else {
            int now = 0, fl = 1;
            For(o, 0, 29) {
                now += num[o];
                if((v >> o) & 1) {
                    if(!now) {
                        fl = 0;
                        break;
                    }
                    now--;
                }
                now >>= 1;
            }
            puts(fl ? "YES" : "NO");
        }
    }
    return 0;
}
