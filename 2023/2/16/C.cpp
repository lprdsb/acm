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
#define maxn 2000
using namespace std;

int n, vis[maxn + 5], pri[maxn + 5], cnt = 0;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int main(){
	//freopen("in", "r", stdin);
    For(i, 2, maxn){
        if(!vis[i]) pri[++cnt] = i;
        for(int j = 1; j <= cnt && i * pri[j] <= maxn; ++j){
            vis[i * pri[j]] = 1;
            if(i % pri[j] == 0) break;
        }
    }
    read(n);
    For(o, 0, n / 2){
        if(!vis[n + o]){
            printf("%d\n", n + o);
            For(i, 1, o) printf("%d %d\n", i, n - i);
            For(i, 1, n - 1) printf("%d %d\n", i, i + 1);
            printf("%d %d\n", 1, n);
            break;
        }
    }
}
