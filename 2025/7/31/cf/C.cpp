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

int chk(int len, int sta) {
    int now = 0;
    For(i, 0, len - 1) {
        now += ((sta >> i) & 1) ? 1 : -1;
        if(now < 0) return 0;
    }
    return now == 0;
}

int main() {
    //freopen("in", "r", stdin);
    int n = 5;
    map<int, map<int, int> > ma;
    For(i, 0, (1 << n) - 1) {
        int cnt1 = 0, cnt2 = 0;
        int tmp = (i << 1);
        For(l, 1, n + 1) For(r, l + 1, n + 1) cnt1 += chk(r - l + 2, i >> (l - 1));
        tmp = i | (1 << n);
        For(l, 1, n + 1) For(r, l + 1, n + 1) cnt2 += chk(r - l + 2, i >> (l - 1));
        ma[cnt1][cnt2]++;
    }
    for(auto [k, ma2] : ma) for(auto [k2, v] : ma2)cout << k << " " << k2 << " " << v << endl;
}
