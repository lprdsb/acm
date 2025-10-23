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
int n, a[2][maxn + 5], num[2][maxn + 5];

int tr[maxn + 5];
void ins(int x) {
    while(x <= n) tr[x]++, x += x & -x;
}

void del(int x) {
    while(x <= n) tr[x]--, x += x & -x;
}
int que(int x) {
    int res = 0;
    while(x) res += tr[x], x -= x & -x;
    return res;
}

int find(int x) {
    int res = 0;
    Rof(o, 20, 0) {
        int to = res + (1 << o);
        if(to > n) continue;
        if(x > tr[to]) {
            res = to;
            x -= tr[to];
        }
    }
    return res + 1;
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(n);
    For(o, 0, 1) {
        For(i, 1, n) tr[i] = 0;
        For(i, 1, n) read(a[o][i]), a[o][i] += 1;
        Rof(i, n, 1) {
            num[o][i] = que(a[o][i]);
            ins(a[o][i]);
        }
    }
    For(i, 1, n) num[0][i] += num[1][i];
    Rof(i, n - 1, 1) if(num[0][i] >= n - i + 1) {
        num[0][i - 1]++;
        num[0][i] -= n - i + 1;
    }
    For(i, 1, n) tr[i] = 0;
    For(i, 1, n) ins(i);
    For(i, 1, n) {
        int tmp = find(num[0][i] + 1);
        printf("%d ", tmp - 1);
        del(tmp);
    }
}
