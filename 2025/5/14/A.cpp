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
int T, n, ma[maxn + 5][maxn + 5];

void mian() {
    read(n);
    int tot = n * n, si = 0, sj = 1, t = n;
    // ma[si][sj] = --tot;
    while(tot) {
        For(i, 1, t) ma[++si][sj] = --tot;
        For(i, 1, t - 1) ma[si][++sj] = --tot;
        For(i, 1, t - 1) ma[--si][sj] = --tot;
        For(i, 1, t - 2) ma[si][--sj] = --tot;
        t -= 2;
    }
    For(i, 1, n) {
        For(j, 1, n) printf("%d ", ma[i][j]); puts("");
    }

}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
