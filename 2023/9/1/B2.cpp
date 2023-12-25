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

int n = 20, m = 0, q = 10, a[1500];

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
    cout << 1 << endl;
    a[++m] = 1;
    For(i, 1, 5) a[++m] = rand() % n + 1;
    sort(a + 1, a + m + 1);
    m = unique(a + 1, a + m + 1) - a - 1;
    cout << n << " " << m << " " << q << endl;
    For(i, 1, m) cout << a[i] << " "; cout << endl;
    For(i, 2, n) cout << rand() % (i - 1) + 1 << " " << i << " " << rand() + 1 << endl;
    For(i, 1, q){
        int k = 10;
        cout << k << " ";
        For(j, 1, k) cout << rand() % n + 1 << " "; cout << endl;
    }
}
