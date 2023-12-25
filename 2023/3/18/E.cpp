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
#define eps 1e-7
#define maxn 10000
using namespace std;

int n, as[maxn + 5];
LD a[maxn + 5], b[maxn + 5];
pair<LD, int> pa[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

LL sol(LD x){
    LL tem = floor(x), tem1 = tem + 1;
    if(x - tem <= tem1 - x) return tem;
    else return tem1;
}

int main(){
    // Frac x = sol(0.018910741301, 0);
    // cout << x.x << " " << x.y << endl;
	// freopen("in.txt", "r", stdin);
    read(n);
    For(i, 1, n) cin >> a[i];
    For(i, 1, n) b[i] = a[i] / a[1];
    For(i, 1, 10000){
        pa[i] = {0, i};
        For(j, 1, n) pa[i].fir = max(pa[i].fir, fabs(sol(i * b[j]) - i * b[j]));
    }
    sort(pa + 1, pa + 10000 + 1);
    int a1 = pa[1].sec;
    // cout << pa[1].fir << endl;
    For(i, 1, n) printf("%lld\n", sol(a1 * b[i]));
    return 0;
}
