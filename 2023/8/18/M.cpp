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

int a, b, c;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int main(){ 
	// freopen("in.txt", "r", stdin);
    read(a); read(b); read(c);
    if(a + b == c) printf("Yes\n%d + %d = %d", a, b, c);
    else{
        int tem = a, pw = 1;
        while(tem){
            For(o, 0, 9) if(a / pw * pw * 10 + o * pw + a % pw + b == c){
                puts("Yes");
                if(pw != 1) printf("%d%d%d + %d = %d", a / pw, o, a % pw, b, c);
                else printf("%d%d + %d = %d", a, o, b, c);
                return 0;
            }
            tem /= 10;
            pw *= 10;
        }
        For(o, 0, 9) if(o * pw + a + b == c){
            puts("Yes");
            printf("%d%d + %d = %d", o, a, b, c);
            return 0;
        }

        tem = b, pw = 1;
        while(tem){
            For(o, 0, 9) if(a + b / pw * pw * 10 + o * pw + b % pw == c){ 
                puts("Yes");
                if(pw != 1) printf("%d + %d%d%d = %d", a, b / pw, o, b % pw, c);
                else printf("%d + %d%d = %d", a, b, o, c);
                return 0;
            }
            tem /= 10;
            pw *= 10;
        }
        For(o, 0, 9) if(o * pw + a + b == c){
            puts("Yes");
            printf("%d + %d%d = %d", a, o, b, c);
            return 0;
        }

        tem = c, pw = 1;
        while(tem){
            For(o, 0, 9) if(a + b == c / pw * pw * 10 + o * pw + c % pw){ 
                puts("Yes");
                if(pw != 1) printf("%d + %d = %d%d%d", a, b, c / pw, o, c % pw);
                else printf("%d + %d = %d%d", a, b, c, o);
                return 0;
            }
            tem /= 10;
            pw *= 10;
        }
        For(o, 0, 9) if(a + b == o * pw + c){
            puts("Yes");
            printf("%d + %d = %d%d", a, b, o, c);
            return 0;
        }
    }
    puts("No");
}
