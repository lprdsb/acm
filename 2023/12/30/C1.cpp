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

#define maxn 100000
int T, n;

void sol() {
    read(n);
    int cnt[2] = { 0, 0 };
    LL sum = 0;
    For(i, 1, n) {
        int x; read(x); sum += x;
        cnt[x & 1]++;
        if(i == 1) printf("%d ", x);
        else if(cnt[1] % 3 == 0) printf("%lld ", sum - cnt[1] / 3);
        else if(cnt[1] % 3 == 1) printf("%lld ", sum - cnt[1] / 3 - 1);
        else printf("%lld ", sum - cnt[1] / 3);
    }
    puts("");
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        sol();
    }
}
