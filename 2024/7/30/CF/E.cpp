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
int tr[maxn + 5], n, q, a[maxn + 5];
vector<int> vec[maxn + 5], pos[maxn + 5];

void ins(int x, int y) {
    while(x <= maxn) tr[x] += y, x += x & -x;
}
int que(int x) {
    int res = 0;
    while(x) res += tr[x], x -= x & -x;
    return res;
}
int find(int x) {
    int now = 0;
    Rof(o, 20, 0) {
        int to = now + (1 << o);
        if(to <= maxn && x > tr[to]) {
            x -= tr[to];
            now = to;
        }
    }
    return now + 1;
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(n); read(q);
    For(i, 1, n) read(a[i]), vec[a[i]].pb(i);
    int now = n;
    For(i, 1, n) pos[i].pb(0);
    For(i, 1, n) ins(i, 1);
    For(i, 1, n) {
        For(j, 1, now) {
            int tem = que(pos[j].back()), p = find(tem + j);
            pos[j].pb(p);
        }
        while(now && pos[now].back() == maxn + 1) now--;
        if(!now) break;
        for(auto j : vec[i]) ins(j, -1);
    }
    // for(auto i : pos[2]) cout << i << " "; cout << endl;
    while(q--) {
        int x, y; read(x); read(y);
        int idx = lower_bound(pos[y].begin(), pos[y].end(), x) - pos[y].begin();
        // cout << idx << endl;
        if(a[x] >= idx) puts("YES");
        else puts("NO");
    }
}
