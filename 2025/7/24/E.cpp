#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)


#define maxn 500000

int n, q, a[maxn + 5];

LL tr[maxn + 5];
void ins(int x, int y) {
    while(x <= n) tr[x] += y, x += x & -x;
}
LL que(int x) {
    LL res = 0;
    while(x) res += tr[x], x -= x & -x;
    return res;
}

vector<int> ch[maxn + 5];

int fa[maxn + 5][25], dfn[maxn + 5], tot = 0, id[maxn + 5];
int dep[maxn + 5], sz[maxn + 5];
void dfs(int u, int pre) {
    sz[u] = 1;
    fa[u][0] = pre;
    For(o, 1, 20) fa[u][o] = fa[fa[u][o - 1]][o - 1];
    dep[u] = dep[pre] + 1;
    dfn[u] = ++tot;
    for(auto v : ch[u]) if(v != pre) {
        dfs(v, u);
        sz[u] += sz[v];
    }
}

int lca(int u, int v) {
    if(dep[u] < dep[v]) swap(u, v);
    Rof(o, 20, 0) if(dep[fa[u][o]] >= dep[v]) u = fa[u][o];
    if(u == v) return u;
    Rof(o, 20, 0) if(fa[u][o] != fa[v][o]) {
        u = fa[u][o];
        v = fa[v][o];
    }
    return fa[u][0];
}

int chk(vector<int> &vec) {
    // for(auto v : vec) cout << v << " "; cout << endl;
    int now = 1 << 24;
    reverse(vec.begin(), vec.end());
    int p = vec.back(); vec.pop_back();
    for(auto v : vec) {
        if(v == 1) now |= (now >> 1);
        else {
            int tmp = now >> v;
            for(int j = 1; j <= 24 / v; ++j) {
                // if(j == 12 && v == 2) cout << "asd" << endl;
                if((now >> (v * j)) & 1) tmp |= (1 << j);
            }
            now = tmp;
        }
        // For(i, 1, 24) cout << ((now >> i) & 1) << " "; cout << endl;
    }
    // cout << now << endl;
    return (now >> p) & 1;
}

int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%d%d", &n, &q);
    For(i, 1, n) scanf("%d", &a[i]);
    For(i, 1, n - 1) {
        int u, v; scanf("%d%d", &u, &v);
        ch[u].push_back(v);
        ch[v].push_back(u);
    }
    dfs(1, 0);
    For(i, 1, n) {
        if(a[i] >= 2) ins(dfn[i], a[i]), ins(dfn[i] + sz[i], -a[i]);
    }
    while(q--) {
        int op, x, y; scanf("%d%d%d", &op, &x, &y);
        if(op == 1) {
            int lc = lca(x, y);
            LL sum = que(dfn[x]) + que(dfn[y]) - 2 * que(dfn[lc]);
            if(a[lc] >= 2) sum += a[lc];
            // cout << sum << endl;
            if(sum > 24) puts("0");
            else {
                int len = dep[x] + dep[y] - 2 * dep[lc] + 1;
                if(len >= 24) puts("1");
                else {
                    // cout << "asd" << endl;
                    int now = x;
                    vector<int> vec;
                    while(now != lc) {
                        vec.push_back(a[now]);
                        now = fa[now][0];
                    }
                    vec.push_back(a[lc]);
                    vector<int> vec1;
                    now = y;
                    while(now != lc) {
                        vec1.push_back(a[now]);
                        now = fa[now][0];
                    }
                    reverse(vec1.begin(), vec1.end());
                    for(auto v : vec1) vec.push_back(v);
                    printf("%d\n", chk(vec));
                }
            }
        }
        else {
            if(a[x] >= 2) {
                ins(dfn[x], -a[x]); ins(dfn[x] + sz[x], a[x]);
            }
            a[x] = y;
            if(a[x] >= 2) {
                ins(dfn[x], a[x]); ins(dfn[x] + sz[x], -a[x]);
            }
        }
    }
}