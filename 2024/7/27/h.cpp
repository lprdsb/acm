#include<bits/stdc++.h>

int t;
int w, l;

int gcd(int x, int y) {
    if(x < y)std::swap(x, y);
    if(y == 0)return x;
    return gcd(y, x % y);
}

std::set<int> s;

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &w, &l);
        s.clear();
        s.insert(1);
        s.insert(2);
        int g[3] = { gcd(w - 2,l),gcd(w - 1,l - 1),gcd(w,l - 2) };
        for(int i = 0;i <= 2;i++) {
            for(int j = 1;j * j <= g[i];j++) {
                if(g[i] % j == 0) {
                    s.insert(j);
                    s.insert(g[i] / j);
                }
            }
        }
        printf("%d ", s.size());
        for(auto i : s) {
            printf("%d ", i);
        }
        printf("\n");
    }
    return 0;
}