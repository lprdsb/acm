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
    int n, m, du[maxn + 5], num[15][4 * maxn + 5]; // d1+d2-2   2d1+d2-1  d  1-1-1- 1-1-1= juhua
    pair<int, int> edge[maxn + 5];
    vector<int> ch[maxn + 5];
    map<int, map<int, int> > ma;
    void init() {
        read(n); read(m);
        For(i, 1, m) {
            int u, v; read(u); read(v);
            edge[i] = { u, v };
            ma[u][v] = ma[v][u] = 1;
            du[u]++; du[v]++;
            ch[u].pb(v);
            ch[v].pb(u);
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
    }
} gra[2];

#define LLL __int128_t
LL C(LL x, LL y) {
    assert(y >= 0 && x >= y);
    LLL res = 1;
    For(i, 1, y) res *= (x - i + 1);
    For(i, 1, y) res /= i;
    return res % mod;
}


int main() {
    // freopen("in.txt", "r", stdin);
    For(o, 0, 1) gra[o].init();
    LL tot = 1ll * gra[0].m * gra[1].n + 1ll * gra[0].n * gra[1].m;
    int res = 0;
    res = (res + 1ll * gra[0].num[3][0] * gra[1].num[2][1] % mod) % mod; // ...
    res = (res + 1ll * gra[0].num[2][1] * gra[1].num[3][0] % mod) % mod;

    res = (res + 1ll * gra[0].num[0][1] * gra[1].num[2][1] % mod * ((tot - 5) % mod) % mod) % mod; // :
    res = (res + 1ll * gra[0].num[2][1] * gra[1].num[0][1] % mod * ((tot - 5) % mod) % mod) % mod;

    res = (res + 1ll * gra[0].num[0][2] * gra[1].num[2][1] % mod) % mod;
    res = (res + 1ll * gra[0].num[2][1] * gra[1].num[0][2] % mod) % mod;

    res = (res + 2ll * gra[0].num[0][1] * gra[1].num[0][1] % mod) % mod; //7 田


    For(d1, 1, 4)  For(d2, 1, 4 - d1) {
        res = (res + 1ll * gra[0].num[2][d1] * gra[1].num[2][d2] % mod * C(tot - d1 - d2, 4 - d1 - d2) % mod) % mod;
    }
    LL tem = 1ll * gra[0].num[2][1] * gra[1].num[2][1];
    tem = (LLL)tem * (tem - 1) / 2 % mod;
    res = (res - tem + mod) % mod;
    // cout << tem << endl;
    printf("%d\n", res);
}