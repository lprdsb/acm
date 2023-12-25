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

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

#define maxn 200000
int n, q, dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int a[maxn + 5];

int as[maxn + 5];
struct Opt{
    int x, y, l, r, id;
};
vector<Opt> vec[2][maxn + 5];

int main(){
	//freopen("in", "r", stdin);
    read(n); read(q);
    For(i, 1, n){
        char c; cin >> c;
        if(c == 'U') a[i] = 0;
        if(c == 'D') a[i] = 1;
        if(c == 'L') a[i] = 3;
        if(c == 'R') a[i] = 2;
    }
    For(i, 1, q){
        int x, y, l, r; read(x); read(y); read(l); read(r);
        vec[0][l - 1].pb({x, y, l, r, i});
        vec[0][n].pb({x, y, l, r, i});
    }
    int nx = 0, ny = 0;
    map<int, map<int, int> > ma;
    ma[0][0] = 1;
    for(auto [x, y, l, r, id] : vec[0][0]){
        if(ma[x][y]) as[id] = 1;
        else vec[1][r].pb({x - nx, y - ny, l, r, id});
    }
    For(i, 1, n){
        nx += dir[a[i]][0]; ny += dir[a[i]][1];
        ma[nx][ny] = i + 1;
        for(auto [x, y, l, r, id] : vec[0][i]){
            if(i == l - 1){
                if(ma[x][y]) as[id] = 1;
                else vec[1][r].pb({x - nx, y - ny, l, r, id});
            }
            else if(ma[x][y] - 1 >= r) as[id] = 1; 
        }
    }
    ma.clear();
    nx = ny = 0;
    ma[0][0] = 1;
    For(i, 1, n){
        nx += dir[a[i]][0]; ny += dir[a[i]][1];
        ma[nx][ny] = i + 1;
        for(auto [x, y, l, r, id] : vec[1][i]) if(ma[nx - x][ny - y] - 1 >= l) as[id] = 1;
    }
    For(i, 1, q) puts(as[i] ? "YES" : "NO");
    return 0;
}
