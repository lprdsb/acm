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
using namespace std;


template <class T>
void read(T & x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

template<class T>
T fp(T x, int y) {
    T asi = 1;
    while(y) {
        if(y & 1) asi *= x;
        x *= x;
        y >>= 1;
    }
    return asi;
}

template<int P>
struct Mint {
    int x;
    Mint() { x = 0; }
    Mint(int _x) : x{ norm(_x % P) } {}
    int norm(int _x) {
        if(_x < 0) _x += P;
        if(_x >= P) _x -= P;
        return _x;
    }
    Mint inv() { return fp(*this, P - 2); }
    Mint operator - () { return { P - x }; }
    Mint& operator += (Mint _x) & {
        x = norm(x + _x.x);
        return *this;
    }
    Mint& operator -= (Mint _x) & {
        x = norm(x - _x.x);
        return *this;
    }
    Mint& operator *= (Mint _x) & {
        x = 1ll * x * _x.x % P;
        return *this;
    }
    Mint& operator /= (Mint _x) & { return *this *= _x.inv(); }
    friend Mint operator + (Mint _x, Mint _y) { return _x += _y; }
    friend Mint operator - (Mint _x, Mint _y) { return _x -= _y; }
    friend Mint operator * (Mint _x, Mint _y) { return _x *= _y; }
    friend Mint operator / (Mint _x, Mint _y) { return _x /= _y; }
    friend bool operator == (Mint _x, Mint _y) { return _x.x == _y.x; }
    friend bool operator != (Mint _x, Mint _y) { return _x.x != _y.x; }
};

const int P1 = 998244353, P2 = 1000000007;
using Z1 = Mint<P1>;
using Z2 = Mint<P2>;

struct Hsh {
    Z1 a;// Z2 b;
};
Hsh operator + (Hsh _x, cst Hsh &_y) {
    _x.a += _y.a;
    // _x.b += _y.b;
    return _x;
}
Hsh operator - (Hsh _x, cst Hsh &_y) {
    _x.a -= _y.a;
    // _x.b -= _y.b;
    return _x;
}
Hsh operator * (Hsh _x, cst Hsh &_y) {
    _x.a *= _y.a;
    // _x.b *= _y.b;
    return _x;
}
bool operator == (cst Hsh &_x, cst Hsh &_y) { return _x.a == _y.a/* && _x.b == _y.b*/; }


#define maxn 2000000
Hsh bas = { 13331/*, 13331*/ }, pw[maxn + 5];
int T, n;
char s[maxn + 5];
struct Node {
    Hsh hsh[maxn + 5];
    Node() {}
    void init(char *s) {
        For(i, 1, n) hsh[i] = hsh[i - 1] * bas + Hsh{ s[i] - 'a' + 1/*, s[i] - 'a' + 1 */ };
    }
    Hsh get_hsh(int l, int r) {
        return (hsh[r] - hsh[l - 1] * pw[r - l + 1]);
    }
} l1, l2;


bool chk(int l, int r) {
    return l1.get_hsh(l, r) == l2.get_hsh(n - r + 1, n - l + 1);
}

int tot = 0;
void mian() {
    // For(i, 1, maxn) s[i] = 'a'; s[maxn + 1] = '\0';
    // n = maxn;
    scanf("%s", s + 1); n = strlen(s + 1);
    l1.init(s);
    For(i, 1, n) if(i < n - i + 1) swap(s[i], s[n - i + 1]);
    l2.init(s);
    For(i, 1, n) if(i < n - i + 1) swap(s[i], s[n - i + 1]);
    if(!chk(1, n)) {
        printf("YES\n1\n%s\n", s + 1);
        return;
    }
    else {
        For(i, 1, n - 1) {
            if(!chk(1, i) && !chk(i + 1, n)) {
                printf("YES\n2\n");
                For(j, 1, i) putchar(s[j]); printf(" ");
                For(j, i + 1, n) putchar(s[j]); puts("");
                return;
            }
        }
    }
    puts("NO");
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    pw[0] = { 1 /*, 1 */ };
    For(i, 1, maxn) pw[i] = pw[i - 1] * bas;
    read(T);
    while(T--) {
        mian();
    }
}