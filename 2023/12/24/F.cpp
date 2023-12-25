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

#define maxn 1000
int T, n, d;
struct Bit {
    int len;
    unsigned LL v[1005];
    void shift(int x) {
        if(x < 64) {
            Rof(i, len - 1, 1) v[i] = (v[i] << x) | (v[i - 1] >> (64 - x));
            v[0] <<= x;
        }
    }
    void operator ^= (cst Bit &_x) {
        int o = min(len, _x.len);
        For(o, 0, o - 1) v[o] ^= _x.v[o];
    }
    int operator [] (cst int &_x) {
        return (v[_x / 64] >> (_x % 64)) & 1;
    }
    void init(int _len) {
        len = (_len - 1) / 64 + 1;
        For(o, 0, len - 1) v[o] = 0;
    }
} f[maxn + 5];

template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

int l[maxn + 5], ok[maxn + 5];
void sol() {
    read(n); read(d);
    int fl = 0;
    For(i, 1, n) {
        read(l[i]);
        if(l[i] > d / 2) {
            if(!fl) fl = i;
            else {
                puts("No");
                return;
            }
        }
    }
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        sol();
    }
}
