#include<stdio.h>

#define maxn 100000
int L[maxn + 5][2], R[maxn + 5][2];
int T, n, k, a[maxn + 5], las[maxn + 5];

void del(int x) {
    for(int o = 0; o <= 1; ++o) {
        R[L[x][o]][o] = R[x][o];
        L[R[x][o]][o] = L[x][o];
    }
}

void mian() {
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for(int i = 0; i <= n; ++i) R[i][0] = i + 1;
    for(int i = 1; i <= n + 1; ++i) L[i][0] = i - 1;
    for(int i = 1; i <= n; ++i) las[i] = 0;
    for(int i = 1; i <= n; ++i) {
        L[i][1] = las[a[i]];
        las[a[i]] = i;
    }
    for(int i = 1; i <= n; ++i) las[i] = n + 1;
    for(int i = n; i >= 1; --i) {
        R[i][1] = las[a[i]];
        las[a[i]] = i;
    }
    for(int i = 1; i <= n; ++i) {
        printf("%d ", k);
        int tmp = k;
        if(L[k][1] != 0 || R[k][1] != n + 1) {
            if(L[k][1] == 0) k = R[k][1];
            else if(R[k][1] == n + 1) k = L[k][1];
            else if(k - L[k][1] <= R[k][1] - k) k = L[k][1];
            else k = R[k][1];
        }
        else {
            if(L[k][0] == 0) k = R[k][0];
            else if(R[k][0] == n + 1) k = L[k][0];
            else if(k - L[k][0] <= R[k][0] - k) k = L[k][0];
            else k = R[k][0];
        }
        del(tmp);
    }
    puts("");
}

int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%d", &T);
    while(T--) {
        mian();
    }
}