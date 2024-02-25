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

#define maxn 10
int n, m, a[maxn + 5], b[maxn + 5], res;
vector<pair<int, int> > vec;
void dfs(int pos) {
    if(pos == m) {
        For(i, 1, n) b[i] = i;
        sort(b + 1, b + n + 1, [](int _x, int _y) {return a[_x] != a[_y] ? a[_x] > a[_y] : _x < _y;});
        For(i, 1, n) if(b[i] == 1) res = min(res, i);
        return;
    }

    a[vec[pos].fir] += 3;
    dfs(pos + 1);
    a[vec[pos].fir] -= 3;

    a[vec[pos].sec] += 3;
    dfs(pos + 1);
    a[vec[pos].sec] -= 3;

    a[vec[pos].fir]++;
    a[vec[pos].sec]++;
    dfs(pos + 1);
    a[vec[pos].fir]--;
    a[vec[pos].sec]--;
}

void mian() {
    read(n); read(m);
    For(i, 1, n) read(a[i]);
    For(i, 1, m) {
        int u, v; read(u); read(v);
        vec.pb({ u, v });
    }
    res = n;
    dfs(0);
    printf("%d\n", res);
    vec.resize(0);
}

int main() {
    //freopen("in", "r", stdin);
    int T;
    read(T);
    while(T--) {
        mian();
    }
}
