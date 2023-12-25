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

int t, n, a[maxn + 5], st[maxn + 5], top = 0;
vector<pair<int, int> > vec;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

void add(int l, int r){
	if(l > r) return;
	vec.pb(mp(l, r));
}

int main(){
	//freopen("in", "r", stdin);
	read(t);
	while(t--){
		top = 0;
		vec.clear();
		read(n);
		For(i, 1, n){
			read(a[i]);
			if(a[i]) st[++top] = i;
		}
		if(top & 1) puts("-1");
		else if(!top) printf("1\n1 %d\n", n);
		else{
			add(1, st[1] - 1);
			For(i, 1, top / 2){
				if(i != 1) add(st[2 * (i -  1)] + 1, st[2 * i - 1] - 1);
				if(a[st[2 * i]] == a[st[2 * i - 1]]){
					if((st[2 * i] - st[2 * i - 1]) & 1) add(st[2 * i - 1], st[2 * i]);
					else add(st[2 * i - 1], st[2 * i - 1]), add(st[2 * i - 1] + 1, st[2 * i]);
				}
				else{
					if((st[2 * i] - st[2 * i - 1]) & 1) add(st[2 * i - 1], st[2 * i - 1]), add(st[2 * i - 1] + 1, st[2 * i]);
					else add(st[2 * i - 1], st[2 * i]);
				}
			}
			add(st[top] + 1, n);
			printf("%d\n", vec.size());
			for(auto i : vec) printf("%d %d\n", i.fir, i.sec);
		}
	}
	return 0;
}



