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
#define maxn 5000
using namespace std;

int n, f[maxn + 5][4];
char s[maxn + 5];

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
    scanf("%s", s + 1); n = strlen(s + 1);
    f[0][0] = 0;
    For(i, 1, n){
        For(j, 0, 3) f[i][j] = f[i - 1][j];
        if(s[i] == 'a'){
            f[i][1] = max(f[i][1], max(f[i - 1][0], f[i - 1][1]) + 1);
            f[i][3] = max(f[i][3], max(f[i - 1][2], f[i - 1][3]) + 1);
        }
        else f[i][2] = max(f[i][2], max(f[i - 1][2], f[i - 1][1]) + 1);
    }
    int as = 0;
    For(i, 0, 3) as = max(as, f[n][i]);
    printf("%d\n", as);
    return 0;
}
