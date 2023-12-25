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

int n, m;
struct Node{
    int pos, id;
} a[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

LL as[maxn + 5];

int tr[maxn + 5];
void ins(int x, int y){
    while(x <= maxn) tr[x] += y, x += x & -x; 
}
int que(int x){
    int res = 0;
    while(x) res += tr[x], x -= x & -x;
    return res;
}

int main(){
	//freopen("in", "r", stdin);
    read(n); read(m);
    For(i, 1, n){
        int x; read(x);
        a[i] = {-x, i};
    }
    sort(a + 1, a + n + 1, [](cst Node &_x, cst Node &_y){
        if(_x.pos != _y.pos) return _x.pos < _y.pos;
        return _x.id < _y.id;
    });
    For(i, 1, n) as[i] = -1;
    LL now = 0;
    Rof(i, n, 1){
        if(i < n) now += 1ll * (n - i) * (a[i + 1].pos - a[i].pos);
        vector<int> vec;
        while(a[i - 1].pos == a[i].pos){
            vec.pb(a[i].id);
            ins(a[i].id, 1);
            i--;
        }
        vec.pb(a[i].id);
        ins(a[i].id, 1);
        for(auto id : vec){
            as[id] = now + que(id) - 1;
        }
    }
    For(i, 1, n) printf("%lld\n", as[i] > m - 2 ? -1 : as[i]);
    return 0;
}
