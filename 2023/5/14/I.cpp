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
#define maxn 1000000
using namespace std;

int n, a[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int l = 1, r = 1;

int main(){
	// freopen("in", "r", stdin);
	read(n);
    For(i, 1, n) read(a[i]);
    For(i, 1, n - 1) if(a[i] > a[i + 1]){
        int now = i;
        while(a[now - 1] == a[i]) now--;
        l = now; r = n;
        For(j, i + 1, n) if(a[j] > a[j - 1]){
            r = j - 1;
            break;
        }
        break;
    }
    int len = r - l + 1;
    For(i, 1, len / 2) swap(a[l + i - 1], a[r - i + 1]);
    int ok = 1;
    For(i, 1, n - 1) if(a[i + 1] - a[i] < 0) ok = 0;
    if(ok) printf("%d %d\n", l, r);
    else puts("impossible");
    return 0;
}
