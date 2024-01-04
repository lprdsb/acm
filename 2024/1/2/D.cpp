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

#define maxn 1048576
int sss;
LL s[21][maxn + 5];
int s1[21][maxn + 5];
int ttt;

template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

int n, q;

int cnt = 0, cnti = 0;
using i128 = __int128_t;
LL sum1 = 0;
i128 get_cos(int pos, LL mask) {
    if(cnt == n) return ((i128)1 << pos) * n;
    if(pos >= 20) {
        cnti = n;
        return ((i128)1 << pos) * n - sum1;
    }
    pair<LL, int> tem = { s[pos + 1][mask >> (pos + 1)] ,s1[pos + 1][mask >> (pos + 1)] };
    cnti = cnt + tem.sec;
    i128 res = cnti * ((i128)1 << pos) - tem.fir;
    return res;
}

int main() {
    // cout << ((&ttt - &sss) >> 18) << endl;
    // freopen("in.txt", "r", stdin);
    read(n); read(q);
    For(i, 1, n) {
        int x; read(x); sum1 += x;
        For(o, 1, 20) if(!((x >> (o - 1)) & 1)) {
            s[o][x >> o] += x & ((1 << o) - 1);
            s1[o][x >> o]++;
        }
    }
    For(o1, 1, 20) {
        int tem = 20 - o1;
        For(o2, 0, tem - 1) For(i, 0, (1 << tem) - 1) if(i & (1 << o2)) {
            s[o1][i ^ (1 << o2)] += s[o1][i];
            s1[o1][i ^ (1 << o2)] += s1[o1][i];
        }
    }
    while(q--) {
        LL k; read(k);
        LL now = 0;
        cnt = 0;
        Rof(o, 62, 0) {
            i128 tem = get_cos(o, now);
            if(k >= tem) {
                k -= tem;
                cnt = cnti;
                now |= (1ll << o);
            }
        }
        printf("%lld\n", now);
    }
    return 0;
}
