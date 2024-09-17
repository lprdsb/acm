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

#define mod 998244353
#define maxn 200000
struct Graph {
    LL n, m, du[maxn + 5], num[5][4 * maxn + 5]; // d1+d2-2   2d1+d2-1  d  1-1-1- 1-1-1= juhua
    pair<int, int> edge[maxn + 5];
    vector<int> ch[maxn + 5];
    map<int, map<int, int> > ma;

    LL c[4][4];
    vector<vector<pair<int, int>>> G;

    void init() {
        read(n); read(m);
        G.resize(n + 1);
        For(i, 1, m) {
            int u, v; read(u); read(v);
            edge[i] = { u, v };
            ma[u][v] = ma[v][u] = 1;
            du[u]++; du[v]++;
            ch[u].pb(v);
            ch[v].pb(u);

            G[u].push_back({ v, i });
            G[v].push_back({ u, i });

        }
        For(i, 1, m) {
            int u = edge[i].fir, v = edge[i].sec;
            num[0][du[u] + du[v] - 2]++;
            num[1][2 * du[u] + du[v] - 2]++;
            num[1][du[u] + 2 * du[v] - 2]++;
        }
        For(i, 1, n) num[2][du[i]]++;
        For(i, 1, n) {
            if(du[i] == 2) {
                int fl[2] = { 0, 0 };
                for(auto v : ch[i]) if(du[v] <= 2) fl[du[v] - 1]++;
                if(fl[0] && fl[1]) num[3][0]++;
            }
            if(du[i] == 3) {
                int cnt = 0;
                for(auto v : ch[i]) if(du[v] == 1) cnt++;
                if(cnt == 2) num[3][0]++;
                For(o1, 0, 2) For(o2, o1 + 1, 2) if(du[ch[i][o1]] == 2 && du[ch[i][o2]] == 2 && ma[ch[i][o1]][ch[i][o2]]) {
                    num[3][0]++;
                    break;
                }
            }
        }
        for(int i = 1; i <= n; i++) {
            if(du[i] < 4) c[1][du[i]]++;
        }
        for(int i = 1; i <= m; i++) {
            auto [u, v] = edge[i];
            int sum = du[u] + du[v] - 2;
            if(sum < 4) {
                c[2][sum]++;
                if(c[2][sum] >= mod) c[2][sum] -= mod;
            }
        }
        // cout << "asd" << endl;
        for(int i = 1; i <= m; i++) {
            auto [u, v] = edge[i];
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
            if(c[3][1] >= mod) c[3][1] -= mod;
        }
    }
} gra[2];

#define LLL __int128_t
#define ll LL

