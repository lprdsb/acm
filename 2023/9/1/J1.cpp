#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 405;

int n, c[N], to[N];
ll f[N][N], X, Y, aux[N];

int main() {
    cout << "asd" << endl;
    freopen("in.txt", "r", stdin);
  cin >> n >> X >> Y;
  for (int i = 1; i <= n; ++i) cin >> c[i];
  for (int i = n; i >= 1; --i) to[i] = i < n and c[i + 1] == c[i] ? to[i + 1] : i;
  for (int l = n; l >= 1; --l) {
    for (int r = l; r <= n; ++r) {
      aux[r] = 0, f[l][r] = f[to[l] + 1][r] + X;
      if (l == r) continue;
      for (int i = l; i < r; ++i) f[l][r] = min(f[l][r], f[l][i] + f[i + 1][r]);
      for (int i = l + 1; i <= r; ++i) if (c[i] == c[l]) f[l][r] = min(f[l][r], Y + f[l + 1][i - 1] + Y + f[i][r]);
      if (c[l] == c[r]) {
        aux[r] = f[l + 1][r - 1] + Y;
        for (int i = l; i < r; ++i) if (c[i] == c[r]) aux[r] = min(aux[r], aux[i] + f[i + 1][r - 1] + Y);
        f[l][r] = min(f[l][r], Y + aux[r] + X);
      }
    }
  }
  cout << f[1][n] << '\n';
  return 0;
}

