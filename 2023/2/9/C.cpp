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
#define maxn 50
using namespace std;

int n, m;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int now = 1, opt[maxn + 5];
int que(int x){
    int asi = 0;
    printf("%d\n", x);
    fflush(stdout);
    read(asi);
    if(!asi) exit(0);
    if(opt[now]) asi = -asi;
    if(now == m) now = 1;
    else now++;
    return asi;
}

int main(){
	//freopen("in", "r", stdin);
    read(n); read(m);
    For(i, 1, m){
        printf("1\n");
        fflush(stdout);
        int x; read(x);
        if(!x) return 0;
        if(x == -1) opt[i] = 1;
    }
    int l = 2, r = n;
    while(l < r){
        int mid = l + r >> 1;
        if(que(mid) == -1) r = mid;
        else l = mid + 1;
    }
    que(l);
    return 0;
}
