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

int t, n, mx[2], mn[2];

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
    read(t);
    while(t--){
        mx[0] = mx[1] = -100000;
        mn[0] = mn[1] = 100000;
        read(n);
        For(i, 1, n){
            int x, y, f1, f2, f3, f4; read(x); read(y); read(f1); read(f2); read(f3); read(f4);
            if(!f1) mx[0] = max(mx[0], x);
            if(!f2) mn[1] = min(mn[1], y);
            if(!f3) mn[0] = min(mn[0], x);
            if(!f4) mx[1] = max(mx[1], y);
        }
        if(mx[0] <= mn[0] && mx[1] <= mn[1]) printf("1 %d %d\n", mx[0], mx[1]);
        else puts("0");
    }
    return 0;
}
