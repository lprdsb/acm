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

int t, x;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

vector<int> as;
int main(){
	//freopen("in", "r", stdin);
    read(t);
    while(t--){
        read(x);
        as.resize(0);
        while(666){
            as.pb(x);
            int tem = x, pw2 = 1;
            while(tem % 2 == 0){
                tem >>= 1;
                pw2 <<= 1;
            }
            if(x == pw2) break;
            x -= pw2;
        }
        while(x != 1){
            x >>= 1;
            as.pb(x);
        }
        printf("%d\n", as.size());
        for(auto i : as) printf("%d ", i);
        puts("");
    }
}
