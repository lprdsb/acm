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
int n, X, Y, a[maxn + 5], b[maxn + 5], cnt = 0;

int tr[2][maxn + 5];
void ins(int ty, int x, int y) {
    if(ty) x = cnt - x + 1;
    while(x <= cnt) tr[ty][x] = min(tr[ty][x], y), x += x & -x;
}
int que(int ty, int x) {
    if(ty) x = cnt - x + 1;
    int mn = n + 1;
    while(x) mn = min(mn, tr[ty][x]), x -= x & -x;
    return mn;
}

bool chk(int x) {
    For(i, 1, n) tr[0][i] = tr[1][i] = n + 1;
    int pos = n;
    Rof(i, n, 1) {
        int tem = min(que(1, lower_bound(b + 1, b + cnt + 1, b[a[i]] + x + 1) - b), que(0, lower_bound(b + 1, b + cnt + 1, b[a[i]] - x) - b - 1));
        if(tem > pos) pos = i;
        For(o, 0, 1) ins(o, a[i], i);
    }
    For(i, 1, n) {
        if(abs(b[a[i]] - X) <= x) {
            if(i == pos) return 1;
        }
        else break;
    }
    For(i, 1, n) {
        if(abs(b[a[i]] - Y) <= x) {
            if(i == pos) return 1;
        }
        else break;
    }
    return 0;
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(n); read(X); read(Y);
    For(i, 1, n) read(a[i]), b[++cnt] = a[i];
    sort(b + 1, b + cnt + 1);
    cnt = unique(b + 1, b + cnt + 1) - b - 1;
    For(i, 1, n) a[i] = lower_bound(b + 1, b + cnt + 1, a[i]) - b;
    int l = abs(X - Y), r = inf;
    while(l < r) {
        // cout << l << " " << r << endl;
        int md = l + r >> 1;
        if(chk(md)) r = md;
        else l = md + 1;
    }
    // cout << chk(1) << endl;
    printf("%d\n", l);
    // cout << (DD)clock() / 1000 << endl;
}
