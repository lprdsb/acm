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

int n, m, mn[2] = { inf, inf }, mx[2] = { 0, 0 };
char ma[55][55];

int main() {
    //freopen("in", "r", stdin);
    read(n); read(m);
    For(i, 1, n) For(j, 1, m) {
        cin >> ma[i][j];
        if(ma[i][j] == '*') {
            mn[0] = min(mn[0], i);
            mn[1] = min(mn[1], j);
            mx[0] = max(mx[0], i);
            mx[1] = max(mx[1], j);
        }
    }
    For(i, mn[0], mx[0]) {
        For(j, mn[1], mx[1]) printf("%c", ma[i][j]);
        puts("");
    }
}
