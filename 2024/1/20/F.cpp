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

#define maxn 200000
int n, a[maxn + 5], b[maxn + 5];
DD as[maxn + 5], asi[maxn + 5];
int st[maxn + 5], top = 0;
LL get_s(int x, int y, int z) {
    return 1ll * (y - x) * (a[z] - a[y]) - 1ll * (z - y) * (a[y] - a[x]);
}
LL get_s1(int x, int y, int z) {
    return 1ll * (y - x) * (a[z] - a[y]) - 1ll * (z - y) * (a[y] - b[x]);
}
DD mx[maxn + 5];
void sol() {
    top = 0;
    For(i, ((n + 2) >> 1), n) {
        while(top > 1 && get_s(st[top - 1], st[top], i) >= 0) top--;
        st[++top] = i;
    }
    Rof(i, n >> 1, 1) {
        int l = 1, r = top;
        while(l < r) {
            int md = l + r >> 1;
            if(get_s(i, st[md], st[md + 1]) >= 0) l = md + 1;
            else r = md;
        }
        mx[i] = max(mx[i + 1], (DD)(a[st[l]] - a[i]) / (st[l] - i) * (1 + n - 2 * i) + 2 * a[i]);
    }
    DD res = 0;
    For(i, 1, n >> 1) {
        int l = 1, r = top;
        while(l < r) {
            int md = l + r >> 1;
            if(get_s1(i, st[md], st[md + 1]) >= 0) l = md + 1;
            else r = md;
        }
        res = max(res, (DD)(a[st[l]] - b[i]) / (st[l] - i) * (1 + n - 2 * i) + 2 * b[i]);
        asi[i] = max(res, mx[i + 1]);
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(n);
    For(i, 1, n) read(a[i]);
    For(i, 1, n) read(b[i]);
    sol();
    For(i, 1, n >> 1) as[i] = asi[i];
    reverse(a + 1, a + n + 1);
    reverse(b + 1, b + n + 1);
    For(i, 1, n) swap(a[i], b[i]);
    sol();
    For(i, 1, n >> 1) as[n - i] = asi[i];
    top = 0;
    For(i, 1, n) {
        while(top > 1 && get_s(st[top - 1], st[top], i) >= 0) top--;
        st[++top] = i;
    }
    as[n] = Inf;
    // cout << st[3] << endl;
    For(i, 1, top - 1)
        as[n] = min(as[n], (DD)(a[st[i + 1]] - a[st[i]]) / (st[i + 1] - st[i]) * (1 + n - 2 * st[i]) + 2 * a[st[i]]);
    For(i, 1, n) printf("%.10lf ", as[i]);
    return 0;
}
