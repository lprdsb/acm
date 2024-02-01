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

#define maxn 200000
int T, n, q, a[maxn + 5], bas = 500;
LL sum[2 * maxn + 5][2];

LL as[maxn + 5];
struct Node {
    int s, k, id;
};
vector<Node> vec[maxn + 5];
int vis[maxn + 5];
vector<int> vd;

void mian() {
    read(n); read(q);
    For(i, 1, n) read(a[i]);
    For(i, 1, q) {
        int s, d, k; read(s); read(d); read(k);
        vec[d].pb({ s, k, i });
        vd.pb(d);
    }
    for(auto i : vd) if(!vis[i]) {
        vis[i] = 1;
        if(i <= bas) {
            Rof(j, n, 1) {
                sum[j][0] = sum[j + i][0] + a[j];
                sum[j][1] = sum[j + i][1] + sum[j][0];
            }
            for(auto [s, k, id] : vec[i]) as[id] = sum[s][1] - sum[s + k * i][1] - 1ll * sum[s + k * i][0] * k;
        }
        else {
            for(auto [s, k, id] : vec[i]) {
                as[id] = 0;
                For(j, 1, k) as[id] += 1ll * j * a[s + (j - 1) * i];
            }
        }
        vec[i].resize(0);
    }
    For(i, 1, q) printf("%lld ", as[i]);
    puts("");
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
        For(i, 1, n) For(o, 0, 1) sum[i][o] = 0;
        for(auto i : vd) vis[i] = 0;
        vd.resize(0);
    }
}
