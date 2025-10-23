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

#define maxn 10000
#define maxm 1000000
int T, a[2][maxn + 5], b[maxm + 5], n;
vector<int> d[maxm + 5];

void mian() {
    read(n);
    For(o, 0, 1) {
        For(i, 1, n) read(a[o][i]);
        sort(a[o] + 1, a[o] + n + 1);
    }
    For(i, 1, n) b[a[1][i]]++;
    if(a[1][n] > a[0][n]) {
        puts("-1");
        return;
    }
    int fl = 1;
    For(i, 1, n) if(a[0][i] != a[1][i]) {
        fl = 0;
        break;
    }
    if(fl) printf("%d\n", a[0][n] + 1);
    else {
        unordered_set<int> se;
        For(i, 1, n) for(auto di : d[a[0][n] - a[1][i]]) if(a[0][n] % di == a[1][i]) se.insert(di);
        for(auto di : se) {
            int fl = 1;
            For(i, 1, n) {
                int t = a[0][i] % di;
                if(b[t] == 0) {
                    fl = 0;
                    For(j, 1, i - 1) b[a[0][j] % di]++;
                    break;
                }
                b[t]--;
            }
            if(fl) {
                printf("%d\n", di);
                return;
            }
        }
        puts("-1");
    }
}

int main() {
    For(i, 1, maxm) for(int j = i; j <= maxm; j += i) d[j].pb(i);
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
        For(i, 1, n) b[a[1][i]] = 0;
    }
}
