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
#define maxn 3000
using namespace std;

int t, n, a[maxn + 5][maxn + 5], b[maxn + 5][maxn + 5], s[maxn + 5][maxn + 5];

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
        For(i, 1, n) For(j, 1, n){
            char c; cin >> c;
            a[i][j] = c - '0';
        }
        int res = 0;
        For(i, 1, n) For(j, 1, n){
            int tem = 0;
            if(i >= 2 && j >= 2) tem ^= s[i - 1][j - 1];
            if(i >= 2 && j + 1 <= n) tem ^= s[i - 1][j + 1];
            if(i >= 3 && j >= 2 && j + 1 <= n) tem ^= s[i - 2][j];
            if(i >= 2) tem ^= b[i - 1][j];
            // if(tem ^ a[i][j]) cout << i << " " << j << endl;
            res += tem ^ a[i][j];
            b[i][j] = tem ^ a[i][j];
            s[i][j] = a[i][j];
        }
        printf("%d\n", res);
    }
    return 0;
}
