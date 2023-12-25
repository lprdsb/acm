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
#define maxn 2000
using namespace std;

int t, n, m, k, ok[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

priority_queue<pair<int, int> > q[maxn + 5];

int main(){
	// freopen("in.txt", "r", stdin);
    read(t);
    while(t--){
        read(n); read(m); read(k);
        int now = (k - 1) % n;
        For(i, 0, n - 1) For(j, 0, m - 1){
            int x; read(x);
            q[i].push({x, j});
        }
        while(k--){
            while(ok[q[now].top().sec]) q[now].pop();
            ok[q[now].top().sec] = 1;
            now--;
            if(now == -1) now = n - 1;
        }
        For(i, 0, m - 1) if(ok[i]) cout << i + 1 << " "; cout << endl;
        For(i, 0, n - 1) while(q[i].size()) q[i].pop();
        For(i, 0, m - 1) ok[i] = 0;
    }
    return 0;
}
