/*
 Author: 李澎瑞
 Result: REG	Submission_id: 7048714
 Created at: Wed Nov 27 2024 20:27:28 GMT+0800 (China Standard Time)
 Problem_id: 8862	Time: 2539	Memory: 23092
*/

#include<bits/stdc++.h>
#include <sys/resource.h>
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
int n, m, col[maxn + 5];
vector<int> ch[maxn + 5];

int c[2];
int dfs(int u) {
    c[col[u]]++;
    for(auto v : ch[u]) {
        if(col[v] == -1) {
            col[v] = 1 - col[u];
            if(!dfs(v)) {
                // cout << "asd" << endl;
                return 0;
            }
        }
        else if(col[v] != 1 - col[u]) {
            // cout << "asd" << endl;
            return 0;
        }
    }
    return 1;
}

int main() {
    // freopen("in.txt", "r", stdin);
    struct rlimit r;
    getrlimit(RLIMIT_STACK, &r);
    r.rlim_cur = 1 << 24;
    setrlimit(RLIMIT_STACK, &r);
    read(n); read(m);
    For(i, 1, m) {
        int u, v; read(u); read(v);
        ch[u].pb(v);
        ch[v].pb(u);
    }
    For(i, 1, n) col[i] = -1;
    LL res = 0;
    For(i, 1, n) if(col[i] == -1) {
        // cout << i << 
        c[0] = c[1] = 0;
        col[i] = 0;
        if(dfs(i)) {
            // cout << "asd" << endl;
            res += 2ll * c[1] * c[0];
        }
    }
    printf("%lld\n", res);
}