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
#define maxn 200000
using namespace std;

int n, m, s, ok[maxn + 5][2], sum[maxn + 5], as[2][maxn + 5];

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
    read(n); read(m); read(s);
    For(i, 1, m){
        int l, r; read(l); read(r);
        if(l <= s){
            sum[l]++;
            sum[min(s, r)]--;
            if(l != s) ok[l][0] = 1;
        }
        if(r >= s){
            sum[r + 1]--;
            sum[max(s + 1, l + 1)]++;
            if(r != s) ok[r][1] = 1;
        }
    }
    For(i, 1, n) sum[i] += sum[i - 1];
    Rof(i, s - 1, 1){
        if(!sum[i]) break;
        if(ok[i][0]) as[0][++as[0][0]] = i;
    }
    For(i, s + 1, n){
        if(!sum[i]) break;
        if(ok[i][1]) as[1][++as[1][0]] = i;
    }
    Rof(i, as[0][0], 1) printf("%d ", as[0][i]);
    For(i, 1, as[1][0]) printf("%d ", as[1][i]);
	return 0;
}
