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

#define maxn 50000
int n, m, q, a[maxn + 5], a1[maxn + 5];

struct Opt {
    int l, r;
    int L[1002], R[1002];
} opt[maxn + 5];

int as[maxn + 5], b[maxn + 5], pre[maxn + 5], id[maxn + 5];
vector<int> vec[maxn + 5];

vector<int> eve[maxn + 5];

int tr[maxn + 5], lim = 0;
void ins(int x, int y) {
    while(x <= lim) tr[x] = min(tr[x], y), x += x & -x;
}
int que(int x) {
    int res = inf;
    while(x) res = min(res, tr[x]), x -= x & -x;
    return res;
}

int vis[maxn + 5];
int main() {
    freopen("in.txt", "r", stdin);
    read(n); read(m); read(q);
    For(i, 1, n) {
        int mx = 0, cnt = 0, mx1 = 0;
        Rof(j, m, 1) {
            char c; cin >> c;
            b[j] = c - '0';
            cnt += b[j];
            if(b[j] && mx && !mx1) mx1 = j;
            if(b[j] && !mx) mx = j;
        }
        a[i] = mx - (cnt == 1);
        if(cnt == 1) a1[i] = a[i] - 1;
        else a1[i] = mx1 - (cnt == 2);
    }
    // For(i, 1, n) cout << a[i] << " "; cout << endl;
    For(i, 1, q) {
        int l, r; read(l); read(r);
        opt[i] = { l, r };
    }
    For(i, 1, q) vec[opt[i].r].pb(i);
    For(i, 0, m) pre[i] = 0;
    For(i, 1, n) {
        pre[a[i]]++;
        id[i] = pre[a[i]];
        for(auto j : vec[i]) For(p, 0, m + 1) opt[j].R[p] = pre[p];
        vec[i].resize(0);
    }
    For(i, 0, m) pre[i]++;
    For(i, 1, q) vec[opt[i].l].pb(i);
    Rof(i, n, 1) {
        pre[a[i]] = id[i];
        for(auto j : vec[i]) For(p, 0, m + 1) opt[j].L[p] = pre[p];
        vec[i].resize(0);
    }
    For(i, 0, m) vec[i].pb(0);
    For(i, 1, n) vec[a[i]].pb(a1[i]);
    For(i, 1, q) {
        int res = -1, now = 0, las = 0;
        Rof(j, m, 0) {
            if(opt[i].L[j] <= opt[i].R[j]) las = j;
            else opt[i].L[j] = opt[i].R[j] + 1;
        }
        Rof(j, m, 0) if(opt[i].L[j] <= opt[i].R[j]) {
            now += opt[i].R[j] - opt[i].L[j] + 1;
            int tem = j + now - (j == las);
            if(res < tem) res = tem;
        }
        // cout << res << endl;
        as[i] = res;
        now = 0;
        Rof(j, m, 0) if(opt[i].L[j] <= opt[i].R[j]) {
            now += opt[i].R[j] - opt[i].L[j] + 1;
            int tem = j + now - (j == las);
            if(res == tem && j != las) {
                eve[j].pb(i);
                vis[i] = 1;
                // cout << j << endl;
            }
        }
    }
    // cout << a[1] << endl;
    // For(i, 1, q) printf("%d\n", as[i]);

    memset(tr, inf, sizeof tr);
    For(i, 0, m) if(eve[i].size()) {
        assert(i);
        // cout << i << endl;
        sort(eve[i].begin(), eve[i].end(), [](int x, int y) {return opt[x].l < opt[y].l;});
        // cout << opt[1].L[2] << " " << opt[1].R[2] << endl;
        // cout << vec[2][1] << endl;
        int now = eve[i].size() - 1;
        lim = vec[i].size();
        Rof(j, vec[i].size() - 1, 1) {
            ins(j, vec[i][j]);
            while(now >= 0 && opt[eve[i][now]].L[i] == j) {
                int tem = que(opt[eve[i][now]].R[i]);
                // cout << i << endl;
                opt[eve[i][now]].R[i]--;
                opt[eve[i][now]].R[i - 1]++;
                opt[eve[i][now]].R[tem]++;
                now--;
            }
        }
        For(i, 1, lim) tr[i] = inf;
    }
    // cout <<
    For(i, 1, q) if(vis[i]) {
        int res = -1, now = 0, las = 0;
        Rof(j, m, 0) {
            if(opt[i].L[j] <= opt[i].R[j]) las = j;
            else opt[i].L[j] = opt[i].R[j] + 1;
        }
        Rof(j, m, 0) if(opt[i].L[j] <= opt[i].R[j]) {
            now += opt[i].R[j] - opt[i].L[j] + 1;
            // cout << j << " " << now << endl;
            int tem = j + now - (j == las);
            if(res < tem) res = tem;
        }
        as[i] = min(as[i], res);
    }
    For(i, 1, q) printf("%d\n", as[i]);
    return 0;
}
