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

int n, a[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int poi_tot = 0;
struct Poi{
    Poi *ch[2];
} poi[40 * maxn + 5];
Poi *get_new(){
    poi[++poi_tot] = {};
    return &poi[poi_tot];
}
Poi *get_o(Poi *rt, int o){
    if(!rt->ch[o]) rt->ch[o] = get_new();
    return rt->ch[o];
}

int main(){
	//freopen("in", "r", stdin);
    read(n);
    For(i, 2, n) read(a[i]), a[i] ^= a[i - 1];
    Poi *Rt = get_new();
    For(i, 1, n){
        Poi *now = Rt;
        Rof(o, 19, 0){
            int to = (a[i] >> o) & 1;
            now = get_o(now, to);
        }
    }
    For(i, 1, n){
        Poi *now = Rt;
        int val = 0;
        Rof(o, 19, 0){
            int to = (a[i] >> o) & 1;
            to ^= 1;
            if(now->ch[to]){
                now = now->ch[to];
                val ^= (1 << o);
            }
            else now = now->ch[!to];
        }
        if(val == n - 1){
            For(j, 1, n) printf("%d ", a[i] ^ a[j]);
            break;
        }
    }
    return 0;
}
