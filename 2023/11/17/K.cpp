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
using namespace std;

int m, n, a[2005];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

LL d, as[2005];

int main(){
	//freopen("in", "r", stdin);
    read(m); read(n);
    Rof(i, m, 1){
        char c; cin >> c;
        a[i] = c - '0';
    }
    read(d);
    For(i, 1, m){
        as[i] = d % a[i];
        d /= a[i];
    }
    Rof(i, m, 1) printf("%d", as[i]);
    puts("");
}
