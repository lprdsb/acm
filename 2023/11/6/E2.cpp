#include <bits/stdc++.h>
 
typedef long long ll;
#define pb push_back
 
using namespace std;
 
const int M = 998244353;
const int N = 500500;
vector<pair<int, int>> g[N];
set<int> bridgesV[N];
bitset<N> used;
int h[N], d[N];
ll bridges = 0;
ll solo = 0;
 
int binpow(ll a, ll x) {
  ll ans = 1;
  while (x) {
    if (x % 2) {
      ans *= a;
      ans %= M;
    }
    a *= a;
    a %= M;
    x /= 2;
  }
  return (int) ans;
}
 
void dfs(int v, int p = -1) {
  if (p != -1) {
    d[v] = h[p] + 1;
    h[v] = h[p] + 1;
  }
  used[v] = true;
  for (auto &[u, w] : g[v]) {
    if (u == p) continue;
    if (!used[u]) {
      dfs(u, v);
      d[v] = min(d[v], d[u]);
      if (h[v] < d[u]) {
        bridgesV[v].insert(u);
        bridgesV[u].insert(v);
        bridges += w + 1;
        solo += w;
      }
    } else {
      d[v] = min(d[v], h[u]);
    }
  }
}
 
int calc_dp(ll n) {
  n %= (M - 1);
  if (n == 1) return 3;
  if (n == 2) return 0;
  int val = binpow(2, n);
  if (n % 2 == 1) {
    val += M - 2;
  } else {
    val += 2;
  }
  val %= M;
  return val;
}
 
signed main() {
	freopen("in.txt", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    a--;
    b--;
    g[a].pb({b, w});
    g[b].pb({a, w});
  }
  if (n % 2 != m % 2) {
    cout << "0\n";
    return 0;
  }
  dfs(0);
  used.reset();
 
  ll ans = 1;
  for (int v = 0; v < n; v++) {
    if (!used[v]) {
      ll cs = 0;
      vector<int> q = {v};
      used[v] = true;
      while (!q.empty()) {
        int u = q.back();
        q.pop_back();
        for (auto &[uu, w] : g[u]) {
          if (bridgesV[u].find(uu) != bridgesV[u].end()) continue;
          cs += w + 1;
          if (!used[uu]) {
            used[uu] = true;
            q.pb(uu);
          }
        }
      }
      cs /= 2;
      cs = max(cs, 1LL);
      ans *= calc_dp(cs);
      ans %= M;
    }
  }
  ans *= binpow(3, solo);
  ans %= M;
  int w = (2 * binpow(3, M - 2)) % M;
  ans *= binpow(w, bridges);
  ans %= M;
  int cycles = (m + 1) - n;
  ans *= binpow(2, cycles);
  ans %= M;
  cout << ans << '\n';
}