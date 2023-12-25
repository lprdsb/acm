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

int t, n, q;
char s[2][maxn + 5];
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
        scanf("%s", s[0] + 1);
        scanf("%s", s[1] + 1);
        read(n); read(q);
        int len = strlen(s[0] + 1);
        For(i, 1, q) vec[i].clear();
        int now = 0;
        For(i, 1, len) now += s[0][i] != s[1][i];
        For(i, 1, q){
            for(auto j : vec[i]) now += s[0][j] != s[1][j];
            int op; read(op);
            if(op == 1){
                int pos; read(pos);
                vec[i + n].pb(pos);
                now -= s[0][pos] != s[1][pos];
            }
            else if(op == 2){
                int o1, p1, o2, p2; read(o1); read(p1); read(o2); read(p2);
                o1--; o2--;
                if(p1 != p2) now -= (s[o1][p1] != s[o1 ^ 1][p1]) + (s[o2][p2] != s[o2 ^ 1][p2]);
                swap(s[o1][p1], s[o2][p2]);
                if(p1 != p2) now += (s[o1][p1] != s[o1 ^ 1][p1]) + (s[o2][p2] != s[o2 ^ 1][p2]);
            }
            else puts(now ? "No" : "Yes");
        }
    }
    return 0;
}
