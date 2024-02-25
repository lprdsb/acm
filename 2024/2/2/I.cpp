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

int n = 100000;

using rd = mt19937_64;

rd rd1(time(0));

int main() {
    freopen("in.txt", "w", stdout);
    cout << n << endl;
    LL sum = 0;
    For(i, 1, n) {
        int x, y, r;
        while(666) {
            x = rd1() % 199 - 99, y = rd1() % 199 - 99, r = rd1() % 100 + 1;
            int rr = min(min(100 - x, x + 100), min(100 - y, y + 100));
            if(r <= rr) break;
        }
        cout << x << " " << y << " " << r << endl;
        sum += y * y;
    }
    // cout << (DD)10000 / 3 << endl;
    // cout << ((DD)sum / n) << endl;
}
