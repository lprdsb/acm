#include<bits/stdc++.h>
#define fs(i,x,y) for(int i=(x),_=(y);i<=_;++i)
#define fn(i,x,y) for(int i=(x),_=(y);i>=_;--i)
#define pi pair<int,int>
#define mpi(x,y) make_pair(x,y)
typedef long long ll;
using namespace std;

const int N = 1e6 + 7;

int n;
int bcj[N];
int deg[N];

struct TREE {
    vector<int>G[N];
    void clr() {
        fs(i, 1, n)G[i].clear();
    }
    void adde(int x, int y) {
        G[x].emplace_back(y);
        G[y].emplace_back(x);
    }
}W, Y;
map<pi, bool>X;

//多测清空

int fd(int x) {
    return x ^ bcj[x] ? bcj[x] = fd(bcj[x]) : x;
}

void mer(int x, int y) {
    int fx = fd(x), fy = fd(y);
    bcj[fx] = fy;
}

bool chk(int x, int y) {
    int fx = fd(x), fy = fd(y);
    return fx == fy;
}

void solve() {
    X.clear();Y.clr();W.clr();
    scanf("%d", &n);
    fs(i, 1, n)deg[i] = 0;
    fs(i, 2, n) {
        int x;scanf("%d", &x);
        W.adde(i, x);
        X[mpi(i, x)] = X[mpi(x, i)] = true;
        // X.adde(i, x);
    }
    fs(i, 2, n) {
        int x;scanf("%d", &x);
        Y.adde(i, x);
        ++deg[i], ++deg[x];
    }
    fs(i, 1, n)bcj[i] = i;
    queue<pi>q;
    fs(i, 1, n)if(deg[i] == 1) {
        // q.push(mpi(i, Y.G[i][0]));
        if(X[mpi(i, Y.G[i][0])] || X[mpi(Y.G[i][0], i)])q.push(mpi(i, Y.G[i][0]));
    }
    int lst = 0;
    while(q.size()) {
        auto [u, v] = q.front();q.pop();
        mer(u, v);
        --deg[v];
        lst = v;
        if(deg[v] == 1) {
            for(int ot : Y.G[v]) {
                if(!chk(ot, v)) {
                    for(int to : W.G[ot]) {
                        if(chk(to, v)) {
                            q.push(mpi(v, ot));break;
                        }
                    }
                }
            }
        }
        // if(X[mpi(u, v)] || X[mpi(v, u)]) {

        // }
    }
    bool ok = true;
    fs(i, 1, n - 1)if(!chk(i, i + 1))ok = false;
    if(ok) {
        printf("%d\n", lst);
    }
    else printf("-1\n");
}

signed main() {
    int T;scanf("%d", &T);
    while(T--) {
        solve();
    }
}