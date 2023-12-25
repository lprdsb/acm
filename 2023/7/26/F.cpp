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
#define maxn 4000
using namespace std;

int t, n, m, fa[maxn + 5], ma[maxn + 5][maxn + 5];
pair<int, int> a[2][maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int find(int x){return fa[x] == x ? x : fa[x] = find(fa[x]);}

int l[maxn + 5], r[maxn + 5];

int mx[maxn + 5], to[2][maxn + 5], pre[maxn + 5];
    int tot = 0;
int sol(){
    For(i, 1, n) if(!to[1][i]) pre[i] = 0;
    For(i, 0, n) r[i] = i + 1;
    For(i, 1, n + 1) l[i] = i - 1; 
    Rof(i, n, 1) if(!to[0][i]){
        queue<int> q; q.push(i);
        while(q.size()){
            int u = q.front(); q.pop();
            int v = l[n + 1];
            // tot++;
            while(v){
                if(!ma[a[0][u].sec][v]){
                    // tot++;
                    // if(tot % 10000000 == 0) cout << tot << endl;
                    r[l[v]] = r[v];
                    l[r[v]] = l[v];
                    pre[v] = u;
                    mx[v] = i;
                    if(to[1][v]) q.push(to[1][v]);
                };
                v = l[v];
            }
        }
    }
    // cout << tot << endl;
    // For(i, 1, n) fa[i] = i;
    int tem = 0;
    For(i, 1, n) if(!to[1][i] && pre[i]){
        if(!tem || a[0][mx[i]].fir + a[1][i].fir >= a[0][mx[tem]].fir + a[1][tem].fir) tem = i;
    }
    if(!tem) return -1;
    int now = tem;
    while(now){
        // tot++;
        // if(tot % 10000000 == 0) cout << tot << endl;
        int tem1 = to[0][pre[now]];
        to[1][now] = pre[now];
        to[0][pre[now]] = now;
        now = tem1;
    }
    return a[0][mx[tem]].fir + a[1][tem].fir;
}

int main(){
    // freopen("in.txt", "r", stdin);
    memset(to, 0, sizeof to);
    For(i, 1, maxn) fa[i] = i;
    read(t);
    while(t--){
        read(n); read(m);
        For(o, 0, 1){
            For(i, 1, n) read(a[o][i].fir), a[o][i].sec = i;
            if(!o) sort(a[o] + 1, a[o] + n + 1);
        }
        For(i, 1, m){
            int u, v; read(u); read(v);
            ma[u][v] = 1;
        }
        LL asi = 0, fl = 0;
        For(i, 1, n){
            if(fl){
                puts("-1");
                continue;
            }
            int tem = sol();
            if(tem == -1){
                puts("-1");
                fl = 1;
                continue;
            }
            printf("%lld\n", asi += tem);
        }
        For(i, 1, n) For(j, 1, n) ma[i][j] = 0;
        For(i, 1, n) to[0][i] = to[1][i] = 0;
    }
    return 0;
}
