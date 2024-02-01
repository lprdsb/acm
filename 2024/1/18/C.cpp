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

#define maxn 100000
int T, n, col[maxn + 5], l[maxn + 5], r[maxn + 5], ll[maxn + 5], rr[maxn + 5], to[maxn + 5], sum[2][maxn + 5];
LL a[maxn + 5];


void mian() {
    read(n);
    For(i, 1, n) read(a[i]);
    a[0] = -Inf; a[n + 1] = Inf;
    For(i, 1, n) to[i] = a[i] - a[i - 1] < a[i + 1] - a[i] ? i - 1 : i + 1;
    For(i, 1, n) if(to[i] == i - 1 && to[i - 1] != i) to[i] = to[i - 1];
    Rof(i, n, 1) if(to[i] == i + 1 && to[i + 1] != i) to[i] = to[i + 1];
    int cnt = 0;
    For(i, 1, n) if(to[i] == i + 1) {
        col[i] = col[i + 1] = ++cnt;
        ll[cnt] = i;
        rr[cnt] = i + 1;
    }
    For(i, 1, n) {
        col[i] = col[to[i]];
        l[col[i]] = min(l[col[i]], i);
        r[col[i]] = max(r[col[i]], i);
    }
    sum[0][1] = sum[1][cnt] = 0;
    For(i, 2, cnt) sum[0][i] = sum[0][i - 1] + a[l[i]] - a[rr[i - 1]] + 1 + ll[i] - l[i];
    Rof(i, cnt - 1, 1) sum[1][i] = sum[1][i + 1] + a[ll[i + 1]] - a[r[i]] + 1 + r[i] - rr[i];
    int m; read(m);
    while(m--) {
        int x, y, res = 0; read(x); read(y);
        if(x < y) {
            if(col[x] == col[y]) {
                if(y <= rr[col[y]]) res = y - x;
                else {
                    if(x <= rr[col[x]]) res = rr[col[x]] - x + a[y] - a[rr[col[x]]];
                    else res = a[y] - a[x];
                }
            }
            else {
                if(x >= rr[col[x]]) res -= ll[col[x]] - x + a[x] - a[rr[col[x]]] + 1;
                res += ll[col[x]] - x;
                x = ll[col[x]];
                res += sum[0][col[y]] - sum[0][col[x]], x = ll[col[y]];
                if(y < x) res += y - x;
                else if(y > x) res += 1 + a[y] - a[rr[col[y]]];
            }
        }
        else {
            if(col[x] == col[y]) {
                if(y >= ll[col[x]]) res = x - y;
                else {
                    if(x >= ll[col[x]]) res = x - ll[col[x]] + a[ll[col[x]]] - a[y];
                    else res = a[x] - a[y];
                }
            }
            else {
                if(x <= ll[col[x]]) res -= x - rr[col[x]] + a[ll[col[x]]] - a[x] + 1;
                res += x - rr[col[x]];
                x = rr[col[x]];
                res += sum[1][col[y]] - sum[1][col[x]], x = rr[col[y]];
                if(y > x) res += x - y;
                else if(y < x) res += 1 + a[ll[col[y]]] - a[y];
            }
        }
        printf("%d\n", res);
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    memset(l, inf, sizeof l);
    memset(r, -inf, sizeof r);
    read(T);
    while(T--) {
        mian();
        For(i, 1, n) {
            l[i] = inf;
            r[i] = -inf;
        }
    }
}
