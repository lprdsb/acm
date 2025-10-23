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
struct Node {
    string s;
    int a, b, c;
} peo[maxn + 5];
bool operator < (Node x, Node y) {
    if(x.a + x.b + x.c != y.a + y.b + y.c) return x.a + x.b + x.c > y.a + y.b + y.c;
    if(x.a != y.a) return x.a > y.a;
    return x.s < y.s;
}

int n;

int main() {
    //freopen("in", "r", stdin);
    read(n);
    For(i, 1, n) cin >> peo[i].s >> peo[i].a >> peo[i].b >> peo[i].c;
    sort(peo + 1, peo + n + 1);
    For(i, 1, n) cout << peo[i].s << endl;
    return 0;
}
