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

int n, m, a[4 * maxn + 5];
vector<pair<int, int> > ch[4 * maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int dis[4 * maxn + 5];

int main(){
	// freopen("in.txt", "r", stdin);
    memset(dis, -1, sizeof dis);
    read(n); read(m);
    For(i, 1, n){
        read(a[i]);
        ch[i].pb({n + 1 + a[i], 1});
        ch[n + 1 + a[i]].pb({i, 0});
    }
    For(i, 0, maxn) For(o, 0, 20) if((i >> o) & 1) ch[n + 1 + i].pb({n + 1 + (i ^ (1 << o)), 0});
    // cout << "asd" << endl;
    For(i, 1, m){
        int u, v; read(u); read(v);
        ch[u].pb({v, 1});
    }
    deque<int> q;
    q.push_back(1);
    dis[1] = 0;
    while(q.size()){
        int u = q.front(); q.pop_front();
        for(auto [v, w] : ch[u]) if(dis[v] == -1 || dis[v] > dis[u] + w){
            dis[v] = dis[u] + w;
            if(w) q.push_back(v);
            else q.push_front(v);
        }
    }
    For(i, 1, n) printf("%d\n", dis[i]);
    return 0;
}
