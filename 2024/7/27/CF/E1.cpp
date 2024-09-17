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
int T, n, a[maxn + 5], p[maxn + 5];

int tr[maxn + 5];
void ins(int x) {
    while(x <= n) tr[x]++, x += x & -x;
}
int que(int x) {
    int res = 0;
    while(x) res += tr[x], x -= x & -x;
    return res;
}

void mian() {
    read(n);
    For(i, 1, n) read(a[i]), p[a[i]] = i;
    ins(p[1]);
    LL res = 0, pre = 1;
    For(i, 2, n) {
        int now = que(p[i]);
        res += (now - pre + i - 1) % (i - 1) * (n - i + 1);
        ins(p[i]);
        pre = now + 1;
    }
    cout << res << endl;
    For(i, 1, n) tr[i] = 0;
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
