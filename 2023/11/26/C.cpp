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

int n;
LL d;

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
    read(n); read(d);
    LL sum = 0;
    int fl = 0;
    For(i, 1, n){
        sum += i - 1;
        if(n - i <= d - sum && 1ll * (n - i) * (i - 1) >= d - sum){
            puts("YES");
            fl = 1;
            For(j, 1, i - 1) printf("%d %d\n", j, j + 1);
            LL res = d - sum;
            int now = i, cnt = 0;
            while(n - i - cnt != (res - cnt + (i - 2)) / (i - 1)){
                printf("1 %d\n", ++now);
                cnt++;
            }
            // break;
            res -= cnt;
            // cout << res << " asd " << n - i - cnt << endl;
            // cout << res % (i - 1) << endl;
            if(res % (i - 1)) printf("%d %d\n", res % (i - 1), ++now);
            For(j, now + 1, n) printf("%d %d\n", i - 1, j);
            puts("1");
            break;
        }
    }
    if(!fl) puts("NO");
}
