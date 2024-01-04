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

#define maxn 100000
int T, n, sx, sy, vis[maxn + 5];
vector<int> num[2];

template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

int que() {
    int x; read(x);
    if(x == -1 || x > n || x <= 0) exit(0);
    vis[x] = 1;
    return x;
}

int get_o(int o) {
    while(num[o].size() && vis[num[o][num[o].size() - 1]]) num[o].pop_back();
    if(num[o].size()) {
        int res = num[o][num[o].size() - 1];
        num[o].pop_back();
        return res;
    }

    while(num[!o].size() && vis[num[!o][num[!o].size() - 1]]) num[!o].pop_back();
    assert(num[!o].size());
    int res = num[!o][num[!o].size() - 1];
    num[!o].pop_back();
    return res;
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        read(n); read(sx); read(sy);
        num[0].resize(0); num[1].resize(0);
        For(i, 1, n) {
            int x, y; read(x); read(y);
            num[(x & 1) ^ (y & 1)].pb(i);
        }
        int pos = (sx & 1) ^ (sy & 1);
        if(num[pos].size() >= num[!pos].size()) {
            puts("First");
            fflush(stdout);
            for(int i = 1; i <= n; i += 2) {
                printf("%d\n", get_o(!pos));
                fflush(stdout);
                if(i < n) que();
            }
        }
        else {
            puts("Second");
            fflush(stdout);
            if(n == 1) que();
            for(int i = 2; i <= n; i += 2) {
                que();
                printf("%d\n", get_o(pos));
                fflush(stdout);
                if(i + 1 == n) que();
            }
        }
        For(i, 1, n) vis[i] = 0;
    }
}
