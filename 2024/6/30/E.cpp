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

#define maxn 5000
int T, n, a[maxn + 5];
LL f[maxn + 5][maxn + 5];
vector<int> ch[maxn + 5];

#define LLL __int128_t
LL b[maxn + 5];
LLL sum = 0;
void dfs(int u, int pre) {
    For(i, 0, n) f[u][i] = 0;
    b[u] = 0;
    for(auto v : ch[u]) if(v != pre) {
        dfs(v, u);
        b[u] += a[v];
        For(i, 0, n) if(f[u][i + 1] != -1) {
            if(f[v][i] != -1) f[u][i + 1] += f[v][i];
            else f[u][i + 1] = -1;
        }
    }
    b[u] -= a[u];
    // if(u == 2) cout << b[u] << endl;
    if(ch[u].size()) {
        if(b[u] < 0) {
            LL cnt = -b[u];
            For(i, 0, n) if(f[u][i]) {
                if(f[u][i] == -1) {
                    sum += (LLL)cnt * i;
                    break;
                }
                LL tem = min(cnt, f[u][i]);
                cnt -= tem;
                f[u][i] -= tem;
                sum += (LLL)tem * i;
                if(!cnt) break;
            }
        }
        else f[u][0] += b[u];
    }
    else f[u][0] = -1;
}
void write(LLL x) {
    if(x == 0) {
        puts("0");
        return;
    }
    vector<int> vec;
    while(x) vec.pb(x % 10), x /= 10;
    reverse(vec.begin(), vec.end());
    for(auto i : vec) printf("%d", i); puts("");
}

void mian() {
    read(n);
    For(i, 1, n) read(a[i]);
    For(i, 2, n) {
        int p; read(p);
        ch[p].pb(i);
    }
    sum = 0;
    dfs(1, 0);
    write(sum);
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
        For(i, 1, n) {
            ch[i].resize(0);
        }
    }
}
