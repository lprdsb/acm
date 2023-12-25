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
#define maxn 300000
using namespace std;

int t, n, a[maxn + 5], ok[2 * maxn + 5], mx[2 * maxn + 5];

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
    memset(ok, -1, sizeof ok);
    read(t);
    while(t--){
        read(n);
        For(i, 1, n) read(a[i]);
        int now = 0;
        ok[n + 1] = 0;
        Rof(i, n, 1){
            mx[i] = max(now + 1, mx[i + a[i] + 1] + 1);
            if(ok[i + a[i] + 1] != -1) ok[i] = ok[i + a[i] + 1] + 1, now = max(now, ok[i]);
        }
        For(i, 1, n - 1){
            if(ok[i + 1] == a[i]) printf("0 ");
            else if(mx[i + 1] >= a[i] || ok[i + 1] != -1) printf("1 ");
            else printf("2 ");
        }
        puts("");
        For(i, 1, n + 1) ok[i] = mx[i] = -1;
    }
    return 0;
}
