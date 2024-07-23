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

int q, P[25];
#define maxn 2097152
struct Tree {
    int up;
    bool tr[maxn + 5], s;
    void ins(int x) {
        x++;
        s ^= 1;
        while(x <= up) tr[x] ^= 1, x += x & -x;
        // cout << tr[1] << endl;
    }
    bool que(int x) {
        x++;
        bool res = 0;
        while(x) res ^= tr[x], x -= x & -x;
        return res;
    }
    int que(int l, int r) {
        bool res = 0;
        // cout << tr[1] << endl;
        if(l <= r) return que(r) ^ que(l - 1);
        else return s ^ que(l - 1) ^ que(r);
    }
} tr[21];

int sum[maxn + 5];
int main() {
    // freopen("in.txt", "r", stdin);
    For(o, 0, 21) P[o] = (1 << o) - 1;
    For(o, 0, 20) {
        tr[o].up = (1 << (o + 1)) + 1;
    }
    // cout << tr[0].tr[1] << endl;
    int n = 0;
    int q; read(q);
    while(q--) {
        int t, v; read(t); read(v);
        For(i, 1, t) For(o, 0, 20) tr[o].ins(sum[n - i] & P[o + 1]);
        n -= t;
        sum[n + 1] = (sum[n] + v) & P[21];
        For(o, 0, 20) tr[o].ins(sum[n] & P[o + 1]);
        n += 1;
        int res = 0;
        For(o, 0, 20) {
            bool tem = tr[o].que((sum[n] + 1) & P[o + 1], (sum[n] + (1 << o)) & P[o + 1]);
            // if(o == 0) cout << (sum[n] + 1) % (1 << (o + 1)) << " " << (sum[n] + (1 << o)) % (1 << (o + 1)) << endl;
            if(tem) res |= 1 << o;
        }
        printf("%d\n", res);
    }
    return 0;
}
