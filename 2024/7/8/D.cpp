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
int T, n, a[maxn + 5], b[maxn + 5], num[maxn + 5];
int tr[maxn + 5];
void ins(int x, int y) {
    while(x <= maxn) tr[x] += y, x += x & -x;
}
int que(int x) {
    int res = 0;
    while(x) res += tr[x], x -= x & -x;
    return res;
}

void mian() {
    read(n);
    For(i, 1, n) read(a[i]);
    For(i, 1, n) read(b[i]);
    For(i, 1, n) num[a[i]]++;
    For(i, 1, n) {
        if(num[b[i]]) num[b[i]]--;
        else {
            puts("NO");
            return;
        }
    }
    int s1 = 0;
    Rof(i, n, 1) s1 += que(a[i]), ins(a[i], 1);
    For(i, 1, n) ins(a[i], -1);
    int s2 = 0;
    Rof(i, n, 1) s2 += que(b[i]), ins(b[i], 1);
    For(i, 1, n) ins(b[i], -1);
    if(s1 % 2 == s2 % 2) puts("YES");
    else puts("NO");
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
        For(i, 1, n) num[a[i]] = 0;
    }
}
