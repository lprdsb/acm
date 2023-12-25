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
#define maxn 10000000
using namespace std;

int tot = 0;
struct Node{
	char c;
	int now, val;
} node[maxn + 5];
bool operator < (Node &x, Node &y){
	if(x.now != y.now) return x.now < y.now;
	return x.val < y.val;
}

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int x;

int main(){
	//freopen("in", "r", stdin);
	while(scanf("%d", &x) != EOF){
		node[++tot] = (Node){'B', x + 2, 1};
		node[++tot] = (Node){'P', x + 5, 2};
		node[++tot] = (Node){'C', x + 6, 3};
	}
	sort(node + 1, node + tot + 1);
	For(i, 1, tot) printf("%d %c\n", node[i].now, node[i].c);
	return 0;
}



