#include<bits/stdc++.h>

using namespace std;

int tt;
int n, k, s, t;

int main() {
    scanf("%d", &tt);
    while(tt--) {
        scanf("%d%d%d%d", &n, &k, &s, &t);
        if(t < s) {
            swap(s, t);
        }
        if(s * 2 > n) {
            s = n - s;
            t = n - t;
            swap(s, t);
        }
        if(n == k) {
            if(t == s) {
                printf("0\n");
            }
            else if(t == n - s) {
                printf("1\n");
            }
            else {
                printf("-1\n");
            }
        }
        else if(n > k && n < 2 * k) {

        }
        else {
            if(t == s) {
                printf("0\n");
            }
            else if(t < k - s) {
                if((t - s) % 2 == 0) {
                    printf("2\n");
                }
                else if(k % 2 == 1) {
                    printf("3\n");
                }
                else {
                    printf("-1\n");
                }
            }
            else if(t <= s + k) {
                if((s + k - t) % 2 == 0) {
                    printf("1\n");
                }
                else {
                    printf("")
                }
            }
            else if(t <= s + k && ) {
                printf("1\n");
            }
            else if((((t - s - 1) / k + 1) * k - (t - s)) % 2 == 0) {
                printf("%d\n", (t - s - 1) / k + 1);
            }
            else if((((t - s - 1) / k + 2) * k - (t - s)) % 2 == 0) {
                printf("%d\n", (t - s - 1) / k + 2);
            }
            else {
                printf("-1\n");
            }
        }
    }
    return 0;
}