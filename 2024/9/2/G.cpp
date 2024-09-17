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

#define maxn 1000000
int T, n, q, k, a[maxn + 5], sum[2][maxn + 5], b[2][maxn + 5], mx[maxn + 5];
pair<int, int> seg[maxn + 5];
int pos[maxn + 5];

void mian() {
    read(n); read(q); read(k);
    For(i, 1, n) read(a[i]);
    For(i, 1, n) pos[i] = i;
    sort(pos + 1, pos + n + 1, [](int x, int y) {return a[x] < a[y];});
    For(i, 1, q) read(seg[i].fir), read(seg[i].sec);
    vector<pair<int, int> > vec;
    For(i, 1, k) {
        int to = k / (k / i);
        vec.pb({ i, to });
        i = to;
    }
    reverse(vec.begin(), vec.end());
    int now[2] = { 1, n };
    for(auto [l, r] : vec) {
        while(now[0] <= n && a[pos[now[0]]] <= k / l) {
            b[0][pos[now[0]]]++;
            now[0]++;
        }
        while(now[1] && a[pos[now[1]]] >= l) {
            b[1][pos[now[1]]]++;
            now[1]--;
        }
        For(o, 0, 1) For(i, 1, n) sum[o][i] = sum[o][i - 1] + b[o][i];
        For(i, 1, q) {
            int tem = ((sum[1][seg[i].sec] - sum[1][seg[i].fir - 1]) - (sum[0][seg[i].sec] - sum[0][seg[i].fir - 1]) + 1) / 2;
            // cout << l << " " << r << " " << tem << endl;
            if((seg[i].sec - seg[i].fir + 1) % 2 == 1 && (sum[1][seg[i].sec] - sum[1][seg[i].fir - 1]) + (sum[0][seg[i].sec] - sum[0][seg[i].fir - 1]) == seg[i].sec - seg[i].fir + 1)
                tem--;
            mx[i] = max(mx[i], tem);
        }
    }
    For(i, 1, q) printf("%d ", mx[i]);
    puts("");
}

int main() {
    // freopen("in.txt", "r", stdin);
    memset(mx, 0, sizeof mx);
    read(T);
    while(T--) {
        mian();
        For(i, 1, q) mx[i] = 0;
        For(o, 0, 1) For(i, 1, n) sum[o][i] = b[o][i] = 0;
    }
}
