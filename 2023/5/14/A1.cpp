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
#define maxn 1000000
using namespace std;

int n, w, a[maxn + 5], num[maxn + 5], sum[maxn + 5];

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
    // freopen("out1.txt", "w", stdout);
    read(n); read(w);
    num[0] = n;
    int mx = 0;
    For(i, 1, w){
        int k; read(k);
        For(j, 1, k){
            int c; read(c);
            num[a[c]]--;
            a[c]++;
            mx = max(mx, a[c]);
            num[a[c]]++;
        }
        For(j, 1, n) For(p, a[j] + 1, mx) sum[j] += num[p];
        // if(i == 1) cout << sum[1] << endl;
    }
    // cout << sum[1] << endl;
    For(i, 1, n) printf("%.6lf\n", (DD)sum[i] / w + 1);
	return 0;
}
