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

int n, q, gc[55], to[55][maxn + 5];
struct Node{
    int v, c;
} a[55];
bool operator < (cst Node &x, cst Node &y){
    return (LL)x.c * y.v > (LL)y.c * x.v;
}

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int gcd(int x, int y){return y ? gcd(y, x % y) : x;}

int main(){
	// freopen("in.txt", "r", stdin);
    memset(to, -1, sizeof to);
    read(n); read(q);
    For(i, 1, n) read(a[i].v), read(a[i].c);
    sort(a + 1, a + n + 1);
    int tot = 0;
    gc[++tot] = a[1].v;
    For(i, 1, n){
        if(gcd(gc[tot], a[i].v) != gc[tot]){
            tot++;
            gc[tot] = gcd(gc[tot - 1], a[i].v);
            a[tot] = a[i];
            int tem = 0;
            For(o, 0, inf){
                if(to[tot][tem] != -1) break;
                to[tot][tem] = o;
                tem = (tem + a[tot].v) % gc[tot - 1];
            }
        }
    }
    // cout << to[2][2] << endl;
    while(q--){
        LL v; read(v);
        if(v % gc[tot]) puts("-1");
        else{
            LL asi = 0;
            Rof(i, tot, 1){
                if(i != 1 && to[i][v % gc[i - 1]] != -1){
                    asi += 1ll * a[i].c * to[i][v % gc[i - 1]];
                    v -= 1ll * a[i].v * to[i][v % gc[i - 1]];
                }
                // cout << v << endl;
                if(i == 1 || v % gc[i - 1]){
                    asi += 1ll * a[i].c * v / a[i].v;
                    break;
                }
            }
            printf("%lld\n", asi);
        }
    }
    return 0;
}
