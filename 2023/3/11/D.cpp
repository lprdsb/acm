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
#define maxn 500000
using namespace std;

int n, as = inf, t;
struct Node{int a, b;} gift[maxn + 5];
bool operator < (cst Node &x, cst Node &y){
    if(x.a != y.a) return x.a < y.a;
    return abs(x.a - x.b) < abs(y.a - y.b);
}

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int mx[maxn + 5];
set<int> se;

int main(){
	//freopen("in", "r", stdin);
    read(t);
    while(t--){
        as = inf;
        se.clear();
        read(n);
        For(i, 1, n) read(gift[i].a), read(gift[i].b);
        sort(gift + 1, gift + n + 1);
        mx[n + 1] = 0;
        Rof(i, n, 1) mx[i] = max(mx[i + 1], gift[i].b);
        se.insert(gift[1].b);
        For(i, 2, n - 1){
            auto it = se.lower_bound(gift[i].a);
            int mn = inf;
            if(it != se.end()) mn = abs(*it - gift[i].a);
            if(it != se.begin()){
                it--;
                mn = min(mn, abs(*it - gift[i].a));
            }
            if(mx[i + 1] >= gift[i].a) as = min(as, mx[i + 1] - gift[i].a);
            else as = min(as, min(mn, gift[i].a - mx[i + 1]));
            se.insert(gift[i].b);
        }
        For(i, 1, n - 1) as = min(as, abs(gift[n].a - gift[i].b));
        as = min(as, abs(gift[1].a - mx[2]));
        printf("%d\n", as);
    }
    return 0;
}
