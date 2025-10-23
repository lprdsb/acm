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
int n, h, a[maxn + 5], as[maxn + 5];
map<int, vector<int> > ma;

int main() {
    freopen("in.txt", "r", stdin);
    read(n); read(h);
    For(i, 1, n) {
        read(a[i]);
        int now = a[i];
        For(j, 1, h) {
            ma[-now].pb(i);
            now >>= 1;
            if(!now) break;
        }
    }
    for(auto [k, v] : ma) {
        // cout << k << " " << h << endl;
        sort(v.begin(), v.end(), [](int x, int y) {
            if((as[x] == 0) ^ (as[y] == 0)) {
                return as[x] < as[y];
            }
            else {
                if(a[x] != a[y]) return a[x] > a[y];
                return x < y;
            }
            });
        for(auto i : v) if(h) as[i]++, h--;
        if(!k && h) {
            sort(v.begin(), v.end(), [](int x, int y) {
                if(a[x] != a[y]) return a[x] > a[y];
                return x < y;
                });
            for(auto i : v) as[i] += h / v.size();
            For(i, 0, (int)(h % v.size()) - 1) as[v[i]]++;
        }
    }
    For(i, 1, n) printf("%d ", as[i]);
    return 0;
}
