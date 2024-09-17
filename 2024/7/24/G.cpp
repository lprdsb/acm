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

int s, t;
LL pw[60];

struct Node {
    int c; LL p, q;
    vector<LL> as;
    Node() {}
    void reduce() {
        while(p % 2 == 0) p /= 2, c++;
        while(q % 2 == 0) q /= 2, c++;
        if(p < q) swap(p, q);
        while(c >= 3) {
            LL k = pw[c - 3] * p * q;
            as.pb(15 * k); as.pb(12 * k); as.pb(5 * k); as.pb(4 * k);
            c--;
        }
    }
    Node(LL x) {
        c = 0; p = x; q = 1;
        reduce();
    }
    void trans() {
        while(pw[c] * p * q != 4) {
            // cout << c << " " << p << " " << q << endl;
            assert(p != q);
            c++;
            LL pp = (p + q) / 2, qq = (p - q) / 2;
            p = pp; q = qq;
            as.pb(pw[c] * p * q);
            reduce();
        }
    }
};

int main() {
    // freopen("in.txt", "r", stdin);
    pw[0] = 1;
    For(i, 1, 50) pw[i] = 2 * pw[i - 1];
    read(s); read(t);
    if(s <= 2 || t <= 2) {
        puts("impossible");
        return 0;
    }
    Node S = s, T = t;
    // cout << "asd" << endl;
    S.trans(); T.trans();
    assert(S.as.size() + T.as.size() <= 2000);
    printf("%d\n", S.as.size() + T.as.size());
    for(auto i : S.as) printf("%lld\n", i);
    reverse(T.as.begin(), T.as.end());
    For(i, 1, T.as.size() - 1) printf("%lld\n", T.as[i]);
    if(t != 4) printf("%lld\n", t);
    return 0;
}
