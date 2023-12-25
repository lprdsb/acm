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
#define maxn 1000000
using namespace std;

int n, tot = 0;

struct Node{
	int len, ch[10], fa;
} poi[2 * maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int tot1 = 1;
int ins(int x, int las){
	int np = las, p;
	if(poi[np].ch[x] && poi[np].len + 1 == poi[poi[np].ch[x]].len) poi[np].ch[x];
	else p = ++tot1;
	poi[p].len = poi[np].len + 1;
	while(np && !poi[np].ch[x]) poi[np].ch[x] = p, np = poi[np].fa;
	if(!np) poi[p].fa = 1;
	else{
		int q = poi[np].ch[x];
		if(poi[np].len + 1 == poi[p].len) poi[p].fa = q;
		else{
			int nq = ++tot1; poi[nq] = poi[q];
			poi[nq].len = poi[np].len + 1;
			poi[q].fa = poi[p].fa = nq;
			while(np && poi[np].ch[x] == q) poi[np].ch[x] = nq, np = poi[np].fa;
		}
	}
	return p;
}

int a[maxn + 5], in[2 * maxn + 5];

#define mod 998244353

int num[maxn + 5], ok[2 * maxn + 5], val[2 * maxn + 5];

int main(){
	// freopen("in.txt", "r", stdin);
	read(n);
    For(i, 1, n) read(a[i]);
    int las = 1;
    Rof(i, n, 1) las = ins(a[i], las);
    For(i, 1, tot1) ok[poi[i].ch[0]] = 1;
    For(i, 1, n){
        if(!a[i]) num[i] = num[i - 1] + 1;
        else num[i] = 0;
    }
    int now = 1;
    Rof(i, n, 1){
        now = poi[now].ch[a[i]];
        if(a[i]) val[now] = (val[now] + num[i - 1] + 1) % mod;
    }
    For(i, 1, tot1) in[poi[i].fa]++;
    queue<int> q;
    For(i, 1, tot1) if(!in[i]) q.push(i);
    while(q.size()){
        int u = q.front(), fa = poi[u].fa; q.pop();
        val[fa] = (val[fa] + val[u]) % mod;
        in[fa]--;
        if(!in[fa]) q.push(fa);
    }
    int res = 1ll * n * (n + 1) / 2 % mod;
    res = 1ll * res * res % mod;
    For(i, 1, tot1) if(!ok[i])
        res = (res - 1ll * val[i] * val[i] % mod * (poi[i].len - poi[poi[i].fa].len) % mod + mod) % mod;
    int sum = 0;
    For(i, 1, n + 1) if(a[i] || i == n + 1) sum = (sum + 1ll * num[i - 1] * (num[i - 1] + 1) / 2 % mod) % mod;
    res = (res - 1ll * sum * sum % mod + mod) % mod;
    printf("%d\n", 1ll * res * 499122177 % mod);
	return 0;
}


