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

LL l, r;

template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

int num[10] = { 6,2,5,5,4,5,6,3,7,6 };
int get_val(LL x) {
    int res = 0;
    while(x) res += num[x % 10], x /= 10;
    return res;
}

int main() {
    //freopen("in", "r", stdin);
    read(l); read(r);
    For(i, l, min(l + 10, r - 1)) if(get_val(i) == get_val(i + 1)) {
        printf("2\n");
        return 0;
    }
    printf("1\n");
    return 0;
}
