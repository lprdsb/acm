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

int n, m;

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
    read(n); read(m);
    int res = 0;
    For(i, 1, n){
        int l = 0, r = 0, ok = 0;
        For(j, 1, m){
            char c; cin >> c;
            if(m & 1){
                if(j == (m + 1) / 2) ok = c - '0';
                else if(j <= m / 2) l += c - '0';
                else r += c - '0';
            }
            else{
                if(j <= m / 2) l += c - '0';
                else r += c - '0';
            }
        }
        if(ok){
            if(l > r) swap(l, r);
            if(!l) res ^= (r & 1);
            else if(l == 1) res ^= (r & 1) ? 2 : 3;
            else res ^= !((l + r) & 1);
        }
        else res ^= (l + r) & 1;
    }
    puts(res ? "Alice" : "Bob");
    return 0;
}
