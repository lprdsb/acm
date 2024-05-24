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
int n;
struct Node {
    int low;
    vector<int> vec;
};
bool operator < (cst Node &_x, cst Node &_y) { return _x.low < _y.low; }
set<Node> se;

int que(int x, int y) {
    printf("? %d %d\n", x, y);
    fflush(stdout);
    char c; cin >> c;
    if(c == '<') return 1;
    return 0;
}

int chk(int x, int y) {
    auto it = --se.lower_bound({ y + 1 });
    return que(x, it->vec[0]);
}

int as[2][maxn + 5];
int main() {
    //freopen("in", "r", stdin);
    read(n);
    vector<int> vec;
    For(i, 1, (n + 1) >> 1) vec.pb(i);
    se.insert({ 1, vec });
    vec.resize(0);
    For(i, 1, n >> 1) vec.pb(i);
    // shuffle(vec.begin(), vec.end(), mt19937());
    for(auto x : vec) {
        int l = 1, r = (n + 1) >> 1;
        while(l < r) {
            int md = l + r >> 1;
            if(chk(x, md)) r = md;
            else l = md + 1;
        }
        // cout << l << endl;
        auto it = --se.lower_bound({ l + 1 });
        vector<int> v[2];
        for(auto i : it->vec) v[que(x, i)].pb(i);
        if(v[0].size()) {
            int tem = it->low;
            as[0][x] = 2 * (tem + v[0].size() - 1);
            se.erase(it);
            se.insert({ tem, v[0] });
            if(v[1].size()) se.insert({ tem + (int)v[0].size(), v[1] });
        }
        else {
            it--;
            v[0].resize(0); v[1].resize(0);
            for(auto i : it->vec) v[que(x, i)].pb(i);
            int tem = it->low;
            as[0][x] = 2 * (tem + v[0].size() - 1);
            se.erase(it);
            se.insert({ tem, v[0] });
            if(v[1].size()) se.insert({ tem + (int)v[0].size(), v[1] });
        }
    }
    for(auto i : se) as[1][i.vec[0]] = 2 * i.low - 1;
    printf("! ");
    For(i, 1, n >> 1) printf("%d ", as[0][i]);
    For(i, 1, (n + 1) >> 1) printf("%d ", as[1][i]);
    fflush(stdout);
    return 0;
}
