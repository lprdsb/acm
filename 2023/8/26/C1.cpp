#include<bits/stdc++.h>
#define For(i, a, b) for(LL i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(LL i = (a), en = (b); i >= en; --i)
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
#define maxn 300000
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

struct Matrix{
    Z a[3][3];
} tra = {{{Z{3} / 4, Z{1} / 4}
        , {Z{1} / 4, Z{1} / 2, Z{1} / 4}
        , {0, Z{1} / 4, Z{3} / 4}}}, uni = {{{1}, {0, 1}, {0, 0, 1}}};
Matrix operator * (Matrix _x, Matrix _y){
    Matrix res = {};
    For(i, 0, 2) For(j, 0, 2){
        Z tem = _x.a[i][j];
        For(p, 0, 2) res.a[i][p] += tem * _y.a[j][p];
    }
    return res;
}

Matrix mfp(Matrix x, LL y){
    Matrix asi = uni;
    while(y){
        if(y & 1) asi = asi * x;
        x = x * x;
        y >>= 1;
    }
    return asi;
}

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int T, a0, p, q;
LL N;
map<LL, LL> A;
int st[maxn + 5], top = 0;
int id[maxn + 5];

int main(){
	// freopen("in.txt", "r", stdin);
    read(T);
    if(T == 1){
        read(N);
        For(i, 1, N){
            LL x; read(x);
            A[x]++;
        }
    }
    else{
        read(N); read(a0); read(p); read(q);
        LL s = 1;
        while(666){
            a0 = (1ll * a0 * p + p) % q + 1;
            if(!id[a0]) st[id[a0] = ++top] = a0;
            else{
                s = id[a0];
                break;
            }
        }
        For(i, 1, min(N, s - 1)) A[st[i]] = 1;
        N -= s - 1;
        For(i, s, top) A[st[i]] = N / (top - s + 1) + ((i - s + 1) <= N % (top - s + 1));
    }
    if(!N) puts("0");
    else{
        Z as = 0;
        for(auto [_, cnt] : A) if(cnt) as += mfp(tra, cnt).a[2][0];
        printf("%d\n", as.x);
    }
    return 0;
}
