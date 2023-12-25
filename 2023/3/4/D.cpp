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

int n, f[maxn + 5], as = 1, a[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

void chkmx(int &x, int y){if(y > x) x = y;}

int main(){
	//freopen("in", "r", stdin);
    read(n);
    For(i, 1, n){
        read(a[i]);
        f[a[i]] = 1;
    }
    For(i, 1, n){
        For(j, 2, maxn){
            int tem = a[i] * j;
            if(tem > maxn) break;
            if(f[tem]) chkmx(f[tem], f[a[i]] + 1);
        } 
    }
    For(i, 1, n) chkmx(as, f[a[i]]);
    printf("%d\n", as);
    return 0;
}
