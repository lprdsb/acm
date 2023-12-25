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

int n, m, a[15][15];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

bool chk(int ind_x, int ind_y, int sta){
	if(ind_y == 1) return 1;
	if(a[ind_x - 1][ind_y - 1] == -1) return 1;
	int sum = (sta & 1) + ((sta >> 1) & 1) + ((sta >> m) & 1) + ((sta >> (m + 1)) & 1) + ((sta >> 2 * m) & 1) + ((sta >> (2 * m + 1)) & 1);
	if(ind_y == 2) return a[ind_x - 1][ind_y - 1] == sum;
	sum += ((sta >> 2) & 1) + ((sta >> (m + 2)) & 1) + ((sta >> (2 * m + 2)) & 1);
	return a[ind_x - 1][ind_y - 1] == sum;
}

bool chk1(int ind_x, int sta){
	if(a[ind_x - 1][m] == -1) return 1;
	int sum = (sta & 1) + ((sta >> 1) & 1) + ((sta >> m) & 1) + ((sta >> (m + 1)) & 1) + ((sta >> (2 * m)) & 1) + ((sta >> (2 * m + 1)) & 1);
	return a[ind_x - 1][m] == sum;
}

bool chk2(int sta){
	int sum = (sta & 1) + ((sta >> m) & 1);
	For(i, 1, m){
		if(i != m) sum += ((sta >> i) & 1) + ((sta >> (m + i)) & 1);
		if(a[n][m - i + 1] != -1 && a[n][m - i + 1] != sum) return 0;
		if(i >= 2) sum -= ((sta >> (i - 2)) & 1) + ((sta >> (m + i - 2)) & 1);
	}
	return 1;
}

int as[15][15], Sta;
bool f[11][11][4194304];
int dfs(int ind_x, int ind_y, int sta){
	// cout << ind_x << " " << ind_y << endl;
	if(ind_y == m + 1){
		if(!chk1(ind_x, sta)) return 0;
		ind_x++;
		ind_y = 1;
	}
	if(ind_x == n + 1) return chk2(sta);
	if(f[ind_x][ind_y][sta]) return 0;
	if(chk(ind_x, ind_y, sta << 1) && dfs(ind_x, ind_y + 1, (sta << 1) & Sta)){
		as[ind_x][ind_y] = 0;
		return 1;
	}
	if(chk(ind_x, ind_y, (sta << 1) | 1) && dfs(ind_x, ind_y + 1, ((sta << 1) & Sta) | 1)){
		as[ind_x][ind_y] = 1;
		return 1;
	}
	f[ind_x][ind_y][sta] = 1;
	return 0;
}

int main(){
	// freopen("in.txt", "r", stdin);
	memset(a, -1, sizeof a);
	read(n); read(m);
	Sta = (1 << (2 * m + 2)) - 1;
    For(i, 1, n) For(j, 1, m){
        char c; cin >> c;
        if(c != '_') a[i][j] = c - '0';
    }
    // cout << dfs(0, 0, 0) << endl;
	dfs(1, 1, 0);
	For(i, 1, n){
		For(j, 1, m) printf("%d", as[i][j]);
		puts("");
	}
    return 0;
}
