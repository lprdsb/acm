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
using namespace std;

int q;
unordered_map<int, int> fa, val;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int get_fa(int x){
    if(!fa[x]) fa[x] = x;
    return fa[x];
}

int find(int x){
    if(x == get_fa(x)) return x;
    int tem = fa[x];
    fa[x] = find(fa[x]);
    val[x] ^= val[tem];
    return fa[x];
}

int main(){
	//freopen("in", "r", stdin);
    read(q);
    int las = 0;
    For(i, 1, q){
        int t; read(t);
        if(t == 1){
            int l, r, x; read(l); read(r); read(x);
            l ^= las; r ^= las; x ^= las;
            if(l > r) swap(l, r);
            l += 2; r += 2;
            if(find(l - 1) != find(r)){
                val[fa[l - 1]] = x ^ val[l - 1] ^ val[r];
                fa[fa[l - 1]] = fa[r];
            }
        }
        else{
            int l, r; read(l); read(r);
            l ^= las; r ^= las;
            if(l > r) swap(l, r);
            l += 2; r += 2;
            if(find(l - 1) == find(r)) printf("%d\n", las = val[l - 1] ^ val[r]);
            else{
                las = 1;
                puts("-1");
            }
        }
    }
    return 0;
}
