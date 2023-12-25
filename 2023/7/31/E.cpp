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
#define maxn 1000
using namespace std;

int n, m, to[maxn + 5], as[maxn + 5];

struct Edge{
    int v, net;
} e[2 * maxn + 5];

vector<int> ch[maxn + 5];

struct Data{
    int l, r, w;
} a[maxn + 5];
bool operator < (Data _x, Data _y){
    if(_x.l != _y.l) return _x.l < _y.l;
    return _x.r > _y.r;
}

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int st[maxn + 5], top = 0, fl = 1;

void dfs(int u){
    int tem = 0;
    for(auto v : ch[u]){
        dfs(v);
        if(!fl) return;
        tem ^= a[v].w;
    }
    if(!u || tem == a[u].w) return;
    if(ch[u].size()){
        if(a[ch[u][0]].l != a[u].l) swap(to[a[ch[u][0]].l - 1], to[a[ch[u][0]].l]);
        else swap(to[a[ch[u][0]].r + 1], to[a[ch[u][0]].r]);
    }
    else if(a[u].l == a[u].r){
        fl = 0;
        return;
    }
    else swap(to[a[u].l], to[a[u].l + 1]);
}

int main(){
	//freopen("in", "r", stdin);
    read(n); read(m);
    For(i, 1, n) to[i] = i;
    a[0] = {0, n + 1};
    For(i, 1, m) read(a[i].l), read(a[i].r), read(a[i].w);
    sort(a + 1, a + m + 1);
    For(i, 1, m){
        while(top && a[i].l > a[st[top]].r) top--;
        ch[st[top]].pb(i);
        // cout << st[top] << " " << i << endl;
        st[++top] = i;
    }
    dfs(0);
    if(!fl) puts("-1");
    else{
        For(i, 1, n) as[to[i]] = i;
        For(i, 1, n) printf("%d ", as[i]);
    }
    return 0;
}
