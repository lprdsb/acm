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

int n, m, k, q;

#define maxn 100000
int fl = 0;
struct Node {
    LL sum[maxn + 5], opt[maxn + 5], asum[maxn + 5];
    int mx[maxn + 5][25], mn[maxn + 5][25], up;
    int find(int pos, int l) {
        Rof(o, 20, 0) {
            int to = l + (1 << o);
            if(to <= k + 1 && pos + sum[mx[l][o]] - sum[l - 1] <= up && pos + sum[mn[l][o]] - sum[l - 1] >= 0) {
                pos += sum[to - 1] - sum[l - 1];
                // if(fl) cout << o << " " << pos << endl;
                l = to;
            }
        }
        return l;
    }
    int f[2][maxn + 5][25];
    LL g[2][maxn + 5][25];
    pair<int, LL> que(int pos, int l, int r) {
        if(l > r) return { pos, 0 };
        if(pos + opt[l] > up) {
            auto tem = que(up, l + 1, r);
            tem.sec += up - pos;
            return tem;
        }
        if(pos + opt[l] < 0) {
            auto tem = que(0, l + 1, r);
            // if(fl && l == 1) cout << tem.sec << endl;
            tem.sec += pos;
            return tem;
        }
        if(pos == 0) {
            Rof(o, 20, 0) {
                int to = l + (1 << o);
                if(to <= r + 1) {
                    auto tem = que(f[0][l][o], to, r);
                    // if(fl && l == 2) cout << g[0][l][o] << endl;
                    tem.sec += g[0][l][o];
                    return tem;
                }
            }
        }
        if(pos == up) {
            Rof(o, 20, 0) {
                int to = l + (1 << o);
                if(to <= r + 1) {
                    auto tem = que(f[1][l][o], to, r);
                    tem.sec += g[1][l][o];
                    return tem;
                }
            }
        }
        int to = find(pos, l);
        // if(fl && l == 2) cout << to << endl;
        if(to <= r + 1) {
            auto tem = que(pos + sum[to - 1] - sum[l - 1], to, r);
            tem.sec += asum[to - 1] - asum[l - 1];
            return tem;
        }
        // if(fl) cout << l << " " << r << endl;
        return { pos + sum[r] - sum[l - 1], asum[r] - asum[l - 1] };
    }
    void init() {
        For(i, 1, k) {
            sum[i] = sum[i - 1] + opt[i];
            asum[i] = asum[i - 1] + abs(opt[i]);
        }
        Rof(i, k, 1) {
            mx[i][0] = mn[i][0] = i;
            For(o, 1, 20) {
                mx[i][o] = mx[i][o - 1];
                mn[i][o] = mn[i][o - 1];
                int to = i + (1 << (o - 1));
                if(to <= k) {
                    if(sum[mx[to][o - 1]] > sum[mx[i][o]]) mx[i][o] = mx[to][o - 1];
                    if(sum[mn[to][o - 1]] < sum[mn[i][o]]) mn[i][o] = mn[to][o - 1];
                }
            }
            f[0][i][0] = min((LL)up, max(0ll, sum[i] - sum[i - 1]));
            g[0][i][0] = f[0][i][0];
            f[1][i][0] = min((LL)up, max(0ll, up + sum[i] - sum[i - 1]));
            g[1][i][0] = up - f[1][i][0];
            For(o, 1, 20) {
                int to1 = i + (1 << (o - 1)), to2 = i + (1 << o) - 1;
                to1 = min(k + 1, to1);
                to2 = min(k, to2);
                auto tem = que(f[0][i][o - 1], to1, to2);
                f[0][i][o] = tem.fir;
                g[0][i][o] = g[0][i][o - 1] + tem.sec;
                tem = que(f[1][i][o - 1], to1, to2);
                f[1][i][o] = tem.fir;
                g[1][i][o] = g[1][i][o - 1] + tem.sec;
            }
        }
    }
} node[2];

int main() {
    // freopen("in.txt", "r", stdin);
    read(n); read(m); read(k); read(q); node[0].up = n; node[1].up = m;
    For(i, 1, k) {
        char c; cin >> c;
        int t; read(t);
        if(c == 'L' || c == 'R') node[0].opt[i] = (c == 'R' ? t : -t);
        if(c == 'U' || c == 'D') node[1].opt[i] = (c == 'U' ? t : -t);
    }
    For(o, 0, 1) node[o].init();
    fl = 1;
    For(i, 1, q) {
        int x, y, l, r; read(x); read(y); read(l); read(r);
        auto tx = node[0].que(x, l, r), ty = node[1].que(y, l, r);
        printf("%d %d %lld\n", tx.fir, ty.fir, tx.sec + ty.sec);
    }
    return 0;
}
