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

#define maxn 300000
int n;
char s[maxn + 5];

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
};

using Z1 = Mint<998244353>;
using Z2 = Mint<1000000007>;
struct Hsh {
    Z1 v1;
    Z2 v2;
};
Hsh operator + (cst Hsh &_x, cst Hsh &_y) { return { _x.v1 + _y.v1, _x.v2 + _y.v2 }; }
Hsh operator - (cst Hsh &_x, cst Hsh &_y) { return { _x.v1 - _y.v1, _x.v2 - _y.v2 }; }
Hsh operator * (cst Hsh &_x, cst Hsh &_y) { return { _x.v1 * _y.v1, _x.v2 * _y.v2 }; }
bool operator == (cst Hsh &_x, cst Hsh &_y) { return _x.v1.x == _y.v1.x && _x.v2.x == _y.v2.x; }

Hsh bas = { 13331, 13331 }, pwb[maxn + 5];
Hsh val[2][maxn + 5];

Hsh get_hsh(int ty, int l, int r) {
    if(!ty) return val[0][r] - val[0][l - 1] * pwb[r - l + 1];
    else return val[1][l] - val[1][r + 1] * pwb[r - l + 1];
}

template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

int to[maxn + 5][2];
LL f[maxn + 5][26], sum[maxn + 5], num[maxn + 5];
int main() {
    // freopen("in.txt", "r", stdin);
    pwb[0] = { 1, 1 };
    For(i, 1, maxn) pwb[i] = pwb[i - 1] * bas;
    read(n);
    scanf("%s", s + 1);
    For(i, 1, n) {
        val[0][i] = val[0][i - 1] * bas + (Hsh) { s[i] - 'a' + 1, s[i] - 'a' + 1 };
    }
    Rof(i, n, 1) {
        val[1][i] = val[1][i + 1] * bas + (Hsh) { s[i] - 'a' + 1, s[i] - 'a' + 1 };
    }
    LL cnt = 0;
    For(i, 1, n) {
        int l = 1, r = min(i, n - i + 1);
        while(l < r) {
            int mid = l + r >> 1;
            if(get_hsh(0, i - mid + 1, i + mid - 1) == get_hsh(1, i - mid + 1, i + mid - 1)) l = mid + 1;
            else r = mid;
        }
        if(!(get_hsh(0, i - l + 1, i + l - 1) == get_hsh(1, i - l + 1, i + l - 1))) l--;
        if(l > 1) {
            sum[i + 1] += i + l; sum[i + l] -= i + l;
            num[i + 1]++; num[i + l]--;

            sum[i - l + 1] -= i - l; sum[i] += i - l;
            num[i - l + 1]--; num[i]++;
        }
        cnt += l;
        to[i][0] = l;
        int tem = 0;
        if(i - l >= 1 && i + l <= n) {
            f[i + l][s[i - l] - 'a']++;
            f[i - l][s[i + l] - 'a']++;
        }
        int l1 = l + 2, r1 = min(i, n - i + 1);
        if(l1 <= r1) {
            int res = 0;
            while(l1 < r1) {
                int mid = l1 + r1 >> 1;
                if(get_hsh(0, i + l + 1, i + mid - 1) == get_hsh(1, i - mid + 1, i - l - 1)) l1 = mid + 1;
                else r1 = mid;
            }
            if(!(get_hsh(0, i + l + 1, i + l1 - 1) == get_hsh(1, i - l1 + 1, i - l - 1))) l1--;
            res += l1 - l - 1;
            f[i + l][s[i - l] - 'a'] += res;
            f[i - l][s[i + l] - 'a'] += res;
        }

        if(i < n) {
            l = 1, r = min(i, n - i);
            while(l < r) {
                int mid = l + r >> 1;
                if(get_hsh(0, i - mid + 1, i + mid) == get_hsh(1, i - mid + 1, i + mid)) l = mid + 1;
                else r = mid;
            }
            if(!(get_hsh(0, i - l + 1, i + l) == get_hsh(1, i - l + 1, i + l))) l--;
            if(l >= 1) {
                sum[i + 1] += i + l + 1; sum[i + l + 1] -= i + l + 1;
                num[i + 1]++; num[i + l + 1]--;

                sum[i - l + 1] -= i - l; sum[i + 1] += i - l;
                num[i - l + 1]--; num[i + 1]++;
            }
            cnt += l;
            to[i][1] = l;
            int tem = 0;
            int l1 = l + 2, r1 = min(i, n - i);
            if(i - l >= 1 && i + l + 1 <= n) {
                f[i + l + 1][s[i - l] - 'a']++;
                f[i - l][s[i + l + 1] - 'a']++;
            }
            if(l1 <= r1) {
                int res = 0;
                while(l1 < r1) {
                    int mid = l1 + r1 >> 1;
                    if(get_hsh(0, i + l + 2, i + mid) == get_hsh(1, i - mid + 1, i - l - 1)) l1 = mid + 1;
                    else r1 = mid;
                }
                if(!(get_hsh(0, i + l + 2, i + l1) == get_hsh(1, i - l1 + 1, i - l - 1))) l1--;
                res += l1 - l - 1;
                f[i + l + 1][s[i - l] - 'a'] += res;
                f[i - l][s[i + l + 1] - 'a'] += res;
            }
        }
    }
    For(i, 1, n) {
        sum[i] += sum[i - 1];
        num[i] += num[i - 1];
        For(o, 0, 25) if(o != s[i] - 'a') f[i][o] -= sum[i] - 1ll * i * num[i];
    }
    LL res = 0;
    For(i, 1, n) For(o, 0, 25) if(f[i][o] > res) res = f[i][o];
    printf("%lld\n", cnt + res);
    For(i, 1, n) For(o, 0, s[i] - 'a' - 1) if(f[i][o] == res) {
        s[i] = 'a' + o;
        printf("%s", s + 1);
        return 0;
    }
    For(i, 1, n) if(f[i][s[i] - 'a'] == res) {
        printf("%s", s + 1);
        return 0;
    }
    Rof(i, n, 1) For(o, s[i] - 'a' + 1, 25) if(f[i][o] == res) {
        s[i] = 'a' + o;
        printf("%s", s + 1);
        return 0;
    }
}
