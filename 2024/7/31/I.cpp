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
int fa[maxn + 5], fai[maxn + 5], T, n, m, k;
vector<pair<int, int> > edge[15];

int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void mian() {
    read(n); read(m); read(k);
    For(i, 1, m) {
        int u, v, w; read(u); read(v); read(w);
        edge[w].pb({ u, v });
    }
    int res = k;
    For(o, 1, k) {
        int cnt = 0;
        For(i, 1, n) fa[i] = i;
        for(auto [u, v] : edge[o]) {
            u = find(u); v = find(v);
            if(u != v) {
                cnt++;
                fa[u] = v;
            }
        }
        int lim = cnt, fl = 1;
        For(sta, 0, (1 << k) - 1) if(!((sta >> (o - 1)) & 1)) {
            For(i, 1, n) fai[i] = fa[i];
            int popcount = 0;
            For(o1, 1, k) if((sta >> (o1 - 1)) & 1) {
                popcount++;
                for(auto [u, v] : edge[o1]) {
                    u = find(u); v = find(v);
                    if(u != v) {
                        fa[u] = v;
                        cnt++;
                    }
                }
            }
            if(cnt + (k - 1 - popcount) * lim < n - 1) {
                fl = 0;
                break;
            }
            cnt = lim;
            For(i, 1, n) fa[i] = fai[i];
        }
        if(fl) {
            res = o;
            break;
        }
    }
    printf("%d\n", res);
    return;
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
        For(i, 1, k) edge[i].resize(0);
    }
}
