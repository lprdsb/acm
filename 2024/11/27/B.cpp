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
int a[maxn + 5];

int main() {
    //freopen("in", "r", stdin);
    int n; read(n);
    int lim = n;
    vector<int> rev;
    if(rev.size() != lim) {
        rev.resize(lim);
        int k = __builtin_ctz(lim) - 1;
        For(i, 0, lim - 1) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << k);
    }
    For(i, 0, n - 1) read(a[i]);
    For(i, 0, lim - 1) if(rev[i] < i) swap(a[rev[i]], a[i]);
    For(i, 0, n - 1) printf("%d ", a[i]);
}
