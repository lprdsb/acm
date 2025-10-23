#include<bits/stdc++.h>
using namespace std;


int T, x, y;

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &x, &y);
        if(x > y) swap(x, y);
        if(x == 1) {
            puts("-1");
        }
        else puts("1");
    }
}