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

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int T, n, m;

int main(){
	//freopen("in", "r", stdin);
    read(T);
    while(T--){
        read(n); read(m);
        if(n % 2 == 0){
            if(m == n){
                puts("YES");
                For(i, 1, n) printf("1 ");
                puts("");
            }
            else if(m >= 2 * n){
                int now = 1;
                while(2 * now * n <= m) now <<= 1;
                int res = m - now * n;
                puts("YES");
                For(i, 1, n){
                    int tem = min(now - 1, tem);
                    printf("%d ", now + tem);
                    res -= tem;
                }
                puts("");
            }
            else{
                if(m % 2 == 0){
                    puts("YES");
                    For(i, 1, m - n) printf("2 ");
                    For(i, 1, 2 * n - m) printf("1 ");
                    puts("");
                }
                else puts("NO");
            }
        }
        else{
            if(m < n + 3) puts("NO");
            else{
                int now = 1;
                while((n + 3) * now * 2 <= m) now *= 2;
                int res = m - (n + 3) * now;
                int tem = min(res, now - 1);
                printf("%d ", now * 2 + tem);
                res -= tem;
                tem = min(tem, )
            }
        }
    }
}
