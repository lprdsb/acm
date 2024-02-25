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

int T, n, m, k;

#define maxn 200000
void chkmx(int &x, int y) { if(x < y) x = y; }
int f[11][maxn + 5], st[11][maxn + 5][25];
void ins(int x) {
    For(o, 0, k) {
        st[o][x][0] = f[o][x];
        For(o1, 1, 20) {
            st[o][x][o1] = st[o][x][o1 - 1];
            int tem = x - (1 << (o1 - 1));
            if(tem >= 0) chkmx(st[o][x][o1], st[o][tem][o1 - 1]);
        }
    }
}
int que(int o, int l, int r) {
    if(l > r) return -inf;
    int len = 1, o1 = 0;
    while((len << 1) <= r - l + 1) len <<= 1, o1++;
    return max(st[o][r][o1], st[o][l + len - 1][o1]);
}

int a[maxn + 5], to[maxn + 5];
pair<int, int> opt[maxn + 5];
vector<int> vec[maxn + 5];
void mian() {
    read(n); read(m); read(k);
    For(i, 1, m) {
        read(opt[i].fir); read(opt[i].sec);
        a[opt[i].fir]++; a[opt[i].sec + 1]--;
    }
    For(i, 1, n + 1) a[i] += a[i - 1];
    to[n + 1] = n + 1;
    Rof(i, n, 1) {
        if(a[i] <= k) to[i] = i;
        else to[i] = to[i + 1];
    }
    For(i, 1, m) {
        int now = to[opt[i].fir];
        while(now <= opt[i].sec) {
            if(now != opt[i].fir) vec[now].pb(i);
            now = to[now + 1];
        }
    }
    f[0][0] = 0;
    ins(0);
    For(i, 1, n + 1) {
        if(a[i] <= k) {
            sort(vec[i].begin(), vec[i].end(), [](int _x, int _y) {return opt[_x].fir > opt[_y].fir;});
            vec[i].pb(0);
            int pre = i - 1;
            For(j, 0, (int)vec[i].size() - 1) {
                int tem = j + a[i] - vec[i].size() + 1;
                For(o, 0, k - tem) {
                    chkmx(f[o + tem][i], que(o, opt[vec[i][j]].fir, pre) + 1);
                    // if(i == 2) cout << opt[vec[i][j]].fir << " " << pre << endl;
                }
                pre = opt[vec[i][j]].fir - 1;
            }
        }
        // if(i == 2) cout << que(0, 0, 1) << endl;
        ins(i);
        // if(i == 1) cout << st[0][1][0] << endl;
    }
    int res = 0;
    For(o, 0, k) chkmx(res, f[o][n + 1] - 1);
    printf("%d\n", res);
}

int main() {
    // freopen("in.txt", "r", stdin);
    memset(f, -inf, sizeof f);
    memset(st, -inf, sizeof st);
    read(T);
    while(T--) {
        mian();
        For(i, 1, n + 1) {
            a[i] = 0;
            vec[i].resize(0);
            For(o, 0, k) f[o][i] = -inf;
        }
    }
}
