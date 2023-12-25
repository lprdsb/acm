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
#define maxn 800000
using namespace std;

int n, L;
LL a[maxn + 5], b[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

bool chk(int x){
    int mx = -inf, ll = 1, rr = 1;
    For(i, 1, 2 * n){
        while(ll <= 4 * n && b[ll] < a[i] - x) ll++;
        while(rr <= 4 * n && b[rr] <= a[i] + x) rr++;
        mx = max(mx, ll - i);
        if(rr - i - 1 < mx) return 0;
    }
    return 1;
}

int main(){
	// freopen("in.txt", "r", stdin);
    read(n); read(L);
    For(i, 1, n) read(a[i]);
    For(i, 1, n) read(b[i]);
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    For(i, 1, n) a[i] += L, a[n + i] = a[i] + L;
    For(i, 1, 3 * n) b[i + n] = b[i] + L;
    int l = 0, r = L / 2;
    while(l < r){
        int mid = l + r >> 1;
        if(chk(mid)) r = mid;
        else l = mid + 1;
    }
    printf("%d\n", l);
    return 0;
}
