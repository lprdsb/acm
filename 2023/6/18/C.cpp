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

int t, n;
char s[2][maxn + 5];

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
    read(t);
    while(t--){
        read(n);
        scanf("%s", s[0] + 1);
        scanf("%s", s[1] + 1);
        int as1 = 0, as2 = 0;
        For(i, 1, n) as1 += s[0][i] != s[1][i];
        if(as1 & 1) as1 = 2 * (as1 - 1) + 1;
        else as1 = 2 * as1;
        For(i, 1, n) as2 += s[0][i] != s[1][n - i + 1];
        if(as2 & 1) as2 = 2 * as2;
        else{
            if(as2) as2 = 2 * (as2 - 1) + 1;
            else as2 = 2;
        }
        printf("%d\n", min(as1, as2));
    }
    return 0;
}
