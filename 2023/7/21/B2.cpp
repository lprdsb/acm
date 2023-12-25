#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 7;

namespace Dinic
{
    int n, m, s, t;
    int tot = 1, head[N];
    struct qxx
    {
        int to, nxt;
        long long res;
    } e[N << 2];
    int level[N], cur[N];
    void clear(int n)
    {
        fill(head, head + n + 1, 0);
        Dinic::n = n;
        tot = 1;
    }
    void addedge(int u, int v, long long cap)
    {
        e[++tot].to = v;
        e[tot].res = cap;
        e[tot].nxt = head[u];
        head[u] = tot;
        e[++tot].to = u;
        e[tot].res = 0;
        e[tot].nxt = head[v];
        head[v] = tot;
    }
    bool bfs()
    {
        fill(level, level + n + 1, 0);
        queue<int> q;
        q.push(s);
        level[s] = 1;
        cur[s] = head[s];
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            for (int i = head[x]; i; i = e[i].nxt)
            {
                int v = e[i].to;
                if (!level[v] && e[i].res > 0)
                {
                    cur[v] = head[v];
                    level[v] = level[x] + 1;
                    q.push(v);
                }
            }
        }
        return level[t];
    }
    long long dfs(int x, long long res)
    {
        if (x == t || !res)
            return res;
        long long flow = res;
        for (int &i = cur[x]; i; i = e[i].nxt)
        {
            int v = e[i].to;
            if (!e[i].res || level[v] != level[x] + 1)
                continue;
            long long f = dfs(v, min(flow, e[i].res));
            if (f > 0)
            {
                e[i].res -= f;
                e[i ^ 1].res += f;
                flow -= f;
                if (!flow)
                    break;
            }
            else
                level[v] = 0;
        }
        return res - flow;
    }
    long long Maxflow()
    {
        long long ans = 0;
        while (bfs())
        {
            ans += dfs(s, INT32_MAX >> 1);
        }
        return ans;
    }
}

struct qxx
{
    int to, nxt;
    long long res;
} e[N << 1];
int head[N], edge_cnt;
void add_edge(int u, int v, int w)
{
    e[++edge_cnt].to = v;
    e[edge_cnt].nxt = head[u];
    e[edge_cnt].res = w;
    head[u] = edge_cnt;
}

int par[N], dep[N], sz[N], Hson[N], top[N], id[N], rk[N], nodeval[N], node_tot;
void dfs_Init(int u, int Par)
{
    par[u] = Par;
    dep[u] = dep[Par] + 1;
    sz[u] = 1;
    Hson[u] = -1;
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].to;
        auto w = e[i].res;
        if (v == Par)
            continue;
        dfs_Init(v, u);
        sz[u] += sz[v];
        nodeval[v] = w;
        if (Hson[u] == -1 || sz[v] > sz[Hson[u]])
            Hson[u] = v;
    }
}

void dfs_work(int u, int t)
{
    top[u] = t;
    id[u] = ++node_tot;
    rk[node_tot] = u;
    if (Hson[u] == -1)
        return;
    dfs_work(Hson[u], t);
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].to;
        if (v != Hson[u] && v != par[u])
            dfs_work(v, v);
    }
}

int tot = 1;
struct seg_tree
{
    int val[N << 2];
    int L[N << 2], R[N << 2];
    void build(int l, int r, int p = 1)
    {
        val[p] = ++tot;
        L[p] = l;
        R[p] = r;
        if (l == r)
        {
            Dinic::addedge(val[p], Dinic::t, nodeval[rk[l]]);
            return;
        }
        int mid = l + r >> 1;
        build(l, mid, p << 1);
        build(mid + 1, r, p << 1 | 1);
        Dinic::addedge(val[p], val[p << 1], INT32_MAX);
        Dinic::addedge(val[p], val[p << 1 | 1], INT32_MAX);
    }
    void update(int l, int r, int node, int p = 1)
    {
        if (l > r)
            return;
        if (l <= L[p] && R[p] <= r)
        {
            Dinic::addedge(node, val[p], INT32_MAX);
            return;
        }
        int mid = L[p] + R[p] >> 1;
        if (l <= mid)
            update(l, r, node, p << 1);
        if (r > mid)
            update(l, r, node, p << 1 | 1);
    }
} ST;

void update_edge(int u, int v, int node)
{
    while (top[u] != top[v])
    {
        if (dep[top[u]] < dep[top[v]])
            swap(u, v);
        ST.update(id[top[u]], id[u], node);
        u = par[top[u]];
    }
    if (id[u] > id[v])
        swap(u, v);
    ST.update(id[u] + 1, id[v], node);
}

void solve()
{
    int n, m;
    cin >> n >> m;
    Dinic::s = 0, Dinic::t = 1;
    vector<int> node(n + 1);
    long long sum = 0;
    Dinic::clear(n * 3 + m + 1);
    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        add_edge(u, v, w);
        add_edge(v, u, w);
    }
    dfs_Init(1, 1);
    dfs_work(1, 1);
    ST.build(2, n);
    for (int i = 1; i <= m; i++)
    {
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        if (x - y <= 0)
            continue;
        sum += x - y;
        tot++;
        Dinic::addedge(Dinic::s, tot, x - y);
        update_edge(u, v, tot);
    }
    // cout << sum << endl;
    cout << sum - Dinic::Maxflow() << '\n';
}

signed main()
{
	freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}