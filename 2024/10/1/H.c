#include<stdio.h>
#include<string.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)

#define maxn 1000000
int n, m, a[maxn + 5], num[maxn + 5];

int main() {
    // freopen("out.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    For(i, 1, n) scanf("%d", &a[i]);
    int now = 1, res = 0, cnt = 0;
    For(i, 1, n) {
        while(now <= n && cnt < m) {
            if(!num[a[now]]) cnt++;
            num[a[now]]++;
            now++;
        }
        // printf("%d %d\n", cnt, now);
        if(now - i == m && cnt == m) res++;
        num[a[i]]--;
        if(!num[a[i]]) cnt--;
    }
    printf("%d\n", res);
}
