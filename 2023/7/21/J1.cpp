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
#define sasd
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

template<int P>
struct Mint{
    int x;
    Mint(){x = 0;}
    Mint(int _x) : x{norm(_x % P)}{}
    int norm(int _x){
        if(_x < 0) _x += P;
        if(_x >= P) _x -= P;
        return _x;
    }
    Mint inv(){return fp(*this, P - 2);}
    Mint operator - (){return {P - x};}
    inline Mint& operator += (Mint _x) &{
        x = norm(x + _x.x);
        return *this;
    }
    inline Mint& operator -= (Mint _x) &{
        x = norm(x - _x.x);
        return *this;
    }
    inline Mint& operator *= (Mint _x) &{
        x = 1ll * x * _x.x % P;
        return *this;
    }
    inline Mint& operator /= (Mint _x) &{return *this *= _x.inv();}
    inline friend Mint operator + (Mint _x, cst Mint &_y){return _x += _y;}
    inline friend Mint operator - (Mint _x, cst Mint &_y){return _x -= _y;}
    inline friend Mint operator * (Mint _x, cst Mint &_y){return _x *= _y;}
    inline friend Mint operator / (Mint _x, cst Mint &_y){return _x /= _y;}
    inline friend bool operator == (Mint _x, cst Mint &_y){return _x.x == _y.x;}
};

const int P = 998244353;
Mint<P> g = 3, ig = g.inv();
using Z = Mint<P>;

vector<int> rev;


vector<Z> roots{Z(0), Z(1)};

LL tot = 0;
struct Poly : vector<Z>{
    // vector<Z> f;
    Poly(){}
    Poly(int len){(*this).resize(len);}
    Poly(vector<Z> _f){
        (*this).resize(_f.size());
        For(i, 0, _f.size() - 1) (*this)[i] = _f[i];
    }
    void ntt(Z gi){
        int n = this->size();
        if (rev.size() != n) {
			int k = __builtin_ctz(n) - 1;
			rev.resize(n);
			for (int i = 0; i < n; i++)rev[i] = rev[i >> 1] >> 1 | (i & 1) << k;
		}
		for (int i = 0; i < n; i++)if (rev[i] < i)std::swap((*this)[i], (*this)[rev[i]]);
		// if (roots.size() < n) {
			int k = __builtin_ctz(roots.size());
			roots.resize(n);
			while ((1 << k) < n) {
				Z e = fp(gi, (P - 1) >> (k + 1));
				for (int i = 1 << (k - 1); i < (1 << k); i++)
					roots[i << 1] = roots[i], roots[i << 1 | 1] = roots[i] * e;
				k++;
			}
		// }
		for (int k = 1; k < n; k <<= 1) {
			for (int i = 0; i < n; i += k << 1) {
				for (int j = 0; j < k; j++) {
					Z u = (*this)[i + j], v = (*this)[i + j + k] * roots[k + j];
					(*this)[i + j] = u + v, (*this)[i + j + k] = u - v;
				}
			}
		}
        if(gi == ig){
            Z tem = ((Z)n).inv();
            For(i, 0, n - 1) (*this)[i] *= tem;
        }
    }
    inline Poly& operator += (Poly _f){ 
        (*this).resize(max((*this).size(), _f.size()));
        For(i, 0, min((*this).size(), _f.size()) - 1) (*this)[i] += _f[i];
        return *this;
    }
    inline Poly& operator -= (Poly _f){
        (*this).resize(max((*this).size(), _f.size()));
        For(i, 0, min((*this).size(), _f.size()) - 1) (*this)[i] -= _f[i];
        return *this;
    }
    inline Poly& operator *= (Poly _f){
        tot += max((*this).size(), _f.size());
        int len = (*this).size() + _f.size() - 1, lim = 1, l = 0;
        while(lim < len) lim <<= 1, l++;
        rev.resize(lim);
        For(i, 0, lim - 1) rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (l - 1));
        (*this).resize(lim);
        _f.resize(lim);
        this->ntt(g); _f.ntt(g);
        For(i, 0, lim - 1) (*this)[i] *= _f[i];
        this->ntt(ig);
        resize(len);
        return *this;
    }
    Poly& operator *= (Z x){
        For(i, 0, (*this).size() - 1) (*this)[i] *= x;
        return *this;
    }
    inline friend Poly operator + (Poly _f, cst Poly &_g){return _f += _g;}
    inline friend Poly operator - (Poly _f, cst Poly &_g){return _f -= _g;}
    inline friend Poly operator * (Poly _f, cst Poly &_g){return _f *= _g;}
    inline Poly inv(int mlim){
        Poly asi(1), tem, tem2(1); asi[0] = (*this)[0].inv(); tem2[0] = 2;
        int lim = 1;
        while(lim < mlim){
            lim <<= 1;
            tem = *this; tem.resize(lim);
            asi *= (tem2 - tem * asi);
            asi.resize(lim);
        }
        asi.resize(mlim);
        return asi;
    }
};

