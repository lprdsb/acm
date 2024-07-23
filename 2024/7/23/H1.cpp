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

#define maxn 4000000
int n, m, k, mx[2005][2005][2];
int sum[2005][2005][2], sum1[2005][2005][2];
struct Node {
    int x[2], y[2];
} node[maxn + 5];

int main() {
    // freopen("in.txt", "r", stdin);
    read(n); read(m); read(k);
    For(i, 1, k) {
        For(o, 0, 1) read(node[i].x[o]), read(node[i].y[o]);
    }
    For(i, 1, k) {
        sum[node[i].x[0]][node[i].y[0]][0]++;
        sum[node[i].x[1] + 1][node[i].y[0]][0]--;
        sum1[node[i].x[0]][node[i].y[1]][0]++;
        sum1[node[i].x[1] + 1][node[i].y[1]][0]--;

        sum[node[i].x[0]][node[i].y[0]][1]++;
        sum[node[i].x[0]][node[i].y[1] + 1][1]--;
        sum1[node[i].x[1]][node[i].y[0]][1]++;
        sum1[node[i].x[1]][node[i].y[1] + 1][1]--;

    }
    // For(i, 1, n) {
    //     For(j, 1, m) cout << sum[i][j][0] << " ";
    //     cout << endl;
    // }
    For(i, 1, n) For(j, 1, m) {
        sum[i][j][0] += sum[i - 1][j][0];
        sum[i][j][1] += sum[i][j - 1][1];
        sum1[i][j][0] += sum1[i - 1][j][0];
        sum1[i][j][1] += sum1[i][j - 1][1];
    }
    Rof(i, n, 1) Rof(j, m, 1) {
        mx[i][j][0] = mx[i][j][1] = inf;
        if(i < n) mx[i][j][0] = mx[i + 1][j][0];
        if(j < m) mx[i][j][1] = mx[i][j + 1][1];
        if(sum1[i][j][1]) mx[i][j][0] = i;
        if(sum1[i][j][0]) mx[i][j][1] = j;
    }
    int res = inf;
    For(i, 1, n) For(j, 1, m) if(sum[i][j][0] && sum[i][j][1]) res = min(1ll * res, 1ll * (mx[i][j][1] - j + 1) * (mx[i][j][0] - i + 1));
    printf("%d\n", res);
}
