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
#define maxn 1000000
using namespace std;

int n, a[maxn + 5], pri[maxn + 5], cnt = 0, vis[maxn + 5], id[maxn + 5], to[maxn + 5], as = inf, hd[maxn + 5], len = 0;
struct Edge{
    int v, net;
} e[2 * maxn + 5];

template <class T>
void read(T &x){
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

void add(int u, int v){
    e[len] = (Edge){v, hd[u]};
    hd[u] = len++;
}

int dis[maxn + 5];
int bfs(int s){
    int asi = inf;
    memset(dis, inf, sizeof dis);
    dis[s] = 0;
    queue<pair<int, int> > q;
    q.push(mp(s, -1));
    while(q.size()){
        int u = q.front().fir, pre = q.front().sec; q.pop();
        Tra(u, i) if(i != pre){
            int v = e[i].v;
            if(dis[v] == inf){
                dis[v] = dis[u] + 1;
                q.push(mp(v, i ^ 1));
            }
            else asi = min(asi, dis[v] + dis[u] + 1);
        }
    }
    return asi;
}

int top = 0;
pair<int, int> st[maxn + 5];
int main(){
    // freopen("in.txt", "r", stdin);
    memset(hd, -1, sizeof hd);
    For(i, 2, maxn){
        if(!vis[i]) pri[id[i] = ++cnt] = i, to[i] = i;
        For(j, 1, cnt){
            if(i * pri[j] > maxn) break;
            vis[i * pri[j]] = 1;
            to[i * pri[j]] = pri[j];
            if(i % pri[j] == 0) break;
        }
    }
    read(n);
    For(i, 1, n){
        int x; read(x);
        if(x == 1){
            puts("1");
            return 0;
        }
        top = 0;
        while(x != 1){
            int tem = to[x];
            st[++top] = mp(id[tem], 0);
            while(x % tem == 0) st[top].sec ^= 1, x /= tem;
        }
        if(top == 1){
            if(st[1].sec) add(0, st[1].fir), add(st[1].fir, 0);
            else{
                puts("1");
                return 0;
            }
        }
        else{
            if(!st[1].sec) swap(st[1], st[2]);
            if(!st[1].sec){
                puts("1");
                return 0;
            }
            if(st[2].sec) add(st[1].fir, st[2].fir), add(st[2].fir, st[1].fir);
            else add(0, st[1].fir), add(st[1].fir, 0);
        }
    }
    For(i, 0, 200) as = min(as, bfs(i));
    if(as == inf) puts("-1");
    else printf("%d\n", as);
    return 0;
}
