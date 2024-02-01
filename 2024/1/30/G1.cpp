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

#define maxn 100
int n, st[maxn + 5][maxn + 5], top[maxn + 5];
vector<int> a;

int main() {
    //freopen("in", "r", stdin);
    read(n);
    LL res = 0, sum = 0;
    For(i, 1, n) {
        read(top[i]);
        For(j, 1, top[i]) read(st[i][j]), sum += st[i][j];
        For(j, 1, top[i] >> 1) res += st[i][j];
        if(top[i] & 1) a.pb(st[i][(1 + top[i]) >> 1]);
    }
    int o = 1;
    if(a.size()) {
        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());
        for(auto j : a) {
            if(o) res += j;
            o ^= 1;
        }
    }
    printf("%lld %lld\n", res, sum - res);
}
