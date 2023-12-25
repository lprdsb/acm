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
#define maxn 300000
using namespace std;

int n, a[maxn + 5], s, t, hd[2 * maxn + 5], len, pri[maxn + 5], vis[maxn + 5], to[maxn + 5], cnt = 0;
struct Edge{
    int v, net;
} e[30 * maxn + 5];

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

int dis[2 * maxn + 5], ok[2 * maxn + 5], pre[2 * maxn + 5];
void dij(int s){
    memset(dis, inf, sizeof dis);
    dis[s] = 0;
    priority_queue<pair<int, int> > q;
    q.push(mp(0, s));
    while(q.size()){
        int u = q.top().sec; q.pop();
        if(ok[u]) continue;
        ok[u] = 1;
        Tra(u, i){
            int v = e[i].v;
            if(dis[u] + 1 < dis[v]){
                dis[v] = dis[u] + 1;
                pre[v] = u;
                q.push(mp(-dis[v], v));
            }
        }
    }
}

int st[maxn + 5], top = 0;
int main(){
	//freopen("in", "r", stdin);
    For(i, 2, maxn){
        if(!vis[i]) pri[++cnt] = i, to[i] = i;
        for(int j = 1; j <= cnt && i * pri[j] <= maxn; ++j){
            vis[i * pri[j]] = 1;
            to[i * pri[j]] = pri[j];
            if(i % pri[j] == 0) break;
        }
    }
    memset(hd, -1, sizeof hd);
    read(n);
    For(i, 1, n){
        read(a[i]);
        int tem = a[i];
        while(tem != 1){
            int tem1 = to[tem];
            add(i, maxn + tem1);
            add(maxn + tem1, i);
            while(tem % tem1 == 0) tem /= tem1;
        }
    }
    read(s); read(t);
    dij(s);
    if(dis[t] == inf) puts("-1");
    else{
        int now = t;
        while(now != s){
            st[++top] = now;
            now = pre[pre[now]];
        }
        st[++top] = s;
        printf("%d\n", top);
        while(top) printf("%d ", st[top--]);
    }
    return 0;
}
