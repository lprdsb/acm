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
using namespace std;

int n, k;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

bool chk(int x){
    int now = 0, sum = 0;
    Rof(i, x, 1){
        sum += k / i;
        now += k % i;
        if(now >= i) now -= i, sum++;
        if(now) now--;
    }
    return sum >= n;
}

int main(){
	//freopen("in", "r", stdin);
    read(n); read(k);
    int l = 1, r = 1e7;
    while(l < r){
        int mid = l + r >> 1;
        if(chk(mid)) r = mid;
        else l = mid + 1;
    }
    if(chk(l)) printf("%d\n", l);
    else puts("Poor E.S.!");
    return 0;
}
