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
#define maxn 200000
using namespace std;

int n, hd[maxn + 5], len = 0, a[maxn + 5], as[maxn + 5], cnt;
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

int sz[maxn + 5], f[maxn + 5][32], g[32];
pair<int, int> to[maxn + 5][32];
int pre[maxn + 5][32];
void dfs(int u){
    sz[u] = 1;
    f[u][0] = 1;
    Tra(u, i){
        int v = e[i].v;
        dfs(v);
        a[u] ^= a[v];
        sz[u] += sz[v];
        memset(g, 0, sizeof g);
        For(j, 0, 31) For(p, 0, 31) if(f[u][j] && f[v][p] && !f[u][j ^ p]){
            g[j ^ p] = 1;
            pre[u][j ^ p] = j;
            to[u][j ^ p] = mp(v, p);
        }
        For(j, 0, 31) if(g[j]) f[u][j] = 1;
    }
    if(!(sz[u] & 1)){
        int val = 0;
        For(i, 0, 4) val |= ((a[u] >> i) & 1) << i;
        f[u][val] = 1;
        pre[u][val] = -1;
    }
}

int top = 0;
pair<int, int> st[maxn + 5];
int main(){
	//freopen("in.txt", "r", stdin);
    memset(hd, -1, sizeof hd);
    read(n);
    For(i, 1, n) read(a[i]);
    For(i, 2, n){
        int x; read(x);
        add(x, i);
    }
    dfs(1);
    if(f[1][a[1]]){
        st[++top] = mp(1, a[1]);
        while(top){
            pair<int, int> now = st[top--];
            while(now.sec){
                if(pre[now.fir][now.sec] == -1){
                    as[++cnt] = now.fir;
                    break;
                }
                st[++top] = to[now.fir][now.sec];
                now.sec = pre[now.fir][now.sec];
            }
        }
        printf("%d\n", cnt + 1);
        while(cnt) printf("%d ", as[cnt--]);
        printf("1\n");
    }
    else puts("-1");
    return 0;
}
