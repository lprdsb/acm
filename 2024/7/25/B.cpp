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

int n, m, x;

#define maxm 10000000
#define maxn 1000000
int dis[maxm + 5], T;
int q[8 * maxm + 5], l = 1, r = 0, tot;

int hd[maxm + 5], len = 0, suf[maxn + 5], pre[maxn + 5];
struct Edge {
    int v, net;
} e[8 * maxm + 5];
int tim = 0;
void add(int u, int v) {
    // assert(len <= 8 * maxm);
    // tim++; assert(tim <= 8 * maxm);
    e[len] = { v, hd[u] };
    hd[u] = len++;
}

void mian() {
    read(n); read(m); read(x); tot = n;
    For(i, 1, m) {
        int u = i, v = i + 1;
        read(u); read(v);
        add(u, v); add(v, u);
        // cout << u << " " << v << " " << len - 2 << " " << len - 1 << endl;
    }
    // cout << n << " " << m << endl;
    tot = n + len;
    int ok = n + len;
    For(i, 1, n) {
        vector<pair<int, int> > vec;
        for(int j = hd[i]; ~j; j = e[j].net) {
            // tim++; assert(tim <= 2 * maxm);
            vec.pb({ j, e[j].v });
        }
        For(j, 0, (int)vec.size() - 1) {
            pre[j] = ++tot;
            if(j) add(pre[j], pre[j - 1]);
            add(pre[j], n + 1 + vec[j].fir);
        }
        Rof(j, (int)vec.size() - 1, 0) {
            suf[j] = ++tot;
            if(j < (int)vec.size() - 1) add(suf[j], suf[j + 1]);
            add(suf[j], n + 1 + vec[j].fir);
        }
        For(j, 0, (int)vec.size() - 1) {
            int id = vec[j].fir;
            if(j) add(n + 1 + (id ^ 1), pre[j - 1]);
            if(j < (int)vec.size() - 1) add(n + 1 + (id ^ 1), suf[j + 1]);
        }
    }
    // assert(tot <= maxm);
    for(int i = hd[1]; ~i; i = e[i].net) {
        add(e[i].v, n + 1 + i);
        // cout << e[i].v << " " << n + 1 + i << endl;
    }
    l = 1; r = 0;
    q[++r] = x;
    dis[x] = 0;
    while(l <= r) {
        // tim++; assert(tim <= 2 * maxm);
        int u = q[l++];
        if(u == 1) continue;
        for(int i = hd[u]; ~i; i = e[i].net) {
            int v = e[i].v;
            if(dis[v] == -1 || dis[v] > dis[u] + (u <= ok)) {
                dis[v] = dis[u] + (u <= ok);
                if(u > ok) q[--l] = v;
                else q[++r] = v;
            }
        }
    }
    // cout << dis[22] << endl;
    int res = inf;
    for(int i = hd[n]; ~i; i = e[i].net) if(n + 1 + i <= ok && dis[n + 1 + i] != -1) res = min(res, dis[n + 1 + i]);
    if(res != inf) printf("Vegetable fallleaves\n%d\n", res - 1);
    else puts("Boring Game");
}

int main() {
    // freopen("in.txt", "r", stdin);
    memset(dis, -1, sizeof dis);
    memset(hd, -1, sizeof hd);
    read(T);
    while(T--) {
        mian();
        For(i, 1, tot) hd[i] = dis[i] = -1;
        len = 0;
        // cout << T << endl;
    }
}