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

int t, a[maxn + 5], n, val[10] = {1, 10, 100, 1000, 10000}, num[10], mx[maxn + 5];
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
	freopen("in.txt", "r", stdin);
    read(t);
    while(t--){
        scanf("%s", s + 1); n = strlen(s + 1);
        LL sum = 0;
        For(i, 1, n) a[i] = s[i] - 'A';
        mx[n + 1] = 0;
        Rof(i, n, 1){
            mx[i] = max(a[i], mx[i + 1]);
            if(a[i] == mx[i]) sum += val[a[i]];
            else sum -= val[a[i]];
        }
        For(i, 0, 4) num[i] = 0;
        LL as = -inf;
        For(i, 1, n){
            sum -= (a[i] == mx[i] ? 1 : -1) * val[a[i]];
            LL asi = sum;
            For(j, 0, mx[i + 1] - 1) asi -= 1ll * num[j] * val[j];
            For(j, mx[i + 1], 4) asi += 1ll * num[j] * val[j];
            For(j, mx[i + 1], 4){
                as = max(as, asi + val[j]);
                asi -= 2ll * num[j] * val[j];
            }
            For(j, 0, a[i] - 1){
                sum -= 1ll * val[j] * num[j];
                num[j] = 0;
            }
            num[a[i]]++;
        }
        printf("%lld\n", as);
    }
    return 0;
}
