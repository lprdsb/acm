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
#define maxn 100
using namespace std;

int q;
LL a[3][maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int sol(LL x){
    int asi = 0;
    while(x) x >>= 1, asi++;
    return asi - 1; 
}

int main(){
	//freopen("in", "r", stdin);
    read(q);
    while(q--){
        int t; LL x, k;
        read(t);
        if(t <= 2){
            read(x); read(k);
            if(t == 1) k *= -1;
            int tem = sol(x);
            k &= ((1ll << tem) - 1);
            //cout << k << endl;
            a[t][tem] += k;
            a[t][tem] &= ((1ll << tem) - 1);
        }
        else{
            read(x);
            int tem = sol(x);
            x = (1ll << tem) + ((x - a[1][tem]) & ((1ll << tem) - 1));
            while(x){
                printf("%lld ", (1ll << tem) + ((x + a[1][tem]) & ((1ll << tem) - 1)));
                x = (1ll << tem) + ((x + a[2][tem]) & ((1ll << tem) - 1));
                x >>= 1;
                tem--;
            }
            puts("");
        }
    }
}
