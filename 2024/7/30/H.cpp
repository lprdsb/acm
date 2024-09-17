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

#define maxn 40
int n, m;

template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

#define maxm 2000000
int sta[41][2], lim[maxm + 5];
int mx[2][maxm + 5];
int main() {
    //freopen("in", "r", stdin);
    read(n); read(m);
    For(i, 1, m) {
        int u, v; read(u); read(v);
        if(u > v) swap(u, v);
        if(v <= 20) {
            sta[u][0] |= (1 << (v - 1));
            sta[v][0] |= (1 << (u - 1));
        }
        else if(u <= 20) {
            sta[u][1] |= (1 << (v - 20 - 1));
            sta[v][0] |= (1 << (u - 1));
        }
    }
    For(mask, 0, (1 << 20) - 1) {
        int fl = 1;
        For(o, 0, 19) if(((mask >> o) & 1) && (mask & sta[o + 1][0])) {
            fl = 0;
            break;
        }
        if(fl) mx[0][mask] = __builtin_popcount(mask);
    }

    For(mask, 0, (1 << 20) - 1) For(o, 0, 19) if((mask >> o) & 1) lim[mask] |= sta[o + 1][1];

    For(mask, 0, (1 << 20) - 1) {
        int fl = 1;
        For(o, 0, 19) if(((mask >> o) & 1) && (mask & sta[20 + o + 1][1])) {
            fl = 0;
            break;
        }
        if(fl) mx[1][mask] = __builtin_popcount(mask);
    }

    For(mask, 0, (1 << 20) - 1) For(o, 0, 19) if(((mask >> o) & 1)) mx[1][mask] = max(mx[1][mask], mx[1][mask ^ (1 << o)]);
    int res = 0;
    For(mask, 0, (1 << 20) - 1) res = max(res, mx[0][mask] + mx[1][((1 << 20) - 1) ^ lim[mask]]);

    printf("%d\n", res);
}
