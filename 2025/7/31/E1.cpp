#include<bits/stdc++.h>
using namespace  std;
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define cst const
#define LL long long

#define maxn 100000
int S;
cst int B = 1000;
int n, q, p[maxn + 5], ip[maxn + 5], sum[maxn / B + 1][maxn + 5];
LL lpr[maxn / B + 1];
LL tr[maxn + 5];
int T;

void ins(int x, int y) {
    // cout << x << endl;
    x++;
    while(x <= n) tr[x] += y, x += x & -x;
}
LL que(int x) {
    x++;
    LL res = 0;
    while(x) res += tr[x], x -= x & -x;
    return res;
}

void add(int x, int y) {
    For(i, 0, x / B) if((i + 1) * B - 1 <= x) {
        lpr[i] += y;
    }
    if(x != (x / B + 1) * B - 1) {
        // cout << (x / B) * B << endl;
        For(i, (x / B) * B, x) ins(ip[i], y);
    }
}

LL que1(int x) {
    // cout << lpr[0] << endl;
    LL res = que(x);
    For(i, 0, n / B) res += 1ll * sum[i][x] * lpr[i];
    return res;
}

int main() {
    // cout << ((&T - &S) >> 18) << endl;
    freopen("in.txt", "r", stdin);
    scanf("%d%d", &n, &q);
    For(i, 1, n) scanf("%d", &p[i]);
    For(i, 1, n) ip[p[i]] = i;
    For(i, 0, n) {
        sum[i / B][ip[i]]++;
    }
    For(i, 0, n / B) For(j, 1, n) sum[i][j] += sum[i][j - 1];
    LL as = 0;
    // cout << "asd" << endl;
    while(q--) {
        int op, l, r, x; scanf("%d%d%d", &op, &l, &r);
        l ^= as; r ^= as;
        if(op == 1) {
            scanf("%d", &x); x ^= as;
            add(l - 1, -x);
            add(r, x);
        }
        else {
            as = que1(r) - que1(l - 1);
            printf("%lld\n", as);
            // as = 0;
        }
    }
    return 0;
}