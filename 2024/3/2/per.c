#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define Tra(u, i) for(int i = hd[u]; ~i; i = e[i].net)
#define cst const
#define LL long long
#define DD double
#define LD long double
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define inf 0x3f3f3f3f
#define Inf 0x3f3f3f3f3f3f3f3f
#define eps 1e-12

int n;
int vis[15];
int st[15];

void dfs(int now) {
    if(now == n + 1) {
        For(i, 1, n) printf("%d ", st[i]);
        puts("");
        return;
    }
    For(i, 1, n) if(!vis[i]) {
        st[now] = i;
        vis[i] = 1;
        dfs(now + 1);
        vis[i] = 0;
    }
}

int main() {
    scanf("%d", &n);
    dfs(1);
}
