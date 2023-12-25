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

int T, n, a[maxn + 5];

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
    read(T);
    while(T--){
        read(n);
        For(i, 1, n) read(a[i]);
        sort(a + 1, a + n + 1);
        LL res = 0, sum = 0, l = 1, r = n;
        while(l < r){
            res += a[l];
            sum += a[l++];
            if(sum >= a[r]){
                sum -= a[r];
                res++;
                r--;
            }
        }
        // cout << l << " " << r << " " << res << " " << sum << endl;
        if(l <= r){
            int tem = (sum + a[l]) >> 1;
            res += tem - sum;
            if(a[l] == 1) res++;
            else{
                if((sum + a[l]) & 1) res += 2;
                else res += 1;
            }
        }
        else{
            if(sum > 1) res += sum / 2 + 1 + (sum & 1) - sum;
        }
        printf("%lld\n", res);
    }
    return 0;
}
