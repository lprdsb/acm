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

#define maxn 1000000
int T, n, sum[maxn + 5];
char s[maxn + 5];

int pre[2 * maxn + 5], cnt[2 * maxn + 5];
void mian() {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    For(i, 1, n) sum[i] = sum[i - 1] + (s[i] == '(' ? 1 : -1);
    if(abs(sum[n]) % 2 != 0) {
        puts("0");
        return;
    }
    int tem = sum[n] / 2;
    LL res = 0;
    For(i, -n, 3 * n) {
        pre[maxn + i] = n + 1;
        cnt[maxn + i] = 0;
    }
    Rof(i, n, 0) {
        // if(i == 1) cout << pre[maxn + 2] << endl;
        if(pre[maxn + sum[i] + tem] >= pre[maxn + 2 * sum[i] + 1]) cnt[maxn + sum[i] + tem] = 0;
        if(sum[i] >= 0) res += cnt[maxn + sum[i] + tem];
        cnt[maxn + sum[i]]++;
        pre[maxn + sum[i]] = i;
    }
    printf("%lld\n", res);
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
