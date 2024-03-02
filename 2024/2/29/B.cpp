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

#define maxn 500000
int T, n, a[maxn + 5];

LL sum = 0;
vector<int> vec[2];

void mian() {
    read(n);
    For(i, 1, n) {
        char c; cin >> c;
        if(c == '<') a[i] = 0;
        else a[i] = 1;
    }
    sum = 0;
    vec[0].resize(0); vec[1].resize(0);
    Rof(i, n, 1) if(!a[i]) vec[1].pb(i);
    For(i, 1, n) {
        if(!a[i]) {
            if(vec[0].size() >= vec[1].size()) sum += vec[0][vec[0].size() - vec[1].size()] - i;
            else sum += vec[1][vec[1].size() - vec[0].size() - 1] - i;
            vec[1].pop_back();
        }
        // if(i == 2) cout << "asd" << sum << "asd" << endl;
        if(vec[a[i]].size() <= vec[!a[i]].size()) printf("%lld ", 2 * sum + (a[i] ? n - i + 1 : i));
        else {
            if(a[i]) printf("%lld ", 2 * sum + i + 2 * (vec[a[i]][vec[a[i]].size() - vec[!a[i]].size() - 1] - i));
            else printf("%lld ", 2 * sum + n - i + 1 + 2 * (i - vec[a[i]][vec[a[i]].size() - vec[!a[i]].size() - 1]));
        }
        if(a[i]) {
            vec[0].push_back(i);
            if(vec[1].size() >= vec[0].size()) sum += vec[1][vec[1].size() - vec[0].size()] - i;
            else sum += vec[0][vec[0].size() - vec[1].size() - 1] - i;
        }
    }
    puts("");
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
