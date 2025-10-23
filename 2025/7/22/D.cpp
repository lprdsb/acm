#include<bits/stdc++.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
using namespace std;

#define maxn 200000
int T, n, a, b[maxn + 5];

void mian() {
    scanf("%d%d", &n, &a);
    int res = 0;
    For(i, 1, n) {
        char c; cin >> c;
        b[i] = c - '0';
        res += b[i];
    }
    int fl = 0;
    int now = -1, cnt = 0;
    For(i, 1, n) {
        if(b[i] != now) {
            now = b[i];
            cnt = 1;
        }
        else cnt++;
        if(b[i] == 1 && cnt >= a) fl = 1;
        if(b[i] == 0 && cnt >= a + 1) fl = 1;
    }
    if(fl) printf("%d\n", n);
    else printf("%d\n", res);
}

int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%d", &T);
    while(T--) {
        mian();
    }
}