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

int n, k;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int a[maxn + 5];

bool chk(int x){
    int cnt = 0, now = -1;
    For(i, 1, n){
        if(now == -1) cnt++, now = a[i];
        if(a[i] - now > x) cnt++, now = a[i];
    }
    return cnt <= k;
}

int main(){
	//freopen("in", "r", stdin);
    read(n); read(k);
    For(i, 1, n) read(a[i]);
    sort(a + 1, a + n + 1);
    int l = 0, r = 1000000000;
    while(l < r){
        int mid = l + r >> 1;
        if(chk(mid)) r = mid;
        else l = mid + 1;
    }
    printf("%d\n", l);
    return 0;
}
