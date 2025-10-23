#include<bits/stdc++.h>
using namespace std;
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define LL long long

int n, m;
vector<int> vec[1000005];

int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }

int main() {
    scanf("%d%d", &n, &m);
    if(gcd(n, m) != 1) puts("NO");
    else {
        puts("YES");
        int nx = 0, ny = 0, fl = 0;
        For(i, 0, n - 1) vec[i].resize(m);
        For(i, 1, n) {
            For(j, 1, m) {
                vec[nx][ny] = (i - 1) * m + j;
                if(j & 1) ny = (ny + j) % m;
                else ny = (ny - j + m) % m;
            }
            if(i != n) vec[nx][ny] = i * m;
            if(i & 1) nx = (nx + i * m) % n;
            else nx = (nx - i * m % n + n) % n;
        }
        For(i, 0, n - 1) {
            For(j, 0, m - 1) printf("%d ", vec[i][j]);
            puts("");
        }
    }
}