#define maxn 200000
int n, m, p;
Z a[maxn + 5], b[maxn + 5], c[maxn + 5], d[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

Poly G;
struct Data{
    Poly G[6], F;
};

Data sol(int l, int r){
    Data asi;
    if(l == r){
        vector<Z> tem = {d[l]};
        asi.G[1] = asi.G[3] = tem;
        asi.G[2] = (vector<Z>){1, -b[l]};
        asi.G[4] = asi.G[5] = asi.F = (vector<Z>){0, a[l - 1]};
        return asi;
    }
    int mid = l + r >> 1;
    Data gl = sol(l, mid), gr = sol(mid + 1, r);
    asi.G[1] = gl.G[1] * gr.G[2] + gl.G[3] * gr.G[4] + gl.G[2] * gr.G[1];
    asi.G[2] = gl.G[2] * gr.G[2];
    asi.G[3] = gl.G[3] * gr.G[5] + gl.G[2] * gr.G[3];
    asi.G[4] = gl.G[4] * gr.G[2] + gl.G[5] * gr.G[4];
    asi.G[5] = gl.G[5] * gr.G[5];
    asi.F = gl.F * gr.G[2] + gl.G[5] * gr.G[4];
    return asi;
}

Poly sol1(int l, int r){
    if(l == r){
        G[l] += c[l] * G[l - 1];
        return {{1, c[l]}};
    }
    int mid = l + r >> 1;
    Poly tem{r - l + 1};
    For(i, 0, tem.size() - 1) tem[i] = G[l + i];
    Poly gl = sol1(l, mid);
    tem *= gl;
    For(i, mid + 1, r) G[i] = tem[i - l];
    gl *= sol1(mid + 1, r);
    return gl;
}

int main(){
	freopen("in.txt", "r", stdin);
    read(n); read(m); read(p);
    For(i, 1, n + m - 1) read(a[i]), a[i] *= p;
    For(i, 1, n + m - 1) read(b[i]), b[i] *= 1 - p;
    For(i, 1, n) read(c[i]), c[i] *= 1 - p;
    For(i, 1, m) read(d[i]);
    G.resize(n + 1);
    G[0] = d[1];
    For(i, 1, n) G[i] = G[i - 1] * b[1];
    Data tem = sol(2, n + m);
    // For(i, 0, tem.G[1].size() - 1) cout << tem.G[1][i].x << " "; cout << endl;
    // cout << "asd" << endl;
    tem.F += tem.G[2];
    tem.G[2] = tem.G[2].inv(n + 1);
    G = (G * tem.F + tem.G[1]) * tem.G[2];
    // For(i, 0, tem.F.size() - 1) cout << tem.F[i].x << " "; cout << endl;
    G.resize(n + 1);
    // For(i, 0, G.size() - 1) cout << G[i].x << " "; cout << endl;
    Z tem1 = (Z){m}.inv();
    sol1(1, n);
    For(i, 1, n) printf("%d\n", G[i] * tem1);
    // cout << clock() / 1000 << endl;
    return 0;
}

