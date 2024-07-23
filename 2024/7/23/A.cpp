#include<bits/stdc++.h>

const int N = 5e5 + 10;

int n, l, r;
int h[N];
int a[N];

int main() {
    scanf("%d%d%d", &n, &l, &r);
    for(int i = 0;i < n;i++) {
        scanf("%d", &h[i]);
        a[(h[i] + 1) / 2]++;
    }
    int rst = n;
    bool f = false;
    
    return 0;
}