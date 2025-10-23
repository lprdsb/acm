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
int T, n;
vector<int> vec;
struct Poi {
    int x, y;
} poi[maxn + 5];

struct Tree {
    int tr[maxn + 5], up;
    void init(int up) {
        this->up = up;
        For(i, 0, up) tr[i] = 0;
    }
    void ins(int x, int y) {
        assert(x);
        while(x <= up) tr[x] += y, x += x & -x;
    }
    int que(int x) {
        x--;
        int res = 0;
        while(x) res += tr[x], x -= x & -x;
        return res;
    }
} tr[2];

vector<int> pos[maxn + 5];

int as[3];
int c1 = 0, c2 = n;

int chk(int x) {
    int t1 = tr[0].que(x), t2 = tr[1].que(x);
    int tmp = min(min(tr[0].que(x), c1 - t1), min(t2, c2 - t2));
    return min(t1, t2) > min(c1 - t1, c2 - t2);
}
int get_as(int x) {
    int t1 = tr[0].que(x), t2 = tr[1].que(x);
    return min(min(t1, t2), min(c1 - t1, c2 - t2));
}

void mian() {
    read(n);
    c1 = 0, c2 = n;
    For(i, 1, n) {
        int x, y; read(x); read(y);
        poi[i] = { x, y };
        vec.pb(x); vec.pb(y);
    }
    as[0] = -1;
    vec.pb(inf);
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    For(i, 1, n) {
        auto [x, y] = poi[i];
        x = lower_bound(vec.begin(), vec.end(), x) - vec.begin() + 1;
        y = lower_bound(vec.begin(), vec.end(), y) - vec.begin() + 1;
        poi[i] = { x, y };
        pos[x].pb(i);
    }
    For(o, 0, 1) tr[o].init(vec.size());
    For(i, 1, n) tr[1].ins(poi[i].y, 1);
    For(i, 1, vec.size()) {
        // cout << i << endl;
        int l = 1, r = vec.size();
        while(l < r) {
            int md = l + r >> 1;
            if(chk(md)) r = md;
            else l = md + 1;
        }
        For(o, -1, 1) {
            int to = min((int)vec.size(), max(1, l + o));
            int t = get_as(to);
            if(as[0] == -1 || as[0] < t) {
                as[0] = t;
                as[1] = vec[i - 1];
                as[2] = vec[to - 1];
            }
        }
        for(auto p : pos[i]) {
            tr[0].ins(poi[p].y, 1); c1++;
            tr[1].ins(poi[p].y, -1); c2--;
        }
    }
    printf("%d\n%d %d\n", as[0], as[1], as[2]);
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
        For(i, 1, vec.size()) {
            pos[i].resize(0);
        }
        vec.resize(0);
    }
}
