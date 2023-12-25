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
#define maxn 10000
using namespace std;

int n, a, b, v[maxn + 5], mn = inf, mx = -inf, as[1001][1001];

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
    read(n); read(a); read(b);
    For(i, 1, n) read(v[i]), v[i] *= -1;
    int now = 0;
    For(i, 1, n) now += v[i], mn = min(mn, now), mx = max(mx, now);
    For(i, 0, a + b){
        int l = max(0, i - b), r = min(a, i);
        int ll = l, rr = r;
        if(mn < 0) ll -= mn, ll = min(r, ll);
        if(mx > 0) rr -= mx, rr = max(l, rr);
        For(j, ll, rr) as[j][i - j] = j + now;
        int tem1 = ll, tem2 = rr;
        For(j, 1, n){
            tem1 += v[j];
            tem1 = min(tem1, r);
            tem1 = max(tem1, l);
            tem2 += v[j];
            tem2 = min(tem2, r);
            tem2 = max(tem2, l);
        }
        // if(i == 1) cout << ll << endl;
        For(j, l, ll) as[j][i - j] = tem1;
        For(j, rr, r) as[j][i - j] = tem2;
    }
    For(i, 0, a){
        For(j, 0, b) printf("%d ", as[i][j]);
        puts("");
    }
    return 0;
}
