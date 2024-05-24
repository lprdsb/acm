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

#define maxn 200000
int n, sum[2][maxn + 5];
LL as[maxn + 5];
vector<int> vecl[maxn + 5], vecr[maxn + 5];

int main() {
    // freopen("in.txt", "r", stdin);
    read(n);
    For(i, 1, n) {
        int l, r; read(l); read(r);
        vecl[l].pb(r);
    }
    multiset<int> se;
    For(i, 1, maxn) {
        for(auto j : vecl[i]) se.insert(j);
        if(se.size()) {
            vecr[*se.begin()].pb(i);
            se.erase(se.begin());
        }
        while(se.size() && *se.begin() <= i) se.erase(se.begin());
    }
    Rof(i, maxn, 1) {
        for(auto j : vecr[i]) se.insert(-j);
        if(se.size()) {
            // cout << -*se.begin() << " asd " << i << endl;
            sum[0][-*se.begin() + 1]++;
            sum[0][i + 1]--;
            sum[1][-*se.begin()]++;
            se.erase(se.begin());
        }
        while(se.size() && -*se.begin() >= i) se.erase(se.begin());
    }
    For(i, 1, maxn) For(o, 0, 1) sum[o][i] += sum[o][i - 1];
    int l = 1;
    For(i, 1, maxn) {
        se.insert(sum[1][i] - i);
        while(l <= i && sum[0][l] + *se.begin() - sum[1][l - 1] + (l - 1) < 0) {
            se.erase(se.find(sum[1][l] - l));
            l++;
        }
        // if(i == 4) cout << *se.begin() << " " << sum[1][l - 1] << " " << sum[0][l - 1] << endl;
        // if(i <= 5) cout << l << " " << i << endl;
        as[i - l + 1]++;
    }
    Rof(i, n, 1) as[i] += as[i + 1];
    For(i, 1, n) printf("%lld\n", as[i]);
    return 0;
}
