#include<bits/stdc++.h>
#define fs(i,x,y) for(int i=(x),_=(y);i<=_;++i)
#define fn(i,x,y) for(int i=(x),_=(y);i>=_;--i)
#define fi first
#define pi pair<int,ll>
#define mpi(x,y) make_pair(x,y)
#define se second
using namespace std;
typedef long long ll;

template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

const int N = 507, P = 998244353, MX = 500;
int n, m, m0, w;
vector<pi>G[N];
int dp[N][N];
int pw[N];
int cpn = 0;
int siz[N], edg[N];
ll dis[N];
bool vis[N];

ll bas[N];
void ins(ll x) {
    fn(i, w - 1, 0) {
        if((x >> i) & 1) {
            if(bas[i])x ^= bas[i];
            else {
                bas[i] = x;
                break;
            }
        }
    }
}

void dfs(int u, ll d) {
    dis[u] = d;vis[u] = true;++siz[cpn];
    for(auto [v, val] : G[u]) {
        ++edg[cpn];
        if(!vis[v]) {
            dfs(v, d ^ val);
        }
        else {
            ins(d ^ dis[v] ^ val);
        }
    }
}

//边权到ll 注意爆ll

int qw(int a, int b) {
    int ans = 1;for(;b;a = (ll)a * a % P, b >>= 1)if(b & 1)ans = (ll)ans * a % P;
    return ans;
}

void pre() {
    pw[0] = 1;
    fs(i, 1, MX)pw[i] = (ll)pw[i - 1] * 2 % P;
}

#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
int num[40], stk[40], tp = 0;
#define LL long long
LL mask[2005], cnt_mask = 0, tra[2005][2005];

map<LL, int> ma;
void Dfs(int pos, LL sum) {
    if(pos == tp + 1) {
        mask[++cnt_mask] = sum;
        ma[sum] = cnt_mask;
        return;
    }
    For(i, 0, num[pos]) Dfs(pos + 1, sum * 33 + i);
}
int c[35][35];

int get_c(LL mask1, LL mask2) {
    int res = 1;
    while(mask1 || mask2) {
        res = 1ll * res * c[mask1 % 33][mask2 % 33] % P;
        mask1 /= 33; mask2 /= 33;
    }
    return res;
}


int f[2005][905][35];
void solve() {
    pre();
    scanf("%d%d%d%d", &n, &m, &m0, &w);
    fs(i, 1, m0) {
        int x, y, z;scanf("%d%d%d", &x, &y, &z);
        G[x].emplace_back(mpi(y, z));
        G[y].emplace_back(mpi(x, z));
    }
    fs(i, 1, n) {
        if(!vis[i]) {
            ++cpn;
            dfs(i, 0);
            edg[cpn] /= 2;
            edg[cpn] = (siz[cpn] - 1) * siz[cpn] / 2 - edg[cpn];
        }
    }
    // dp!!!!!个数
    int dim = 0;
    fn(i, w - 1, 0)if(bas[i])++dim;
    int cnt = m - m0 - (cpn - 1);
    dp[0][dim] = 1;
    fs(i, 1, cnt) {
        fs(j, dim, w) {
            dp[i][j] = (dp[i][j] + (ll)dp[i - 1][j] * pw[j]) % P;
            if(j)dp[i][j] = (dp[i][j] + (ll)dp[i - 1][j - 1] * ((pw[w] - pw[j - 1] + P) % P)) % P;
        }
    }
    int ans = (ll)qw(pw[w], cpn - 1) * dp[cnt][w] % P;
    cout << ans << endl;

    For(i, 1, cpn) num[siz[cpn]]++;
    For(i, 1, 32) if(num[i]) stk[++tp] = num[i];
    Dfs(1, 0);
    For(i, 1, cnt_mask) For(j, 1, cnt_mask) tra[i][j] = get_c(mask[i], mask[j]);
    LL tem = 1;
    For(i, 1, tp) {
        f[ma[tem]][0][1] = 1;
        tem *= 33;
    }
    // for(auto [k, v] : ma) For(i, 0, 900) For()
}

int main() {
    c[0][0] = 1;
    For(i, 1, 32) {
        c[i][0] = 1;
        For(j, 1, i) c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % P;
    }
    //freopen("in", "r", stdin);
    solve();
}
