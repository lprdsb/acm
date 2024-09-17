#include<bits/stdc++.h>
using std::max;

const int N = 110;
int t;
int n, m;
int r[N], w[N];
int mr, mw;

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        mr = 0;
        mw = 0;
        for(int i = 0;i < m;i++) {
            scanf("%d%d", &r[i], &w[i]);
            mr = max(mr, r[i]);
            mw = max(mw, w[i]);
        }
        if(mr + mw > n) {
            puts("IMPOSSIBLE");
        }
        else {
            for(int i = 0;i < mr;i++) {
                printf("R");
            }
            for(int i = mr;i < n;i++) {
                printf("W");
            }
            printf("\n");
        }
    }
    return 0;
}