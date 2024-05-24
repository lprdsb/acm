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
int n, m, a[maxn + 5][maxn + 5];
void mian() {
    read(n); read(m);
    For(i, 1, n) For(j, 1, n) a[i][j] = 0;
    int fl = 0;
    if(m >= n + 2) {
        fl = 1;
        a[1][1] = a[1][n] = 1;
        m -= 4;
        int now = 2;
        while(m >= n - 2 && now <= n) {
            For(i, 2, n - 1) a[now][i] = 1;
            m -= n - 2;
            now++;
        }
        if(now <= n) {
            a[now][1] = a[now][n] = 1;
            For(i, 2, 1 + m) a[1][i] = 1;
        }
        else {
            a[n][1] = a[n][n] = 1;
            now = 2;
            while(m && now <= n - 1) {
                a[1][now++] = 1;
                m--;
            }
            now = 2;
            while(m && now <= n - 1) {
                a[now++][1] = 1;
                m--;
            }
            now = 2;
            while(m && now <= n - 1) {
                a[now++][n] = 1;
                m--;
            }
        }
    }
    else {
        fl = 1;
        if(m >= 7) {
            For(i, 1, m - 2) a[1][i] = 1;
            a[2][1] = a[2][m - 3] = 1;
        }
        else {
            if(m == 1) a[1][1] = 1;
            else if(m == 2) a[1][1] = a[1][n] = 1;
            else if(m == 3) a[1][1] = a[1][n] = a[n][1] = 1;
            else if(m == 4) a[1][1] = a[1][n] = a[n][1] = a[n][n] = 1;
            else if(m == 5) a[1][1] = a[2][1] = a[1][2] = a[1][n] = a[n][1] = 1;
            else if(m == 6) a[1][1] = a[2][1] = a[1][2] = a[3][1] = a[2][2] = a[1][3] = 1;
        }
    }

    if(fl) {
        puts("Yes");
        For(i, 1, n) {
            For(j, 1, n) printf("%d", a[i][j]);
            puts("");
        }
    }
    else puts("No");
}

int main() {
    //freopen("in", "r", stdin);
    int T; read(T);
    while(T--) {
        mian();
    }
}
