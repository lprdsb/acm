#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int P = 998244353, iv2 = (P + 1) / 2;

struct Graph {
    ll n, m, c[4][4];
    vector<vector<pair<int, int>>> G;
    vector<pair<int, int>> edges;
    vector<int> du;
    Graph() {
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
                c[i][j] = 0;
        cin >> n >> m;
        G.resize(n + 1);
        du.resize(n + 1);
        edges.resize(m + 1);
        for(int i = 1; i <= m; i++) {
            int u, v;
            cin >> u >> v;
            edges[i] = { u, v };
            G[u].push_back({ v, i });
            G[v].push_back({ u, i });
            du[u]++, du[v]++;
        }
        for(int i = 1; i <= n; i++) {
            if(du[i] < 4) c[1][du[i]]++;
        }
        for(int i = 1; i <= m; i++) {
            auto [u, v] = edges[i];
            int sum = du[u] + du[v] - 2;
            if(sum < 4) {
                c[2][sum]++;
                if(c[2][sum] >= P) c[2][sum] -= P;
            }
        }
        // cerr << "ok\n";
        for(int i = 1; i <= m; i++) {
            auto [u, v] = edges[i];
            auto find3 = [&](int x, int fe) {
                vector<int> ve; ve.push_back(x);
                set<int> st; st.insert(x);
                int i = 0;
                while(i < 4 && i < ve.size()) {
                    int x = ve[i]; i++;
                    for(auto [y, ei] : G[x]) if(ei != fe) {
                        if(st.find(y) == st.end()) {
                            ve.push_back(y), st.insert(y);
                            if(ve.size() > 3) return false;
                        }
                    }
                }
                return ve.size() == 3;
                };
            if(find3(u, i)) c[3][1]++;
            if(find3(v, i)) c[3][1]++;
            if(c[3][1] >= P) c[3][1] -= P;
        }
    }
    void print() {
        for(int i = 1; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                cout << c[i][j] << " \n"[j == 3];
            }
        }
    }
};

signed main() {
    freopen("in.txt", "r", stdin);
    Graph G, H;
    // G.print(), H.print();
    ll allm = (G.m * H.n + G.n * H.m) % P;
    int N = 8;
    ll cas[] = {
        G.c[2][1] * H.c[2][1] * 2 % P,
        G.c[2][2] * H.c[1][1] % P + G.c[1][1] * H.c[2][2] % P,

        (G.c[2][1] * H.c[1][1] + G.c[1][1] * H.c[2][1]) % P * (allm - 5) % P,//

        G.c[1][2] * H.c[1][2] % P,

        (G.c[1][2] * H.c[1][1] + G.c[1][1] * H.c[1][2]) % P * (allm - 3) % P,

        G.c[1][1] * H.c[1][1] % P * (((allm - 2) * (allm - 3) / 2) % P) % P,

        G.c[3][1] * H.c[1][1] % P + G.c[1][1] * H.c[3][1] % P,
        G.c[1][3] * H.c[1][1] % P + G.c[1][1] * H.c[1][3] % P,
    };
    ll ans = accumulate(cas, cas + N, 0ll);
    ll dec = G.c[1][1] * H.c[1][1] % P;
    dec = dec * (dec - 1) % P * iv2 % P;
    ans -= dec;
    // for(int i = 0; i < N; i++) {
    //     cout << cas[i] << '\n';
    // }
    cout << dec << '\n';
    cout << (ans % P + P) % P << '\n';
    return 0;
}