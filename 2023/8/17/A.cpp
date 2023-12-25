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

int t, n, a[55];
char s[55];

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
        scanf("%s", s + 1); n = strlen(s + 1);
        if(n == 2){
            if(s[1] == '(' && s[2] == ')') puts("NO");
            else if(s[1] == '(' && s[2] == '(')puts("YES\n()()");
            else if(s[1] == ')' && s[2] == ')') puts("YES\n()()");
            else puts("YES\n(())");
            continue;
        }
        puts("YES");
        int fl = 0, sum = 0;
        For(i, 1, n){
            a[i] = s[i] == ')';
            if(a[i] ^ (!(i & 1)) ^ a[1]) fl = 1;
        }
        if(fl){
            For(i, 1, n) printf("()");
            puts("");
        }
        else{
            For(i, 1, n) printf("(");
            For(i, 1, n) printf(")");
            puts("");
        }
    }
}
