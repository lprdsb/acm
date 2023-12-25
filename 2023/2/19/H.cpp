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
#define maxn 100000
using namespace std;

int t, n, pos[maxn + 5], a[maxn + 5];

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
        read(n);
        For(i, 1, n){
            int x; read(x);
            pos[x] = i;
        }
        For(i, 1, n) read(a[i]);
        int pre = n + 1, fl = 0;
        Rof(i, n, 1){
            if(pos[a[i]] <= pre) pre = pos[a[i]];
            else{
                fl = 1;
                printf("%d\n", i);
                break;
            }
        }
        if(!fl) printf("%d\n", 0);
    }
    return 0;
}
