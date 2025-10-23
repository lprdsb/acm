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

#define maxn 600
#define maxm 2000
int n, q;
map<string, int> ma;
char s[maxn + 5];
pair<int, int> pa[maxm + 5];

int tot = 0;
int tos() {
    fgets(s, 1000, stdin);
    string res = "";
    char *c = s;
    while(*c && *c != '\n') res += *c, c++;
    if(!ma.count(res)) ma[res] = ++tot;
    return ma[res];
}

vector<int> ch[maxn + 5];
int f[maxn + 5][maxn + 5];

int main() {
    // freopen("in.txt", "r", stdin);
    memset(f, inf, sizeof f);
    read(n); read(q);
    For(i, 1, q) {
        int u = tos(), v = tos();
        pa[i] = { u, v };
    }
    For(i, 1, n) {
        vector<int> vec;
        int m; read(m);
        For(j, 1, m) {
            vec.pb(tos());
        }
        for(auto u : vec) for(auto v : vec) f[u][v] = min(f[u][v], 1);
    }
    // cout << ma.count("Suzhou Jie") << endl;
    // cout << f[ma["Bagou"]][ma["Suzhou Jie"]] << endl;
    For(i, 1, tot) f[i][i] = 0;
    For(k, 1, tot) For(i, 1, tot) For(j, 1, tot) f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
    For(i, 1, q) printf("%d\n", max(0, f[pa[i].fir][pa[i].sec] - 1));
    return 0;
}
