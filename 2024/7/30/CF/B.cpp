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
int T, n, a[2][maxn + 5];

void mian() {
    read(n);
    For(i, 0, 1) For(j, 1, n) {
        char c; cin >> c;
        if(c == '.') a[i][j] = 1;
        else a[i][j] = 0;
    }
    int cnt = 0;
    For(i, 3, n) {
        if(a[0][i - 2] && !a[1][i - 2] && a[0][i - 1] && a[1][i - 1] && a[0][i] && !a[1][i]) cnt++;
        if(a[1][i - 2] && !a[0][i - 2] && a[1][i - 1] && a[0][i - 1] && a[1][i] && !a[0][i]) cnt++;
    }
    cout << cnt << endl;
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
