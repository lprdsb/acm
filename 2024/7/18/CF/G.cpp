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

#define maxn 2000000
int T, n, k, s[maxn + 5], num[maxn + 5], as[maxn + 5];
vector<int> f[maxn + 5];
vector<pair<int, int> > pre[maxn + 5];

void mian() {
    read(n); read(k);
    For(o, 1, k) {
        char c; cin >> c;
        s[o] = c - '0';
    }
    For(i, 1, n) For(o, 1, k) {
        char c; cin >> c;
        num[o] += c - '0';
    }
    For(i, 0, k) f[i].resize(2 * n + 1), pre[i].resize(2 * n + 1);
    f[0][0] = 1;
    For(o, 0, k - 1) For(i, 0, 2 * n) if(f[o][i]) {
        int tem = 2 * i + s[o + 1] - num[o + 1];
        if(tem <= 2 * n && tem >= 0 && !f[o + 1][tem]) {
            f[o + 1][tem] = 1;
            pre[o + 1][tem] = { i, 0 };
        }
        tem = 2 * i + s[o + 1] - (n - num[o + 1]);
        // cout << o << " " << i << " " << tem << endl;
        if(tem <= 2 * n && tem >= 0 && !f[o + 1][tem]) {
            f[o + 1][tem] = 1;
            pre[o + 1][tem] = { i, 1 };
        }
    }
    if(!f[k][0]) puts("-1");
    else {
        int now = 0;
        Rof(i, k, 1) {
            as[i] = pre[i][now].sec;
            now = pre[i][now].fir;
        }
        For(i, 1, k) printf("%d", as[i]);
        puts("");
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
        For(i, 0, k) {
            num[i] = 0;
            f[i].resize(0);
            pre[i].resize(0);
        }
    }
}
