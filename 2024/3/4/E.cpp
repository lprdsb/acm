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

#define maxn 1000
int T, n;
vector<pair<int, int> > ch[2 * maxn + 5];

int vis[2 * maxn + 5], inst[2 * maxn + 5], tp = 0, fl = 0;
pair<int, int> st[2 * maxn + 5];
void dfs(int u, int pre) {
    vis[u] = 1;
    for(auto [v, w] : ch[u]) if(v != pre) {
        inst[u] = 1;
        st[++tp] = { u, w };
        if(inst[v]) {
            For(i, 1, tp) if(st[i].fir == v) {
                int tpi = 0;
                For(j, i, tp) st[++tpi] = st[j];
                tp = tpi;
                break;
            }
            fl = 1;
            return;
        }
        else {
            dfs(v, u);
            if(fl) return;
        }
        tp--;
        inst[u] = 0;
    }
}

int que(int x, int y) {
    if(x > n) swap(x, y);
    printf("? %d %d\n", x, y - n);
    fflush(stdout);
    int res; read(res);
    return res;
}

void mian() {
    read(n);
    For(i, 1, 2 * n) {
        int x, y; read(x); read(y);
        ch[x].pb({ n + y, i });
        ch[n + y].pb({ x, i });
    }
    For(i, 1, 2 * n) if(!vis[i]) {
        dfs(i, 0);
        if(fl) break;
    }
    // cout << fl << endl;
    // For(i, 1, tp) cout << st[i].fir << " "; cout << endl;
    while(tp > 4) {
        int md = 1 + tp >> 1;
        if(md & 1) md++;
        int ok = que(st[1].fir, st[md].fir);
        int fl1 = 0;
        For(i, 1, md - 1) if(st[i].sec == ok) {
            fl1 = 1;
            break;
        }
        if(!fl1) {
            tp = md;
            st[md].sec = ok;
        }
        else {
            int tpi = 1;
            For(i, md, tp) st[++tpi] = st[i];
            tp = tpi;
            st[1].sec = ok;
        }
    }
    if(st[1].fir > n) printf("! %d %d %d %d\n", st[2].fir, st[4].fir, st[1].fir - n, st[3].fir - n);
    else printf("! %d %d %d %d\n", st[1].fir, st[3].fir, st[2].fir - n, st[4].fir - n);
    fflush(stdout);
    char s[10];
    scanf("%s", s);
    if(s[0] == 'E') exit(0);
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        mian();
        tp = fl = 0;
        For(i, 1, 2 * n) {
            ch[i].resize(0);
            inst[i] = vis[i] = 0;
        }
    }
}
