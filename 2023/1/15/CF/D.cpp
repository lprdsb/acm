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
#define maxn 50
using namespace std;

int t, n, a[maxn + 5];
map<LL, int> ma;

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
        int mx = 0;
        ma.clear();
        read(n);
        For(i, 1, n){
            read(a[i]);
            For(j, 1, i - 1){
                int tem = a[i] - a[j];
                for(int p = 1; p * p <= tem; ++p) if(tem % p == 0){
                    LL x = p + (tem / p);
                    if(x & 1) continue;
                    x /= 2;
                    x = x * x - a[i];
                    if(x < 0) continue;
                    ma[x]++;
                    // cout << x << " " << ma[x] << endl;
                    if(ma[x] > mx) mx = ma[x];
                }
            }
        }
        // cout << ma[5] << endl;
        For(i, 0, mx) if(i * (i + 1) == 2 * mx){
            printf("%d\n", i + 1);
            break;
        }
    }
}
