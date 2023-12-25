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

int as = inf;
LL n, bas[20];
char s[20];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

void dfs(int pos, LL now, int asi){
    if(now == n){
        as = min(as, asi);
        return;
    }
    if(pos == 0) return;
    if(now > n){
        while(now - bas[pos] >= n) now -= bas[pos], asi += pos;
        dfs(pos - 1, now, asi);
        dfs(pos - 1, now - bas[pos], asi + pos);
    }
    else{
        while(now + bas[pos] <= n) now += bas[pos], asi += pos;
        dfs(pos - 1, now, asi);
        dfs(pos - 1, now + bas[pos], asi + pos);
    }
}

int main(){
	//freopen("in", "r", stdin);
    read(n);
    For(i, 1, 16) bas[i] = 10 * bas[i - 1] + 1;
    dfs(16, 0, 0);
    printf("%d\n", as);
    return 0;
}
