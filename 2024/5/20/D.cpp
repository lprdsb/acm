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

int T, n, k, a[] = { 0, 1,3,6,1,2,1 };

int que(int l, int x) {
    cout << "? " << l << " " << x << endl;
    int res; read(res);
    return res;
}

void mian() {
    read(n); read(k);
    int mx = -1;
    For(i, 1, n) if(que(1, i * n) == n) {
        mx = i;
        break;
    }
    assert(mx != -1);
    Rof(i, n / k, 1) {
        int now = 0;
        For(j, 1, k) {
            now++;
            if(now == n + 1) break;
            now = que(now, i * mx);
            if(now == n + 1) break;
        }
        if(now == n) {
            cout << "! " << i * mx << endl;
            int tem; read(tem);
            return;
        }
    }
    cout << "! -1" << endl;
    int tem; read(tem);
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
