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

int n, t;
vector<pair<int, int> > vec;

int main() {
    //freopen("in", "r", stdin);
    read(n); read(t); t *= 2;
    For(i, 1, n) {
        int a, b; read(a); read(b);
        vec.pb({ a, b });
    }
    sort(vec.begin(), vec.end());
    int res = 2;
    For(i, 0, n - 2) {
        int tem = 2 * (vec[i + 1].fir - vec[i].fir) - (vec[i].sec + vec[i + 1].sec);
        if(tem >= t) res++;
        if(tem > t) res++;
    }
    printf("%d\n", res);
}
