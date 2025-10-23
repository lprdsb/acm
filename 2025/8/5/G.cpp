#include<bits/stdc++.h>
using namespace std;
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define LL long long


#define maxn 1000000
int T, n, pri[maxn + 5], cnt = 0, vis[maxn + 5], sum[maxn + 5];

void mian() {
    scanf("%d", &n);
    int tot = n / 2;
    For(i, 1, n) if(i % 2) {
        for(int j = i; j <= n; j *= 2) {
            if(vis[j] % 2) {
                printf("%d ", j);
                tot--;
                if(!tot) break;
            }
        }
        if(!tot) break;
    }
    puts("");
}

int main() {
    For(i, 2, maxn) {
        if(!vis[i]) vis[i] = 1, pri[++cnt] = i;
        for(int j = 1;j <= cnt && i * pri[j] <= maxn; ++j) {
            vis[i * pri[j]] = vis[i] + 1;
            if(i % pri[j] == 0)  break;
        }
    }
    // For(i, 1, maxn) if(i % 2) {
    //     for(int j = i; j <= maxn; j *= 2) {
    //         if(vis[j] % 2) sum[j]++;
    //     }
    // }
    // For(i, 1, maxn) sum[i] += sum[i - 1];
    // For(i, 1, maxn) cout << i << " " << sum[i] << endl;
    // For(i, 1, maxn) if(i % 2 == 0 && sum[i] < n / 2) cout << "asd" << endl;
    scanf("%d", &T);
    while(T--) {
        mian();
    }
}