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

#define maxn 100000
struct Node {
    int a, b;
} p[maxn + 5];
typedef struct Node Node;

int n;

int main() {
    scanf("%d", &n);
    For(i, 0, n - 1) {
        scanf("%d%d", &p[i].a, &p[i].b);
    }
    int now = 0;
    while(666) {
        int x; scanf("%d", &x);
        if(x == -1) break;
        int mn = -1;
        For(i, 1, n) {
            if(p[now].b >= x) {
                if(mn == -1 || p[now].b < p[mn].b) mn = now;
            }
            now++;
            if(now == n) now = 0;
        }
        if(mn != -1) {
            now = mn;
            p[now].b -= x;
        }
    }
    For(i, 1, n) {
        if(p[now].b) printf("%d %d\n", p[now].a, p[now].b);
        now++;
        if(now == n) now = 0;
    }
}
