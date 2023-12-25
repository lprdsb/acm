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

int t, n, a[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int mn = inf, mx = -inf;

bool chk(int lim){
    int mni = inf, mxi = -inf;
    For(i, 1, n) if(a[i] - mn > 2ll * lim && mx - a[i] > 2ll * lim){
        mni = min(mni, a[i]);
        mxi = max(mxi, a[i]);
    }
    if(mni == inf) return 1;
    return mxi - mni <= 2 * lim;
}

int main(){
	//freopen("in", "r", stdin);
    read(t);
    while(t--){
        read(n);
        mn = inf; mx = -inf;
        For(i, 1, n){
            read(a[i]);
            mn = min(mn, a[i]);
            mx = max(mx, a[i]);
        }
        int l = 0, r = 1e9;
        while(l < r){
            int mid = l + r >> 1;
            if(chk(mid)) r = mid;
            else l = mid + 1;
        }
        printf("%d\n", l);
    }
	return 0;
}
