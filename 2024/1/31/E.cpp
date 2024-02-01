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

int T;
auto rd = mt19937_64(114514);
using Vec = vector<int>;

int a[100] = { 0, 2, 4, 1, 5, 3 }, X = 3;

int que(int x) {
    printf("? %d\n", x);
    fflush(stdout);
    // if(a[x] < X) {
    //     X--;
    //     return -1;
    // }
    // if(a[x] > X) {
    //     X++;
    //     return 1;
    // }
    // return 0;
    char c; cin >> c;
    if(c == '<') return -1;
    if(c == '>') return 1;
    return 0;
}

int que1(int x, int y) {
    int res = que(x);
    que(y);
    return res;
}

void sol(Vec &vec) {
    if(vec.size() <= 1) return;
    int pos = vec[rd() % vec.size()];
    Vec vl, vr;
    while(que(pos));
    for(auto i : vec) if(i != pos) {
        if(que1(i, pos) < 0) vl.pb(i);
        else vr.pb(i);
    }
    sol(vl); sol(vr);
    vec = vl;
    vec.pb(pos);
    for(auto i : vr) vec.pb(i);
}

int n;
void mian() {
    read(n);
    Vec as;
    For(i, 1, n) as.pb(i);
    sol(as);
    Vec ias(n);
    For(i, 0, as.size() - 1) ias[as[i] - 1] = i + 1;
    printf("! ");
    for(auto i : ias) printf("%d ", i); puts("");
    fflush(stdout);
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
/*
2 4 1 5 3
*/