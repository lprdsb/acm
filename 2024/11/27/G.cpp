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
int T, n, m;
int f[2][maxn + 5];

int l[maxn + 5];
vector<int> vec[maxn + 5];

void mian() {
    read(n); read(m);
    int o = 0;
    For(_, 1, n) {
        int k, c, d; read(k); read(c); read(d);
        For(i, 0, c - 1) {
            vec[i].resize(0);
            l[i] = 0;
        }
        o ^= 1;
        // cout << _ << endl;
        For(i, 0, m) {
            if(i) f[o][i] = max(f[o][i - 1], f[!o][i]);
            int t = i % c;
            if(l[t] < vec[t].size()) f[o][i] = max(f[o][i], f[!o][vec[t][l[t]]] + (i - vec[t][l[t]]) / c * d);
            while(vec[t].size() > l[t] && f[!o][i] >= f[!o][vec[t].back()] + (i - vec[t].back()) / c * d) vec[t].pop_back();
            vec[t].push_back(i);
            while(l[t] < vec[t].size() && (i - vec[t][l[t]]) / c >= k) l[t]++;
        }
    }
    int res = 0;
    For(i, 1, m) res = max(res, f[o][i]);
    printf("%d\n", res);
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
        For(o, 0, 1) For(i, 0, m) f[o][i] = 0;
    }
}
