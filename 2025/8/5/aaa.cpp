#include<bits/stdc++.h>
#define fs(i,x,y) for(int i=(x),_=(y);i<=_;++i)
#define fn(i,x,y) for(int i=(x),_=(y);i>=_;--i)
using namespace std;
typedef long long ll;

const int N = 105;
int a[N][N];
int id, m, k, n;
int b[N];

#define maxm 100
int tr[105];
void ins(int x) {
    x = 101 - x;
    while(x <= maxm) tr[x] ^= 1, x += x & -x;
}
int que(int x) {
    x = 101 - x;
    int res = 0;
    while(x) res ^= tr[x], x -= x & -x;
    return res;
}

void solve() {
    scanf("%d%d%d%d", &id, &m, &k, &n);
    int now = 0;
    fs(stp, 1, m) {
        int hh = 0;
        int cnt = 0;
        fs(st, 1, k) {
            fs(i, 1, 100) tr[i] = 0;
            fs(i, 1, n)fs(j, 1, n) {
                scanf("%d", &a[i][j]);
                cnt ^= que(a[i][j]);
                ins(a[i][j]);
            }
            hh |= cnt;
        }
        b[stp] = hh;
    }
    fs(i, 1, m)printf("%d", b[i]);
    printf("\n");
    // fs(i, 1, 100)b[i] = i;
    // random_shuffle(b + 1, b + 101);
    // int now = 0;
    // fs(i, 1, 10) {
    //     fs(j, 1, 10)a[i][j] = b[++now];
    // }
    // int hh = 1;
    // fs(i, 1, 10 - 1) {
    //     fs(j, 1, 10 - 1) {
    //         int tp = a[i][j] + a[i + 1][j] + a[i][j + 1] + a[i + 1][j + 1];
    //         if(tp % 4 != 2)hh = 0;
    //     }
    // }
    // cout << hh << endl;
}

signed main() {
    int T = 1;
    while(T--) {
        solve();
    }
}