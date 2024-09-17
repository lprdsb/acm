#include<bits/stdc++.h>
#define fs(i,x,y) for(int i=(x),_=(y);i<=_;++i)
#define fn(i,x,y) for(int i=(x),_=(y);i>=_;--i)
using namespace std;

const int N = 1e5 + 7, M = 1e5;
int n;
int a[N];
bool vis[N];

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

void solve() {
    scanf("%d", &n);
    fs(i, 1, M)vis[i] = false;
    fs(i, 1, n)scanf("%d", &a[i]), vis[a[i]] = true;
    int cnt = 0;
    fs(i, 1, M) {
        if(!vis[i]) {
            int now = 0;
            for(int j = i;j <= M;j += i) {
                if(vis[j]) {
                    now = gcd(now, j / i);
                }
            }
            if(now == 1)++cnt;
        }
    }
    if(cnt & 1)printf("dXqwq\n");
    else printf("Haitang\n");
}

signed main() {
    int T;scanf("%d", &T);
    while(T--) {
        solve();
    }
}
