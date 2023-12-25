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

int n, m, deg[maxn + 5];
vector<int> ma[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int main(){
	//freopen("in", "r", stdin);
    read(n); read(m);
    For(i, 1, m){
        int u, v; read(u); read(v);
        ma[u].pb(v);
        deg[v]++;
    }
    queue<int> q;
    For(i, 1, n) if(!deg[i]) q.push(i);
    int cnt = 0;
    vector<int> as;
    while(q.size()){
        int u = q.front(); q.pop();
        as.pb(u);
        for(auto v : ma[u]){
            deg[v]--;
            if(!deg[v]) q.push(v);
        }
    }
    if(as.size() == n){
        puts("1");
        for(auto i : as) printf("%d ", i);
    }
    else{
        puts("2");
        For(i, 1, n) printf("%d ", i); puts("");
        For(i, 1, n) printf("%d ", n - i + 1);
    }
    return 0;
}
