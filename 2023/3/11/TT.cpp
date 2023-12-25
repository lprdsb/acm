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

int n, m, hd[maxn + 5], len = 0, a[maxn + 5];
struct Edge{int v, w, net;} e[2 * maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

void add(int u, int v, int w){
    e[len] = {v, w, hd[u]};
    hd[u] = len++;
}

int st[maxn + 5], top;
DD ok, as[maxn + 5];
pair<int, int> sta[maxn + 5];
int dfs(int u){
    st[++top] = u;
    Tra(u, i){
        int v = e[i].v, w = e[i].w;
        pair<int, int> tem = sta[u];
        tem.fir *= -1;
        tem.sec = w - tem.sec;
        if(!sta[v].fir){
            sta[v] = tem;
            if(!dfs(v)) return 0;
        }
        else if(sta[v] != tem){
            DD tem1 = (DD)(sta[v].sec - tem.sec) / (2 * tem.fir);
            // cout << u << " " << v << endl;
            if(ok == 114514 || fabs(tem1 - ok) <= eps) ok = tem1;
            else return 0;
        }
    }
    return 1;
}

int main(){
	//freopen("in", "r", stdin);
    memset(hd, -1, sizeof hd);
    read(n); read(m);
    For(i, 1, m){
        int u, v, w; read(u); read(v); read(w);
        add(u, v, w); add(v, u, w);
    }
    For(i, 1, n) if(!sta[i].fir){
        top = 0;
        sta[i] = {1, 0};
        ok = 114514;
        if(!dfs(i)){
            puts("NO");
            return 0;
        }
        // cout << ok << endl;
        if(ok == 114514){
            For(i, 1, top) a[i] = -sta[st[i]].fir * sta[st[i]].sec;
            sort(a + 1, a + top + 1);
            ok = a[(1 + top) >> 1];
        }
        For(i, 1, top) as[st[i]] = sta[st[i]].fir * ok + sta[st[i]].sec;
    }
    puts("YES");
    For(i, 1, n) printf("%.2lf ", as[i]);
    return 0;
}
