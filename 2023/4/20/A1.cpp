#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <random>
#include <bitset>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <chrono>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template <class T>
istream& operator>>(istream& is, vector<T>& v) {
  for (T& x : v)
    is >> x;
  return is;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  if (!v.empty()) {
    os << v.front();
    for (int i = 1; i < v.size(); ++i)
      os << ' ' << v[i];
  }
  return os;
}

const int N = 50010;

struct Point {
  int x, y, h;

  bool operator<(const Point &rhs) const {
    return x < rhs.x;
  }
};

template <typename Z, typename Y>
struct ZFrac {
  Z a, b;

  ZFrac(Z a = 0, Z b = 1) : a(a), b(b) {}

  bool operator==(const ZFrac& rhs) const { return a * (Y)rhs.b == b * (Y)rhs.a; }
  bool operator<(const ZFrac& rhs) const { return a * (Y)rhs.b < b * (Y)rhs.a; }

  bool operator>(const ZFrac &rhs) const {
    return rhs < *this;
  }
  bool operator<=(const ZFrac &rhs) const {
    return !(rhs < *this);
  }
  bool operator>=(const ZFrac &rhs) const {
    return !(*this < rhs);
  }
};

using Frac = ZFrac<ll, __int128>;

int n, m;
int a[N], b[N], c[N];
Frac k[N], srtk[N];
Frac globalTime;
Point p[N];
int x[N], y[N], h[N], kind[N];
ll ans[N], hsum[N];
pair<Frac, int> insEvent[N];

bool globalCmp(int i, int j) {
  return a[i] * (ll)b[j] * (__int128)globalTime.a + c[i] * (ll)b[j] * (__int128)globalTime.b
       < a[j] * (ll)b[i] * (__int128)globalTime.a + c[j] * (ll)b[i] * (__int128)globalTime.b;
}

Frac inter(int i, int j) {
  return Frac(c[j] * (ll)b[i] - c[i] * (ll)b[j], a[i] * (ll)b[j] - a[j] * (ll)b[i]);
}

struct ScanlineGroup {
  int tot;
  int id[N];
  ll tag[N];

  void add(int i) {
    ++tot;
    id[tot] = i;
  }

  void solve(int l, int r) {
    priority_queue<pair<Frac, int>, vector<pair<Frac, int>>, greater<pair<Frac, int>>> events(insEvent + 1, insEvent + n + 1), lazyErase;
    globalTime = x[1];
    sort(id + l, id + r + 1, globalCmp);
    int rest = n;
    for (int i = l; i < r; ++i)
      if (kind[id[i]] > kind[id[i + 1]])
        events.emplace(inter(id[i], id[i + 1]), i);
    function<pair<Frac, int>()> getNextEvent = [&] {
      while (!lazyErase.empty() && lazyErase.top() == events.top()) {
        lazyErase.pop();
        events.pop();
      }
      return events.top();
    };
    while (rest) {
      int i;
      tie(globalTime, i) = getNextEvent(); events.pop();
      if (i < 0) {
        --rest;
        i = -i;
        c[m + 1] = y[i];
        tag[upper_bound(id + l, id + r + 1, m + 1, globalCmp) - id] += h[i];
      } else {
        if (i > l && kind[id[i - 1]] > kind[id[i]])
          lazyErase.emplace(inter(id[i - 1], id[i]), i - 1);
        if (i + 1 < r && kind[id[i + 1]] > kind[id[i + 2]])
          lazyErase.emplace(inter(id[i + 1], id[i + 2]), i + 1);
        tag[i] += tag[i + 1];
        ans[id[i]] -= tag[i + 1];
        tag[i + 1] = 0;
        swap(id[i], id[i + 1]);
        if (i > l && kind[id[i - 1]] > kind[id[i]])
          events.emplace(inter(id[i - 1], id[i]), i - 1);
        if (i + 1 < r && kind[id[i + 1]] > kind[id[i + 2]])
          events.emplace(inter(id[i + 1], id[i + 2]), i + 1);
      }
    }
    for (int i = l + 1; i <= r; ++i) tag[i] += tag[i - 1];
    for (int i = l; i <= r; ++i)
      ans[id[i]] += tag[i];
    tag[r + 1] = 0;
  }

  void solve() {
    int b = sqrt(n);
    for (int i = 1; i <= tot; i += b)
      solve(i, min(i + b - 1, tot));
  }
} pos, neg;

int ffrac(int a, int b) {
  if (a >= b) return a / b;
  else return (a - b + 1) / b;
}

int main() {
  freopen("in.txt", "r", stdin);
  int nol_cl = clock();
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  for (int i = 1; i <= n; ++i)
    cin >> p[i].x >> p[i].y >> p[i].h;
  for (int i = 1; i <= m; ++i)
    cin >> a[i] >> b[i] >> c[i];
  b[m + 1] = 1;
  sort(p + 1, p + n + 1);
  for (int i = 1; i <= n; ++i) {
    x[i] = p[i].x;
    y[i] = p[i].y;
    h[i] = p[i].h;
    insEvent[i] = make_pair(Frac(x[i]), -i);
  }
  for (int i = 1; i <= n; ++i)
    hsum[i] = hsum[i - 1] + h[i];
  for (int i = 1; i <= m; ++i) {
    if (b[i] > 0) {
      a[i] = -a[i];
      pos.add(i);
    } else if (b[i] < 0) {
      a[i] = -a[i];
      b[i] = -b[i];
      neg.add(i);
    } else if (a[i] > 0) {
      int ceil = ffrac(c[i] + a[i] - 1, a[i]);
      ans[i] = hsum[lower_bound(x + 1, x + n + 1, ceil) - x - 1];
    } else if (a[i] < 0) {
      int floor = ffrac(-c[i], -a[i]);
      ans[i] = hsum[n] - hsum[upper_bound(x + 1, x + n + 1, floor) - x - 1];
    } else
      ans[i] = (c[i] > 0) ? hsum[n] : 0;
  }
  int cnt = 0;
  for (int i = 1; i <= m; ++i) {
    k[i] = Frac(a[i], b[i]);
    if (b[i])
      srtk[++cnt] = k[i];
  }
  sort(srtk + 1, srtk + cnt + 1);
  for (int i = 1; i <= m; ++i)
    if (b[i])
      kind[i] = lower_bound(srtk + 1, srtk + cnt + 1, k[i]) - srtk;

  pos.solve();
  for (int i = 1; i <= n; ++i)
    y[i] = -y[i];
  neg.solve();
  for (int i = 1; i <= m; ++i)
    cout << ans[i] << '\n';

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}