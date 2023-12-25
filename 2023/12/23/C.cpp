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

#define maxn 100000
int T, n, c[maxn + 5];

template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

vector<pair<int, int> > vec;
vector<int> len;
int st[maxn + 5];
void sol() {
    read(n);
    For(i, 1, n) {
        int x; read(x);
        vec.pb({ x, 0 });
    }
    For(i, 1, n) {
        int x; read(x);
        vec.pb({ x, 1 });
    }
    For(i, 1, n) read(c[i]);
    int top = 0;
    sort(vec.begin(), vec.end());
    for(auto [x, v] : vec) {
        if(!v) st[++top] = x;
        else {
            len.pb(x - st[top]);
            top--;
        }
    }
    sort(len.begin(), len.end());
    sort(c + 1, c + n + 1);
    LL res = 0;
    For(i, 0, len.size() - 1) res += 1ll * c[n - i] * len[i];
    printf("%lld\n", res);
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        sol();
        vec.resize(0);
        len.resize(0);
    }
}
