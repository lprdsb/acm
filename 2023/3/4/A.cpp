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

int n, m, a[maxn + 5][maxn + 5], as = inf;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int vis[maxn + 5];
int sol(){
    int asi = inf, sum = 0;
    For(i, 1, m) vis[i] = 0;
    For(i, 1, m) if(a[1][i]) vis[i] = 1, sum++;
    For(i, 2, n){
        int cnt = 0;
        For(j, 1, m) cnt += !(a[i][j] ^ vis[j]);
        if(!cnt) sum++;
        else if(cnt != m) break;
        if(i == n) asi = min(asi, sum);
    }
    sum = 1;
    For(i, 1, m) vis[i] = 0;
    For(i, 1, m) if(!a[1][i]) vis[i] = 1, sum++;
    For(i, 2, n){
        int cnt = 0;
        For(j, 1, m) cnt += !(a[i][j] ^ vis[j]);
        if(!cnt) sum++;
        else if(cnt != m) break;
        if(i == n) asi = min(asi, sum);
    }
    return asi;
}

int main(){
	//freopen("in", "r", stdin);
    read(n); read(m);
    For(i, 1, n) For(j, 1, m){
        char c; cin >> c;
        a[i][j] = c == 'B';
    }
    as = min(as, sol());
    For(i, 1, n) For(j, 1, m) a[i][j] ^= 1;
    as = min(as, sol());
    if(as != inf) printf("%d\n", as);
    else puts("-1");
    return 0;
}
