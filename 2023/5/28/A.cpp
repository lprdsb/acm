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

int t, n, hd[maxn + 5], len = 0, ok[maxn + 5];
struct Edge{int v, net, id;} e[2 * maxn + 5];
void add(int u, int v, int id){
    e[len] = {v, hd[u], id};
    hd[u] = len++;
}

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
    len = 0;
    memset(hd, -1, sizeof hd);
    read(t);
    while(t--){
        read(n);
        For(i, 1, n - 1){
            int u, v; read(u); read(v);
            add(u, v, i); add(v, u, i);
        }
        priority_queue<pair<int, int> > q[2];
        int asi = 0, o = 0;
        q[0].push({0, 1});
        while(q[o].size()){
            asi++;
            int now = 0;
            while(q[o].size()){
                pair<int, int> pa = q[o].top(); q[o].pop();
                if(-pa.fir >= now){
                    now = -pa.fir;
                    ok[pa.sec] = 1;
                    Tra(pa.sec, i){
                        int v = e[i].v, id = e[i].id;
                        if(ok[v]) continue;
                        q[o].push({-id, v});
                    }
                }
                else q[o ^ 1].push(pa);
            }
            o ^= 1;
        } 
        printf("%d\n", asi);
        For(i, 1, n){
            hd[i] = -1;
            ok[i] = 0;
        }
        len = 0;
    }
	return 0;
}
