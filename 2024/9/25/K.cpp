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

#define ULL unsigned LL

#define maxn 100000
int T, n, q;
ULL a[maxn + 5];
mt19937_64 rd(114514);
unordered_map<int, ULL> ma;

void mian() {
    read(n); read(q);
    For(i, 1, n) {
        int x; read(x);
        if(!ma.count(x)) ma[x] = rd();
        a[i] = a[i - 1] ^ ma[x];
    }
    while(q--) {
        int l, r; read(l); read(r);
        puts((a[r] ^ a[l - 1]) ? "YES" : "NO");
    }
    return;
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
