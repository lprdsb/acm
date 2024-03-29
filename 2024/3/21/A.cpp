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

#define maxn 100000
int n, m, op[maxn + 5], pos[maxn + 5];
int fa[maxn + 5];
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

int st[maxn + 5], tp = 0, mx[maxn + 5];

int tr[maxn + 5];
void ins(int x, int y) {
    while(x <= n) tr[x] += y, x += x & -x;
}
int ffind(int x) {
    int now = 0;
    Rof(o, 19, 0) {
        int to = now | (1 << o);
        if(to <= n && x > tr[to]) {
            x -= tr[to];
            now = to;
        }
    }
    return now + 1;
}

int main() {
    //freopen("in", "r", stdin);
    read(n); read(m);
    For(i, 1, n) fa[i] = i, ins(i, 1);
    For(i, 1, m) read(op[i]), read(pos[i]);
    For(i, 1, m) if(op[i]) {
        while(tp && pos[st[tp]] >= pos[i]) tp--;
        st[++tp] = i;
    }
    Rof(i, m, 1) {
        mx[i] = mx[i + 1];
        if(!op[i]) mx[i] = max(mx[i], pos[i]);
    }
    int now = 1, pre = mx[1];
    For(i, 1, n) {
        while(now <= tp && pos[st[now]] <= i) {
            pre = ffind(mx[st[now]] - i + 1);
            now++;
        }
        if(pre && fa[pre] == pre) {
            printf("%d ", pre);
            ins(pre, -1);
            fa[pre] = find(pre - 1);
            pre = find(pre);
        }
        else break;
    }
    For(i, 1, n) if(fa[i] == i) printf("%d ", i);
}