int main() {
    // freopen("in.txt", "r", stdin);
    // cout << "asd" << endl;
    For(o, 0, 1) gra[o].init();
    Graph G, H;
    G.n = gra[0].n;
    G.m = gra[0].m;
    H.n = gra[1].n;
    H.m = gra[1].m;

    for(int i = 1; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            G.c[i][j] = gra[0].c[i][j];
            H.c[i][j] = gra[1].c[i][j];
        }
    }
    ll allm = (G.m * H.n + G.n * H.m) % mod;
    LL tot = 1ll * gra[0].m * gra[1].n + 1ll * gra[0].n * gra[1].m;
    assert(tot % mod == allm);
    ll tallm = 1ll * G.m * H.n + 1ll * G.n * H.m;
    int N = 8;
    LLL ttem = (LLL)(tallm - 2) * (tallm - 3) / 2;
    int tt = ttem % mod;
    ll cas[10] = {
        G.c[2][1] * H.c[2][1] * 2 % mod,
        G.c[2][2] * H.c[1][1] % mod + G.c[1][1] * H.c[2][2] % mod,

        (G.c[2][1] * H.c[1][1] + G.c[1][1] * H.c[2][1]) % mod * (allm - 5 + mod) % mod,//

        G.c[1][2] * H.c[1][2] % mod,
        (G.c[1][2] * H.c[1][1] + G.c[1][1] * H.c[1][2]) % mod * (allm - 3 + mod) % mod,
        G.c[1][1] * H.c[1][1] % mod * (tt) % mod,
        G.c[3][1] * H.c[1][1] % mod + G.c[1][1] * H.c[3][1] % mod,
        G.c[1][3] * H.c[1][1] % mod + G.c[1][1] * H.c[1][3] % mod,
    };
    For(i, 1, 7) cas[i] = (cas[i - 1] + cas[i]) % mod;
    ll ans = cas[7];

    assert(gra[0].num[3][0] == G.c[3][1] && gra[1].num[3][0] == H.c[3][1]);
    assert(gra[0].num[2][1] == G.c[1][1] && gra[1].num[2][1] == H.c[1][1]);
    assert(gra[0].num[2][2] == G.c[1][2] && gra[1].num[2][2] == H.c[1][2]);
    assert(gra[0].num[2][3] == G.c[1][3] && gra[1].num[2][3] == H.c[1][3]);
    assert(gra[0].num[0][1] == G.c[2][1] && gra[1].num[0][1] == H.c[2][1]);
    assert(gra[0].num[0][2] == G.c[2][2] && gra[1].num[0][2] == H.c[2][2]);

    int res = 0;
    For(o, 0, 1) For(o1, 0, 3) For(o2, 0, 3) gra[o].num[o1][o2] %= mod;
    res = (res + 2ll * gra[0].num[0][1] * gra[1].num[0][1] % mod) % mod; //7 田
    assert(res == cas[0]);
    res = (res + 1ll * gra[0].num[0][2] * gra[1].num[2][1] % mod) % mod;
    res = (res + 1ll * gra[0].num[2][1] * gra[1].num[0][2] % mod) % mod;
    assert(res == cas[1]);
    res = (res + 1ll * gra[0].num[0][1] * gra[1].num[2][1] % mod * ((tot - 5) % mod) % mod) % mod; // :
    res = (res + 1ll * gra[0].num[2][1] * gra[1].num[0][1] % mod * ((tot - 5) % mod) % mod) % mod;
    // assert((1ll * gra[0].num[0][1] * gra[1].num[2][1] % mod * ((tot - 5) % mod) % mod + 1ll * gra[0].num[2][1] * gra[1].num[0][1] % mod * ((tot - 5) % mod) % mod) % mod == (G.c[2][1] * H.c[1][1] + G.c[1][1] * H.c[2][1]) % mod * (allm - 5 + mod) % mod);
    assert((tot - 5) % mod == (allm - 5 + mod) % mod);
    res = (res + 1ll * gra[0].num[2][2] * gra[1].num[2][2] % mod) % mod;
    assert(res == cas[3]);
    res = (res + 1ll * gra[0].num[2][2] * gra[1].num[2][1] % mod * ((tot - 3) % mod) % mod) % mod;
    res = (res + 1ll * gra[0].num[2][1] * gra[1].num[2][2] % mod * ((tot - 3) % mod) % mod) % mod;
    assert(res == cas[4]);
    res = (res + 1ll * gra[0].num[2][1] * gra[1].num[2][1] % mod * ((LLL)(tot - 2) * (tot - 3) / 2 % mod) % mod) % mod;
    assert(res == cas[5]);
    res = (res + 1ll * gra[0].num[3][0] * gra[1].num[2][1] % mod) % mod; // ...
    res = (res + 1ll * gra[0].num[2][1] * gra[1].num[3][0] % mod) % mod;
    assert(res == cas[6]);
    res = (res + 1ll * gra[0].num[2][1] * gra[1].num[2][3] % mod) % mod;
    res = (res + 1ll * gra[0].num[2][3] * gra[1].num[2][1] % mod) % mod;
    assert(res == cas[7]);
    // For(d1, 1, 4)  For(d2, 1, 4 - d1) {
    //     res = (res + 1ll * gra[0].num[2][d1] * gra[1].num[2][d2] % mod * C(tot - d1 - d2, 4 - d1 - d2) % mod) % mod;
    // }
    assert(ans == res);
    LL tem = gra[0].num[2][1] * gra[1].num[2][1];
    tem = (LLL)tem * (tem - 1) / 2 % mod;
    res = (res - tem + mod) % mod;
    // cout << tem << endl;
    printf("%d\n", res);
}
