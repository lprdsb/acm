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

int t, n;

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
        if(n == 2) puts("1 2");
        else if(n == 3) puts("1 2 3");
        else if(n == 4) puts("1 2 3 4");
        else if(n == 5) puts("5 2 1 4 3");
        else if(n == 6) puts("4 1 6 3 2 5");
        else if(n == 7) puts("7 4 1 6 3 2 5");
        else if(n == 8) puts("7 4 1 2 5 8 3 6");
        else if(n == 9) puts("7 4 9 6 3 2 1 8 5");
        else if(n == 10) puts("10 7 4 9 6 3 2 1 8 5");
        else if(n == 11) puts("11 4 9 6 3 2 1 8 5 10 7");
        else{
            if(n % 3 <= 1){
                int now;
                if(n % 3){
                    printf("%d ", n);
                    now = n - 3;
                }
                else now = n - 2;
                printf("%d ", now);
                now -= 3;
                printf("%d ", now);
                now += 5;
                while(now != 3){
                    printf("%d ", now);
                    now -= 3;
                }
                printf("%d ", now);
                printf("2 ");
                now = 1;
                while(now <= n - 8){
                    printf("%d ", now);
                    now += 3;
                }
                now -= 3;
                now += 7;
                while(now != 2){
                    printf("%d ", now);
                    now -= 3;
                }
                puts("");
            }
            else{
                int now = n;
                printf("%d ", now);
                now -= 7;
                printf("%d ", now);
                now += 5;
                while(now != 3){
                    printf("%d ", now);
                    now -= 3;
                }
                printf("3 2 ");
                now = 1;
                while(now != n - 10){
                    printf("%d ", now);
                    now += 3;
                }
                printf("%d ", now);
                now += 7;
                printf("%d ", now);
                now -= 3;
                printf("%d ", now);
                now += 5;
                printf("%d ", now);
                now -= 3;
                printf("%d ", now);
                now -= 5;
                while(now != 5){
                    printf("%d ", now);
                    now -= 3;
                }
                puts("5");
            }
        }
    }
}
