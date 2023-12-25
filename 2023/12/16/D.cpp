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
int T, n, a[maxn + 5];

template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for (ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if (ch == '-') ok = 1;
    for (x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if (ok) x = -x;
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while (T--) {
        read(n);
        set<int> se; se.insert(n);
        map<int, int> ma;
        LL sum = 0;
        For(i, 1, n) read(a[i]);
        Rof(i, n, 1) {
            ma[*se.begin()]++;
            sum += *se.begin();
            se.insert(a[i]);
        }
        LL res = sum;
        For(i, 1, n - 1) {

            sum -= a[i] == 0;
            ma[a[i] == 0]--;
            if (ma[a[i] == 0] == 0) ma.erase(a[i] == 0);

            auto it = ma.lower_bound(a[i]);
            vector<int> vec;
            int cnt = 0;
            while (it != ma.end()) {
                sum -= 1ll * it->fir * it->sec;
                cnt += it->sec;
                vec.pb(it->fir);
                it++;
            }
            for (auto j : vec) ma.erase(j);
            ma[a[i]] += cnt;
            sum += 1ll * cnt * a[i];

            sum += n;
            ma[n]++;

            res = max(res, sum);
            // cout << i << " " << sum << endl;
            // if (i == 3) {
            //     for (auto [j, p] : ma) cout << j << " " << p << endl;
            // }
        }
        printf("%lld\n", res);
    }
    return 0;
}
