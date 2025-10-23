#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

int tt;
int n, m, k;
char c[N];
int a[N];
int b[N];

int main() {
    scanf("%d", &tt);
    while(tt--) {
        scanf("%d%d%d", &n, &m, &k);
        for(int i = 0;i < n;i++) {
            scanf("%s", c);
            for(int j = 0;j < m;j++) {
                a[i * m + j] = c[j] - '0';
            }
        }
        int ans = 0;
        for(int j = m - 2;j >= 0;j--) {
            int lst = 0, f = 2;
            for(int i = 0;i < n;i++) {
                if(a[i * m + j] == 1) {
                    for(int s = lst;s < i;s++) {
                        a[s * m + j] = f;
                    }
                    lst = i + 1;
                    f = 2;
                    continue;
                }
                if(a[i * m + j + 1] == 0) {
                    f = 0;
                }
                if(a[i * m + j + 1] > 1 && f > 0) {
                    f = max(f, a[i * m + j + 1] + 1);
                }
            }
            for(int s = lst;s < n;s++) {
                a[s * m + j] = f;
            }
        }
        for(int i = 0;i < n;i++) {
            b[i * m] = 1;
            for(int j = 1;j < m;j++) {
                b[i * m + j] = 0;
            }
        }
        for(int j = 1;j < m - 1;j++) {
            for(int i = 0;i < n;i++) {
                if(b[i * m + j - 1] && a[i * m + j] != 1) {
                    b[i * m + j] = 1;
                }
            }
            for(int i = 1;i < n;i++) {
                if(b[(i - 1) * m + j] && a[i * m + j] != 1) {
                    b[i * m + j] = 1;
                }
            }
            for(int i = n - 2;i >= 0;i--) {
                if(b[(i + 1) * m + j] && a[i * m + j] != 1) {
                    b[i * m + j] = 1;
                }
            }
            for(int i = 0;i < n;i++) {
                if(b[i * m + j] && a[i * m + j] > k) {
                    ans = 1;
                    break;
                }
            }
            if(ans) {
                break;
            }
        }
        // for(int i = 0;i < n;i++) {
        //     for(int j = 0;j < m;j++) {
        //         printf("%d", a[i * m + j]);
        //     }
        //     printf("\n");
        // }
        // for(int i = 0;i < n;i++) {
        //     for(int j = 0;j < m;j++) {
        //         printf("%d", b[i * m + j]);
        //     }
        //     printf("\n");
        // }
        puts(ans ? "YES" : "NO");
    }
    return 0;
}