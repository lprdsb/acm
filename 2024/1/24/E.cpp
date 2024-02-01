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
int n, q, s, d, a[maxn + 5];
set<pair<int, int> > se;
int fa[maxn + 5];
vector<int> vec[maxn + 5];
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

vector<pair<int, int> > ch[maxn + 5];

int mx[maxn + 5];
void dfs(int u, int pre) {
    for(auto [v, w] : ch[u]) if(v != pre) {
        mx[v] = max(mx[u], w);
        dfs(v, u);
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(n); read(q); read(s); read(d);
    For(i, 1, n) read(a[i]), se.insert({ a[i], i }), vec[i].pb(i), fa[i] = i;
    int cnt = n - 1;
    while(cnt) {
        For(i, 1, n) if(fa[i] == i) {
            for(auto j : vec[i]) se.erase({ a[j], j });
            int u, v, dis = inf;
            for(auto j : vec[i]) {
                auto it = se.lower_bound({ a[j] - d, 0 });
                if(it != se.end()) {
                    int tem = abs(abs(a[j] - it->fir) - d);
                    if(tem < dis) u = j, v = it->sec, dis = tem;
                }
                if(it != se.begin()) {
                    it--;
                    int tem = abs(abs(a[j] - it->fir) - d);
                    if(tem < dis) u = j, v = it->sec, dis = tem;
                }

                it = se.lower_bound({ a[j] + d, 0 });
                if(it != se.end()) {
                    int tem = abs(abs(a[j] - it->fir) - d);
                    if(tem < dis) u = j, v = it->sec, dis = tem;
                }
                if(it != se.begin()) {
                    it--;
                    int tem = abs(abs(a[j] - it->fir) - d);
                    if(tem < dis) u = j, v = it->sec, dis = tem;
                }
            }
            if(find(v) != i) {
                ch[u].pb({ v, dis }); ch[v].pb({ u, dis });
                fa[i] = find(v);
            }
            for(auto j : vec[i]) se.insert({ a[j], j });
        }
        For(i, 1, n) if(fa[i] != i && vec[i].size()) {
            for(auto j : vec[i]) vec[find(i)].pb(j);
            vec[i].resize(0);
            cnt--;
        }
    }
    // cout << "asd" << endl;
    dfs(s, 0);
    while(q--) {
        int i, k; read(i); read(k);
        puts(mx[i] <= k ? "Yes" : "No");
    }
    return 0;
}
