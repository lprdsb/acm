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
#define maxn 40000
using namespace std;

int a, b, c, n, m;
vector<int> ch[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int dis[3][maxn + 5], s[3];

int main(){
	//freopen("in", "r", stdin);
    read(a); read(b); read(c);
    read(s[0]); read(s[1]); read(n); read(m);
    s[2] = n;
    For(i, 1, m){
        int u, v; read(u); read(v);
        ch[u].pb(v); ch[v].pb(u);
    }
    memset(dis, inf, sizeof dis);
    For(o, 0, 2){
        queue<int> q;
        q.push(s[o]);
        dis[o][s[o]] = 0;
        while(q.size()){
            int u = q.front(); q.pop();
            for(auto v : ch[u]) if(dis[o][v] > dis[o][u] + 1){
                dis[o][v] = dis[o][u] + 1;
                q.push(v);
            }
        }
    }
    int fl = 0;
    LL res = Inf;
    For(i, 1, n){
        if(dis[0][i] != inf && dis[1][i] != inf && dis[2][i] != inf) fl = 1;
        res = min(res, 1ll * a * dis[0][i] + 1ll * b * dis[1][i] + 1ll * (a + b - c) * dis[2][i]);
    }
    if(fl) printf("%lld\n", res);
    else puts("-1");
    return 0;
}
