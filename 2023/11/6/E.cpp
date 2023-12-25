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
#define maxn 100000
using namespace std;

#define i128 __int128_t

int n, a[maxn + 5], b[maxn + 5], d[maxn + 5], c[maxn + 5];
LL sb;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int ind[maxn + 5];

int dty(LL x){
    if(x < 0) return -1;
    if(x == 0) return 0;
    return 1;
}

void work(i128 x){
    For(i, 1, n) ind[i] = i;
    sort(ind + 1, ind + n + 1, [&](cst int &_x, cst int &_y){
        int d1 = dty(d[_x]), d2 = dty(d[_y]);
        if(d1 != d2) return d1 > d2;
        if(d1 >= 0) return (i128)x * (c[_x] - c[_y]) + (i128)c[_x] * c[_y] * (a[_x] - a[_y]) < 0;
        return (i128)x * (c[_x] - c[_y]) + (i128)c[_x] * c[_y] * (b[_x] - b[_y]) > 0;
    });
}

bool chk(i128 x){
    work(x);
    LL now = sb;
    For(i, 1, n){
        now -= d[ind[i]];
        if((i128)(now + b[ind[i]]) * c[ind[i]] > x) return 0;
    }
    return 1;
}

void sol(i128 x){
    work(x);
    For(i, 1, n) printf("%d ", ind[i]); puts("");
}

int main(){
	// freopen("in.txt", "r", stdin);
    int T;
    read(T);
    while(T--){
        read(n);
        sb = 0;
        For(i, 1, n) read(a[i]), read(b[i]), read(c[i]), sb += b[i];
        For(i, 1, n) d[i] = b[i] - a[i];
        i128 l = 0, r = Inf;
        while(l < r){
            i128 mid = l + r >> 1;
            if(chk(mid)) r = mid;
            else l = mid + 1;
        }
        sol(l);
    }
    return 0;
}
