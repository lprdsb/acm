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

int n, k, a[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int b[maxn + 5];
void sol(int l, int r){
    if(!k) return;
    if(l + 1 == r) return;
    k -= 2;
    int mid = l + r >> 1;
    swap(a[mid - 1], a[mid]);
    if(k) sol(l, mid);
    if(k) sol(mid, r);
}

int main(){
	//freopen("in", "r", stdin);
    read(n); read(k); k--;
    if(k & 1){
        puts("-1");
        return 0;
    }
    For(i, 0, n - 1) a[i] = i + 1;
    sol(0, n);
    if(k){
        puts("-1");
        return 0;
    }
    For(i, 0, n - 1) printf("%d ", a[i]);
    return 0;
}
