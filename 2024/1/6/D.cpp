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
int T, n, a[maxn + 5];

set<int> se[maxn + 5];

bool sol(int l, int r, int val) {
    // cout << l << " " << r << " " << val << endl;
    if(l > r) return 1;
    if(l == r) return val == a[l];
    auto it = se[val].lower_bound(l);
    vector<int> vec;
    while(it != se[val].end() && *it <= r) {
        vec.pb(*it);
        it++;
    }
    if(!vec.size()) return 0;
    int pre = l - 1, res = 1;
    for(auto i : vec) res &= sol(pre + 1, i - 1, val + 1), pre = i;
    res &= sol(pre + 1, r, val + 1);
    return res;
}

void mian() {
    read(n);
    int fl = 0;
    For(i, 1, n) read(a[i]), se[a[i]].insert(i), fl += !a[i];
    if(fl != 1) {
        puts("NO");
        return;
    }
    if(sol(1, n, 0)) puts("YES");
    else puts("NO");
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
        For(i, 1, n) se[a[i]].clear();
    }
}
