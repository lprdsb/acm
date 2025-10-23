#include<bits/stdc++.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
using namespace std;


#define maxn 5000000
int n, a[maxn + 5], b[maxn + 5], T, pri[maxn + 5], vis[maxn + 5], cnt = 0, to[maxn + 5];

vector<int> vec;
void mian() {
    scanf("%d", &n);
    vec.resize(0);
    For(i, 1, n) {
        scanf("%d", &a[i]);
        int x = a[i];
        while(x != 1) {
            vec.push_back(to[x]);
            b[to[x]] ^= 1;
            x /= to[x];
        }
    }
    int fl = 0;
    for(auto d : vec) {
        if(b[d]) fl = 1;
        b[d] = 0;
    }
    if(n == 2) {
        if(a[1] == a[2]) puts("YES");
        else puts("NO");
        return;
    }
    if(fl && n % 2 == 0) puts("NO");
    else puts("YES");
}

int main() {
    // freopen("in.txt", "r", stdin);
    For(i, 2, maxn) {
        if(!vis[i]) pri[++cnt] = i, to[i] = i;
        for(int j = 1; j <= cnt && i * pri[j] <= maxn; ++j) {
            vis[i * pri[j]] = 1;
            to[i * pri[j]] = pri[j];
            if(i % pri[j] == 0) break;
        }
    }
    scanf("%d", &T);
    while(T--) {
        mian();
    }
}