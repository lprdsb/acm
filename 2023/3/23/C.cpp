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

int t;
LL n;

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
    read(t);
    while(t--){
        read(n);
        // cout << ceil((sqrt(2 * n - 1) - 1)/ 2) << endl;
        LL sq = sqrt(n), as = 0, as1 = 0;
        if(sq & 1){
            as = (sq - 1) / 2;
            as1 = sq / 2 + 1;
            if(sq * sq != n) as++;
        }
        else{
            as = sq / 2;
            as1 = sq / 2;
            if(sq * sq != n) as1++;
        }
        if(n == 1) puts("0");
        else printf("%lld\n", min(2 * as, 2 * as1 - 1));
    }
    return 0;
}
