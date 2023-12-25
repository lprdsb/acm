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

int n, k, hd[maxn + 5], len = 0, a[maxn + 5];
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

int son[maxn + 5], mx[maxn + 5];
void dfs(int u, int pre){
    Tra(u, i){
        int v = e[i].v;
        if(v == pre) continue;
        dfs(v, u);
        if(mx[v] > mx[son[u]]) son[u] = v;
    }
    mx[u] = mx[son[u]] + 1;
}

int l[maxn + 5], top_st, lpr[maxn + 5];
LL sum[maxn + 5];
pair<int, LL> st[maxn + 5];
vector<pair<int, LL> > vec[maxn + 5]; 
void dfs1(int u, int pre, int top){
    LL tem = 0;
    if(son[u]){
        dfs1(son[u], u, top);
        tem += sum[top];
        lpr[top]++;
        if(vec[top][l[top]].fir + lpr[top] > k + 1) sum[top] -= vec[top][l[top]++].sec;
    }
    if(l[top] <= (int)vec[top].size() - 1 && vec[top][vec[top].size() - 1].fir + lpr[top] == 1)
        vec[top][vec[top].size() - 1].sec += a[u], sum[top] += a[u];
    else vec[top].pb(mp(1 - lpr[top], a[u])), sum[top] += a[u];
    Tra(u, i){
        int v = e[i].v;
        if(v == pre || v == son[u]) continue;
        dfs1(v, u, v);
        tem += sum[v];
        lpr[v]++;
        if(vec[v][l[v]].fir + lpr[v] > k + 1) l[v]++;
        top_st = 0;
        int now = vec[top].size() - 1;
        Rof(j, (int)vec[v].size() - 1, l[v]){
            while(now >= l[top] && vec[top][now].fir + lpr[top] < vec[v][j].fir + lpr[v]){
                st[++top_st] = vec[top][now];
                sum[top] -= vec[top][now].sec;
                vec[top].pop_back();
                now--;
            }
            if(now >= l[top] && vec[top][now].fir + lpr[top] == vec[v][j].fir + lpr[v]){
                st[++top_st] = vec[top][now];
                st[top_st].sec += vec[v][j].sec;
                sum[top] -= vec[top][now].sec;
                vec[top].pop_back();
                now--;
            }
            else{
                st[++top_st] = vec[v][j];
                st[top_st].fir += lpr[v] - lpr[top];
            }
        }
        while(top_st){
            vec[top].pb(st[top_st]);
            sum[top] += st[top_st].sec;
            top_st--;
        }
    }
    // if(u == 2){
    //     Rof(i, vec[top].size() - 1, l[top]) cout << vec[top][i].fir + lpr[top] << " " << vec[top][i].sec << endl;
    // }
    LL now = 0;
    while(l[top] <= (int)vec[top].size() - 1 && vec[top][vec[top].size() - 1].sec + now <= tem){
        now += vec[top][vec[top].size() - 1].sec;
        sum[top] -= vec[top][vec[top].size() - 1].sec;
        vec[top].pop_back();
    }
    if(l[top] <= (int)vec[top].size() - 1)
        vec[top][vec[top].size() - 1].sec -= tem - now, sum[top] -= tem - now;
    vec[top].pb(mp(0 - lpr[top], tem));
    sum[top] += tem;
}

int main(){
	// freopen("in.txt", "r", stdin);
    memset(hd, -1, sizeof hd);
    read(n); read(k);
    For(i, 1, n) read(a[i]);
    For(i, 1, n - 1){
        int u, v; read(u); read(v);
        add(u, v); add(v, u);
    }
    dfs(1, 0);
    dfs1(1, 0, 1);
    printf("%lld\n", sum[1]);
    return 0;
}
