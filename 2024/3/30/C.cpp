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
int n, x, y, a[maxn + 5];

void mian() {
    read(n); read(x); read(y);
    For(i, 0, x - 1) read(a[i]);
    sort(a, a + x);
    For(i, 1, x - 1) a[i] -= a[0];
    a[0] = 0;
    LL sum = 0, res = x - 2;
    vector<int> cnt[2];
    For(i, 0, x - 1) {
        int len = (a[(i + 1) % x] - a[i] + n) % n;
        if(len == 1);
        if(len == 2) res++;
        else cnt[len % 2].pb(len);
    }
    sort(cnt[0].begin(), cnt[0].end());
    for(auto i : cnt[0]) {
        int tem = i / 2 - 1;
        if(y >= tem) {
            res += i / 2 + tem;
            y -= tem;
        }
        else {
            res += 2 * y;
            y = 0;
            break;
        }
    }
    for(auto i : cnt[1]) {
        int tem = i / 2;
        if(y >= tem) {
            res += 2 * tem;
            y -= tem;
        }
        else {
            res += 2 * y;
            y = 0;
            break;
        }
    }
    printf("%lld\n", res);
}

int main() {
    // freopen("in.txt", "r", stdin);
    int T; read(T);
    while(T--) {
        mian();
    }
}
