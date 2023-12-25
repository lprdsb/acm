#include<bits/stdc++.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define Tra(u, i) for(int i = hd[u]; ~i; i = e[i].net)
#define cst const
#define U unsigned
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
void read(T& x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

struct Bit : vector<U LL> {
    Bit operator <<= (int _x) {
        int tem = _x / 64;
        Rof(i, size() - 1, tem) (*this)[i] = (*this)[i - tem];
        For(i, 0, min((int)size(), tem) - 1) (*this)[i] = 0;
        _x &= 63;
        if(_x) {
            Rof(i, size() - 1, 1) (*this)[i] = ((*this)[i] << _x) | ((*this)[i - 1] >> (64 - _x));
            (*this)[0] <<= _x;
        }
        return (*this);
    }
    Bit operator << (cst int &_x) {
        Bit tem = *this;
        tem <<= _x;
        return tem;
    }
    Bit operator >>= (int _x) {
        int tem = _x / 64;
        For(i, 0, size() - 1 - tem) (*this)[i] = (*this)[i + tem];
        For(i, max(0, (int)size() - tem), size() - 1) (*this)[i] = 0;
        _x &= 63;
        if(_x) {
            For(i, 0, size() - 2) (*this)[i] = ((*this)[i] >> _x) | (((*this)[i + 1] & ((1ull << _x) - 1)) << (64 - _x));
            (*this)[size() - 1] >>= _x;
        }
        return (*this);
    }
    Bit operator >> (cst int &_x) {
        Bit tem = *this;
        tem >>= _x;
        return tem;
    }
    Bit operator &= (cst Bit &_x) { For(i, 0, size() - 1) (*this)[i] &= _x[i]; return (*this); }
    Bit operator |= (cst Bit &_x) { For(i, 0, size() - 1) (*this)[i] |= _x[i]; return (*this); }
    Bit operator ^= (cst Bit &_x) { For(i, 0, size() - 1) (*this)[i] ^= _x[i]; return (*this); }
    friend Bit operator & (Bit _x, cst Bit &_y) { return _x &= _y; }
    friend Bit operator | (Bit _x, cst Bit &_y) { return _x |= _y; }
    friend Bit operator ^ (Bit _x, cst Bit &_y) { return _x ^= _y; }
    int get_bit(int _x) { return ((*this)[_x >> 6] >> (_x & 63)) & 1; }
    void init(cst int &_x) {
        resize(((_x - 1) >> 6) + 1);
        For(i, 0, size() - 1) (*this)[i] = 0;
    }
};

int main() {
    //freopen("in", "r", stdin);
}
