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

int t, n;

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
        int c1 = 0, c2 = 0;
        For(i, 1, n){
            char c; cin >> c;
            c1 += c - '0';
        }
        For(i, 1, n){
            char c; cin >> c;
            c2 += c - '0';
        }
        if(c1 + c2 <= n){
            For(i, 1, c1 + c2) printf("1");
            For(i, c1 + c2 + 1, n) printf("0");
        }
        else{
            For(i, 1, n - (c1 + c2 - n)) printf("1");
            For(i, n - (c1 + c2 - n) + 1, n) printf("0");
        }
        puts("");
    }
    return 0;
}
