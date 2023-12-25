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

int n, a[maxn + 5], las[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

vector<int> ch[maxn + 5];
int in[maxn + 5], as[maxn + 5];

int main(){
	//freopen("in", "r", stdin);
    read(n);
    For(i, 1, n){
        read(a[i]);
        if(a[i] != 1 && !las[a[i] - 1]){
            puts("-1");
            return 0;
        }
        if(a[i] != 1){
            ch[las[a[i] - 1]].pb(i);  
            in[i]++;
        }
        if(las[a[i]]) ch[i].pb(las[a[i]]), in[las[a[i]]]++;
        las[a[i]] = i;
    }
    queue<int> q;
    For(i, 1, n) if(!in[i]) q.push(i);
    int tot = 0;
    while(q.size()){
        int u = q.front(); q.pop();
        as[u] = ++tot;
        for(auto v : ch[u]){
            in[v]--;
            if(!in[v]) q.push(v);
        }
    }
    if(tot == n){
        For(i, 1, n) printf("%d ", as[i]);
    }
    else puts("-1");
}
