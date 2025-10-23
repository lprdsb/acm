#include<bits/stdc++.h>
#define fs(i,x,y) for(int i=(x),_=(y);i<=_;++i)
#define fn(i,x,y) for(int i=(x),_=(y);i>=_;--i)
using namespace std;
typedef long long ll;

const int N = 205;
int x;
int n;
int d;
int b[N];
int a[N][N];
int f[5][5][5];

void cover(int x0, int x1, int y0, int y1, int typ) {
    fs(i, x0, x1) {
        fs(j, y0, y1) {
            a[i][j] = f[typ][i - x0 + 1][j - y0 + 1];
        }
    }
}

void solve() {
    scanf("%d", &x);
    while(x) {
        b[d + 1] = x & 1;x >>= 1;
        ++d;
    }
    printf("%d\n", d * 3);
    n = d * 3;
    fs(i, 1, d - 1) {
        cover(i * 3 - 2, i * 3, i * 3 - 2, i * 3, 2);
        cover(i * 3 - 2, i * 3, i * 3 + 1, i * 3 + 3, 3);
        cover(d * 3 - 2, d * 3, i * 3 - 2, i * 3, b[i]);
    }
    cover(d * 3 - 2, d * 3, d * 3 - 2, d * 3, 1);
    fs(i, 1, n) {
        fs(j, 1, n) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

signed main() {
    int T = 1;
    f[3][1][1] = -1;f[3][2][2] = -1;f[3][3][3] = -1;
    f[1][1][1] = 1;f[1][3][3] = 1;f[1][2][2] = 1;
    f[2][1][1] = 1;f[2][1][3] = 1;f[2][2][1] = 1;f[2][2][2] = 1;f[2][3][2] = 1;f[2][3][3] = 1;
    // scanf("%d", &T);
    while(T--) {
        solve();
    }
}