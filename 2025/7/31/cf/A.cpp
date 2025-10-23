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

#define maxn 3000
int T, n, a[maxn + 5], b[maxn + 5], id[maxn + 5];

void mian() {
    read(n);
    For(i, 1, n) read(a[i]), read(b[i]), id[i] = i;
    sort(id + 1, id + n + 1, [](int x, int y) {return a[x] < a[y];});
    vector<int> vec;
    int now = 0;
    For(i, 1, n) {
        if(b[id[i]] > now) vec.pb(id[i]), now = b[id[i]];
    }
    printf("%d\n", vec.size());
    for(auto i : vec) printf("%d ", i);
    puts("");
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
