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

#define maxn 300000
#define maxm 10000000

int pri[maxm + 5], vis[maxm + 5], id[maxm + 5], cnt = 0, sg[maxm + 5];

int T, n, a[maxn + 5];

void mian() {
    read(n);
    For(i, 1, n) read(a[i]);
    int sum = 0;
    For(i, 1, n) sum ^= sg[a[i]];
    puts(sum ? "Alice" : "Bob");
}

int main() {
    // freopen("in.txt", "r", stdin);
    For(i, 2, maxm) {
        if(!vis[i]) pri[++cnt] = i, id[i] = cnt;
        for(int j = 1; j <= cnt && i * pri[j] <= maxm; ++j) {
            vis[i * pri[j]] = 1;
            id[i * pri[j]] = id[pri[j]];
            if(i % pri[j] == 0) break;
        }
    }
    For(i, 1, maxm) sg[i] = (i % 2 == 0) ? 0 : id[i];
    // For(i, 1, 10) cout << sg[i] << " "; cout << endl;
    sg[1] = 1;
    read(T);
    while(T--) {
        mian();
    }
}
