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
int n, pre[maxn + 5];
LL f[maxn + 5];

int main() {
    //freopen("in", "r", stdin);
    read(n);
    For(i, 1, n) {
        int x; read(x);
        For(j, i, n) if(f[j] < f[j - i] + x) {
            f[j] = f[j - i] + x;
            pre[j] = i;
        }
    }
    printf("%lld\n", f[n]);
    vector<int> vec;
    int now = n;
    while(now) {
        vec.pb(pre[now]);
        now -= pre[now];
    }
    printf("%d\n", vec.size());
    for(auto v : vec) printf("%d ", v);
}
