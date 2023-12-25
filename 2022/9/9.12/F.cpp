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

int t, n, w, m, a[maxn + 5], pos[10][2], as1, as2;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

void chk(int x, int y){
	if(as1 == -1){
		as1 = x, as2 = y;
		return;
	}
	if(x < as1){
		as1 = x, as2 = y;
		return;
	}
}

int main(){
	//freopen("in", "r", stdin);
	read(t);
	while(t--){
		memset(pos, -1, sizeof pos);
		string s; cin >> s;
		read(w); read(m);
		n = s.length();
		For(i, 1, n) a[i] = (a[i - 1] + s[i - 1] - '0') % 9;
		For(i, 1, n - w + 1){
			int now = (a[i + w - 1] - a[i - 1] + 9) % 9;
			if(pos[now][0] == -1) pos[now][0] = i;
			else if(pos[now][1] == -1) pos[now][1] = i;
		} 
		while(m--){
			as1 = as2 = -1;
			int l, r, k; read(l); read(r); read(k);
			int tem = (a[r] - a[l - 1] + 9) % 9;
			For(i, 0, 8){
				if(pos[i][0] != -1){
					int to = (k - tem * i + 999) % 9;
					if(to == i){
						if(pos[i][1] != -1) chk(pos[i][0], pos[i][1]);
					}
					else if(pos[to][0] != -1) chk(pos[i][0], pos[to][0]);
				}
			}
			printf("%d %d\n", as1, as2);
		}
	}
	return 0;
}


