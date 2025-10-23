#include<bits/stdc++.h>
#define fs(i,x,y) for(int i=(x),_=(y);i<=_;++i)
#define fn(i,x,y) for(int i=(x),_=(y);i>=_;--i)
using namespace std;
typedef long long ll;

const int P = 998244353;
const int N = 1e5 + 7;
struct Mat {
    static const int N = 16;
    int a[N + 1][N + 1];
    Mat() { fs(i, 0, N)fs(j, 0, N)a[i][j] = 0; }
    void clr() {
        fs(i, 0, N)fs(j, 0, N)a[i][j] = 0;
    }
    Mat operator *(Mat rhs) {
        Mat tp;
        fs(i, 0, N)fs(k, 0, N)fs(j, 0, N)tp.a[i][j] = (tp.a[i][j] + (ll)a[i][k] * rhs.a[k][j]) % P;
        return tp;
    }
}A, ans;

ll n;
int k;
int a[N];
int f[N], g[N];

Mat qw(Mat a, ll b) {
    Mat ans;fs(i, 0, 16)ans.a[i][i] = 1;
    for(;b;a = a * a, b >>= 1)if(b & 1)ans = ans * a;
    return ans;
}

int qw(int a, ll b) {
    int ans = 1;for(;b;a = (ll)a * a % P, b >>= 1)if(b & 1)ans = (ll)ans * a % P;
    return ans;
}

void solve() {
    scanf("%lld%d", &n, &k);
    fs(j, 1, k)scanf("%d", &a[j]);
    A.clr();fs(i, 0, 16)f[i] = 0, g[i] = 0;
    fs(j, 1, k) {
        int v = a[j];
        fs(i, 0, 15) {
            A.a[16][i] = (A.a[16][i] + (i + v) / 16) % P, A.a[(i + v) % 16][i] = (A.a[(i + v) % 16][i] + 1) % P;
            A.a[16][i] = (A.a[16][i] + (i * v) / 16) % P, A.a[(i * v) % 16][i] = (A.a[(i * v) % 16][i] + 1) % P;
            A.a[i & v][i] = (A.a[i & v][i] + 1) % P;
            A.a[i | v][i] = (A.a[i | v][i] + 1) % P;
            A.a[i ^ v][i] = (A.a[i ^ v][i] + 1) % P;
        }
        A.a[16][16] = (A.a[16][16] + 1) % P;
        A.a[16][16] = (A.a[16][16] + v) % P;
        // A.a[16][16] = (A.a[16][16] + 1) % P;
        A.a[16][16] = (A.a[16][16] + 1) % P;
        A.a[16][16] = (A.a[16][16] + 1) % P;
    }
    fs(j, 1, k)f[a[j]] = 1;
    ans = qw(A, n - 1);
    fs(i, 0, 16)fs(j, 0, 16)g[i] = (g[i] + (ll)ans.a[i][j] * f[j]) % P;
    int sum = 0;
    fs(i, 0, 16)sum = (sum + (ll)g[i] * i) % P;
    int prod = k;
    // fs(i, 1, n - 1)prod = (ll)prod * k % P * 5 % P;
    prod = (ll)prod * qw(k, n - 1) % P * qw(5, n - 1) % P;
    prod = qw(prod, P - 2);
    printf("%lld\n", (ll)sum * prod % P);
}

signed main() {
    int T = 1;
    scanf("%d", &T);
    while(T--) {
        solve();
    }
}