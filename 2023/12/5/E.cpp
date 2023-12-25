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
#define maxn 100000
using namespace std;

int T, n;
int num[maxn + 5][26], len[maxn + 5];
char s[50 * maxn + 5];

template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for (ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if (ch == '-') ok = 1;
    for (x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if (ok) x = -x;
}

int lim[50 * maxn + 5][26];
int bas[26], mx = 0;
void solve() {
    read(n);
    mx = 0;
    For(i, 1, n) {
        scanf("%s", s + 1); len[i] = strlen(s + 1);
        For(j, 1, len[i]) num[i][s[j] - 'a']++;
        mx = max(mx, len[i]);
    }
    Rof(i, n, 1) {
        For(o, 0, 25) {
            int pos = len[i] - 1;
            if (lim[pos][o] != -1 && lim[pos][o] != num[i][o]) {
                puts("NO");
                return;
            }
            lim[len[i] - 1][o] = num[i][o];
        }
        if (i >= 2) {
            For(j, len[i - 1], len[i] - 1) {
                int tem = j / len[i - 1], pos = j % len[i - 1];
                For(o, 0, 25) {
                    if (lim[j][o] != -1) {
                        lim[j][o] -= num[i - 1][o] * tem;
                        if (lim[j][o] < 0 || lim[j][o] > num[i - 1][o] || lim[j][o] > j % len[i - 1] + 1) {
                            puts("NO");
                            return;
                        }
                        if (lim[pos][o] != -1 && lim[pos][o] != lim[j][o]) {
                            puts("NO");
                            return;
                        }
                        lim[pos][o] = lim[j][o];
                        lim[j][o] = -1;
                    }
                    else break;
                }
            }
        }
    }
    vector<int> as;
    int now = -1;
    For(i, 0, len[1] - 1) {
        For(o, 0, 25) {
            if (lim[i][o] != -1) {
                if (i - now < lim[i][o] - bas[o]) {
                    puts("NO");
                    return;
                }
                if (i < now) {
                    puts("NO");
                    return;
                }
                For(j, 1, lim[i][o] - bas[o]) as.pb(o), now++;
                bas[o] = lim[i][o];
            }
            else break;
        }
    }
    puts("YES");
    for (auto c : as) putchar('a' + c); puts("");
    For(i, 2, n) {
        vector<int> asi;
        For(j, 0, len[i] - 1) asi.pb(as[j % as.size()]);
        for (auto c : asi) putchar('a' + c); puts("");
        swap(as, asi);
    }
}

int main() {
    //freopen("in.txt", "r", stdin);
    memset(lim, -1, sizeof lim);
    read(T);
    while (T--) {
        solve();
        For(i, 1, n) For(o, 0, 25) num[i][o] = 0;
        For(o, 0, 25) bas[o] = 0;
        For(i, 0, mx - 1) For(o, 0, 25) lim[i][o] = -1;
    }
    return 0;
}
