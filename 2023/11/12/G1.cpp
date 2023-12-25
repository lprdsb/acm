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

template<class T>
T fp(T x, int y){
    T asi = 1;
    while(y){
        if(y & 1) asi *= x;
        x *= x;
        y >>= 1;
    }
    return asi;
}

int T, n, m;
template<int P>
struct Mint{
    LL x;
    Mint(){x = 0;}
    Mint(LL _x) : x{norm(_x % P)}{}
    int norm(LL _x){
        if(_x < 0) _x += P;
        if(_x >= P) _x -= P;
        return _x;
    }
    Mint inv(){return fp(*this, P - 2);}
    Mint operator - (){return {P - x};}
    Mint& operator += (Mint _x) &{
        x = norm(x + _x.x);
        return *this;
    }
    Mint& operator -= (Mint _x) &{
        x = norm(x - _x.x);
        return *this;
    }
    Mint& operator *= (Mint _x) &{
        x = 1ll * x * _x.x % P;
        return *this;
    }
    Mint& operator /= (Mint _x) &{return *this *= _x.inv();}
    friend Mint operator + (Mint _x, Mint _y){return _x += _y;}
    friend Mint operator - (Mint _x, Mint _y){return _x -= _y;}
    friend Mint operator * (Mint _x, Mint _y){return _x *= _y;}
    friend Mint operator / (Mint _x, Mint _y){return _x /= _y;}
    friend bool operator == (Mint _x, Mint _y){return _x.x == _y.x;}
};

template<int P1, int B1, int P2, int B2>
struct Hsh{
    Mint<P1> v1; Mint<P2> v2;
    friend Hsh operator + (Hsh _x, Hsh _y){
        _x.v1 += _y.v1;
        _x.v2 += _y.v2;
        return _x;
    }
    friend Hsh operator * (Hsh _x, Hsh _y){
        _x.v1 *= _y.v1;
        _x.v2 *= _y.v2;
        return _x;
    }
    friend bool operator == (Hsh _x, Hsh _y){return _x.v1 == _y.v1 && _x.v2 == _y.v2;}
    Hsh(){v1 = 0; v2 = 0;}
    Hsh(LL _x) : v1{_x}, v2{_x}{}
    Hsh(Mint<P1> _x, Mint<P2> _y) : v1{_x}, v2{_y}{}
};
cst int P1 = 998244353, P2 = 1000000007, B1 = 13331, B2 = 13337;
using Z = Hsh<P1, B1, P2, B2>;

Z bas[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

vector<int> ch[maxn + 5];

int st[maxn + 5], top = 0;
map<int, map<int, bool> > ma;
int dep[maxn + 5], fa[maxn + 5];
void dfs(int u, int pre){
    dep[u] = dep[pre] + 1;
    fa[u] = pre;
    for(auto v : ch[u]) if(v != pre){
        if(!dep[v]) dfs(v, u);
        else if(dep[v] < dep[u]){
            ma[u][v] = ma[v][u] = 1;
            int now = u;
            while(now != v){
                st[++top] = now;
                ma[now][fa[now]] = 1;
                ma[fa[now]][now] = 1;
                now = fa[now];
            }
            st[++top] = now;
        } 
    }
}

int sz[maxn + 5];
Z f[maxn + 5];
void dfs1(int u, int pre){
    sz[u] = 1;
    f[u] = bas[1];
    vector<int> vec;
    for(auto v : ch[u]) if(v != pre && !ma[u][v]){
        dfs1(v, u);
        vec.pb(v);
        sz[u] += sz[v];
    }
    sort(vec.begin(), vec.end(), [](cst int &_x, cst int &_y){
        if(f[_x].v1 == f[_y].v1) return f[_x].v2.x < f[_y].v2.x;
        return f[_x].v1.x < f[_y].v1.x;
    });
    for(auto v : vec) f[u] = f[u] * bas[sz[v]] + f[v];
    f[u] = f[u] * Z{sz[u]};
}

int main(){
	// freopen("in.txt", "r", stdin);
    bas[0] = Z{1};
    bas[1] = Z{Mint<P1>{B1}, Mint<P2>{B2}};
    For(i, 2, maxn) bas[i] = bas[i - 1] * bas[1];
    read(T);
    while(T--){
        read(n); read(m);
        For(i, 1, m){
            int u, v; read(u); read(v);
            ch[u].pb(v);
            ch[v].pb(u);
        }
        if(m >= n + 1) puts("NO");
        else{
            if(m == n - 1) puts("YES");
            else{
                dfs(1, 0);
                int fl[2] = {0, 0}, fl1 = 0;
                Z uni[2];
                For(i, 1, top){
                    dfs1(st[i], 0);
                    if(top & 1){
                        if(!fl[0]) uni[0] = f[st[i]], fl[0] = 1;
                        else if(uni[0] == f[st[i]]);
                        else{
                            fl1 = 1;
                            break;
                        }
                    }
                    else{
                        if(!fl[i & 1]) uni[i & 1] = f[st[i]], fl[i & 1] = 1;
                        else if(uni[i & 1] == f[st[i]]);
                        else{
                            fl1 = 1;
                            break;
                        }
                    }
                }
                // cout << f[3].v1.x << " " << f[3].v2.x << endl;
                if(fl1) puts("NO");
                else puts("YES");
            }
        }
        top = 0;
        ma.clear();
        For(i, 1, n){
            dep[i] = 0;
            ch[i].resize(0);
        }
    }
}
