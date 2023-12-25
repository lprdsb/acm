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

int n, m, col[maxn + 5][maxn + 5], cnt[2][maxn + 5], vis[2][maxn + 5], tot = 0, to[2][maxn + 5][maxn + 5], b[maxn + 5], cntb, ma[2][maxn + 5][maxn + 5];
pair<int, pair<int, int> > as[2 * maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int l[maxn + 5][maxn + 5], r[maxn + 5][maxn + 5], u[maxn + 5][maxn + 5], d[maxn + 5][maxn + 5];
void init(){
	For(i, 1, n) r[i][0] = 1, l[i][m + 1] = m;
	For(i, 1, m) d[0][i] = 1, u[n + 1][i] = n;
	For(i, 1, n) For(j, 1, m){
		l[i][j] = j - 1;
		r[i][j] = j + 1;
		u[i][j] = i - 1;
		d[i][j] = i + 1;
	}
}
void del(int x, int y){
	r[x][l[x][y]] = r[x][y];
	l[x][r[x][y]] = l[x][y];
	u[d[x][y]][y] = u[x][y];
	d[u[x][y]][y] = d[x][y];
}

int find(int x){
	int l = 1, r = cntb;
	while(l < r){
		int mid = l + r >> 1;
		if(b[mid] >= x) r = mid;
		else l = mid + 1;
	}
	return l;
}

int main(){
	//freopen("in", "r", stdin);
	read(n); read(m);
	For(i, 1, n) For(j, 1, m) read(col[i][j]);
	For(i, 1, n){
		For(j, 1, m) b[j] = col[i][j];
		sort(b + 1, b + m + 1);
		cntb = unique(b + 1, b + m + 1) - b - 1;
//		if(i == 1) cout << b[1] << " " << b[2] << endl;
		For(j, 1, m){
			int x = to[0][i][j] = find(col[i][j]);
			if(!ma[0][i][x]) cnt[0][i]++;
			ma[0][i][x]++;
		}
	}
	For(i, 1, m){
		For(j, 1, n) b[j] = col[j][i];
		sort(b + 1, b + n + 1);
		cntb = unique(b + 1, b + n + 1) - b - 1;
		For(j, 1, n){
			int x = to[1][j][i] = find(col[j][i]);
			if(!ma[1][i][x]) cnt[1][i]++;
			ma[1][i][x]++;
		}
	}
//	For(i, 1, n){
//		For(j, 1, m) cout << to[1][i][j] << " "; cout << endl;
//	}
//	For(i, 1, m) cout << cnt[1][i] << endl;
	init();
	queue<pair<int, int>> q;
	For(i, 1, n) if(cnt[0][i] == 1) q.push(mp(0, i)), vis[0][i] = 1;
	For(i, 1, m) if(cnt[1][i] == 1) q.push(mp(1, i)), vis[1][i] = 1;
	while(q.size()){
		pair<int, int> now = q.front(); q.pop();
//		cout << now.fir << " " << now.sec << endl;
		if(!now.fir){
			int pos = l[now.sec][m + 1];
			if(pos) as[++tot] = mp(col[now.sec][pos], now);
			while(pos){
				int x = to[1][now.sec][pos];
				ma[1][pos][x]--;
				if(!ma[1][pos][x]){
					cnt[1][pos]--;
					if(!vis[1][pos] && cnt[1][pos] == 1) q.push(mp(1, pos)), vis[1][pos] = 1;
				}
				if(pos) del(now.sec, pos);
				pos = l[now.sec][pos];
			}
		}
		else{
			int pos = u[n + 1][now.sec];
			if(pos) as[++tot] = mp(col[pos][now.sec], now);
			while(pos){
				int x = to[0][pos][now.sec];
				ma[0][pos][x]--;
				if(!ma[0][pos][x]){
					cnt[0][pos]--;
					if(!vis[0][pos] && cnt[0][pos] == 1) q.push(mp(0, pos)), vis[0][pos] = 1;
				} 
				if(pos) del(pos, now.sec);
				pos = u[pos][now.sec];
			}
		}
	}
	int fl = 1;
	For(i, 1, n) if(l[i][m + 1]) fl = 0;
	For(i, 1, m) if(u[n + 1][i]) fl = 0;
	if(fl){
		printf("%d\n", tot);
		Rof(i, tot, 1) printf("%d %d %d\n", as[i].sec.fir + 1, as[i].sec.sec, as[i].fir);
	}
	else puts("-1");
	return 0;
}


