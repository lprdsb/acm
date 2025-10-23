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

LL n, fl, tot = 0;
map<LL, map<LL, LL> > ma;
int que(LL l, LL r) {
    if(ma.count(l) && ma[l].count(r)) return ma[l][r];
    cout << "? " << l << " " << r << endl;
    tot++;
    assert(tot <= 33);
    int x; read(x);
    assert(x != -1);
    if(x == -1) exit(0);
    return ma[l][r] = x;
}

void mian() {
    tot = 0;
    read(n);
    fl = 0;
    int t = que(1, n / 2);
    if(t) fl = que(1, n / 4) != que(n / 4 + 1, n / 2);
    else fl = que(n / 2 + 1, n / 4 * 3) != que(n / 4 * 3 + 1, n);
    LL l, r;
    if(fl) {
        l = n / 2 + 1;
        r = n - 1;
        if(t) {
            while(l < r) {
                LL md = l + r >> 1;
                if(que(1, md)) l = md + 1;
                else r = md;
            }
        }
        else {
            while(l < r) {
                LL md = l + r >> 1;
                if(que(n - md + 1, n)) l = md + 1;
                else r = md;
            }
        }
    }
    else {
        l = 2;
        r = n / 2;
        if(t) {
            while(l < r) {
                LL md = l + r >> 1;
                if(que(1, md)) r = md;
                else l = md + 1;
            }
        }
        else {
            while(l < r) {
                LL md = l + r >> 1;
                if(que(n / 2 + 1, n / 2 + 1 + md - 1)) r = md;
                else l = md + 1;
            }
        }
    }
    cout << "! " << l << endl;
}

int main() {
    //freopen("in", "r", stdin);
    int T;
    read(T);
    while(T--) {
        mian();
        ma.clear();
    }
}
