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

#define ULL unsigned LL
#define UI unsigned int
#define LLL __int128

int n;
ULL b[80], s, a[80];

LLL q = (LLL)1 << 64;
namespace c1 {
    vector<ULL> vec[2];
    void print(UI x, UI y) {
        For(i, 0, n - 1) {
            if(i & 1) {
                printf("%d", y & 1);
                y >>= 1;
            }
            else {
                printf("%d", x & 1);
                x >>= 1;
            }
        }
    }
    int tot = 0, tp[2] = { 0, 0 }, tpt = 0;
    int sss;
    pair<int, ULL> st[2][1 << 23], tv[1 << 23];
    int ttt;
    void sol(int o) {
        st[o][tp[o]++] = { 0, 0 };
        for(auto v : vec[o]) {
            int p = 0;
            while(p != tp[o] && (LLL)st[o][p].sec + v < q) p++;
            if(p == tp[o]) p = 0;
            int to = p, p1 = 0;
            tpt = 0;
            while(p != -1 || p1 != tp[o]) {
                if(p == -1) {
                    tv[tpt++] = { st[o][p1].fir << 1, st[o][p1].sec };
                    p1++;
                }
                else if(p1 == tp[o]) {
                    tv[tpt++] = { st[o][p].fir << 1 | 1, st[o][p].sec + v };
                    p++;
                    if(p == tp[o]) p = 0;
                    if(p == to) p = -1;
                }
                else {
                    if(st[o][p].sec + v < st[o][p1].sec) {
                        tv[tpt++] = { st[o][p].fir << 1 | 1, st[o][p].sec + v };
                        p++;
                        if(p == tp[o]) p = 0;
                        if(p == to) p = -1;
                    }
                    else {
                        tv[tpt++] = { st[o][p1].fir << 1, st[o][p1].sec };
                        p1++;
                    }
                }
            }
            tp[o] = tpt;
            For(i, 0, tpt - 1) st[o][i] = tv[i];
        }
    }
    void mian() {
        // cout << ((&ttt - &sss) >> 18) << endl;
        For(i, 0, n - 1) vec[i & 1].pb(b[i]);
        For(o, 0, 1) reverse(vec[o].begin(), vec[o].end()), sol(o);
        int now = tp[1] - 1;
        For(i, 0, tp[0] - 1) {
            int k = st[0][i].fir; ULL v = st[0][i].sec;
            if(v <= s) {
                while((LLL)v + (LLL)st[1][now].sec > s) now--;
                if(v + st[1][now].sec == s) {
                    print(k, st[1][now].fir);
                    exit(0);
                }
            }
            else break;
        }

        now = tp[1] - 1;
        LLL up = s + q;
        For(i, 0, tp[0] - 1) {
            int k = st[0][i].fir; ULL v = st[0][i].sec;
            while((LLL)v + (LLL)st[1][now].sec > up) now--;
            if(v + st[1][now].sec == s) {
                print(k, st[1][now].fir);
                exit(0);
            }
        }
    }
}

namespace c2 {
    ULL sol(ULL x, ULL y) {
        int k = 0;
        ULL res = 0, tem = x;
        while(!(tem & 1)) tem >>= 1, k++;
        For(o, k, 63) if((y >> o) & 1) {
            res += 1ull << (o - k);
            y -= x << (o - k);
        }
        return res;
    }
    void print(LLL x) {
        vector<int> st;
        while(x) st.pb(x % 10), x /= 10;
        reverse(st.begin(), st.end());
        for(auto i : st) cout << i; cout << endl;
    }
    int tot = 0;
    void mian() {
        ULL tem = b[0], uni = 1;
        while(!(tem & 1)) uni <<= 1, tem >>= 1;
        ULL c = uni;
        int uu = 1 << (64 - n + 1);
        while(c < uu) {
            ULL t = sol(b[0], c);
            LLL tt = q / uni;
            while(666) {
                assert(b[0] * t == c);
                LLL sum = 0;
                int fl = 0;
                For(i, 0, n - 1) {
                    a[i] = b[i] * t;
                    if(a[i] <= sum || sum + a[i] >= q) {
                        fl = 1;
                        break;
                    }
                    sum += a[i];
                }
                if(!fl) {
                    ULL mask = 0; LLL ss = s * t;
                    if(ss <= sum) {
                        ULL ttt = (ULL)1 << (n - 1);
                        Rof(i, n - 1, 0) {
                            if(ss >= a[i]) {
                                mask |= ttt;
                                ss -= a[i];
                                if(!ss) break;
                            }
                            ttt >>= 1;
                        }
                        if(!ss) {
                            For(i, 0, n - 1) printf("%d", (mask >> i) & 1);
                            return;
                        }
                    }
                }
                if(t + tt > q) break;
                t += tt;
            }
            c += uni;
        }

    }
}

int main() {
    //freopen("in", "r", stdin);
    n = 48;
    read(n);
    For(i, 0, n - 1) {
        b[i] = (ULL)1 << i;
        read(b[i]);
    }
    s = 1025;
    read(s);
    if(n <= 46) c1::mian();
    else c2::mian();
}
