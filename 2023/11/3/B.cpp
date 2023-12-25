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

int T;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

vector<int> pos[15];

int main(){
	//freopen("in", "r", stdin);
    read(T);
    while(T--){
        pos[2].pb(1); pos[3].pb(2); pos[4].pb(3);
        For(_, 1, 12){
            int a, b; read(a); read(b);
            For(i, 1, 9){
                int fl = 0;
                For(j, 0, pos[i].size() - 1){
                    if(pos[i][j] == a) fl = 1;
                    if(fl) pos[i + b].pb(pos[i][j]);
                }
                if(fl){
                    while(pos[i][pos[i].size() - 1] != a) pos[i].pop_back();
                    pos[i].pop_back();
                    break;
                }
            }
        }
        puts(pos[9].size() == 3 ? "Y" : "N");
        For(i, 1, 9) pos[i].resize(0);
    }
    return 0;
}
