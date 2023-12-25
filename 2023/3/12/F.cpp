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
#define maxn 300
using namespace std;

int n, t, a[maxn + 5];
LL as = 0, f[maxn + 5][maxn + 5], g[maxn + 5][maxn + 5], ma[maxn + 5][maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int st[maxn + 5], top = 0;
int main(){
	// freopen("in.txt", "r", stdin);
    read(n); read(t);
    For(i, 1, n) read(a[i]);
    For(i, 1, 300) For(j, i, 300){
        top = 0;
        For(p, 1, n) if(a[p] >= i && a[p] <= j){
            int l = 0, r = top;
            while(l < r){
                int mid = l + r >> 1;
                if(st[mid] > a[p]) r = mid;
                else l = mid + 1;
            }
            if(st[l] > a[p]) l--;
            if(l == top) st[++top] = a[p];
            else st[l + 1] = a[p];
        }
        ma[i][j] = max(ma[i][j], 1ll * top);
        // if(i == 1 && j == 2) cout << top << endl;
    }
    For(i, 1, 300) For(j, 1, 300) For(p, 0, i - 1) f[i][j] = max(f[i][j], f[p][j - 1] + ma[p][i]);
    Rof(i, 300, 1) For(j, 1, 300) For(p, i + 1, 301) g[i][j] = max(g[i][j], g[p][j - 1] + ma[i][p]);
    For(i, 1, 300) For(j, 0, 300) For(p, 0, 300) if(j + p <= t) 
        as = max(as, 1ll * f[i][j] + g[i][p] + 1ll * (t - j - p) * ma[i][i]);
    // cout << ma[3][4] << endl;
    printf("%lld\n", as);
    return 0;
}
