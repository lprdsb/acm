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

#define maxn 1000000
int T, n, c, k, a[maxn + 5], num[26], vis[maxn + 5];

int sol(vector<int> &vec) {
    if(!vec.size()) return 0;
    // cout << vec[0] << endl;
    vector<int> vv;
    for(auto i : vec) if(!(i & 1)) {
        if(!vis[i >> 1]) vv.pb(i >> 1);
        vis[i >> 1] = 1;
    }
    for(auto i : vec) vis[i >> 1] = 0;
    int res = sol(vv) + 1, fl = 1;
    vv.resize(0);
    for(auto i : vec) {
        if(i == 1) {
            fl = 0;
            break;
        }
        if(!vis[i >> 1]) vv.pb(i >> 1);
        vis[i >> 1] = 0;
    }
    for(auto i : vec) vis[i >> 1] = 0;
    if(fl) res = min(res, sol(vv));
    return res;
}

void mian() {
    read(n); read(c); read(k);
    For(i, 0, c - 1) num[i] = 0;
    For(i, 1, n) {
        char cc; cin >> cc;
        a[i] = cc - 'A';
    }
    int sta = 0;
    For(i, 1, k - 1) {
        num[a[i]]++;
        sta |= 1 << a[i];
    }
    For(i, k, n) {
        if(!num[a[i]]) sta |= 1 << a[i];
        num[a[i]]++;
        vis[sta] = 1;
        num[a[i - k + 1]]--;
        if(!num[a[i - k + 1]]) sta ^= 1 << a[i - k + 1];
    }
    vector<int> vec;
    For(i, 0, (1 << c) - 1) if(vis[i] && !((i >> a[n]) & 1)) vec.pb(i);
    For(i, 0, (1 << c) - 1) vis[i] = 0;
    // for(auto i : vec) cout << i << endl;
    printf("%d\n", sol(vec) + 1);
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
