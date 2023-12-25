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

int T, n, m, in[2][maxn + 5], a[maxn + 5];
vector<int> ch[2][maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int l[maxn + 5], r[maxn + 5];

vector<pair<int, int> > vec[maxn + 5];

int main(){
    // cout << -inf << endl;
	// freopen("in.txt", "r", stdin);
    memset(l, -inf, sizeof l);
    memset(r, inf, sizeof r);
    read(T);
    while(T--){
        read(n); read(m);
        For(i, 1, n){
            read(a[i]);
            if(a[i]) l[i] = r[i] = a[i];
        }
        For(i, 1, m){
            int u, v; read(u); read(v);
            ch[0][u].pb(v); in[0][v]++;
            ch[1][v].pb(u); in[1][u]++;
        }
        For(o, 0, 1){
            queue<int> q;
            For(i, 1, n) if(!in[o][i]){
                if(!o) l[i] = max(l[i], 1);
                else r[i] = min(r[i], n);
                q.push(i);
            }
            while(q.size()){
                int u = q.front(); q.pop();
                for(auto v : ch[o][u]){
                    if(!o) l[v] = max(l[v], l[u] + 1);
                    else r[v] = min(r[v], r[u] - 1);
                    in[o][v]--;
                    if(!in[o][v]) q.push(v);
                }
            }
        }
        int fl = 0;
        For(i, 1, n){
            if(l[i] <= r[i] && l[i] >= 1 && r[i] <= n) vec[l[i]].pb({r[i], i});
            else{
                fl = 1;
                break;
            }
        }
        priority_queue<pair<int, int> > q;
        For(i, 1, n){
            for(auto [to, id] : vec[i]) q.push({-to, id});
            if(!q.size()){
                fl = 1;
                break;
            }
            pair<int, int> pa = q.top(); q.pop();
            if(-pa.fir < i){
                fl = 1;
                break;
            }
            a[pa.sec] = i;
        }
        if(fl) puts("-1");
        else{
            For(i, 1, n) printf("%d ", a[i]);
            puts("");
        }
        For(i, 1, n){
            vec[i].resize(0);
            l[i] = -inf;
            r[i] = inf;
            For(o, 0, 1){
                in[o][i] = 0;
                ch[o][i].resize(0);
            }
        }
    }
}
