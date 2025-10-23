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

int vis[maxn + 5], ok[maxn + 5], fl = 0, online = 0, a[maxn + 5];
vector<int> vec;
int n, m;

int chk(int x) {
    int s = 1;
    online = 0;
    For(i, 1, n) vis[i] = 0;
    For(i, 1, m) {
        if(a[i] > 0) {
            online++;
            vis[a[i]] = 1;
            if(a[i] == x) s = 1;
        }
        else {
            if(vis[-a[i]]) online--;
            vis[-a[i]] = 0;
            if(-a[i] == x) s = 0;
        }
        if(online && !s) return 0;
    }
    return 1;
}

int main() {
    //freopen("in", "r", stdin);
    read(n); read(m);
    if(m == 1) {
        printf("%d\n", n);
        For(i, 1, n) printf("%d ", i);
        return 0;
    }
    int f = -1;
    For(i, 1, m) {
        char c; cin >> c;
        int x; read(x);
        if(i == 1) f = x;
        if(c == '-') {
            a[i] = -x;
            if(!vis[x]) fl = x;
            vis[x] = 0;
        }
        else {
            a[i] = x;
            vis[x] = 1;
        }
        ok[x] = 1;
    }
    For(i, 1, n) if(!ok[i]) vec.pb(i);
    if(!fl && chk(f)) vec.pb(f);
    if(fl && chk(fl)) vec.pb(fl);
    sort(vec.begin(), vec.end());
    printf("%d\n", vec.size());
    for(auto v : vec) printf("%d ", v);
}
