#include<bits/stdc++.h>
using namespace std;
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)

#define maxn 1000000
#define P 998244353
int T, n, a[maxn + 5], cnt[maxn + 5], fac[maxn + 5], ifac[maxn + 5];
int st[maxn + 5], tp = 0, L[maxn + 5], R[maxn + 5];
vector<int> ch[maxn + 5];

int fp(int x, int y) {
    int res = 1;
    while(y) {
        if(y & 1) res = 1ll * res * x % P;
        x = 1ll * x * x % P;
        y >>= 1;
    }
    return res;
}

int dep[maxn + 5];
void dfs(int u, int pre) {
    dep[u] = dep[pre] + 1;
    for(auto v : ch[u]) if(v != pre) dfs(v, u);
}

int C(int x, int y) {
    return 1ll * fac[x] * ifac[y] % P * ifac[x - y] % P;
}

void mian() {
    // cout << "asd" << endl;
    scanf("%d", &n);
    For(i, 1, n) scanf("%d", &a[i]);
    tp = 0;
    a[0] = -1;
    a[n + 1] = 0;
    For(i, 1, n + 1) {
        int las = 0;
        while(tp && a[i] < a[st[tp]]) {
            R[st[tp]] = i;
            if(las) ch[st[tp]].push_back(las);
            las = st[tp];
            tp--;
        }
        if(las) ch[i].push_back(las);
        L[i] = st[tp];
        st[++tp] = i;
    }
    int las = 0;
    while(tp) {
        if(las) ch[st[tp]].push_back(las);
        las = st[tp];
        tp--;
    }
    if(las) ch[st[tp]].push_back(las);
    dep[0] = -2;
    dfs(0, 0);
    // For(i, 1, n) cout << dep[i] << " "; cout << endl;
    // For(i, 1, n) cout << L[i] << " " << R[i] << endl; cout << endl;
    int res = 0;
    For(i, 1, n) {
        int cnt = R[i] - L[i] - 1;
        // if(!cnt)
        res = (res + 1ll * C(cnt + dep[i] - 1, dep[i])) % P;
        // cout << i << " " << cnt << " " << dep[i] << endl;
    }
    res = (res + 1) % P;
    printf("%d\n", res);
}

int main() {
    fac[0] = 1;
    For(i, 1, maxn) fac[i] = 1ll * fac[i - 1] * i % P;
    ifac[maxn] = fp(fac[maxn], P - 2);
    Rof(i, maxn - 1, 0) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % P;
    // freopen("in.txt", "r", stdin);
    scanf("%d", &T);
    while(T--) {
        mian();
        For(i, 0, n + 1) ch[i].resize(0);
    }
}