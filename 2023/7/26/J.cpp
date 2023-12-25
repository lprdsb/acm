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

int t, n, m, cnt1 = 0, cnt2 = 0;
struct Edge{
	int u, v, w;
} e1[maxn + 5], e2[maxn + 5];
bool operator < (Edge x, Edge y){return x.w < y.w;}

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int fa[maxn + 5], as[maxn + 5];
int find(int x){return fa[x] == x ? x : fa[x] = find(fa[x]);}

int main(){
	// freopen("in.txt", "r", stdin);
	For(i, 1, maxn) fa[i] = i;
	read(t);
	while(t--){
		read(n); read(m);
		For(i, 1, m){
			int u, v, w1, w2; read(u); read(v); read(w1); read(w2);
			e1[i] = {u, v, w1};
			e2[i] = {u, v, w2};
		}
		sort(e1 + 1, e1 + m + 1);
		For(i, 1, m){
			int u = e1[i].u, v = e1[i].v;
			if(find(u) != find(v)){
				e1[++cnt1] = e1[i];
				fa[find(u)] = find(v);
			}
		}
		For(i, 1, n) fa[i] = i;
		
		sort(e2 + 1, e2 + m + 1);
		For(i, 1, m){
			int u = e2[i].u, v = e2[i].v;
			if(find(u) != find(v)){
				e2[++cnt2] = e2[i];
				fa[find(u)] = find(v);
			}
		}
		For(i, 1, n) fa[i] = i;

		For(o, 0, 2000){
			int l = 1, r = 1, cnt = 0, val = 0;
			while(l <= cnt1 || r <= cnt2){
				int fl = 0;
				Edge tem;
				if(l > cnt1) tem = e2[r++], fl = 1;
				else if(r > cnt2) tem = e1[l++];
				else if(e1[l].w < e2[r].w + (DD)o / 2) tem = e1[l++];
				else tem = e2[r++], fl = 1;
				if(find(tem.u) != find(tem.v)){
					cnt += fl;
					fa[find(tem.u)] = find(tem.v);
					val += tem.w;
				}
			}
			as[cnt] = val;
			For(i, 1, n) fa[i] = i;
		}

		int pre = -1;
		For(i, 0, n - 1){
			if(as[i]){
				if(pre + 1 != i){
					int tem = (as[pre] - as[i]) / (i - pre);
					For(j, pre + 1, i - 1) as[j] = as[j - 1] - tem;
				}
				pre = i;
			}
		}
		For(i, 0, n - 1) printf("%d\n", as[i]);

		For(i, 0, n) as[i] = 0;
		For(i, 1, n) fa[i] = i;
		cnt1 = cnt2 = 0;
	}
}
