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
void read(T& x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

const int P = 998244353;
using Z = int;
int fp(int x, int y) {
    int res = 1;
    while(y) {
        if(y & 1) res = 1ll * res * x % P;
        x = 1ll * x * x % P;
        y >>= 1;
    }
    return res;
}

namespace NTT {
    int lim;
    void resize(int _lim) {
        lim = _lim;
    }
    Z g = 3;
    vector<int> rev;
    vector<Z> gpw{ 0, 1 };
    void dft(int *f) {
        if(rev.size() != lim) {
            rev.resize(lim);
            int k = __builtin_ctz(lim) - 1;
            For(i, 0, lim - 1) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << k);
        }
        For(i, 0, lim - 1) if(rev[i] < i) swap(f[rev[i]], f[i]);
        if(gpw.size() < lim) {
            int k = __builtin_ctz(gpw.size());
            gpw.resize(lim);
            while((1 << k) < lim) {
                Z w = fp(g, (P - 1) >> (k + 1));
                For(i, 1 << (k - 1), (1 << k) - 1) {
                    gpw[i << 1] = gpw[i];
                    gpw[(i << 1) | 1] = 1ll * gpw[i] * w % P;
                }
                k++;
            }
        }
        for(int i = 2; i <= lim; i <<= 1) {
            int ii = i >> 1;
            for(int j = 0; j < lim; j += i) {
                For(p, 0, ii - 1) {
                    Z tem1 = f[j + p], tem2 = 1ll * gpw[ii + p] * f[j + ii + p] % P;
                    f[j + p] = tem1 + tem2;
                    if(f[j + p] >= P) f[j + p] -= P;
                    f[j + ii + p] = tem1 - tem2;
                    if(f[j + ii + p] < 0) f[j + ii + p] += P;
                }
            }
        }
    }
    void idft(int *f) {
        reverse(f + 1, f + lim);
        dft(f);
        Z inv = fp(lim, P - 2);
        For(i, 0, lim - 1) f[i] = 1ll * f[i] * inv % P;
    }
}


#define maxn 2000000
int n, m, tot = 0;
char s1[maxn + 5], s2[maxn + 5];
vector<char> vec[maxn + 5];

Z sum2[maxn + 5];
Z F[4 * maxn + 5], F1[4 * maxn + 5], F2[4 * maxn + 5];
Z G[4 * maxn + 5], G1[4 * maxn + 5], G2[4 * maxn + 5];
Z H[4 * maxn + 5];

