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

int n, m, k, a[maxn + 5];
struct Graph{
    vector<pair<int, int> > ch[maxn + 5];
    pair<int, int> pre[maxn + 5];
} gra[2];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int vis[maxn + 5], inst[maxn + 5];
pair<int, int> to[maxn + 5];
void dfs(int u){
    // cout << u << endl;
    inst[u] = 1;
    vis[u] = 1;
    for(auto [v, c] : gra[0].ch[u]){
        if(!vis[v]){
            dfs(v);
            gra[0].pre[v] = {u, c};
        }
        else if(inst[v]) to[u] = {v, c};
    }
    inst[u] = 0;
}

int main(){
	// freopen("in.txt", "r", stdin);
    read(n); read(m); read(k);
    For(i, 1, k) read(a[i]);
    For(i, 1, m){
        int u, v; read(u); read(v);
        char c; cin >> c;
        gra[0].ch[u].pb({v, c - 'a'});
        gra[1].ch[v].pb({u, c - 'a'});
    }
    dfs(1);
    memset(vis, 0, sizeof vis);
    queue<int> q;
    For(i, 1, k){
        vis[a[i]] = 1;
        q.push(a[i]);
    }
    while(q.size()){
        int u = q.front(); q.pop();
        for(auto [v, c] : gra[1].ch[u]){
            if(!vis[v]){
                vis[v] = 1;
                gra[1].pre[v] = {u, c};
                q.push(v);
            }
        }
    }
    // For(i, 1, n) if(to[i].fir) cout << i << endl;
    For(i, 1, n){
        if(to[i].fir && vis[i]){
            vector<int> as, tem;
            int now = i;
            while(now != 1){
                as.pb(gra[0].pre[now].sec);
                now = gra[0].pre[now].fir;
            }
            reverse(as.begin(), as.end());
            now = i;
            int tt = to[i].fir;
            as.pb(to[i].sec);
            while(now != tt){
                tem.pb(gra[0].pre[now].sec);
                now = gra[0].pre[now].fir;
            }
            reverse(tem.begin(), tem.end());
            for(auto j : tem) as.pb(j);
            now = i;
            while(gra[1].pre[now].fir){
                as.pb(gra[1].pre[now].sec);
                now = gra[1].pre[now].fir;
            }
            for(auto j : as) printf("%c", 'a' + j);
            puts("");
            return 0;
        }
    }
    puts("-1");
    return 0;
}
