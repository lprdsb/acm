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

#define maxn 1000
int n, a[maxn + 5];
vector<pair<int, int> > as;

void sol(vector<int> &vec, int l, int r) {
    if(!vec.size() || l == r) return;
    int md = l + r >> 1;
    vector<int> vl, vr;
    for(auto i : vec) {
        if(a[i] > md) {
            as.pb({ 2, i });
            vr.pb(i);
        }
        else vl.pb(i);
    }
    if(vr.size()) {
        For(i, l + 1, md) as.pb({ 1, i });
    }
    sol(vl, l, md); sol(vr, md + 1, r);
}

int main() {
    //freopen("in", "r", stdin);
    read(n);
    For(i, 1, n) read(a[i]);
    vector<int> vec;
    For(i, 1, n) vec.pb(i);
    sol(vec, 0, maxn);
    printf("%d\n", as.size());
    for(auto [o, x] : as) printf("%d %d\n", o, x);
    return 0;
}
