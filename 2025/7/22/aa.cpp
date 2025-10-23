#include<bits/stdc++.h>
#define fs(i,x,y) for(int i=(x),_=(y);i<=_;++i)
#define fn(i,x,y) for(int i=(x),_=(y);i>=_;--i)
using namespace std;

const int N = 2e3 + 3;
int a[N][N];
int f[N];
int n;

void solve() {
    scanf("%d", &n);
    fs(i, 1, n)scanf("%d", &f[i]);
    fs(i, 1, n) {
        if(f[i] == 1) {
            fs(j, 1, i - 1)a[i][j] = a[j][i] = 0;
            a[i][i] = 0;
        }
        else {
            a[i][i] = 1;
            fs(j, 1, f[i] - 2)a[i][j] = a[j][i] = j + 1;
            fs(j, f[i] - 1, i - 1)a[i][j] = a[j][i] = 0;
        }
    }
    fs(i, 1, n) {
        fs(j, 1, n)printf("%d ", a[i][j]);
        printf("\n");
    }
}

signed main() {
    int T;scanf("%d", &T);
    while(T--) {
        solve();
    }
}