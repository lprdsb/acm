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

#define maxn 2000000
int n;
vector<int> V, as;
void sol(vector<int> &vec, int now, int dep) {
    int tem = 0;
    for(auto i : vec) tem += i != 0;
    if(!tem) return;
    if(dep == n) {
        as.pb(now);
        return;
    }
    vector<int> v;
    For(i, 0, (1 << (n - dep)) - 1) {
        v.pb(vec[i] & vec[i + 1]);
        i++;
    }
    sol(v, now, dep + 1);
    v.resize(0);
    For(i, 0, (1 << (n - dep)) - 1) {
        v.pb(vec[i] & (vec[i + 1] >> 1));
        i++;
    }
    sol(v, now | (1 << dep), dep + 1);
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(n);
    V.pb(1);
    For(i, 1, (1 << n) - 1) {
        int x; read(x);
        V.pb(x);
    }
    sol(V, 0, 0);
    sort(as.begin(), as.end());
    printf("%d\n", as.size());
    for(auto i : as) printf("%d\n", i);
    return 0;
}
