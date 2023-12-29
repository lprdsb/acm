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

#define maxn 600
#define mod 1000000007

struct Tree {
    int tot, ch[maxn + 5][26], cnt[maxn + 5], fa[maxn + 5], to[maxn + 5];
    Tree() { tot = 1; }
    void ins(char *s) {
        int len = strlen(s + 1);
        int now = 1;
        For(i, 1, len) {
            int o = s[i] - 'a';
            if(!ch[now][o]) {
                tot++;
                fa[ch[now][o] = tot] = now;
                to[tot] = o;
            }
            now = ch[now][o];
        }
        cnt[now]++;
    }
} tr[2];

int n, m, ok[maxn + 5][maxn + 5], f[2][maxn + 5][maxn + 5];
char s[maxn + 5];
int main() {
    // freopen("in.txt", "r", stdin);
    read(n); read(m);
    For(i, 1, n) {
        scanf("%s", s + 1);
        tr[0].ins(s);
        int len = strlen(s + 1);
        For(j, 1, len) if(j < len - j + 1) swap(s[j], s[len - j + 1]);
        tr[1].ins(s);
    }
    For(i, 1, tr[0].tot) For(j, 1, tr[1].tot) if(!((m & 1) && (tr[0].to[i] != tr[1].to[j]))) {
        int now1 = i, now2 = j;
        if(m & 1) now1 = tr[0].fa[now1];
        int fl = 1;
        while(now2 != 1) {
            now1 = tr[0].ch[now1][tr[1].to[now2]];
            now2 = tr[1].fa[now2];
            if(!now1) {
                fl = 0;
                break;
            }
        }
        if(fl) ok[i][j] += tr[0].cnt[now1];
    }
    int o1 = 0, res = 0;
    f[0][1][1] = 1;
    For(i, 0, ((m + 1) >> 1) - 1) {
        For(i, 1, tr[0].tot) For(j, 1, tr[1].tot) if(f[o1][i][j]) For(o2, 0, 25) {
            int t1 = tr[0].ch[i][o2], t2 = tr[1].ch[j][o2];
            if(t1 && t2) {
                f[o1 ^ 1][1][1] = (f[o1 ^ 1][1][1] + 1ll * tr[0].cnt[t1] * tr[1].cnt[t2] % mod * f[o1][i][j] % mod) % mod;
                f[o1 ^ 1][1][t2] = (f[o1 ^ 1][1][t2] + 1ll * tr[0].cnt[t1] * f[o1][i][j] % mod) % mod;
                f[o1 ^ 1][t1][1] = (f[o1 ^ 1][t1][1] + 1ll * tr[1].cnt[t2] * f[o1][i][j] % mod) % mod;
                f[o1 ^ 1][t1][t2] = (1ll * f[o1 ^ 1][t1][t2] + f[o1][i][j]) % mod;
            }
        }
        For(i, 1, tr[0].tot) For(j, 1, tr[1].tot) f[o1][i][j] = 0;
        o1 ^= 1;
    }
    // cout << ok[1][1] << endl;
    ok[1][1] = !(m & 1);
    For(i, 1, tr[0].tot) For(j, 1, tr[1].tot) if((i == 1 && j == 1) || (i != 1 && j != 1))
        res = (res + 1ll * ok[i][j] * f[o1][i][j] % mod) % mod;
    printf("%d\n", res);
    return 0;
}