int sol(vector<char> &v, int l, int r) {
    if(v.size() == 0) return l;
    if(l > r || r - l + 1 < v.size()) return -1;
    int len = v.size() + min(maxn, 2 * (int)v.size()) - 1, lim = 1;
    while(lim < len) lim <<= 1;
    For(i, 0, lim - 1) F[i] = F1[i] = F2[i] = 0;
    NTT::resize(lim);
    Z sum1 = 0;
    For(i, 0, v.size() - 1) {
        if(v[i] == '-') {
            F1[v.size() - 1 - i] = 1;
        }
        else {
            F[v.size() - 1 - i] = v[i] - 'a' + 1;
            F2[v.size() - 1 - i] = (v[i] - 'a' + 1) * (v[i] - 'a' + 1);
            sum1 += (v[i] - 'a' + 1) * (v[i] - 'a' + 1);
            if(sum1 >= P) sum1 -= P;
        }
    }
    NTT::dft(F); NTT::dft(F1); NTT::dft(F2);

    while(l + v.size() - 1 <= r) {
        For(i, 0, lim - 1) G[i] = G1[i] = G2[i] = 0;
        For(i, 0, min(r - l, 2 * (int)v.size() - 1)) {
            sum2[i] = 0;
            if(s2[l + i] == '-') {
                G1[i] = 1;
            }
            else {
                G[i] = s2[l + i] - 'a' + 1;
                G2[i] = sum2[i] = (s2[l + i] - 'a' + 1) * (s2[l + i] - 'a' + 1);
            }
            if(i) {
                sum2[i] += sum2[i - 1];
                if(sum2[i] >= P) sum2[i] -= P;
            }
            // if(i == 2) cout << sum2[2] << endl;
            if(i >= v.size()) {
                if(s2[l + i - v.size()] != '-') sum2[i] -= (s2[l + i - v.size()] - 'a' + 1) * (s2[l + i - v.size()] - 'a' + 1);
                if(sum2[i] < 0) sum2[i] += P;
            }
        }
        NTT::dft(G); NTT::dft(G1); NTT::dft(G2);
        For(i, 0, lim - 1) H[i] = (2ll * F[i] * G[i] % P + 1ll * F1[i] * G2[i] % P + 1ll * F2[i] * G1[i] % P) % P;
        NTT::idft(H);
        For(i, v.size() - 1, min(r - l, 2 * (int)v.size() - 1)) if((1ll * sum1 + sum2[i] - H[i] + P) % P == 0) {
            int fl = 1;
            For(j, 0, v.size() - 1) if(s2[l + i - j] != v[v.size() - 1 - j] && s2[l + i - j] != '-' && v[v.size() - 1 - j] != '-') {
                fl = 0;
                break;
            }
            if(fl) return l + i + 1;
        }
        l += v.size();
    }
    return -1;
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(n); read(m);
    // if(n == 857181) {
    //     puts("Yes");
    //     return 0;
    // }
    scanf("%s%s", s1 + 1, s2 + 1);
    n = strlen(s1 + 1); m = strlen(s2 + 1);
    int l = 1, r = 1, fl = 0;
    For(i, 1, n) if(s1[i] == '*') fl = 1;
    if(!fl) {
        For(i, 1, max(n, m)) swap(s1[i], s2[i]);
        swap(n, m);
    }
    fl = 0;
    For(i, 1, n) if(s1[i] == '*') fl = 1;
    if(!fl) {
        if(n != m) {
            puts("No");
            return 0;
        }
        For(i, 1, n) if(s1[i] != s2[i] && s1[i] != '-' && s2[i] != '-') {
            puts("No");
            return 0;
        }
        puts("Yes");
        return 0;
    }
    while(l <= min(n, m) && (s1[l] == s2[l] || s1[l] == '-' || s2[l] == '-') && s1[l] != '*' && s2[l] != '*') l++;
    if(l == m + 1) {
        while(l <= n && s1[l] == '*') l++;
        if(l == n + 1) {
            puts("Yes");
            return 0;
        }
        puts("No");
        return 0;
    }
    while(r <= min(n, m) && (s1[n - r + 1] == s2[m - r + 1] || s1[n - r + 1] == '-' || s2[m - r + 1] == '-') && s1[n - r + 1] != '*' && s2[m - r + 1] != '*') r++;
    if(r == m + 1) {
        while(r <= n && s1[n - r + 1] == '*') r++;
        if(r == n + 1) {
            puts("Yes");
            return 0;
        }
        puts("No");
        return 0;
    }
    if((s1[l] != '*' && s2[l] != '*') || (s1[n - r + 1] != '*' && s2[m - r + 1] != '*')) {
        puts("No");
        return 0;
    }
    if(s2[l] == '*' || s2[m - r + 1] == '*') {
        // if(n == 1597194 || m == 1597194) cout << "asd1" << endl;
        puts("Yes");
        return 0;
    }
    if(s1[l] == '*' && s1[n - r + 1] == '*' && l <= m - r + 1) {
        For(i, l, m - r + 1) if(s2[i] == '*') {
            // if(n == 1597194 || m == 1597194) cout << "asd2" << endl;
            puts("Yes");
            return 0;
        }
        For(i, l, n - r) {
            if(s1[i] == '*') tot++;
            else vec[tot].pb(s1[i]);
        }
        int sss = 0;
        For(i, 1, tot) {
            int tem = l;
            l = sol(vec[i], l, m - r + 1);
            if(l == -1) {
                // if(n == 4982 || m == 4982) {
                //     cout << tem << " " << sss << endl;
                //     For(i, tem, tem + 50) cout << s2[i]; cout << endl;
                // }
                puts("No");
                return 0;
            }
            sss += vec[i].size();
        }
        // if(n == 1597194 || m == 1597194) cout << "asd3" << endl;
        puts("Yes");
        return 0;
    }
    puts("No");
    return 0;
}
