#include<bits/stdc++.h>

using namespace std;

const int N = 1500;

int t;
int n;
int f[N];
int a[N][N];
set<int> r[N];
set<int> c[N];

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 1;i <= n;i++) {
            scanf("%d", &f[i]);
        }
        for(int i = 1;i <= n;i++) {
            for(int j = 0;j <= n;j++) {
                if(f[i] == j) {
                    continue;
                }
                r[i].insert(j);
                c[i].insert(j);
            }
        }
        for(int i = 1;i < n;i++) {
            for(int j = i + 1;j <= n;j++) {
                if(f[j] == v[i].back()) {
                    printf("%d %d %d\n", i, j, v[i].back());
                    v[i].pop_back();
                    while(b[j][v[i].back()]) {
                        printf("!%d\n", v[i].back());
                        v[i].pop_back();
                    }
                    printf("!\n");
                    a[i][j] = a[j][i] = v[i].back();
                    b[j][v[i].back()] = true;
                    v[i].pop_back();
                    v[i].push_back(f[j]);
                }
                else {
                    printf("%d %d %d\n", i, j, v[i].back());
                    a[i][j] = a[j][i] = v[i].back();
                    b[j][v[i].back()] = true;
                    v[i].pop_back();
                }
            }
        }
        for(int i = 1;i <= n;i++) {
            while(b[i][v[i].back()]) {
                v[i].pop_back();
            }
            a[i][i] = v[i].back();
        }
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= n;j++) {
                printf("%d ", a[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}