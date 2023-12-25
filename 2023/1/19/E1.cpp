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
 
int n, k, a[maxn + 5];
 
template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}
 
int ok;
bool chk(int x){
    int sum = k / 2;
    ok = 1;
    For(i, 2, n){
        sum -= (a[i] <= x) && ok;
        if(!sum && (i != n || !(k & 1))) return 1;
        if(a[i] <= x && ok) ok = 0;
        else ok = 1;
    }
    sum = (k + 1) / 2;
    ok = 1;
    For(i, 1, n){
        sum -= (a[i] <= x) && ok;
        if(!sum) return i != n || (k & 1);
        if(a[i] <= x && ok) ok = 0;
        else ok = 1;
    }
    return 0;
}
 
int main(){
	//freopen("in", "r", stdin);
    read(n); read(k);
    For(i, 1, n) read(a[i]);
    int l = 1, r = 1e9;
    while(l < r){
        int mid = l + r >> 1;
        if(chk(mid)) r = mid;
        else l = mid + 1;
    }
    printf("%d\n", l);
    return 0;
}