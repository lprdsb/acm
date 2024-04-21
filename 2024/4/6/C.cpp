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

typedef __int128_t LLL;
int T, m;
LL n;
LLL cnt[50], len[50];
LD dcnt[50], dlen[50];

void mian() {
    read(n); read(m);
    cnt[0] = dcnt[0] = 1;
    For(i, 1, 60) cnt[i] = cnt[i - 1] * m;
    Rof(i, 20, 1) cnt[i] -= cnt[i - 1];
    For(i, 1, 20) len[i] = len[i] + cnt[i] * i;
    Rof(i, 20, 1) if()
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
