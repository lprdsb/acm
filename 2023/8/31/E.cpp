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
#define maxn 4000
#define mod 998244353
using namespace std;

int n, k;

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

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

Z f[2][2][maxn + 5];
int main(){
	// freopen("in.txt", "r", stdin);
    read(n); read(k);
    f[0][0][0] = 1;
    f[0][0][1] = -1;
    int o = 0;
    For(i, 0, n - 1){
        For(o1, 0, 1) For(j, 1, k - 1) f[o][o1][j] += f[o][o1][j - 1];
        For(j, 0, k - 1){
            if(j < k - 1){
                f[o ^ 1][0][j + 1] += (k - j) * f[o][0][j];
                f[o ^ 1][0][j + 2] -= (k - j) * f[o][0][j];

                f[o ^ 1][1][j + 1] += (k - j) * f[o][1][j];
                f[o ^ 1][1][j + 2] -= (k - j) * f[o][1][j];
            }
            else{
                f[o ^ 1][0][0] += f[o][0][j];
                f[o ^ 1][0][1] -= f[o][0][j];
                
                f[o ^ 1][1][0] += f[o][0][j] + f[o][1][j];
                f[o ^ 1][1][1] -= f[o][0][j] + f[o][1][j];
            }
            f[o ^ 1][0][1] += f[o][0][j];
            f[o ^ 1][0][j + 1] -= f[o][0][j];

            f[o ^ 1][1][1] += f[o][1][j];
            f[o ^ 1][1][j + 1] -= f[o][1][j];
            
            f[o][0][j] = f[o][1][j] = 0;
        }
        o ^= 1;
        // if(i == 1) cout << f[o][1][0].x << endl;
    }
    Z res = 0;
    For(i, 0, k - 1){
        f[o][1][i] += f[o][1][i - 1];
        res += f[o][1][i];
    }
    printf("%d\n", res.x);
    return 0;
}
