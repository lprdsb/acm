#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define For(i, a, b) for(LL i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define LL long long
#define UI unsigned int
#define maxn 5000000

int vis[maxn + 5], pri[maxn + 5], cnt = 0;

int main() {
    For(i, 2, maxn) {
        if(!vis[i]) pri[++cnt] = i;
        for(int j = 1; j <= cnt && i * pri[j] <= maxn; ++j) {
            vis[i * pri[j]] = 1;
            if(i % pri[j] == 0) break;
        }
    }
    // For(i, 1, cnt) printf("%d ", pri[i]);
    int n; scanf("%d", &n);
    For(i, 1, n) {
        int x; scanf("%d", &x);
        if(!vis[x]) puts("1");
        else if(!vis[x - 2] || x % 2 == 0) puts("2");
        else puts("3");
    }
}