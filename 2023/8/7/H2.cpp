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

int n = 10000, t = 11000;

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
    cout << n << " " << t << endl;
    For(i, 1, n){
        /*if(i & 1) cout << 1 << " ";
        else */cout << 1ll * rand() * rand() % 1000000000 + 1 << " ";
    }
    // For(_, 1, t - 1){
    //     cout << 1 << " " << 1ll * rand() * rand() % n + 1 << " " << 1ll * rand() * rand() * rand() % 100000000 + 1 << endl;
    // }
    For(i, 1, t - 1){
        cout << "1 " << 1ll * rand() * rand() % n + 1 << " " << 1ll * rand() * rand() % 1000000000 + 1 << endl;
    }
    For(i, 1, 1){
        int l = 1ll * rand() * rand() % n + 1, r = 1ll * rand() * rand() % n + 1;
        if(l > r) swap(l, r);
        cout << "2 " << l << " " << r << endl;
    }
    // cout << "2 2 1000" << endl;
}
