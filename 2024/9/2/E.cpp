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
int T, n, fa[maxn + 5], sz[maxn + 5];
vector<int> vec[maxn + 5];
LL W, val[maxn + 5][2];

void mian() {
    read(n); read(W);
    For(i, 2, n) read(fa[i]), sz[fa[i]]++;
    For(i, 1, n - 1) {
        if(sz[i] == 0) {
            int to = fa[i + 1];
            vec[i + 1].pb(i);
            int now = i;
            while(now != to) {
                vec[now].pb(i);
                now = fa[now];
            }
        }
        else vec[i + 1].pb(i);
    }
    int now = n;
    while(now != 1) vec[now].pb(n), now = fa[now];
    For(i, 2, n) for(auto u : vec[i]) val[u][1]++;
    LL sum = 0, cnt = 0;
    For(i, 1, n) cnt += val[i][1] != 0;
    For(i, 2, n) {
        int x; LL y; read(x); read(y);
        for(auto u : vec[x]) sum -= val[u][0];
        W -= y;
        for(auto u : vec[x]) {
            val[u][1]--;
            if(!val[u][1]) cnt--;
            val[u][0] += y;
            sum += val[u][0];
        }
        printf("%lld ", sum + cnt * W);
    }
    puts("");
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
        For(i, 1, n) {
            sz[i] = 0;
            vec[i].resize(0);
            val[i][0] = val[i][1] = 0;
        }
    }
}
