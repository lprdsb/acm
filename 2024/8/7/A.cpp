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

#define maxn 10000
int n, m, k, a[maxn + 5];
int f[maxn + 5][25][45][2];
int sum[maxn + 5];
vector<int> vec[maxn + 5];

void chkmx(int &x, int y) { if(x < y) x = y; }

int vis[maxn + 5];
int main() {
    // freopen("in.txt", "r", stdin);
    read(n); read(k); read(m);
    For(i, 1, n) read(a[i]);
    vector<int> id;
    For(i, 1, n) id.pb(i);
    sort(id.begin(), id.end(), [](int x, int y) {return a[x] < a[y];});
    for(auto i : id) {
        int cnt = 0;
        Rof(j, i, max(1, i - k + 1)) {
            if(vec[j].size() != m) vec[j].pb(a[i]);
            if(vis[j]) {
                cnt++;
                if(cnt == m) break;
            }
        }
        vis[i] = 1;
    }
    Rof(i, n, 1) {
        sum[i] = sum[i + 1] + a[i];
        if(i + k <= n) sum[i] -= a[i + k];
    }
    memset(f, -inf, sizeof f);
    int tmp = f[0][0][0][0];
    f[0][0][m][0] = 0;
    For(i, 0, n - 1) {
        assert(vec[i + 1].size() <= m);
        For(i1, 0, m) For(i2, -m, m) For(o, 0, 1) if(f[i][i1][i2 + m][o] != tmp) {
            if(i + k <= n) {
                int now = sum[i + 1];
                For(j, 0, min(k, m)) {
                    int c = i2 < 0 ? j : max(0, j - i2);
                    if(i1 + c <= m && i2 - j >= -m) chkmx(f[i + k][i1 + c][i2 - j + m][1], f[i][i1][i2 + m][o] + now);
                    else break;
                    if(j < vec[i + 1].size()) now -= vec[i + 1][j];
                    else break;
                }
            }
            if(i % k != k - 1) {
                if(i2 < 0) chkmx(f[i + 1][i1][i2 + 1 + m][0], f[i][i1][i2 + m][o] + a[i + 1]);
                else chkmx(f[i + 1][i1 + 1][i2 + 1 + m][0], f[i][i1][i2 + m][o] + a[i + 1]);
                if(o) {
                    chkmx(f[i + 1][i1][i2 + m][1], f[i][i1][i2 + m][o] + a[i + 1]);
                    if(i2 != -m) chkmx(f[i + 1][i1 + (i2 <= 0)][i2 - 1 + m][1], f[i][i1][i2 + m][o]);
                }
                chkmx(f[i + 1][i1][i2 + m][0], f[i][i1][i2 + m][o]);
            }
        }
    }
    int res = -inf;
    For(i, 0, m) res = max(res, max(f[n][i][m][0], f[n][i][m][1]));
    printf("%d\n", res);
    return 0;
}
