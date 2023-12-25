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
#define maxn 500
using namespace std;

int n, m;
LL as = 0, edge[maxn + 5][maxn + 5];

template <class T>
void read(T &x){
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

LL lv[maxn + 5], rv[maxn + 5], sla[maxn + 5], sla_to[maxn + 5];
int lto[maxn + 5], rto[maxn + 5], okl[maxn + 5], okr[maxn + 5];
void sol(int x){
    memset(okl, 0, sizeof okl);
    memset(okr, 0, sizeof okr);
    okl[x] = 1;
    For(i, 1, n) sla[i] = 1ll * lv[x] + rv[i] - edge[x][i], sla_to[i] = x;
    while(666){
        int mn = 0;
        For(i, 1, n) if(!okr[i] && (!mn || sla[i] < sla[mn])) mn = i;
        LL tem = sla[mn];
        For(i, 1, n){
            if(okl[i]) lv[i] -= tem;
            if(okr[i]) rv[i] += tem;
            else sla[i] -= tem;
        }
        if(!rto[mn]){
            int now = sla_to[mn], pre = mn;
            while(now){
                int ppre = lto[now], nnow = sla_to[ppre];
                lto[now] = pre;
                rto[pre] = now;
                now = nnow;
                pre = ppre;
            }
            break;
        }
        else{
            okl[rto[mn]] = 1;
            okr[mn] = 1;
            For(i, 1, n) if(!okr[i] && sla[i] > 1ll * lv[rto[mn]] + rv[i] - edge[rto[mn]][i]){
                sla[i] = 1ll * lv[rto[mn]] + rv[i] - edge[rto[mn]][i];
                sla_to[i] = rto[mn];
            }
        }
    }
}

int main(){
    // freopen("in.txt", "r", stdin);
    read(n); read(m);
    For(i, 1, n) For(j, 1, n) edge[i][j] = -Inf;
    For(i, 1, m){
        int u, v, w; read(u); read(v); read(w);
        edge[u][v] = w;
    }
    memset(lv, inf, sizeof lv);
    memset(rv, 0, sizeof rv);
    For(i, 1, n) sol(i);
    For(i, 1, n) as += edge[rto[i]][i];
    printf("%lld\n", as);
    For(i, 1, n) printf("%d ", rto[i]);
    return 0;
}
