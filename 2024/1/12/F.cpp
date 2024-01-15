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
#define maxn 500000
using namespace std;

int T, n, m;
int s[maxn + 5];
int poi_tot = 0;
struct Poi {
    int len, cnt;
    map<int, Poi*> ch;
    Poi *to;
} poi[maxn + 5];
Poi *get_new() {
    poi[++poi_tot] = {};
    return &poi[poi_tot];
}
struct Tree {
    Poi *Rt[2];
    Tree() {
        Rt[0] = get_new();
        Rt[1] = get_new();
        Rt[0]->to = Rt[1]->to = Rt[1];
        Rt[1]->len = -1;
    }
    void init() {
        Rt[0] = get_new();
        Rt[1] = get_new();
        Rt[0]->to = Rt[1]->to = Rt[1];
        Rt[1]->len = -1;
    }
    Poi *get_o(Poi *rt, int o) {
        if(!rt->ch[o]) return Rt[0];
        return rt->ch[o];
    }
    Poi* ins(Poi *las, int pos) {
        int o = s[pos];
        while(s[pos - las->len - 1] != s[pos]) las = las->to;
        if(las->ch[o]) return las->ch[o];
        else {
            Poi *now = get_new(), *pre = las->to;
            now->len = las->len + 2;
            while(s[pos - pre->len - 1] != s[pos]) pre = pre->to;
            pre = get_o(pre, o);
            now->to = pre;
            now->cnt = pre->cnt + 1;
            las->ch[o] = now;
            return now;
        }
    }
    int cnt[maxn + 5], vis[maxn + 5];
    int que(Poi *las) {
        For(i, 0, m) cnt[i] = vis[i] = 0;
        For(i, 1, n) vis[s[i]] = 1;
        For(i, 1, m) cnt[i] += !vis[i];
        while(las->len != -1) {
            int tmp = s[n + 1 - las->len - 1];
            if(!las->ch[tmp]) cnt[tmp]++;
            las = las->to;
        }
        int mx = 0;
        For(i, 1, m) mx = max(mx, cnt[i]);
        int res = 0;
        For(i, 1, m) res += cnt[i] == mx;
        return res;
    }
} tr;

template <class T>
void read(T &x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}


int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        read(n); read(m);
        For(i, 1, n) read(s[i]);
        Poi *las = tr.Rt[0];
        For(i, 1, n) las = tr.ins(las, i);
        printf("%d\n", tr.que(las));
        poi_tot = 0;
        tr.init();
    }
    return 0;
}

