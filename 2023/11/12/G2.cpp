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
template<class T1, class T2>
struct Hsh{
    T1 v1;
    T2 v2;
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
    Hsh(T1 _x, T2 _y) : v1{_x}, v2{_y}{}
};
using Z1 = Mint<998244353>;
using Z2 = Mint<1000000007>;

struct fun{
    bool operator ()(int x, int y)cst{
        return x > y;
    }
};


int main(){
	// Hsh<Z1, Z2> tem{998244354};
    // cout << tem.v1.x << endl;
}
