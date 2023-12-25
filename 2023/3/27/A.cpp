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
#define maxn 300000
using namespace std;

int t, n;
vector<int> vec[2];

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
        vec[0].clear();
        vec[1].clear();
        read(n);
        int fl = 0;
        For(i, 1, n){
            int x; read(x);
            if(x <= 0) vec[0].pb(x);
            else vec[1].pb(x);
            fl |= x != 0;
        }
        if(!fl){
            puts("No");
            continue;
        }
        int now = 0;
        puts("Yes");
        For(i, 1, n){
            int tem;
            if(now >= 0){
                tem = vec[0][vec[0].size() - 1];
                vec[0].pop_back();
            }
            else{
                tem = vec[1][vec[1].size() - 1];
                vec[1].pop_back();
            }
            now += tem;
            printf("%d ", tem);
        }
        puts("");
    }
}
