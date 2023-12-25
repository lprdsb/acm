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
#define maxn 500
using namespace std;

int n, k, a[maxn + 5][maxn + 5], sum[maxn * maxn + 5], tot = 0, pre[maxn + 5][maxn + 5], mn[maxn * maxn + 5][2], mx[maxn * maxn + 5][2], col[maxn * maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int main(){
	memset(mn, inf, sizeof mn);
	//freopen("in", "r", stdin);
	read(n); read(k);
	For(i, 1, n) For(j, 1, n){
		read(a[i][j]);
		if(!sum[a[i][j]]) col[++tot] = a[i][j];
		sum[a[i][j]]++;
		mn[a[i][j]][0] = min(mn[a[i][j]][0], i);
		mx[a[i][j]][0] = max(mx[a[i][j]][0], i);
		mn[a[i][j]][1] = min(mn[a[i][j]][1], j);
		mx[a[i][j]][1] = max(mx[a[i][j]][1], j);
	}
	if(tot <= k){
		printf("%d\n", k - tot);
		return 0;
	}
	For(i, 1, n){
		For(j, 1, n) For(o, 1, n) pre[j][o] = 0;
		For(j, 1, tot){
			if(max(mx[col[j]][0] - mn[col[j]][0] + 1, mx[col[j]][1] - mn[col[j]][1] + 1) <= i){
				int mn_x = max(1, mx[col[j]][0] - i + 1), mn_y = max(1, mx[col[j]][1] - i + 1);
				int mx_x = min(n - i + 1, mn[col[j]][0]), mx_y = min(n - i + 1, mn[col[j]][1]);
				if(mn_x <= mx_x && mn_y <= mx_y){
					pre[mn_x][mn_y]++;
					pre[mx_x + 1][mn_y]--;
					pre[mn_x][mx_y + 1]--;
					pre[mx_x + 1][mx_y + 1]++;
				}
			}
		}
		For(j, 1, n) For(o, 1, n){
			pre[j][o] += pre[j - 1][o] + pre[j][o - 1] - pre[j - 1][o - 1];
			if(tot - pre[j][o] == k - 1 || tot - pre[j][o] == k){
				//cout << i << " " << j << " " << o << endl;
				puts("1");
				return 0;
			}
		}
	}
	puts("2");
	return 0;
}
