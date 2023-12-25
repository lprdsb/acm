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
#define maxn 1000000
using namespace std;

int n, a[maxn + 5], to[maxn + 5];
LL as = 0;
map<int, int> ma[maxn + 5];

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
    read(n);
    For(i, 1, n) read(a[i]);
    to[n + 1] = n + 1;
    Rof(i, n, 1){
        to[i] = i;
        while(to[i] <= n){
            if(a[to[i]] == 1) ma[i][1]++;
            else if(ma[i][a[to[i]] - 1]){
                ma[i][a[to[i]] - 1]--;
                ma[i][a[to[i]]]++;
            }
            else break;
            to[i]++;
            if(ma[i].size() < ma[to[i]].size()) swap(ma[i], ma[to[i]]);
            for(auto j : ma[to[i]]) ma[i][j.fir] += j.sec;
            to[i] = to[to[i]];
        }
        // if(i == 1) cout << to[i] << endl;
        as += to[i] - i;
    }
    printf("%lld\n", as);
    return 0;
}
