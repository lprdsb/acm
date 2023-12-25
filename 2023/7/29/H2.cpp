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

int t = 1, n = 100000, q = 100000, range = 100000000;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int main(){
	freopen("in.txt", "w", stdout);
    cout << t << endl;
    while(t--){
        cout << n << " " << q << endl;
        For(i, 1, n){
            int x1, x2, y1, y2;
            x1 = 1ll * rand() * rand() % range;
            x2 = 1ll * rand() * rand() % range;
            if(x1 > x2) swap(x1, x2);
            y1 = 1ll * rand() * rand() % range;
            y2 = 1ll * rand() * rand() % range;
            if(y1 > y2) swap(y1, y2);
            cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
        }
        For(i, 1, q){
            int l = rand() % n + 1, r = rand() % n + 1;
            if(l > r) swap(l, r);
            cout << l << " " << r << endl;
        }
    }
}
