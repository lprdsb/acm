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

int tot = 0, mmx = 0, st[35], tp = 0;
void dfs(int pos, int res, int mx = 1) {
    if(pos > res) {
        tot++;
        mmx = max(mmx, mx);
        if(mx == 8316) {
            For(i, 1, tp) cout << st[i] << " ";
            cout << endl;
        }
        return;
    }
    For(i, 0, res / pos) {
        st[++tp] = i;
        dfs(pos + 1, res - i * pos, mx * (i + 1) * i / 2);
        tp--;
    }
}

int main() {
    //freopen("in", "r", stdin);
    dfs(1, 32, 1);
    cout << tot << endl;
    cout << mmx << endl;
}
