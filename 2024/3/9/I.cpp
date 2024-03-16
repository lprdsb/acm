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

int T;
LL n, k;

int chk(int a, int b) {
    LLL aa = 1, bb = 1;
    For(i, 1, k) {
        aa *= a; bb *= b;
        if(bb - aa >= n) {
            if(bb - aa == n) return i == k ? 2 : 1;
            else return 1;
        }
    }
    return 0;
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        read(n); read(k);
        int res = 0;
        For(i, 1, 1000000) if(n % i == 0) {
            int l = 1, r = 1000000000;
            while(l < r) {
                int md = l + r >> 1;
                if(chk(md, md + i)) r = md;
                else l = md + 1;
            }
            if(chk(l, l + i) == 2) res++;
        }
        printf("%d\n", res);
    }
}
