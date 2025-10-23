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

int n, q;

template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

#define maxn 2000000
int dir[4][2] = { {0, 1} ,{0, -1}, {1, 0}, {-1, 0} };
int qq[maxn + 5][2];

int main() {
    //freopen("in", "r", stdin);
    read(n); read(q);
    For(i, 1, n) qq[i][0] = n - i + 1, qq[i][1] = 0;
    int l = 1, r = n;
    while(q--) {
        int op; read(op);
        if(op == 1) {
            char c; cin >> c;
            int nx = qq[r][0], ny = qq[r][1];
            int o = 0;
            if(c == 'R') o = 2;
            if(c == 'L') o = 3;
            if(c == 'U') o = 0;
            if(c == 'D') o = 1;
            nx += dir[o][0]; ny += dir[o][1];
            r++;
            qq[r][0] = nx; qq[r][1] = ny;
            l++;
        }
        else {
            int x; read(x);
            cout << qq[r - x + 1][0] << " " << qq[r - x + 1][1] << endl;
        }
    }
}
