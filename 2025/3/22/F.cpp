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

#define maxn 400000
int T, n, k, a[maxn + 5];

int tr[maxn + 5];
void ins(int x, int y) {
    while(x <= n) tr[x] += y, x += x & -x;
}
int find(int x) {
    int res = 0;
    Rof(o, 20, 0) {
        int to = res + (1 << o);
        if(to <= n && x - tr[to] > 0) {
            x -= tr[to];
            res = to;
        }
    }
    return res + 1;
}

LL tr1[2][maxn + 5];
void ins1(int x, int y) {
    LL t = (x - 1) * y;
    while(x <= n) {
        tr1[0][x] += y;
        tr1[1][x] += t;
        x += x & -x;
    }
}
LL que1(int x) {
    LL res = 0;
    int t = x;
    while(x) {
        res += tr1[0][x] * t - tr1[1][x];
        x -= x & -x;
    }
    return res;
}

int num[maxn + 5];

LL get_s(int x) { return 1ll * x * (x - 1) / 2; }

void mian() {
    read(n); read(k);
    For(i, 1, n) read(a[i]);
    // cout << k << endl;
    LL res = Inf;
    // int cnt = 0;
    For(i, 1, k) num[i] = 0;
    set<int> se;
    Rof(i, n, 1) {
        if(num[a[i]]) {
            ins(num[a[i]], -1);
            ins1(num[a[i]], -1);
            se.erase(num[a[i]]);
        }
        num[a[i]] = i;
        ins1(num[a[i]], 1);
        ins(num[a[i]], 1);
        se.insert(num[a[i]]);
        // cout << i << " " << find(1) << endl;
        // if(i == 2) cout << se.size() << endl;
        if(se.size() == k) {
            int p = find(k / 2), pmx = *(--se.end());
            // cout << i << " " << se.size() << endl;
            LL tmp = que1(p) + 1ll * (k + 1) * (pmx - p) - (que1(pmx) - que1(p)) - (pmx - i + 1);
            res = min(res, tmp);
            // if(i == 4) cout << tmp << endl;
            // cout << i << " " << res << endl;
        }
    }
    cout << res - get_s(k / 2) - get_s((k + 1) / 2) << endl;
}

int main() {
    freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
        For(i, 1, n) tr[i] = tr1[0][i] = tr1[1][i] = 0;
    }
}
