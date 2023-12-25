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
#define maxn 100000
using namespace std;

int n, m, to[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int C, T;

int fa[2 * maxn + 5], ok[2 * maxn + 5], col[2 * maxn + 5];
int find(int x){
    if(fa[x] == x) return x;
    int ffa = find(fa[x]);
    ok[x] ^= ok[fa[x]];
    fa[x] = ffa;
    return fa[x];
}

int main(){
	// freopen("in.txt", "r", stdin);
    read(C); read(T);
    For(i, 1, 2 * maxn) fa[i] = i, ok[i] = col[i] = 0;
    while(T--){
        // cout << "asd" << T << endl;
        read(n); read(m);
        For(i, 1, n) to[i] = i;
        int tot = n;
        For(i, 1, m){
            char c; cin >> c;
            if(c == '+'){
                int u, v; read(u); read(v);
                int pre = to[v];
                to[u] = ++tot;
                fa[tot] = pre;
            }
            else if(c == '-'){
                int u, v; read(u); read(v);
                int pre = to[v];
                to[u] = ++tot;
                fa[tot] = pre;
                ok[tot] = 1;
            }
            else{
                int u; read(u);
                to[u] = ++tot;
                if(c == 'U') col[tot] = 1;
            }
        }
        For(i, 1, n){
            if(find(i) != find(to[i])){
                ok[find(i)] = ok[i] ^ ok[to[i]];
                fa[find(i)] = find(to[i]);
            }
        }
        For(i, 1, n){
            find(i); find(to[i]);
            if(ok[i] != ok[to[i]]) col[find(i)] = 1;
        }
        int res = 0;
        For(i, 1, n) res += col[find(to[i])];
        printf("%d\n", res);
        For(i, 1, tot) fa[i] = i, ok[i] = col[i] = 0;
    }
    return 0;
}
