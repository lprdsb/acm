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

int t, n, m, r;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

unordered_map<int, int> ok[2][10005], f[105][200];
vector<int> vec;
void chkmn(int &x, int y){
    if(y == -1) return;
    if(x == -1 || x > y) x = y;
}
int dfs(int tt, int nx, int ny){
    if(tt > r || nx > n || ny > m) return -1;
    if(ok[0][nx][nx + ny + tt] || ok[1][ny][nx + ny + tt]) return -1; 
    // cout << tt << " " << nx << " " << ny << endl;
    if(nx == n && ny == m) return 0;
    if(f[tt][nx].count(ny)) return f[tt][nx][ny];
    int asi = -1;
    chkmn(asi, dfs(tt + 1, nx, ny));
    chkmn(asi, dfs(tt, nx + 1, ny));
    chkmn(asi, dfs(tt, nx, ny + 1));
    vec.pb(tt);
    if(asi != -1) asi++;
    return f[tt][nx][ny] = asi;
}

int main(){
	// freopen("in.txt", "r", stdin);
	read(t);
    while(t--){ 
        read(n); read(m); read(r);
        int fl = 0;
        if(n > m) fl = 1, swap(n, m);
        For(i, 0, n) ok[0][i].clear();
        For(i, 0, m) ok[1][i].clear();
        for(auto i : vec) For(j, 0, n) f[i][j].clear();
        vec.clear();
        For(i, 1, r){
            int op, x, t; read(t); read(op); read(x); op--;
            if(fl) op ^= 1;
            ok[op][x][t] = 1;
        }
        printf("%d\n", dfs(0, 0, 0));
    }
    return 0;
}
