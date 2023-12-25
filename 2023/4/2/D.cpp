#include<bits/stdc++.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define Tra(u, i) for(int i = hd[u]; ~i; i = e[i].net)
#define cst const
#define LL __int128
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

int t, q;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int main(){
	// freopen("in.txt", "r", stdin);
    read(t);
    while(t--){
        LL L = 0, R = 1e35;
        read(q);
        while(q--){
            int opt, a, b, n; read(opt);
            if(opt == 1){
                read(a); read(b); read(n);
                LL l = (n == 1 ? 1 : 1ll * (n - 1) * (a - b) + b + 1), r = 1ll * (n - 1) * (a - b) + a;
                if(l > r) printf("0 ");
                else{
                    if(r < L || l > R) printf("0 ");
                    else{
                        L = max(L, l);
                        R = min(R, r);
                        printf("1 ");
                    }
                }
            }
            else{
                // if(q == 0) cout << L << " " << R << endl;
                read(a); read(b);
                LL as1 = ceil((LD)(L - a) / (a - b)) + 1, as2 = ceil((LD)(R - a) / (a - b)) + 1;
                if(as1 <= 0) as1 = 1;
                if(as2 <= 0) as2 = 1;
                if(as1 == as2) printf("%.0Lf ", (LD)as1);
                else printf("-1 ");
            }
        }
        puts("");
    }
    return 0;
}
