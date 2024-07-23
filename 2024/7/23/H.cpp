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

#define maxn 4000000
int n, m, k, mx[2005][2005][2];
struct Node {
    int x[2], y[2];
} node[maxn + 5];

int res = inf;
vector<int> opt[maxn + 5];
void sol(vector<int> &vec, int l, int r) {
    if(l == r) {
        set<int> se;
        For(i, 1, m) {
            int mn = inf;
            for(auto t : opt[i]) mn = min(mn, t);
            if(mn != inf) se.insert(mn);
            if(se.size()) {
                mx[l][i][0] = *se.begin();
                if(*se.begin() == i) se.erase(se.begin());
            }
        }
        return;
    }
    int md = l + r >> 1, fll = 0, flr = 0;
    vector<int> vv;
    for(auto id : vec) if(node[id].x[0] <= md) {
        if(node[id].x[0] <= l && node[id].x[1] >= md) {
            opt[node[id].y[0]].pb(node[id].y[1]);
        }
        else vv.pb(id);
    }
    sol(vv, l, md);
    for(auto id : vec) if(node[id].x[0] <= md) {
        if(node[id].x[0] <= l && node[id].x[1] >= md) opt[node[id].y[0]].pop_back();
    }
    vv.resize(0);

    for(auto id : vec) if(node[id].x[1] > md) {
        if(node[id].x[1] >= r && node[id].x[0] <= md + 1) {
            opt[node[id].y[0]].pb(node[id].y[1]);
        }
        else vv.pb(id);
    }
    sol(vv, md + 1, r);
    for(auto id : vec) if(node[id].x[1] > md) {
        if(node[id].x[1] >= r && node[id].x[0] <= md + 1) opt[node[id].y[0]].pop_back();
    }
}

void sol1(vector<int> &vec, int l, int r) {
    if(l == r) {
        set<int> se;
        For(i, 1, n) {
            int mn = inf;
            for(auto t : opt[i]) mn = min(mn, t);
            if(mn != inf) se.insert(mn);
            if(se.size()) {
                mx[i][l][1] = *se.begin();
                if(*se.begin() == i) se.erase(se.begin());
            }
        }
        return;
    }
    int md = l + r >> 1, fll = 0, flr = 0;
    vector<int> vv;
    for(auto id : vec) if(node[id].y[0] <= md) {
        if(node[id].y[0] <= l && node[id].y[1] >= md) {
            opt[node[id].x[0]].pb(node[id].x[1]);
        }
        else vv.pb(id);
    }
    sol1(vv, l, md);
    for(auto id : vec) if(node[id].y[0] <= md) {
        if(node[id].y[0] <= l && node[id].y[1] >= md) opt[node[id].x[0]].pop_back();
    }
    vv.resize(0);

    for(auto id : vec) if(node[id].y[1] > md) {
        if(node[id].y[1] >= r && node[id].y[0] <= md + 1) {
            opt[node[id].x[0]].pb(node[id].x[1]);
        }
        else vv.pb(id);
    }
    sol1(vv, md + 1, r);
    for(auto id : vec) if(node[id].y[1] > md) {
        if(node[id].y[1] >= r && node[id].y[0] <= md + 1) opt[node[id].x[0]].pop_back();
    }
}

int sum[2005][2005][2];

int main() {
    // freopen("in.txt", "r", stdin);
    read(n); read(m); read(k);
    For(i, 1, k) {
        For(o, 0, 1) read(node[i].x[o]), read(node[i].y[o]);
        sum[node[i].x[0]][node[i].y[0]][0]++;
        sum[node[i].x[0] + 1][node[i].y[0]][0]--;
        sum[node[i].x[0]][node[i].y[0]][1]++;
        sum[node[i].x[0]][node[i].y[1] + 1][1]--;
    }
    For(i, 1, n) For(j, 1, m) {
        sum[i][j][0] += sum[i - 1][j][0];
        sum[i][j][1] += sum[i][j - 1][1];
    }
    vector<int> vec;
    For(i, 1, k) vec.pb(i);
    sol(vec, 1, n); sol1(vec, 1, m);
    // For(i, 1, n) {
    //     For(j, 1, m) cout << mx[i][j][0] << " ";
    //     cout << endl;
    // }
    For(i, 1, n) For(j, 1, m) if(sum[i][j][0] && sum[i][j][1]) res = min(res, (mx[i][j][0] - j + 1) * (mx[i][j][1] - i + 1));
    printf("%d\n", res);
}
