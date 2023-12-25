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

#define maxn 200000
mt19937_64 engine(time(0));
int T, n, c[2 * maxn + 5], sum[2 * maxn + 5];
#define u64 unsigned long long
u64 w[maxn + 5];

template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

#define mod 998244353

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        read(n);
        For(i, 1, n) w[i] = engine();
        u64 now = 0;
        map<u64, int> ma;
        ma[now] = 0;
        vector<pair<int, int> > vec;
        For(i, 1, 2 * n) {
            read(c[i]);
            now ^= w[c[i]];
            if(ma.find(now) != ma.end()) {
                if(!now) vec.pb({ ma[now] + 1, i });
                else sum[ma[now] + 1]++, sum[i + 1]--;
            }
            ma[now] = i;
        }
        printf("%d ", vec.size());
        int res = 1;
        For(i, 1, 2 * n) sum[i] += sum[i - 1];
        for(auto [l, r] : vec) {
            int cnt = 0;
            For(i, l, r) cnt += !sum[i];
            res = 1ll * res * cnt % mod;
        }
        printf("%d\n", res);
        For(i, 0, 2 * n + 1) sum[i] = 0;
    }
}
