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
#define eps 1e-7
#define maxn 10000
using namespace std;

int t, n, m, a[20], b[20], ok[1024], sta = 0;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int vis[1024];
int dfs(int now){
    vis[now] = 1;
    For(i, 0, n - 1){
        int to = now ^ (1 << i);
        if(ok[to] || vis[to]) continue;
        if(!dfs(to)){
            vis[now] = 0;
            return 1;
        }
    }
    vis[now] = 0;
    return 0;
}

int main(){
    freopen("in.txt", "r", stdin);
    read(t);
    while(t--){
        memset(ok, 0, sizeof ok);
        sta = 0;
        read(n); read(m);
        For(i, 0, n - 1){
            char c; cin >> c;
            a[i] = c - '0';
        }
        For(i, 0, n - 1){
            char c; cin >> c;
            sta |= (c - '0' == a[i]) << i;
        }
        For(i, 1, m){
            int tem = 0;
            For(j, 0, n - 1){
                char c; cin >> c;
                tem |= (c == '=') << j;
            }
            ok[tem] = 1;
        }
        if(dfs(sta)) puts("Alice");
        else puts("Bob");
    }
    return 0;
}
