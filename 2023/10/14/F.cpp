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

int n, q, as[maxn + 5];
struct Node{
    int id, r, k;
};
vector<Node> opt[maxn + 5];
vector<int> seg[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int tr[maxn + 5];
void ins(int x, int val){
    x = maxn - x + 1;
    while(x <= maxn) tr[x] += val, x += x & -x;
}
int que(int x){
    x = maxn - x + 1;
    int res = 0;
    while(x) res += tr[x], x -= x & -x;
    return res;
}

int main(){
	//freopen("in", "r", stdin);
    read(n); read(q);
    For(i, 1, n){
        int l, r; read(l); read(r);
        seg[l].pb(r);
    }
    For(i, 1, q){
        int a, b; read(a); read(b);
        opt[a].pb({i, a, 1});
        opt[min(a, b)].pb({i, max(a, b), -1});
    }
    For(i, 1, maxn){
        for(auto r : seg[i]) ins(r, 1);
        for(auto [id, r, k] : opt[i]) as[id] += k * que(r);
    }
    For(i, 1, q) printf("%d\n", as[i]);
}
