#include <bits/stdc++.h>
#define fp(i, a, b) for (int i = a, i##_ = b; i <= i##_; ++i)
#define fd(i, a, b) for (int i = a, i##_ = b; i >= i##_; --i)
using namespace std;
using ll = long long;
const int N = 1e3 + 5;
int n, f[N];
vector<array<int, 3>> ans;
int check(int a, int b) {
if (!b) return a <= 7;
int cnt = 1, c;
while (b) {
cnt += a / b;
c = a % b, a = b, b = c;
}
return cnt <= 25;
}
void dfs(int, int, int);
void calcC(int, int, int, int);
void calcR(int x, int y, int r, int c) { // c = a * r + b
if (r <= 1) return;
int a = c / r;
fp(i, 0, a - 1) dfs(x, y + i * r, r);
calcC(x, y + a * r, r, c % r);
}
void calcC(int x, int y, int r, int c) { // r = a * c + b
if (c <= 1) return;
int a = r / c;
fp(i, 0, a - 1) dfs(x + i * c, y, c);
calcR(x + a * c, y, r % c, c);
}
void dfs(int x, int y, int k) {
if (k == 1) return;
if(k <= 7){

    ans.push_back({x, y, k});
    return;
}
int a = f[k], b = k - f[k];
dfs(x, y, a), dfs(x + a, y + a, b);
calcR(x + a, y, b, a), calcC(x, y + a, a, b);
    ans.push_back({x, y, k});
}
void Solve() {
scanf("%d", &n);
// freopen("s.out", "w", stdout);
// printf("%d\n", n);
memset(f, -1, sizeof f);
f[1] = 0;
fp(i, 2, n) {
fp(j, 1, i / 2) {
if (check(i - j, j)) {
f[i] = j;
break;
}
}
}
dfs(1, 1, n);
printf("%llu\n", ans.size());
// reverse(ans.begin(), ans.end());
for (auto [x, y, k] : ans) printf("%d %d %d\n", x, y, k);
}
int main() {
int t = 1;
while (t--) Solve();
return 0;
}
