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
#define mod 998244353
using namespace std;

int n, k, a[maxn + 5], tot = 1;
struct Data : array<int, 4>{};
Data f[10 * maxn + 5];
int ch[10 * maxn + 5][2];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

Data que(int x){
    int now = 1;
    Data res = {0, 0, 0, 0};
    Rof(o, 20, 0){
        if((k >> o) & 1) now = ch[now][!((x >> o) & 1)];
        else{
            int tem = ch[now][!((x >> o) & 1)];
            res[0] = (res[0] + f[tem][0]) % mod;
            res[1] = (1ll * res[1] + f[tem][0] + f[tem][1]) % mod;
            res[2] = (res[2] + f[tem][0] + 2ll * f[tem][1] + f[tem][2]) % mod;
            res[3] = (res[3] + f[tem][0] + 3ll * f[tem][1] + 3ll * f[tem][2] + f[tem][3]) % mod;
            now = ch[now][(x >> o) & 1];
        }
        if(!now) break;
    }
    return res;
}
void ins(int x, Data val){
    int now = 1;
    Rof(o1, 20, 0){
        if(!ch[now][(x >> o1) & 1]) ch[now][(x >> o1) & 1] = ++tot;
        now = ch[now][(x >> o1) & 1];
        For(o2, 0, 3) f[now][o2] = (f[now][o2] + val[o2]) % mod;
    }
}

int main(){
	// freopen("in.txt", "r", stdin);
    read(n); read(k);
    if(k >= 2000000){
        puts("0");
        return 0;
    }
    For(i, 1, n) read(a[i]);
    ins(0, {1, 0, 0, 0});
    For(i, 1, n){
        a[i] ^= a[i - 1];
        Data res = que(a[i]);
        // if(i == 2) cout << res[0] << endl;
        if(i == n) printf("%d\n", res[3]);
        ins(a[i], res);
    }
    return 0;
}
