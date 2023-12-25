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
#define mod 998244353
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
using Z = Mint<P>;
Z inv2 = Z{2}.inv();

struct Node{
    Z a;
    int b;
};
struct Data : vector<Node>{};

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

Z get_val(Data &dat, int x){
    Z res = 0;
    for(Node i : dat) res += i.a * fp(Z{2}, 1ll * x * i.b % (P - 1));
    return res;
}

void sol(LL l, LL r, Data &suf){
    Data res = suf;
    for(auto &i : res){
        i.b = 2ll * i.b % (P - 1);
        i.a /= (Z{2} - fp(Z{2}, i.b));
    }
    res.pb({2, 0});
    r %= P - 1;
    Z tem = get_val(suf, r + 1) - 2;
    for(auto i : suf)
        tem -= i.a * fp(Z{2}, 2ll * i.b * (r + 1) % (P - 1)) / (Z{2} - fp(Z{2}, 2ll * i.b % (P - 1)));
    tem *= fp(inv2, r + 1);
    res.pb({tem, 1});
    if(l == 1){
        printf("%d\n", get_val(res, 1).x);
        return;
    }
    sol((l + 1) >> 1, l - 1, res);
}

int t;
LL n;

Z get_f(int x){
    if(x >= n) return 0;
    return inv2 * (get_f(x + 1) + get_f(2 * x)) + 1;
}

int main(){
	// freopen("in.txt", "r", stdin);
    read(t);
    while(t--){
        read(n);
        if(n == 1){
            puts("0");
            continue;
        }
        Data tem;
        sol((n + 1) >> 1, n - 1, tem);
    }
    return 0;
}
