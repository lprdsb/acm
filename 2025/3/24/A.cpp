#include<bits/stdc++.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define Tra(u, i) for(int i = hd[u]; ~i; i = e[i].net)
#define cst const
#define LL long long
#define DD double
#define LD long double
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define inf 0x3f3f3f3f
#define Inf 0x3f3f3f3f3f3f3f3f
#define eps 1e-12
using namespace std;

template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

#define maxn 400000
int T, n, pri[maxn + 5], vis[maxn + 5], cnt = 0;

void mian() {
    read(n);
    if(n == 2) {
        puts("2 1");
        return;
    }
    if(n == 3) {
        puts("2 1 3");
        return;
    }
    int tmp = 1;
    For(i, 1, cnt) {
        if(2 * pri[i] <= n) tmp = pri[i];
        else break;
    }
    printf("%d ", tmp);
    For(i, 1, 2 * tmp - 1) if(i < 2 * tmp - i) printf("%d %d ", i, 2 * tmp - i);
    For(i, 2 * tmp, n) printf("%d ", i);
    puts("");
}

int main() {
    For(i, 2, maxn) {
        if(!vis[i]) pri[++cnt] = i;
        for(int j = 1; j <= cnt && i * pri[j] <= maxn; ++j) {
            vis[i * pri[j]] = 1;
            if(i % pri[j] == 0) break;
        }
    }
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
