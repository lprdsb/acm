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

int t, n, a[maxn + 5];

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
        For(i, 1, n){
            char c; cin >> c;
            a[i] = c - '0';
        }
        For(i, 1, n / 2){
            if(a[i] != a[n - i + 1]){
                For(j, i, n - i + 1){
                    if(a[j] != a[n - j + 1]) a[j] ^= 1;
                    else break;
                }
                break;
            }
        }
        int fl = 1;
        For(i, 1, n / 2){
            if(a[i] != a[n - i + 1]){
                fl = 0;
            }
        }
        if(fl) puts("Yes");
        else puts("No");
    }
    return 0;
}
