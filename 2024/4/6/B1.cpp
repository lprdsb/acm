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
int T, a[maxn + 5], n, k;

int sol(int x, int y) {
    swap(a[x], a[y]);
    int now = a[1] > a[2] ? 1 : 2;
    int res = now == x;
    For(i, 3, n) {
        if(a[i] > a[now]) now = i;
        res += now == x;
        // cout << i << " " << now << " " << res << endl;
    }
    swap(a[x], a[y]);
    return res;
}

void mian() {
    read(n); read(k);
    For(i, 1, n) read(a[i]);
    int res = max(sol(1, k), sol(k, k));
    // cout << res << endl;
    For(i, 1, n) if(a[i] > a[k]) {
        res = max(res, sol(i, k));
        break;
    }
    printf("%d\n", res);
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
