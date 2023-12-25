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
#define maxn 250
using namespace std;

int n, as[maxn + 5];
pair<int, int> pa[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int main(){
	//freopen("in", "r", stdin);
    read(n);
    For(i, 1, n){
        printf("? %d ", i);
        For(j, 1, n) printf("%d", i != j);
        puts("");
        fflush(stdout);
        read(pa[i].fir); pa[i].fir *= -1;
        pa[i].sec = i;
    }
    sort(pa + 1, pa + n + 1);
    int sum = 0;
    For(i, 1, n){
        as[pa[i].sec] = 1;
        sum -= pa[i].fir;
        if(sum - i * (n - i) == i * (i - 1) / 2){
            printf("! ");
            For(j, 1, n) printf("%d", as[j]);
            puts("");
            fflush(stdout);
            break;
        }
    }
    return 0;
}
