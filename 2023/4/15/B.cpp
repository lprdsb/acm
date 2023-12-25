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

int n, m, hd[maxn + 5], len = 0;
struct Edge{int v, net;} e[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

void add(int u, int v){
    e[len] = {v, hd[u]};
    hd[u] = len++;
}

int ok[maxn + 5], in[maxn + 5], vis[maxn + 5];

int main(){
	// freopen("in.txt", "r", stdin);
    memset(hd, -1, sizeof hd);
    read(n); read(m);
    For(i, 1, m){
        int u, v; read(u); read(v);
        if(u == v){
            if(ok[u]){
                puts("Yes");
                return 0;
            }
            ok[u]= 1, vis[u] = 1;
        }
        else in[v]++, add(u, v);
    }
    int cnt = 0;
    queue<int> q;
    For(i, 1, n) if(!in[i]) q.push(i);
    while(q.size()){
        int u = q.front(); q.pop();
        cnt++;
        Tra(u, i){
            int v = e[i].v;
            if(vis[u]){
                vis[v] = 1;
                if(ok[v]){
                    puts("Yes");
                    return 0;
                }
            }
            in[v]--;
            if(!in[v]) q.push(v);
        }
    }
    puts(cnt == n ? "No" : "Yes");
	return 0;
}
