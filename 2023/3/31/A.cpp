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

int n, a[maxn + 5], as = 0;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int b[maxn + 5];
int sol(){
    int to = n - 1, asi = 0;
    For(i, 1, n - 1){
        while(to > i && b[i] + b[to] >= b[n]) to--;
        if(to <= i) break;
        asi = max(asi, b[i] + b[to]);
    }
    return asi;
}

int sol1(int ind){
    int asi = 0;
    b[n] = a[ind];
    For(i, 1, n - 1) b[i] = a[i + (i >= ind)] % a[ind];
    sort(b + 1, b + n + 1);
    asi = max(asi, sol());
    int mx[2] = {0, 0};
    For(i, 1, n) if(i != ind){
        int tem = a[i] % a[ind];
        if(tem > mx[0]) swap(mx[0], tem);
        if(tem > mx[1]) swap(mx[1], tem);
    }
    return max(asi, (mx[0] + mx[1]) % a[ind]);
}

int main(){
	//freopen("in", "r", stdin);
    read(n);
    For(i, 1, n) read(a[i]);
    sort(a + 1, a + n + 1);
    Rof(i, n, 1){
        if(a[i] > as) as = max(as, sol1(i));
        else break;
    }
    printf("%d\n", as);
    return 0;
}
