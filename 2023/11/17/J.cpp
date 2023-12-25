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

int T, a, b, h, w;

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
    read(T);
    while(T--){
        read(a); read(b); read(h); read(w);
        if(w < a) puts("0");
        else if(w <= b) puts("-1");
        else{
            if(1ll * w * w <= 1ll * a * a + 1ll * b * b) puts("0");
            else{
                DD ss = (DD)b / w;
                DD cc = sqrt(1 - ss * ss);
                printf("%.10lf\n", b * cc - a * ss);
            }
        }
    }
    return 0;
}
