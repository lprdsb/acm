#include<bits/stdc++.h>
#define For(i, a, b) for(LL i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(LL i = (a), en = (b); i >= en; --i)
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
int T, sum[maxn + 5];
LL n;

int S(LL x) {
    return sum[x % 1000000] + sum[x / 1000000];
}
map<LL, int> ma;

void mian() {
    n = 1000000000000ll;
    // read(n);
    int sq = sqrt(n) + 2, res = 0;
    For(i, 1, sq) {
        int tem = n % i;
        LL tt = n / i;
        if(S(i) == tem && !ma.count(i)) res++, ma[i] = 1;
        // if(!ma.count(i)) res += S(i) == tem, ma[i] = 1;
        while(tem <= 108 && tem < n) {
            if(S(tt) == (n % tt) && (tt > 1000000 || !ma.count(tt))) res++, ma[tt] = 1;
            tem += i;
            tt--;
        }
    }
    for(auto [c, d] : ma)cout << "//" << c << ' ' << (n % c == S(c)) << ' ' << d << endl;
    // printf("%d\n", res);
}

int main() {
    // freopen("in.txt", "r", stdin);
    For(i, 1, maxn) sum[i] = sum[i / 10] + i % 10;
    read(T);
    while(T--) {
        mian();
        ma.clear();
    }
}
