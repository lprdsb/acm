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

int t, n, a[50];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

vector<pair<int, int> > vec;

int main(){
	//freopen("in", "r", stdin);
    read(t);
    while(t--){
        
        read(n);
        int mx = 0, mn = 0;
        vec.resize(0);
        For(i, 1, n){
            read(a[i]);
            if(!mn || a[i] < a[mn]) mn = i;
            if(!mx || a[i] > a[mx]) mx = i;
        }
        if(a[mx] + a[mn] >= 0){
            For(i, 1, n) if(i != mx) vec.pb({i, mx}), a[i] += a[mx];
        }
        else{
            For(i, 1, n) if(i != mn) vec.pb({i, mn}), a[i] += a[mn];
        }
        if(a[1] >= 0){
            For(i, 2, n) if(a[i] < a[i - 1]) vec.pb({i, i - 1}), a[i] += a[i - 1];
        }
        else{
            Rof(i, n - 1, 1) if(a[i] > a[i + 1]) vec.pb({i, i + 1}), a[i] += a[i + 1];
        }
        printf("%d\n", vec.size());
        for(auto i : vec) printf("%d %d\n", i.fir, i.sec);
    }

}
