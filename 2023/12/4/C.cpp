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

int T, n;
LL a[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

LL gcd(LL x, LL y){return y ? gcd(y, x % y) : x;}

map<int, bool> ma;

int main(){
	//freopen("in", "r", stdin);
    read(T);
    while(T--){
        read(n);
        LL sum = 0;
        ma.clear();
        For(i, 1, n) read(a[i]), sum += a[i], ma[a[i]] = 1;
        int fl = 1;
        For(i, 1, n) if(a[i] != a[1]){
            fl = 0;
            break;
        }
        if(fl){
            puts("1");
            continue;
        }
        LL mx = -Inf;
        For(i, 1, n) mx = max(mx, a[i]);
        LL gc = 0;
        For(i, 1, n) gc = gcd(gc, mx - a[i]);
        LL res = min((mx + 1) * n - sum, ((mx + gc) * n - sum) / gc);
        int tem = mx, cnt = 0;
        while(ma[tem]) cnt++, tem -= gc;
        res = min(res, (mx * n - sum) / gc + cnt);
        printf("%lld\n", res);
    }
}
