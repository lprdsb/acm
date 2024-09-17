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

int n, m, x;

#define maxm 5000000
#define maxn 1000000
int to[maxm + 5], dis[maxm + 5], T;
vector<pair<int, int> > ch[maxm + 5];
int q[maxm + 5], l = 1, r = 0, tot;

int hd[maxm + 5], len = 0, suf[maxn + 5], pre[maxn + 5];
struct Edge {
    int v, net;
} e[2 * maxm + 5];
void add(int u, int v) {
    e[len] = { v, hd[u] };
    hd[u] = len++;
}

void mian() {
    read(n); read(m); read(x); tot = n;
    For(i, 1, m) {
        int u, v; read(u); read(v);
        ch[u].pb({ ++tot, v }); add(u, v); assert(n + len == tot);
        ch[v].pb({ ++tot, u }); add(v, u); assert(n + len == tot);
        to[tot] = tot - 1;
        to[tot - 1] = tot;
        // cout << u << " " << v << " " << tot - 1 << " " << tot << endl;
    }
    // for(auto [id, v] : ch[4]) cout << id << endl;
    int ok = tot;
    For(i, 1, n) {
        For(j, 0, ch[i].size() - 1) {
            pre[j] = ++tot;
            if(j) add(pre[j], pre[j - 1]);
            add(pre[j], ch[i][j].fir);
        }
        Rof(j, ch[i].size() - 1, 0) {
            suf[j] = ++tot;
            if(j < ch[i].size() - 1) add(suf[j], suf[j + 1]);
            add(suf[j], ch[i][j].fir);
        }
        For(j, 0, ch[i].size() - 1) {
            int id = ch[i][j].fir;
            // if(to[id] == 33) cout << pre[j - 1] << endl;
            if(j) add(to[id], pre[j - 1]);
            if(j < ch[i].size() - 1) add(to[id], suf[j + 1]);
        }
    }
    assert(tot <= maxm);
    for(auto [id, v] : ch[1]) add(v, id);
    For(i, 1, tot) dis[i] = -1;
    l = 1; r = 0;
    q[++r] = x;
    dis[x] = 0;
    while(l <= r) {
        int u = q[l++];
        if(u == 1) continue;
        for(int i = hd[u]; ~i; i = e[i].net) {
            int v = e[i].v;
            // cout << v << endl;
            if(dis[v] == -1 || dis[v] > dis[u] + (u <= ok)) {
                dis[v] = dis[u] + (u <= ok);
                if(u > ok) q[--l] = v;
                else q[++r] = v;
            }
        }
    }
    int res = inf;
    // cout << dis[5] << endl;
    // for(auto [id, v] : ch[n]) cout << dis[id] << endl;
    for(auto [id, v] : ch[n]) if(dis[id] != -1) res = min(res, dis[id]);
    if(res != inf) printf("Vegetable fallleaves\n%d\n", res - 1);
    else puts("Boring Game");
}

int main() {
    // freopen("in.txt", "r", stdin);
    memset(dis, -1, sizeof dis);
    memset(hd, -1, sizeof hd);
    read(T);
    while(T--) {
        mian();
        For(i, 1, tot) {
            hd[i] = -1;
            ch[i].resize(0);
        }
        len = 0;
    }
}