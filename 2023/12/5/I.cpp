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
#define maxn 100000
using namespace std;

int T, n, m;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

pair<int, int> opt[maxn + 5];

int main(){
	//freopen("in", "r", stdin);
    read(T);
    while(T--){
        read(n); read(m);
        For(i, 1, m) read(opt[i].fir), read(opt[i].sec);
        sort(opt + 1, opt + m + 1);
        int fl = 1;
        For(i, 1, m){
            if(opt[i].fir == opt[i - 1].fir && opt[i].sec != opt[i - 1].sec){
                fl = 0;
                break;
            }
            if(opt[i].fir - opt[i - 1].fir == opt[i].sec - opt[i - 1].sec) continue;
            if(opt[i].fir - opt[i - 1].fir - 1 >= opt[i].sec) continue;
            fl = 0;
            break;
        }
        puts(fl ? "Yes" : "No");
    }
    return 0;
}
