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

int n = 200000, m = 200000, q = 200000;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int main(){
    srand(time(0));
	freopen("in.txt", "w", stdout);
    cout << n << " " << m << endl;
    For(i, 1, n) cout << 1ll * rand() * rand() % n + 1 << " "; cout << endl;
    cout << q << endl;
    For(i, 1, q){
        int l = 1ll * rand() * rand() % m + 1, r = 1ll * rand() * rand() % m + 1;
        if(l > r) swap(l, r);
        cout << l << " " << r << endl;
    }
}
