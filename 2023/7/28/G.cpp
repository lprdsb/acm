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
#define maxn 50000
using namespace std;

int n, m, L, a[maxn + 5], b[maxn + 5], B = 50000;

template<int P>
struct Mint{
    int x;
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

const int mod = 998244353;
using Z = Mint<mod>;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

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

int tr[maxn + 5], ty = 0;
void ins(int x, int y){
    x = maxn - x;
    while(x <= maxn) tr[x] += y, x += x & -x; 
}
int que(int x){
    x = maxn - x;
    int asi = 0;
    while(x) asi += tr[x], x -= x & -x;
    return asi;
}

int main(){
	// freopen("in.txt", "r", stdin);
    read(n); read(m); read(L);
    For(i, 1, n) read(a[i]); sort(a + 1, a + n + 1);
    For(i, 1, m) read(b[i]); sort(b + 1, b + m + 1);
    Z as = 0;
    // For(i, 1, n) For(j, 1, m) For(p, 1, L) as += (a[i] + b[j] + p - 1) / p;
    // as = 0;
    For(o, 1, min(B, L)){
        Z sum = 0;
        For(i, 1, n) sum += (a[i] + o - 1) / o;
        as += sum * m;
        sum = 0;
        For(i, 1, m) sum += b[i] / o;
        as += sum * n;
        For(i, 1, m) ins(b[i] % o, 1);
        For(i, 1, n) as += que(o - (a[i] + o - 1) % o);
        For(i, 1, m) ins(b[i] % o, -1);
    }
    if(L > B){
        ty = 1;
        as += 1ll * (L - B) * n * m;
        For(o, 1, B){
            int l = m, r = m;
            Z sum = 0;
            For(i, 1, n){
                while(l && (a[i] - 1 + b[l]) / o > B){
                    sum += b[l] / o;
                    ins(b[l] % o, 1);
                    l--;
                }
                while(r > l && (a[i] - 1 + b[r]) / o >= L){
                    sum -= b[r] / o;
                    ins(b[r] % o, -1);
                    r--;
                }
                // if(l != r) cout << (a[i] - 1 + b[l]) / o << " " << (a[i] - 1 + b[r]) / o << endl;
                as += 1ll * (L - B) * (m - r) + sum + 1ll * ((a[i] - 1) / o - B) * (r - l) + que(o - (a[i] - 1) % o);
            }
            while(r > l) ins(b[r] % o, -1), r--;
        }
    }
    printf("%d\n", as / L / m);
    return 0;
}
