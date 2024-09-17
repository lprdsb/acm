#include<bits/stdc++.h>

typedef long long ll;

const int N = 110;
const ll M = 998244353;

int t;
int n;
int a[N];
ll ans;

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 0;i < n;i++) {
            scanf("%d", &a[i]);
        }
        bool f;
        while(true) {
            f = false;
            for(int i = 0;i < n - 1;i++) {
                if(a[i] < a[i + 1]) {
                    a[i]++;
                    a[i + 1]--;
                    f = true;
                }
            }
            if(!f) {
                break;
            }
        }
        ans = 1;
        for(int i = 0;i < n;i++) {
            ans = ans * a[i] % M;
        }
        printf("%lld\n", ans);
    }
    return 0;
}