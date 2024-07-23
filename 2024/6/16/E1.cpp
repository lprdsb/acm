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
int T, n, a[maxn + 5], b[maxn + 5];
vector<pair<int, int> > vec[maxn + 5];
int as[maxn + 5];

int tr[maxn + 5], to[maxn + 5];
void ins(int x, int y) {
    while(x <= n) tr[x] += y, x += x & -x;
}
int que(int x) {
    int res = 0;
    while(x) res += tr[x], x -= x & -x;
    return res;
}

void mian() {
    read(n);
    For(i, 1, n) {
        char c; cin >> c;
        a[i] = c - '0';
    }
    For(i, 1, n) {
        char c; cin >> c;
        b[i] = c - '0';
    }
    int q; read(q);
    For(i, 1, q) {
        int l, r; read(l); read(r);
        vec[l].pb({ i, r });
    }
    Rof(i, n, 1) {
        if(a[i]) ins(i, 1);
        if(b[i]) to[i] = i;
        if(i + 2 <= n && !a[i] && !a[i + 2] && !b[i + 1]) {
            b[i + 1] = 1;
            to[i + 1] = i + 2;
            if(i + 3 <= n && !a[i + 2] && b[i + 3]) {
                a[i + 2] = 1;
                ins(to[i + 3], 1);
            }
        }
        if(i + 2 <= n && b[i] && b[i + 2] && !a[i + 1]) {
            a[i + 1] = 1;
            ins(to[i + 2], 1);
        }
        for(auto [id, r] : vec[i]) as[id] = que(r);
    }
    For(i, 1, q) printf("%d\n", as[i]);
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
        For(i, 1, n) {
            vec[i].resize(0);
            tr[i] = 0;
        }
    }
}
