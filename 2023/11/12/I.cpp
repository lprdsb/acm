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

map<LL, LL> ma;
vector<LL> vec;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int mod = 998244353;

int now = 0;
int opt(int x){
    // printf("walk %d\n", x);
    // fflush(stdout);
    int res;
    // read(res);
    now = (now + x) % mod;
    return now;
}

int main(){
	//freopen("in", "r", stdin);
    srand(time(0));
    LL x = 0;
    while(666){
        int tem = 1ll * rand() * rand() % mod;
        int as = opt(tem);
        x += tem;
        if(!ma[as]){
            ma[as] = x;
            cout << ma.size() << endl;
        }
        else break;
    }
}
