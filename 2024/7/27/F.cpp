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
int SSS;
int hd[41 * maxn + 5], len = 0, dis[41 * maxn + 5];
struct Edge {
    int v, net;
} e[70 * maxn + 5];
int T, n, a, b, p[maxn + 5], id[maxn + 5], tot = 0;
int poi[40 * maxn + 5][2];
int TTT;

void add(int u, int v) {
    // if(u == 2) cout << v << endl;
    e[len] = { v, hd[u] };
    hd[u] = len++;
    assert(len <= 70 * maxn);
}

int ins(int rt1, int rt2, int l, int r, int x) {
    assert(rt1 <= 40 * maxn);
    if(l == r) {
        add(n + rt1, l);
        return rt1;
    }
    int md = l + r >> 1;
    if(x <= md) {
        poi[rt1][0] = ins(++tot, poi[rt2][0], l, md, x);
        poi[rt1][1] = poi[rt2][1];
    }
    else {
        poi[rt1][0] = poi[rt2][0];
        poi[rt1][1] = ins(++tot, poi[rt2][1], md + 1, r, x);
    }
    For(o, 0, 1) if(poi[rt1][o]) add(n + rt1, n + poi[rt1][o]);
    return rt1;
}
void que(int rt, int l, int r, int ql, int qr, int x) {
    if(!rt) return;
    if(ql <= l && qr >= r) return add(x, n + rt);
    int md = l + r >> 1;
    if(ql <= md) que(poi[rt][0], l, md, ql, qr, x);
    if(qr > md) que(poi[rt][1], md + 1, r, ql, qr, x);
}

int ins1(int rt1, int rt2, int l, int r, int x) {
    assert(rt1 <= 40 * maxn);
    if(l == r) {
        add(l, n + rt1);
        return rt1;
    }
    int md = l + r >> 1;
    if(x <= md) {
        poi[rt1][0] = ins1(++tot, poi[rt2][0], l, md, x);
        poi[rt1][1] = poi[rt2][1];
    }
    else {
        poi[rt1][0] = poi[rt2][0];
        poi[rt1][1] = ins1(++tot, poi[rt2][1], md + 1, r, x);
    }
    For(o, 0, 1) if(poi[rt1][o])  add(n + poi[rt1][o], n + rt1);
    return rt1;
}
void que1(int rt, int l, int r, int ql, int qr, int x) {
    if(!rt) return;
    if(ql <= l && qr >= r) return add(n + rt, x);
    int md = l + r >> 1;
    if(ql <= md) que1(poi[rt][0], l, md, ql, qr, x);
    if(qr > md) que1(poi[rt][1], md + 1, r, ql, qr, x);
}

void mian() {
    read(n); read(a); read(b);
    For(i, 1, n) read(p[i]);
    if(a == b) {
        puts("0");
        return;
    }
    For(i, 1, n) id[i] = i;
    sort(id + 1, id + n + 1, [](cst int &x, cst int &y) {return p[x] > p[y];});
    int rt1 = ++tot, rt2 = ++tot;
    For(i, 1, n) {
        que(rt1, 1, n, max(1, id[i] - p[id[i]]), min(n, id[i] + p[id[i]]), id[i]);
        que1(rt2, 1, n, max(1, id[i] - p[id[i]]), min(n, id[i] + p[id[i]]), id[i]);
        rt1 = ins(++tot, rt1, 1, n, id[i]);
        rt2 = ins1(++tot, rt2, 1, n, id[i]);
    }
    // cout << "asd" << endl;
    deque<int> dq;
    dq.pb(a);
    dis[a] = 0;
    while(dq.size()) {
        int u = dq.front(); dq.pop_front();
        // cout << u << endl;
        for(int i = hd[u]; ~i; i = e[i].net) {
            int v = e[i].v, w = u <= n;
            // if(u == 2) cout << v << endl;
            if(dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                if(!w) dq.push_front(v);
                else dq.push_back(v);
            }
        }
    }
    printf("%d\n", dis[b]);
}

int main() {
    memset(hd, -1, sizeof hd);
    memset(dis, inf, sizeof dis);
    cout << ((&TTT - &SSS) >> 18) << endl;
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
        For(i, 1, n + tot) {
            hd[i] = -1;
            dis[i] = inf;
        }
        For(i, 1, tot) poi[i][0] = poi[i][1] = 0;
        tot = 0; len = 0;
    }
}
