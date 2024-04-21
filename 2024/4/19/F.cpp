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

#define maxn 6000000
int T, n, a[maxn + 5];
struct Set {
    int fa[maxn + 5];
    void init() {
        For(i, 1, 3 * n + 1) fa[i] = i;
    }
    int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
    void mer(int x, int y) { fa[find(x)] = find(y); }
} se[2];

void sol(int l, int r) {
    // cout << l << " " << r << endl;
    int ll = l, rr = r;
    l = se[1].find(l);
    if(l > r) return;
    while(se[1].find(se[0].find(l) + 1) <= r) se[0].mer(l, se[1].find(se[0].find(l) + 1));
}

int L[maxn + 5], R[maxn + 5], sum[maxn + 5], vis[maxn + 5];
void mian() {
    read(n);
    For(i, 1, n) read(L[i]), read(R[i]);
    For(o, 0, 1) se[o].init();
    For(i, 1, 3 * n + 1) sum[i] = vis[i] = 0;
    For(i, 1, n) {
        int l = n + i - R[i], r = n + i - L[i];
        sum[l]++; sum[r + 1]--;
    }
    For(i, 1, 3 * n) {
        sum[i] += sum[i - 1];
        if(!sum[i]) se[1].mer(i, i + 1);
    }

    For(i, 1, 3 * n) sum[i] = 0;
    For(i, 1, n) {
        int l = n + i + L[i], r = n + i + R[i];
        sum[l]++; sum[r + 1]--;
    }
    For(i, 1, 3 * n) {
        sum[i] += sum[i - 1];
        if(!sum[i]) se[1].mer(i, i + 1);
    }

    For(i, 1, n) {
        sol(n + i - R[i], n + i - L[i]);
        sol(n + i + L[i], n + i + R[i]);
    }
    For(i, 1, n) {
        int l = se[1].find(n + i - R[i]), r = se[1].find(n + i + L[i]);
        if(l <= n + i - L[i] && r <= n + i + R[i]) se[0].mer(l, r);
    }
    int res = 0;
    For(i, 1, n) {
        if(se[1].find(n + i - R[i]) <= n + i - L[i]) vis[se[0].find(se[1].find(n + i - R[i]))] = 1;
        else if(se[1].find(n + i + L[i]) <= n + i + R[i]) vis[se[0].find(se[1].find(n + i + L[i]))] = 1;
        else res++;
    }
    For(i, 1, 3 * n) res += vis[i];
    printf("%d\n", res);
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
