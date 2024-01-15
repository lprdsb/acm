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

#define maxn 10000000
int T, n, m;
int tot = 0;
int ch[maxn + 5][2];
LL sum[maxn + 5];
char s[maxn + 5];

LL res = 0;
void dfs(int u) {
    For(o, 0, 1) if(ch[u][o]) dfs(ch[u][o]);
    res += min(sum[ch[u][0]], sum[ch[u][1]]);
}

void mian() {
    read(n); read(m);
    tot++;
    For(i, 1, n) {
        int now = 1, cnt;
        scanf("%s", s + 1); read(cnt);
        For(j, 1, m) {
            int o = s[j] - '0';
            if(!ch[now][o]) ch[now][o] = ++tot;
            now = ch[now][o];
            sum[now] += cnt;
        }
    }
    dfs(1);
    printf("%lld\n", res);
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        mian();
        res = 0;
        while(tot) ch[tot][0] = ch[tot][1] = sum[tot] = 0, tot--;
    }
}
