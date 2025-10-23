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
int T, n, V[maxn + 5], W[maxn + 5], id[maxn + 5];

bool chk(int x) {
    vector<int> vec[2];
    For(i, 1, n) {
        if(V[id[i]] < x) vec[0].pb(W[id[i]]);
        else vec[1].pb(W[id[i]] + V[id[i]] - x);
    }
    For(o, 0, 1) {
        sort(vec[o].begin(), vec[o].end());
    }
    int now = 0;
    for(auto v : vec[0]) {
        while(now < vec[1].size() && vec[1][now] < v) now++;
        if(now == vec[1].size()) return 0;
        now++;
    }
    return 1;

}

void mian() {
    read(n);
    For(i, 1, n) read(V[i]), read(W[i]);
    For(i, 1, n) id[i] = i;
    sort(id + 1, id + n + 1, [](int x, int y) {return V[x] < V[y];});
    int l = 1, r = 1000000001;
    while(l < r) {
        int md = l + r >> 1;
        if(!chk(md)) r = md;
        else l = md + 1;
    }
    printf("%d\n", l - 1);
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
