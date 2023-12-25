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
#define maxn 500000
using namespace std;

int n, m, B = 2000, a[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int tr[maxn + 5];
void ins(int x, int y){while(x <= maxn) tr[x] += y, x += x & -x;}
int que(int x){int asi = 0; while(x) asi += tr[x], x -= x & -x; return asi;}

int inv[maxn + 5];

struct Data{
    int l, r, id;
} b[maxn + 5];
bool operator < (Data _a, Data _b){
    if(_a.l / B != _b.l / B) return _a.l < _b.l;
    return _a.r < _b.r;
}

int L = 1, R = 0;
LL as[maxn + 5], res = 0, cnt[maxn + 5], sum[maxn + 5];
void insl(int x){
    res += sum[a[x]] - cnt[a[x]] * inv[x];
    sum[a[x]] += inv[x];
    cnt[a[x]]++;
}
void dell(int x){
    sum[a[x]] -= inv[x];
    cnt[a[x]]--;
    res -= sum[a[x]] - cnt[a[x]] * inv[x];
}
void insr(int x){
    res += cnt[a[x]] * inv[x] - sum[a[x]];
    sum[a[x]] += inv[x];
    cnt[a[x]]++;
}
void delr(int x){
    sum[a[x]] -= inv[x];
    cnt[a[x]]--;
    res -= cnt[a[x]] * inv[x] - sum[a[x]];
}

int main(){
	//freopen("in", "r", stdin);
    read(n); read(m);
    For(i, 1, n) read(a[i]), inv[i] = que(a[i]), ins(a[i] + 1, 1);
    For(i, 1, m) read(b[i].l), read(b[i].r), b[i].id = i;
    sort(b + 1, b + m + 1);
    For(i, 1, m){
        while(L > b[i].l) insl(--L);
        while(R < b[i].r) insr(++R);
        while(L < b[i].l) dell(L++);
        while(R > b[i].r) delr(R--);
        as[b[i].id] = res;
    }
    For(i, 1, m) printf("%lld\n", as[i]);
    return 0;
}
