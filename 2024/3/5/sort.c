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

int n, tot = 0;
struct Node {
    int tot;
    char name[1000];
    LL num[1000];
} dat[105];

int st[1005], tp = 0, ind[105];

int cmp(char *x, char *y) {
    int lx = strlen(x), ly = strlen(y), up = lx;
    if(ly > up) up = ly;
    For(i, 0, up) if(x[i] != y[i]) {
        if(x[i] < y[i]) return -1;
        else return 1;
    }
    return 0;
}

int ccmp(cst void *x, cst void *y) {
    return cmp(dat[*(int*)x].name, dat[*(int*)y].name);
}

void sol(int x) {
    if(x) printf("_");
    while(x) st[++tp] = x % 10, x /= 10;
    while(tp) printf("%d", st[tp--]);
    printf(" ");
}

int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    For(i, 1, n) {
        char name[1001];
        LL num;
        int ffl = 0;
        scanf("%s%lld", name, &num);
        For(j, 1, tot) if(!cmp(dat[j].name, name)) {
            ffl = 1;
            int fl = 0;
            For(p, 1, dat[j].tot) if(dat[j].num[p] == num) {
                fl = 1;
                break;
            }
            if(!fl) dat[j].num[++dat[j].tot] = num;
            break;
        }
        if(!ffl) {
            tot++;
            strcpy(dat[tot].name, name);
            dat[tot].num[dat[tot].tot = 1] = num;
        }
    }
    For(i, 1, tot) ind[i] = i;
    qsort(ind + 1, tot, 4, ccmp);
    For(i, 1, n) {
        For(j, 1, dat[ind[i]].tot) {
            printf("%s", dat[ind[i]].name);
            sol(j - 1);
            printf("%lld\n", dat[ind[i]].num[j]);
        }
    }
    return 0;
}
