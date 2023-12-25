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

int n;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

char s[maxn + 5];
int a[maxn + 5][maxn + 5];

bool chk(int x, int y){
    For(i, 1, n + 1) if(a[x][i] != a[y][i]) return a[x][i] < a[y][i];
    return 0;
}

int main(){
	//freopen("in", "r", stdin);
    read(n);
    scanf("%s", s + 1);
    For(i, 1, n){
        int fl = 0;
        For(j, i, n){
            if(s[j] != 'z' && !fl){
                a[i][j - i + 1] = 26;
                fl = 1;
            } 
            else a[i][j - i + 1] = s[j] - 'a' + 1;
        }
    }
    int mx = 0;
    For(i, 1, n){
        if(!mx || chk(mx, i)) mx = i;
    }
    For(i, 1, n - mx + 1) printf("%c", 'a' + a[mx][i] - 1);
    return 0;
}
