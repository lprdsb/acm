#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define For(i, a, b) for(LL i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define LL long long
#define maxn 20

int n;
int a[maxn + 5][maxn + 5], b[maxn + 5][maxn + 5];

char s[2005];
void read(int *A) {
    int len = 0;
    while(666) {
        fgets(s + 1, 2000, stdin); len = strlen(s + 1);
        int fl = 0;
        For(i, 1, len) if(s[i] >= '0' && s[i] <= '9') {
            fl = 1;
            break;
        }
        if(fl) break;
        // if(len != 1 || s[1] == '0') break;
    }
    // printf("asd : %s", s + 1);
    A[0] = 1;
    A[1] = -1;
    For(i, 1, len) {
        if(s[i] >= '0' && s[i] <= '9') {
            if(A[A[0]] == -1) A[A[0]] = 0;
            A[A[0]] = A[A[0]] * 10 + s[i] - '0';
        }
        else if(A[A[0]] != -1) {
            A[++A[0]] = -1;
        }
    }
    if(A[A[0]] == -1) A[0]--;
    if(!A[1]) A[0]--;
}

int ok[maxn + 5][60005], st[20][60005], tp[20];

void dfs(int idx, int pos, int now, int sta) {
    if(now == a[idx][0] + 1) {
        ok[idx][sta] = 1;
        st[idx][++tp[idx]] = sta;
        return;
    }
    if(pos + a[idx][now] > n) return;
    dfs(idx, pos + 1, now, sta);
    dfs(idx, pos + a[idx][now] + 1, now + 1, sta | (((1 << a[idx][now]) - 1) << pos));
}

int bas[20], as[20];
int dfs1(int idx, int mask, int sta) {
    if(idx == n + 1) {
        For(i, 1, n) if(bas[i] <= b[i][0]) return 0;
        For(i, 1, n) {
            For(j, 0, n - 1) printf("%d", (as[i] >> j) & 1);
            puts("");
        }
        return 1;
    }
    For(i, 1, tp[idx]) if((st[idx][i] & mask) == (sta & mask)) {
        int maski = 0, stai = 0, fl = 0;
        For(o, 0, n - 1) if(((st[idx][i] >> o) & 1) && bas[o + 1] > b[o + 1][0]) {
            fl = 1;
            break;
        }
        if(fl) continue;
        int tmp = 0;
        For(o, 0, n - 1) if((st[idx][i] >> o) & 1) {
            maski |= 1 << o;
            b[o + 1][bas[o + 1]]--;
            stai |= (b[o + 1][bas[o + 1]] != 0) << o;
            if(!b[o + 1][bas[o + 1]]) {
                bas[o + 1]++;
                tmp |= 1 << o;
            }
        }
        as[idx] = st[idx][i];
        if(dfs1(idx + 1, maski, stai)) return 1;
        For(o, 0, n - 1) if((st[idx][i] >> o) & 1) {
            if((tmp >> o) & 1) bas[o + 1]--;
            b[o + 1][bas[o + 1]]++;
        }
    }
    return 0;
}

int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    For(i, 1, n) read(a[i]);
    For(i, 1, n) read(b[i]);
    For(i, 1, n) {
        For(j, 1, a[i][0]) if(!a[i][j]) {
            while(666) n++;
        }
        For(j, 1, b[i][0]) if(!b[i][j]) {
            while(666) n++;
        }
    }
    // For(i, 1, n) {
    //     printf("%d\n", b[i][0]);
    //     For(j, 1, b[i][0]) printf("%d ", b[i][j]);
    //     puts("");
    // }
    For(i, 1, n) dfs(i, 0, 1, 0);
    For(i, 1, n) bas[i] = 1;
    if(!dfs1(1, 0, 0)) {
        puts("-1");
        // while(666) n++;
    }
    // For(i, 0, 60000) if(ok[2][i]) {
    //     Rof(o, n - 1, 0) printf("%d", (i >> o) & 1);
    //     puts("");
    // }
}