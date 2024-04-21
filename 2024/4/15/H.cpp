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

int T, k, n, a[1 << 21], sum[1 << 21];

int dfs(int l, int r, int len) {
    if(r - l + 1 == len) return sum[r] - sum[l - 1] == 0;
    int md = l + r >> 1, res = dfs(l, md, len) + dfs(md + 1, r, len);
    if(res && sum[r] - sum[l - 1] - ((r - l + 1) / len) + res >= 1) res--;
    // if(l == 1 && r == 4) cout << sum[r] - sum[l - 1] - ((r - l + 1) / len) - res << endl;
    return res;
}

bool chk(int x, int len) {
    For(i, 1, n) sum[i] = (a[i] >= x) + sum[i - 1];
    return dfs(1, n, len) == 0;
}

void mian() {
    read(k); n = 1 << k;
    For(i, 1, n) read(a[i]);
    // cout << chk(3, 2) << endl;
    Rof(o, k - 1, 0) {
        int l = 1, r = n + 1;
        while(l < r) {
            int md = l + r >> 1;
            if(!chk(md, 1 << o)) r = md;
            else l = md + 1;
        }
        printf("%d ", l - 1);
    }
    puts("");
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
