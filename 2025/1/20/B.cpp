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

#define maxn 100000
int n, a[maxn + 5];

struct Node {
    int op, i, x;
};
vector<Node> as;

int main() {
    //freopen("in", "r", stdin);
    read(n);
    For(i, 0, n - 1) read(a[i]);
    int sum = 0;
    Rof(i, n - 1, 0) {
        int k = ((i - a[i] - k) % n + n) % n;
        as.pb({ 1, i + 1, k });
        sum += k;
    }
    as.pb({ 2, n, n });
    for(auto [op, i, x] : as) cout << op << " " << i << " " << x << endl;
    return 0;
}
