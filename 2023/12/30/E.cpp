#include<bits/stdc++.h>
#define For(i, a, b) for(LL i = (a), en = (b); i <= en; ++i)
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

#define ULL unsigned LL
LL n;
#define maxn 10000000
int pri[maxn + 5], cnt = 0, vis[maxn + 5];

template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

ULL miu[maxn + 5], miui[maxn + 5];
map<LL, ULL> f;
ULL get_miu(LL x) {
    if(x <= maxn) return miu[x];
    if(f.count(x)) return f[x];
    // cout << x << endl;
    ULL res = 1;
    For(i, 2, x) {
        LL now = x / i, to = x / now;
        res -= (ULL)(to - i + 1) * get_miu(now);
        i = to;
    }
    return f[x] = res;
}

map<LL, ULL> fi;
ULL get_s2(LL x) {
    return 
}
ULL get_miui(LL x) {
    if(x <= maxn) return miui[x];
    if(f.count(x)) return fi[x];
    // cout << x << endl;
    ULL res = 1;
    For(i, 2, x) {
        LL now = x / i, to = x / now;
        res -= (ULL)(to - i + 1) * get_miu(now);
        i = to;
    }
    return f[x] = res;
}

ULL get_s(LL x) {
    ULL res = 0;
    For(i, 1, x) {
        LL now = x / i, to = x / now;
        res += (ULL)(to - i + 1) * (ULL)(sqrt(now));
        i = to;
    }
    return res;
}

int main() {
    freopen("in.txt", "r", stdin);
    For(i, 2, maxn) {
        if(!vis[i]) pri[++cnt] = i, miu[i] = -1;
        for(int j = 1; j <= cnt && i * pri[j] <= maxn; ++j) {
            vis[i * pri[j]] = 1;
            if(i % pri[j] == 0) {
                miu[i * pri[j]] = 0;
                break;
            }
            else miu[i * pri[j]] = -miu[i];
        }
    }
    miu[1] = miui[1] = 1;
    For(i, 2, maxn) {
        miui[i] += miui[i - 1] + (ULL)miu[i] * i * i;
        miu[i] += miu[i - 1];
    }
    ULL res = 0, pre = 0;
    read(n);
    For(i, 1, n) {
        LL now = n / i / i;
        if(!now) break;
        LL to = sqrt(n / now);
        // cout << i << " " << to << endl;
        ULL tem = get_miu(to);
        res += (tem - pre) * get_s(now);
        pre = tem;
        i = to;
    }
    printf("%llu\n", res);
    return 0;
}
