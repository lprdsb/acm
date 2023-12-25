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
#define maxn 200000
using namespace std;

int t, n, sum[maxn + 5], as; 
vector<int> vec[maxn + 5];

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
        as = 0;
        read(n);
        For(i, 1, n){
            vec[i].clear();
            int k; read(k);
            For(j, 1, k){
                int x; read(x);
                vec[i].pb(x);
                sum[x]++;
            }
        }
        For(i, 1, n){
            int fl = 0;
            for(auto j : vec[i]) if(sum[j] == 1){
                fl = 1;
                break;
            }
            as |= !fl;
        }
        if(as) puts("Yes");
        else puts("No");
        For(i, 1, n) for(auto j : vec[i]) sum[j]--;
    }
    return 0;
}
