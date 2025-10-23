#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 50;

int n, q;
int a[N];
int b[N];
int c[N];
int d[N];
int s[N];

int main() {
    scanf("%d%d", &n, &q);
    for(int i = 0;i < n;i++) {
        scanf("%d", &a[i]);
    }
    b[0] = (a[0] - 1) / 2 + 1;
    for(int i = 1;i <= 32;i++) {
        b[i] = (b[i - 1] + a[i] - 1) / 2 + 1;
    }
    for(int i = 0;i <= 32;i++) {
        c[i] = -1;
    }
    for(int i = 33;i < n;i++) {
        b[i] = (b[i - 1] + a[i] - 1) / 2 + 1;
        c[i] = a[i - 32] - 1;
        for(int j = i - 32;j <= i;j++) {
            c[i] = (c[i] + a[j] - 1) / 2 + 1;
        }
        if((c[i - 1] + a[i] - 1) / 2 + 1 == b[i]) {
            d[i]++;
        }
    }
    for(int i = 1;i < n;i++) {
        s[i] = s[i - 1] + d[i];
    }
    while(q--) {
        int x, y;
        scanf("%d%d", &x, &y);
        int k = upper_bound(a, a + n, x) - a;
        k = n - k;
        if(k < y) {
            printf("0\n");
        }
        else {
            int z = x;
            while(k >= y) {
                z = (z + a[n - k] - 1) / 2 + 1;
                if(z == b[n - k]) {
                    z = b[n - y];
                    break;
                }
                if(z == c[n - k]) {
                    if(s[n - y] - s[n - k] == 0) {
                        z = c[n - y];
                    }
                    else {
                        z = b[n - y];
                    }
                    break;
                }
                k--;
            }
            printf("%d\n", z - x);
        }
    }
    return 0;
}