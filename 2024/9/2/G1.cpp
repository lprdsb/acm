#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 100;
int a[N], L[N], R[N], qz1[N], qz2[N], Ans[N];

int main() {
    freopen("in.txt", "r", stdin);
    int T;scanf("%d", &T);
    while(T--) {
        int n, q, K;
        scanf("%d%d%d", &n, &q, &K);
        for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
        for(int i = 1;i <= q;i++) scanf("%d%d", &L[i], &R[i]), Ans[i] = 0;
        int t = sqrt(K);
        for(int i = 1;i <= t;i++) {
            qz1[0] = qz2[0] = 0;
            for(int j = 1;j <= n;j++) {
                qz1[j] = qz1[j - 1] + (a[j] <= i);
                qz2[j] = qz2[j - 1] + (a[j] > K / (i + 1));
            }
            for(int j = 1;j <= q;j++) {
                int tmp1 = qz1[R[j]] - qz1[L[j] - 1];
                int tmp2 = qz2[R[j]] - qz2[L[j] - 1];
                if(tmp1 + tmp2 == R[j] - L[j] + 1) Ans[j] = max(Ans[j], max(0, tmp2 - tmp1) / 2);
                else Ans[j] = max(Ans[j], (max(0, tmp2 - tmp1) + 1) / 2);
            }
        }
        for(int i = 1;i <= q;i++) printf("%d ", Ans[i]);
        printf("\n");
    }

    return 0;
}