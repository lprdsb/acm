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

int d, l;
char a1, b1, a2, b2;
DD pi = acos(-1.0);

int sol(int d, int l) {
    DD tem = -2.0 / 3 * pi + (DD)d / 180 * pi;
    DD x = l * cos(tem), y = -l * sin(tem);
    DD h = sqrt(3) / 2;
    int cy = 0, cx = 0;
    DD s = y / sqrt(3);
    while(y > h) y -= h, cy++;
    DD w = y / sqrt(3) * 2;
    x += s;
    while(x > 1) {
        cx += 2;
        x -= 1;
    }
    if(x > w) cx++;
    if(cy % 2 == 0) {
        if(cx % 4 == 0) return 3;
        if(cx % 4 == 1) return 1;
        if(cx % 4 == 2) return 0;
        if(cx % 4 == 3) return 2;
    }
    else {
        if(cx % 4 == 0) return 2;
        if(cx % 4 == 1) return 0;
        if(cx % 4 == 2) return 1;
        if(cx % 4 == 3) return 3;
    }
    return -1;
}

int sol1(char c, int x) {
    if(x == 0) return 0;
    if(c == 'B') return x;
    if(c == 'C') {
        if(x == 1) return 2;
        if(x == 2) return 3;
        if(x == 3) return 1;
    }
    if(c == 'D') {
        if(x == 1) return 3;
        if(x == 2) return 1;
        if(x == 3) return 2;
    }
    return -1;
}

int main() {
    // freopen("in.txt", "r", stdin);
    cin >> a1 >> b1 >> d >> l;
    int res1 = sol1(a1, sol(d, l));
    cin >> a2 >> b2 >> d >> l;
    int res2 = sol1(a2, sol(d, l));
    // cout << res1 << " " << res2 << endl;
    if(res1 == res2) puts("YES");
    else puts("NO");
}
