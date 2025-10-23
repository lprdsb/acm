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

#define maxn 300000
int n, m;

#define LIM 1000000000ll
LL a[maxn + 5], b[maxn + 5];
int chk(int id, LL x, LL y) {
    LL tmp = (2 * LIM * (y - a[id]) - (b[id] - a[id]) * (x + LIM));
    if(tmp) return tmp < 0;
    return -1;
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(n); read(m);
    For(i, 1, n) read(a[i]);
    For(i, 1, n) read(b[i]);
    // cout << chk(2, -10, 0) << endl;
    For(i, 1, m) {
        int ok[2] = { 0, 0 };
        For(o, 0, 1) {
            LL x, y; read(x); read(y);
            int l = 1, r = n + 1;
            while(l < r) {
                int md = l + r >> 1, tmp = chk(md, x, y);
                if(tmp == -1) {
                    ok[o] = -1;
                    break;
                }
                if(tmp) r = md;
                else l = md + 1;
            }
            // cout << x << " " << y << " " << ok[o] << endl;
            // if(ok[o] == -1) break;
            ok[o] = l - 1;
        }
        if(ok[0] == -1 || ok[1] == -1 || ok[0] != ok[1]) puts("-1");
        else printf("%d\n", ok[0]);
    }
    return 0;
}
