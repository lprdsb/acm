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

#define maxn 200000
int T, n, a[maxn + 5], b[maxn + 5];

template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for (ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if (ch == '-') ok = 1;
    for (x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if (ok) x = -x;
}

int ok[maxn + 5], to[maxn + 5];

int tr[2][maxn + 5];
void ins(int ty, int x, int y) {
    while (x <= n) {
        if (ty) tr[ty][x] = max(tr[ty][x], y);
        else tr[ty][x] = min(tr[ty][x], y);
        x += x & -x;
    }
}
int que(int ty, int x) {
    int res = -1;
    while (x) {
        if (ty) {
            if (res == -1 || tr[ty][x] > res) res = tr[ty][x];
        }
        else {
            if (res == -1 || tr[ty][x] < res) res = tr[ty][x];
        }
        x -= x & -x;
    }
    return res;
}

int main() {
    // freopen("in.txt", "r", stdin);
    memset(tr[0], inf, sizeof tr[0]);
    read(T);
    while (T--) {
        read(n);
        For(i, 1, n) read(a[i]);
        For(i, 1, n) read(b[i]);
        Rof(i, n, 1) {
            to[a[i]] = i;
            ins(1, i, a[i]);
            ins(0, i, b[i]);
            if (to[b[i]]) {
                // if (i == 1) cout << que(1, to[b[i]]) << endl;
                if (b[i] >= que(1, to[b[i]]) && b[i] <= que(0, to[b[i]])) ok[i] = 1;
            }
        }
        For(i, 1, n) tr[0][i] = inf, tr[1][i] = 0;
        For(i, 1, n) to[i] = 0;
        For(i, 1, n) {
            to[a[i]] = i;
            ins(1, n - i + 1, a[i]);
            ins(0, n - i + 1, b[i]);
            if (to[b[i]]) {
                if (b[i] >= que(1, n - to[b[i]] + 1) && b[i] <= que(0, n - to[b[i]] + 1)) ok[i] = 1;
            }
        }
        int res = 1;
        For(i, 1, n) {
            // cout << ok[i] << endl;
            res &= ok[i];
            ok[i] = 0;
        }
        puts(res ? "YES" : "NO");
        For(i, 1, n) {
            to[i] = 0;
            tr[0][i] = inf, tr[1][i] = 0;
        }
    }
}
