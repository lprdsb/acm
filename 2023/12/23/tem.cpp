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

#define maxn 1000000
int l = 30, r = 35;
int fa[maxn + 5], ok[maxn + 5];

template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

vector<pair<int, pair<int, int> > > edge;
int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int gcd(int x, int y) {
    return y ? gcd(y, x % y) : x;
}

int mn[maxn + 5];
int main() {
    //freopen("in", "r", stdin);
    For(i, l, r) fa[i] = i;
    For(i, l, r) For(j, i + 1, r) {
        edge.pb({ i * j / gcd(i, j), {i, j} });
    }
    For(i, l, r) {
        mn[i] = -1;
        For(j, l, r) if(j != i && (mn[i] == -1 || i * j / gcd(i, j) < mn[i])) mn[i] = i * j / gcd(i, j);
    }
    sort(edge.begin(), edge.end());
    for(auto [w, v] : edge) {
        if(find(v.fir) != find(v.sec)) {
            // 
            /*if(ok[v.sec])*/
            if(w != mn[v.fir] && w != mn[v.sec]) cout << v.fir << " " << v.sec << endl;
            ok[v.sec] = 1;
            fa[find(v.fir)] = find(v.sec);
        }
    }
}
