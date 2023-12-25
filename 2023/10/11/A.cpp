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
#define maxn 50
using namespace std;

int t, n, m, k, a[maxn + 5], b[maxn + 5];

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
        read(n); read(m); read(k);
        For(i, 1, n) read(a[i]); sort(a + 1, a + n + 1);
        For(i, 1, m) read(b[i]); sort(b + 1, b + m + 1);
        For(_, 1, k){
            // cout << _ << endl;
            if(_ & 1){
                if(a[1] <= b[1] && a[n] <= b[m]){

                    if((k - _ + 1) & 1) swap(a[1], b[m]);
                    break;
                }
                if(a[1] < b[m]){
                    swap(a[1], b[m]);
                    For(i, 1, n - 1) if(a[i] > a[i + 1]) swap(a[i], a[i + 1]);
                    Rof(i, m, 2) if(b[i] < b[i - 1]) swap(b[i], b[i - 1]);
                }
            }
            else{
                if(b[1] <= a[1] && b[m] <= a[n]){
                    if((k - _ + 1) & 1) swap(b[1], a[n]);
                    break;
                }
                if(b[1] < a[n]){
                    swap(b[1], a[n]);
                    For(i, 1, m - 1) if(b[i] > b[i + 1]) swap(b[i], b[i + 1]);
                    Rof(i, n, 2) if(a[i] < a[i - 1]) swap(a[i], a[i - 1]);
                }
            }
        }
        LL res = 0;
        For(i, 1, n) res += a[i];
        printf("%lld\n", res);
    }
    return 0;
}
