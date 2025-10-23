#include<bits/stdc++.h>
using namespace std;
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)


#define maxn 200000
int T, n, a[maxn + 5];

int chk(int x) {
    int now = 0;
    For(i, 1, n) {
        if(now > a[i]) return 0;
        now = max(now, a[i] - x);
    }
    return 1;
}

void mian() {
    scanf("%d", &n);
    int mx = 0;
    For(i, 1, n) scanf("%d", &a[i]), mx = max(mx, a[i]);
    int l = 0, r = mx;
    while(l < r) {
        int md = l + r >> 1;
        if(chk(md)) r = md;
        else l = md + 1;
    }
    printf("%d\n", l);
}

int main() {
    scanf("%d", &T);
    while(T--) {
        mian();
    }
}