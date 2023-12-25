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
#define maxn 300000
using namespace std;

int t, n, f[maxn + 5], to[4] = {1, 3, 0, 2};

struct node{
	int ch[2], val[4];
};
vector<node> tr;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int main(){
	//freopen("in", "r", stdin);
	read(t);
	while(t--){
		tr.clear();
		tr.pb((node){{0, 0}, {0, 0, 0, 0}});
		read(n);
		For(i, 0, n - 1){
			int a, now = 0; read(a);
			f[i] = 0;
			Rof(j, 29, 0){
				int b1 = (a >> j) & 1, b2 = (i >> j) & 1;
				//if(i == 2 && j == 1) cout << b1 << " " << b2 << endl;
				f[i] = max(f[i], tr[now].val[to[b1 * 2 + b2]] + 1);
				//tr[now].val[b1 * 2 + b2] = max(tr[now].val[b1 * 2 + b2], f[i]);
				if(!tr[now].ch[b1 ^ b2]){
					tr.pb((node){{0, 0}, {0, 0, 0, 0}});
					tr[now].ch[b1 ^ b2] = tr.size() - 1;
				}
				now = tr[now].ch[b1 ^ b2];
			}
			now = 0;
			Rof(j, 29, 0){
				int b1 = (a >> j) & 1, b2 = (i >> j) & 1;
				//if(i == 2 && j == 1) cout << b1 << " " << b2 << endl;
				f[i] = max(f[i], tr[now].val[to[b1 * 2 + b2]] + 1);
				tr[now].val[b1 * 2 + b2] = max(tr[now].val[b1 * 2 + b2], f[i]);
				if(!tr[now].ch[b1 ^ b2]){
					tr.pb((node){{0, 0}, {0, 0, 0, 0}});
					tr[now].ch[b1 ^ b2] = tr.size() - 1;
				}
				now = tr[now].ch[b1 ^ b2];
			}
		}
		int as = 0;
		For(i, 1, n) as = max(as, f[i]);
		printf("%d\n", as);
	}
	return 0;
}
