#include<bits/stdc++.h>

const int N = 5e3 + 10;
int n;
int a[N];
int f[N][N];
int mn[N][N];
int mx[N][N];

int main() {
    scanf("%d", &n);
    for(int i = 0;i < n;i++) {
        scanf("%d", &a[i]);
        mn[i][i] = a[i];
        mx[i][i] = a[i];
    }
    
    return 0;
}