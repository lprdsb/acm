#include<bits/stdc++.h>
using namespace std;
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define P 998244353

int main() {
    int n, c[2] = { 0, 0 };
    scanf("%d", &n);
    For(i, 1, n) {
        int x; scanf("%d", &x);
        c[x & 1]++;
    }
    printf("%d\n", 1ll * c[0] * c[1] % P);
}