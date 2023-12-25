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

int n;
DD pi = acos(-1.0);
pair<DD, DD> pa[2 * maxn + 5];

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
    read(n);
    For(i, 1, n){
        int x, y, r; read(x); read(y); read(r);
        if(1ll * x * x + 1ll * y * y <= 1ll * r * r){
            puts("Yes");
            return 0;
        }
        DD tem = atan2(x, y), tem1 = asin(r/sqrt((DD)x * x + (DD)y * y));
        pa[i] = {tem - tem1, tem + tem1};
    }
    sort(pa + 1, pa + n + 1);
    For(i, 1, n) pa[n + i] = pa[i];
    For(i, 1, n){
        DD tem = pa[i + n - 1].sec - pa[i].fir;
        while(tem < 0) tem += 2 * pi;
        if(tem < pi){
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    return 0;
}
