#include<bits/stdc++.h>
#define fs(i,x,y) for(int i=(x),_=(y);i<=_;++i)
#define fn(i,x,y) for(int i=(x),_=(y);i>=_;--i)
#define pi pair<int,int>
#define mpi(x,y) make_pair(x,y)
typedef long long ll;
using namespace std;

const int N = 2e5 + 7, M = 4e5 + 7;
int n;
int a[N], b[N];
vector<int>G[N];
set<int>s[N];
set<pi>bs[N];
int ce[N];
int deg[M], bcj[M], idx;
int ans[N];

int fd(int x) {
    // cout << "??" << x << endl;
    return bcj[x] ^ x ? bcj[x] = fd(bcj[x]) : x;
}

void chk(int vq, int vh, int u) {
    if(vq == 0)ce[u]--;
    if(vh == 0)ce[u]++;
}

bool mer(int x, int y, int u) {
    // cout << "???" << endl;
    int fx = fd(x), fy = fd(y);
    if(fx ^ fy) {
        bcj[fy] = fx;
        int tpdeg = deg[fx];
        deg[fx] += deg[fy];
        chk(tpdeg, deg[fx], u);
    }
    return false;
}

int ins(int u, int val) {
    if(s[u].find(val) != s[u].end()) {
        s[u].erase(s[u].find(val));
        return -1;
    }
    else {
        s[u].insert(val);
        return 1;
    }
}

void merge(int u, int v) {
    set<int>hh;
    // cout << "HH1" << endl;
    for(auto [num, id] : bs[v])hh.insert(fd(id));
    for(auto [num, id] : bs[v]) {
        auto it = bs[u].lower_bound(mpi(num, 0));
        if(hh.find(fd(id)) != hh.end()) {
            if(it != bs[u].end() && (*it).first == num) {
                // cout << "HHHH" << endl;
                hh.erase(hh.find(fd(id)));
                mer(fd((*it).second), fd(id), u);
            }

        }
        if(it == bs[u].end() || (*it).first != num)bs[u].insert(mpi(num, id));
    }
    // if(v == 7)cout << hh.size() << ' ' << (*hh.begin()) << ' ' << id[7][4] << ' ' << ce[u] << endl;
    // cout << "HH2" << endl;
    for(int id : hh)if(deg[id] == 0)++ce[u];
    // cout << ce[u] << endl;
    // for(auto [num,id] : bs[v]) {

    // }
    for(int nod : s[v]) {
        int dta = ins(u, nod);
        int fnod = fd(nod);
        int tpdeg = deg[fnod];
        deg[fnod] += dta;
        chk(tpdeg, deg[fnod], u);
    }
    // cout << "HHH3" << endl;
}

void dfs(int u, int fa) {
    for(int v : G[u]) {
        if(v ^ fa) {
            // cout << "//" << u << ' ' << v << endl;
            dfs(v, u);
            if(bs[u].size() > bs[v].size())merge(u, v);
            else merge(v, u), swap(bs[v], bs[u]), swap(s[v], s[u]), swap(ce[v], ce[u]);
        }
    }
    // if(u == 3) {
    //     cout << "///" << s[u].size() << ' ' << ce[u] << endl;
    // }
    ans[u] = (int)s[u].size() / 2 + ce[u];
}

void solve() {
    scanf("%d", &n);
    fs(i, 1, n)scanf("%d", &a[i]);
    fs(i, 1, n)scanf("%d", &b[i]);
    fs(i, 1, n) {
        if(a[i] != b[i]) {
            ++idx;
            bs[i].insert(mpi(a[i], idx));
            bcj[idx] = idx;deg[idx] = 2;
            ++idx;
            bs[i].insert(mpi(b[i], idx));
            bcj[idx] = idx - 1;
            s[i].insert(a[i]), s[i].insert(b[i]);
        }
        else {
            ++idx;
            bs[i].insert(mpi(a[i], idx));
            bcj[idx] = idx;
            ce[i] = 1;
        }
    }
    // fs(i, 1, idx)bcj[i] = i;
    fs(i, 1, n - 1) {
        int x, y;scanf("%d%d", &x, &y);
        G[x].emplace_back(y);G[y].emplace_back(x);
    }
    // cout << "HHH" << endl;
    dfs(1, 0);
    fs(i, 1, n)printf("%d ", ans[i]);
}

signed main() {
    int T = 1;
    while(T--) {
        solve();
    }
}