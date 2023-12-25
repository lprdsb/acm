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
#define maxn 500
using namespace std;

int n, m, ma[maxn + 5][maxn + 5], d[maxn + 5], as = inf;
struct Node{
    Node *pre, *net;
    int u, v;
} node[4 * maxn * maxn + 5];


template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

void del(Node *x){
    x->pre->net = x->net;
    if(x->net) x->net->pre = x->pre;
}
void add(Node *x, int val){
    x->net = node[val].net;
    if(node[val].net) node[val].net->pre = x;

    x->pre = &node[val];
    node[val].net = x;
}
int bas = 0;
void mdy(int u){
    For(i, 1, u - 1) if(!ma[i][u]){
        Node *tem = &node[bas + i * n + u];
        del(tem);
        add(tem, d[u] + d[i]);
    }
    For(i, u + 1, n) if(!ma[i][u]){
        Node *tem = &node[bas + u * n + i];
        del(tem);
        add(tem, d[u] + d[i]);
    }
}

int main(){
	// freopen("in.txt", "r", stdin);
    read(n); read(m);
    bas = 2 * n + 1;
    For(i, 1, m){
        int u, v; read(u); read(v);
        ma[u][v] = ma[v][u] = 1;
        d[u]++; d[v]++;
    }
    For(i, 1, n) For(j, i + 1, n) if(!ma[i][j]){
        node[bas + i * n + j].u = i;
        node[bas + i * n + j].v = j;
        add(&node[bas + i * n + j], d[i] + d[j]);
    }
    while(666){
        int fl = 0;
        Node *now;
        Rof(i, 2 * n, 0) if(node[i].net){
            fl = 1;
            now = node[i].net;
            as = min(as, i);
            break;
        }
        if(!fl) break;
        del(now);
        d[now->u]++; d[now->v]++;
        ma[now->u][now->v] = 1;
        ma[now->v][now->u] = 1;
        mdy(now->u); mdy(now->v);
    }
    printf("%d\n", as);
    return 0;
}
