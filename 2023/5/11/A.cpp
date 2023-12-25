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
#define maxn 20000
#define mod 1000000007
using namespace std;

int n, a[maxn + 5], num[maxn + 5], fac[maxn + 5], ifac[maxn + 5], b[maxn + 5], cnt = 0, as = 0;
class Gra{
    public:
        int ma[maxn + 5][2];
        void init(){
            For(i, 1, cnt) ma[b[i]][0] = ma[b[i]][1] = 0;
        }
        int add(int u, int v){
            if(ma[u][0]){
                if(ma[u][0] == v) return 1;
                if(ma[u][1]){
                    if(ma[u][1] == v) return 1;
                    return 0;
                }
                else ma[u][1] = v;
            }
            else ma[u][0] = v;
            return 1;
        }
} g;
struct Frac{
    int a, b;
};
bool operator < (cst Frac &x, cst Frac &y){
    return (DD)x.a / x.b < (DD)y.a / y.b;
}
map<pair<Frac, Frac>, bool> ma;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int fp(int x, int y){
    int asi = 1;
    while(y){
        if(y & 1) asi = 1ll * asi * x % mod;
        x = 1ll * x * x % mod;
        y >>= 1;
    }
    return asi;
}

int c(int x, int y){return 1ll * fac[x] * ifac[y] % mod * ifac[x - y] % mod;}

int gcd(int x, int y){return y ? gcd(y, x % y) : x;}

int st[maxn + 5], top = 0, vis[maxn + 5];
void sol(int x1, int y1, int x2, int y2){
    if(x1 == x2 || y1 == y2) return;
    Frac k = {y2 - y1, x2 - x1}, bb = {x2 * y1 - x1 * y2, x2 - x1};
    int gc = gcd(abs(k.a), abs(k.b));
    k.a /= gc; k.b /= gc;
    if(k.b < 0) k.a = -k.a, k.b = -k.b;
    gc = gcd(abs(bb.a), abs(bb.b));
    bb.a /= gc; bb.b /= gc;
    if(bb.b < 0) bb.a = -bb.a, bb.b = -bb.b;
    if(ma[{k, bb}]) return;
    ma[{k, bb}] = 1;


    g.init();
    int x = x2 - x1, y = y2 - y1;
    For(i, 1, cnt) if(num[b[i]]){
        int tem;
        if(y * (b[i] - x1) % x == 0){
            tem = y * (b[i] - x1) / x + y1;
            if(tem < 0 || tem > maxn + 1 || !num[tem]) continue;
            if(!g.add(b[i], tem)) return;
            if(!g.add(tem, b[i])) return;
        }
    }
    For(i, 1, cnt) if(num[b[i]] && !g.ma[b[i]][0]) return;
    For(i, 1, cnt) vis[b[i]] = 0;
    int asi = 1, fl = 0;
    For(i, 1, cnt) if(num[b[i]] && !vis[b[i]]){
        int now = b[i];
        if(g.ma[now][0] == now){
            if(num[now] & 1){
                asi = 0;
                break;
            }
            else{
                int tem = num[now];
                asi = 1ll * asi * fac[tem] % mod;
            }
        }
        else{
            top = 0;
            while(now){
                vis[now] = 1;
                st[++top] = now;
                if(!vis[g.ma[now][0]]) now = g.ma[now][0];
                else if(!vis[g.ma[now][1]]) now = g.ma[now][1];
                else break;
            }
            For(j, 1, top / 2) swap(st[j], st[top - j + 1]);
            if(g.ma[b[i]][1]){
                now = g.ma[b[i]][1];
                while(now){
                    vis[now] = 1;
                    st[++top] = now;
                    if(!vis[g.ma[now][0]]) now = g.ma[now][0];
                    else if(!vis[g.ma[now][1]]) now = g.ma[now][1];
                    else break;
                }
            }
            if(k.a == -1 && k.b == 1){
                if(top == 2 && num[st[1]] == num[st[2]]){
                    if(num[st[1]] == n / 2) fl = 1;
                    asi = 1ll * asi * (num[st[1]] + 1) % mod * fac[num[st[1]]] % mod * fac[num[st[1]]] % mod;
                }
                else asi = 0;
            }
            else{
                int asii = fac[num[st[1]]], res = num[st[1]];
                For(j, 2, top){
                    // cout << k.a << " " << k.b << " " << num[st[j]] << " " << res << endl;
                    if(num[st[j]] < res){
                        asii = 0;
                        break;
                    }
                    asii = 1ll * asii * fac[num[st[j]]] % mod;
                    res = num[st[j]] - res;
                }
                if(!res) asi = 1ll * asi * asii % mod;
                else asi = 0;
            }
        }
    }
    if(asi && fl) asi = (asi - 2ll * fac[n / 2] * fac[n / 2] % mod + mod) % mod;
    as = (1ll * as + asi) % mod;
}

void sol0(){
    int mx = 0;
    For(i, 1, cnt) if(num[b[i]] > num[mx]) mx = b[i];
    if(num[mx] >= n / 2){
        as++;
        if(num[mx] != n) as++;
    }
}

int main(){
	// freopen("in.txt", "r", stdin);
    fac[0] = 1;
    For(i, 1, maxn) fac[i] = 1ll * fac[i - 1] * i % mod;
    ifac[maxn] = fp(fac[maxn], mod - 2);
    Rof(i, maxn - 1, 0) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % mod; 
    read(n);
    For(i, 1, n){
        read(a[i]);
        a[i] += 10001;
        num[a[i]]++;
        b[++cnt] = a[i];
    }
    sort(b + 1, b + cnt + 1);
    cnt = unique(b + 1, b + cnt + 1) - b - 1;
    For(i, 1, cnt) For(j, 1, cnt){
        sol(a[1], a[2], b[i], b[j]);
        sol(a[2], a[1], b[i], b[j]);
        sol(a[1], b[i], a[2], b[j]);
        sol(a[2], b[i], a[1], b[j]);
        sol(a[1], b[i], b[j], a[2]);
        sol(a[2], b[i], b[j], a[1]);
        sol(b[i], a[1], b[j], a[2]);
        sol(b[i], a[2], b[j], a[1]);
    }
    For(i, 1, cnt) as = 1ll * as * ifac[num[b[i]]] % mod;
    sol0();
    printf("%d\n", as);
	return 0;
}
