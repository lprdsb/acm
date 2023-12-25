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
#define maxn 400000
#define mod 998244353
using namespace std;

int n, m, k, as = 0;
struct Edge{int v, net;};
int len = 0, hd[maxn + 5];
Edge e[2 * maxn + 5];
void add(int u, int v){
    e[len] = {v, hd[u]};
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

int dfn[maxn + 5], low[maxn + 5], st[maxn + 5], top = 0, tot = 0, col = 0;
void tar(int u){
    st[++top] = u;
    dfn[u] = low[u] = ++tot;
    Tra(u, i){
        int v = e[i].v;
        if(dfn[v]) low[u] = min(low[u], dfn[v]);
        else{
            tar(v);
            low[u] = min(low[u], low[v]);
            if(dfn[u] == low[v]){
                col++;
                cout << col << endl;
                int tmp = 0;
                do{
                    tmp=st[top--];
                    cout << tmp << " ";
                }while(tmp!=v);
                cout << u << endl;
            }
        }
    }
}

int main(){
	// freopen("in.txt", "r", stdin);
    freopen("in.txt", "r", stdin);
    memset(hd, -1, sizeof hd);
    read(n); read(m); read(k);
    For(i, 1, m){
        int u, v; read(u); read(v);
        add(u, v); add(v, u);
    }
    col = n;
    tar(1);
    return 0;
}
