#include<bits/stdc++.h>
using namespace  std;
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)

int T;


#define maxn 100000
int n, a[maxn + 5], s[maxn + 5], s1[maxn + 5], b[maxn + 5];
vector<int> d[maxn + 5];

int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }

void mian() {
    scanf("%d", &n);
    For(i, 1, n) scanf("%d", &b[i]);
    int fl = 1;
    For(i, 2, n) if(b[i] != b[1]) {
        fl = 0;
        break;
    }
    if(fl) {
        puts("0");
        return;
    }
    if(n == 2) {
        int res = max(b[1], b[2]);
        printf("%d\n", max(res, abs(b[1] - b[2])));
        return;
    }
    vector<int> D;
    For(i, 1, n) a[i] = abs(b[i] - b[i - 1]);
    for(auto i : d[b[1]]) D.push_back(i);
    for(auto i : d[b[n]]) D.push_back(i);
    int res = 1;
    for(auto i : D) {
        int cnt = 0;
        For(j, 1, n) cnt += a[j] % i == 0;
        if(cnt >= n - 1) res = max(res, i);
        else if(cnt == n - 2 && b[n] % i == 0) res = max(res, i);
    }
    int gc = 0;
    For(i, 2, n) gc = gcd(gc, a[i]);
    printf("%d\n", max(res, gc));
}

int main() {
    For(i, 1, maxn) for(int j = i; j <= maxn; j += i) d[j].push_back(i);
    // freopen("in.txt", "r", stdin);
    scanf("%d", &T);
    while(T--) {
        mian();
    }
}