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

int t, n, m, d, a[maxn + 5];

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
        read(n); read(m); read(d);
        For(i, 1, m) read(a[i]); a[m + 1] = n + 1;
        int now = a[1] == 1;
        a[0] = 1;
        int as = 0;
        For(i, now, m){
            as += (a[i + 1] - a[i] - 1) / d + 1;
        }
        int res = as, ok = 0;
        For(i, 1, m){
            int tem;
            if(a[i] != 1) tem = res - (a[i + 1] - a[i] - 1) / d - (a[i] - a[i - 1] - 1) / d + (a[i + 1] - a[i - 1] - 1) / d - 1;
            else tem = res;
            // if(i == 1) cout << tem << endl;
            if(tem < as){
                as = tem;
                ok = 1;
            }
            else if(tem == as) ok++;
        }
        printf("%d %d\n", as, ok);
    }
    return 0;
}
