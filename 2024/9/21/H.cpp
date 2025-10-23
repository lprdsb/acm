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

#define maxn 100000
int T, n, a[maxn + 5], num[maxn + 5], k;

void ins(int x) {
    if(!num[x]) k--;
    num[x]++;
}
void del(int x) {
    num[x]--;
    if(!num[x]) k++;
}

int as[maxn + 5];
void mian() {
    read(n); read(k);
    For(i, 1, n) read(a[i]);
    int now = 1;
    int mn = inf;
    For(i, 1, n) {
        while(now <= n && k) {
            ins(a[now]);
            now++;
        }
        if(!k) {
            as[i] = now - i;
            mn = min(mn, as[i]);
        }
        del(a[i]);
    }
    // cout << mn << endl;
    if(mn == inf) puts("N0");
    else {
        For(i, 1, n) if(as[i] == mn) {
            printf("%d %d\n", i, i + mn - 1);
            return;
        }
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    memset(as, inf, sizeof as);
    read(T);
    while(T--) {
        mian();
        For(i, 1, n) as[i] = inf;
    }
}
