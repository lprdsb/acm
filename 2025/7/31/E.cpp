#include<bits/stdc++.h>
using namespace  std;
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define cst const
#define LL long long

#define maxn 100000
int S;
cst int B = 700;
int n, q, p[maxn + 5], ip[maxn + 5], sum[maxn / B + 1][maxn + 5];
LL lpr[maxn / B + 1];
LL tr[maxn + 5];
int T;

void ins(int x, int y) {
    // cout << x << endl;
    x++;
    while(x <= n + 1) tr[x] += y, x += x & -x;
}
LL que(int x) {
    x++;
    LL res = 0;
    while(x) res += tr[x], x -= x & -x;
    return res;
}

void add(int x, int y) {
    // cout << x << endl;
    ins(x, y);
    For(i, 0, n / B) lpr[i] += 1ll * y * sum[i][x];
    // cout << sum[i][x] << endl;
}

LL que1(int x) {
    // cout << lpr[0] << endl;
    LL res = 0;
    For(i, 0, x / B) if(x >= (i + 1) * B - 1) {
        res += lpr[i];
    }
    // cout << res << endl;
    if(x != ((x / B + 1) * B - 1)) {
        For(i, x / B * B, x) {
            res += que(p[i]);
            // cout << i << " " << que(p[i]) << endl;
        }
    }
    return res;
}

int main() {
    // cout << ((&T - &S) >> 18) << endl;
    // freopen("in.txt", "r", stdin);
    scanf("%d%d", &n, &q);
    For(i, 1, n) scanf("%d", &p[i]);
    // For(i, 1, n) ip[p[i]] = i;
    For(i, 0, n) {
        sum[i / B][p[i]]++;
    }
    For(i, 0, n / B) Rof(j, n, 0) sum[i][j] += sum[i][j + 1];
    LL as = 0;
    while(q--) {
        LL op, l, r, x; scanf("%lld%lld%lld", &op, &l, &r);
        l ^= as; r ^= as;
        if(op == 1) {
            scanf("%lld", &x); x ^= as;
            add(l, x);
            add(r + 1, -x);
        }
        else {
            // cout << que(3) << endl;
            as = que1(r) - que1(l - 1);
            printf("%lld\n", as);
            // as = 0;
        }
    }
    return 0;
}