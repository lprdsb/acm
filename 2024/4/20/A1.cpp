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
int n;
struct Round {
    int x, y, r, id;
} rrr[maxn + 5];
int poi_tot = 0;
struct Poi {
    Poi *ch[2];
    vector<int> vec;
} poi[35 * maxn + 5];
Poi *get_new() {
    poi[++poi_tot] = {};
    return &poi[poi_tot];
}
Poi *get_o(Poi *rt, int o) {
    if(!rt->ch[o]) rt->ch[o] = get_new();
    return rt->ch[o];
}
void mdy(Poi *rt, int l, int r, cst Round &x, int ty) {
    if(x.x - x.y <= l && x.x + x.y >= r) {
        if(ty) rt->vec.pb(x.id);
        else {
            For(i, 0, rt->vec.size() - 1) if(rt->vec[i] == x.id) {
                For(j, i, rt->vec.size() - 2) rt->vec[j] = rt->vec[j + 1];
                rt->vec.pop_back();
                break;
            }
        }
        return;
    }
    int md = l + r >> 1;
    if(x.x - x.y <= md) mdy(get_o(rt, 0), l, md, x, ty);
    if(x.x + x.y > md) mdy(get_o(rt, 1), md + 1, r, x, ty);
}
bool chk(cst Round &rou, int x, int y) {
    LL dis = 1ll * (x - rou.x) * (x - rou.x) + 1ll * (y - rou.y) * (y - rou.y);
    return dis < 1ll * rou.r * rou.r;
}
int que(Poi *rt, int l, int r, int x, int y) {
    if(!rt) return 0;
    for(auto id : rt->vec) if(chk(rrr[id], x, y)) return id;
    if(l == r) return 0;
    int md = l + r >> 1;
    if(x <= md) return que(rt->ch[0], l, md, x, y);
    return que(rt->ch[1], md + 1, r, x, y);
}

int main() {
    // freopen("in.txt", "r", stdin);
    int inf = 1000000000;
    read(n);
    Poi *Rt = get_new();
    For(i, 1, n) {
        int op, x, y; read(op); read(x); read(y);
        if(op == 1) {
            rrr[i] = { x, y, y, i };
            mdy(Rt, -inf, inf, rrr[i], 1);
        }
        else {
            int res = que(Rt, -inf, inf, x, y);
            if(res) {
                printf("%d\n", res);
                mdy(Rt, -inf, inf, rrr[res], 0);
            }
            else puts("-1");
        }
    }
}
