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
int T, n, k, as[maxn + 5][maxn + 5];

void sol() {
    For(i, 0, n - 1) For(j, 0, n - 1) as[i][j] = 0;
    read(n); read(k);
    if(k % n == 0) {
        For(i, 0, k / n - 1) {
            For(j, 0, n - 1) as[(i + j) % n][j] = 1;
        }
        puts("Yes");
        For(i, 0, n - 1) {
            For(j, 0, n - 1) printf("%d ", as[i][j]);
            puts("");
        }
        puts("");
        return;
    }
    if(k % 4 == 0) {
        for(int i = 0; i < n; i += 2) {
            for(int j = 0; j < n; j += 2) {
                as[i][j] = as[i][j + 1] = as[i + 1][j] = as[i + 1][j + 1] = 1;
                k -= 4;
                if(!k) break;
            }
            if(!k) break;
        }
        puts("Yes");
        For(i, 0, n - 1) {
            For(j, 0, n - 1) printf("%d ", as[i][j]);
            puts("");
        }
        puts("");
        return;
    }
    else if(k % 4 == 2) {
        if(n * n - k >= 6 && k >= 6) {
            k -= 6;
            if(k) {
                for(int i = 4; i < n; i += 2) {
                    as[0][i] = as[0][i + 1] = as[1][i] = as[1][i + 1] = 1;
                    k -= 4;
                    if(!k) break;
                }
            }
            if(k) {
                for(int i = 2; i < n; i += 2) {
                    as[2][i] = as[2][i + 1] = as[3][i] = as[3][i + 1] = 1;
                    k -= 4;
                    if(!k) break;
                }
            }
            if(k) {
                for(int i = 4; i < n; i += 2) {
                    for(int j = 0; j < n; j += 2) {
                        as[i][j] = as[i][j + 1] = as[i + 1][j] = as[i + 1][j + 1] = 1;
                        k -= 4;
                        if(!k) break;
                    }
                    if(!k) break;
                }
            }
            as[0][0] = as[0][2] = as[1][1] = as[1][2] = as[2][0] = as[2][1] = 1;
            puts("Yes");
            For(i, 0, n - 1) {
                For(j, 0, n - 1) printf("%d ", as[i][j]);
                puts("");
            }
            puts("");
            return;
        }
    }
    puts("No");
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        sol();
    }
}
