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

const int P = 998244353;
Mint<P> g = 3, ig = g.inv();
using Z = Mint<P>;

vector<int> rev;

namespace NTT{
    
}

struct Poly : vector<Z>{
    Poly(){}
    Poly(int len){this->resize(len);}
    Poly(vector<Z> _f){*this = _f;}
    Poly ntt(Z gi){
        int lim = this->size();
        For(i, 0, lim - 1) if(rev[i] < i) swap(f[rev[i]], f[i]);
        for(int i = 2; i <= lim; i <<= 1){
            Z w = fp(gi, (P - 1) / i);
            int ii = i >> 1;
            for(int j = 0; j < lim; j += i){
                Z wi = 1;
                For(p, j, j + ii - 1){
                    Z tem1 = f[p], tem2 = wi * f[p + ii];
                    f[p] = tem1 + tem2;
                    f[p + ii] = tem1 - tem2;
                    wi *= w;
                }
            }
        }
        Z tem = ((Z)lim).inv();
        if(gi == ig) For(i, 0, lim - 1) f[i] *= tem;
        return *this;
    }
    Poly& operator += (Poly _f){
        int tem = max(f.size(), _f.f.size());
        f.resize(tem); _f.resize(tem);
        For(i, 0, tem - 1) f[i] += _f.f[i];
        return *this;
    }
    Poly& operator -= (Poly _f){
        int tem = max(f.size(), _f.f.size());
        f.resize(tem); _f.resize(tem);
        For(i, 0, tem - 1) f[i] -= _f.f[i];
        return *this;
    }
    Poly& operator *= (Poly _f){
        int len = f.size() + _f.f.size() - 1, lim = 1, l = 0;
        while(lim < len) lim <<= 1, l++;
        rev.resize(lim);
        For(i, 0, lim - 1) rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (l - 1));
        f.resize(lim);
        _f.resize(lim);
        this->ntt(g); _f.ntt(g);
        For(i, 0, lim - 1) f[i] *= _f.f[i];
        this->ntt(ig);
        resize(len);
        return *this;
    }
    Poly& operator *= (Z x){
        For(i, 0, f.size() - 1) f[i] *= x;
        return *this;
    }
    friend Poly operator + (Poly _f, Poly _g){return _f += _g;}
    friend Poly operator - (Poly _f, Poly _g){return _f -= _g;}
    friend Poly operator * (Poly _f, Poly _g){return _f *= _g;}
    friend Poly operator * (Poly _f, Z x){return _f *= x;}
    friend Poly operator * (Z x, Poly _f){return _f *= x;}
    Poly deri(){
        Poly asi(f.size() - 1);
        For(i, 0, f.size() - 2) asi.f[i] = f[i + 1] * (i + 1);
        return asi;
    }
    Poly inte(){
        Poly asi(f.size() + 1);
        For(i, 1, f.size()) asi.f[i] = f[i - 1] / i;
        return asi;
    }
    Poly inv(int mlim){
        Poly asi(1), tem, tem2(1); asi.f[0] = f[0].inv(); tem2.f[0] = 2;
        int lim = 1;
        while(lim < mlim){
            lim <<= 1;
            tem = *this; tem.resize(lim);
            asi = (asi * (tem2 - tem * asi)).resize(lim);
        }
        return asi.resize(mlim);
    }
    Poly ln(int mlim){return (inv(mlim) * deri()).inte().resize(mlim);}
    Poly exp(int mlim){
        Poly asi(1), tem, tem1(1); asi.f[0] = 1; tem1.f[0] = 1;
        int lim = 1;
        while(lim < mlim){
            lim <<= 1;
            tem = *this; tem.resize(lim);
            asi = (asi * (tem1 - asi.ln(lim) + tem)).resize(lim);
        }
        return asi.resize(mlim);
    }
    Poly sqrt(int mlim){
        Poly asi(1), tem; asi.f[0] = 1;
        int lim = 1;
        while(lim < mlim){
            lim <<= 1;
            tem = *this; tem.resize(lim);
            asi = (asi - (asi * asi - tem) * ((Z)2 * asi).inv(lim)).resize(lim);
        }
        return asi.resize(mlim);
        // return ((Z){2}.inv() * this->ln(mlim)).exp(mlim).resize(mlim);
    }
    Poly pfp(int mlim, int k){return ((Z){k} * this->ln(mlim)).exp(mlim).resize(mlim);}
};

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int main(){
	// freopen("in.txt", "r", stdin);
    return 0;
}

