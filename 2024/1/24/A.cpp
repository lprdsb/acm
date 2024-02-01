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

#define maxn 200000
int T, n, m;
char s[maxn + 5];
vector<int> num[5];

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        read(n);
        int sum = 0;
        For(i, 1, n) {
            int cnt[5] = { 0, 0, 0, 0, 0 };
            scanf("%s", s + 1); m = strlen(s + 1);
            For(j, 1, m) cnt[s[j] - 'a']++;
            For(o, 0, 4) num[o].pb(2 * cnt[o] - m);
        }
        int res = 0;
        For(o, 0, 4) {
            sort(num[o].begin(), num[o].end());
            reverse(num[o].begin(), num[o].end());
            int now = 0, cnt = 0;
            for(auto i : num[o]) {
                now += i;
                cnt++;
                if(now > 0) res = max(res, cnt);
            }
            num[o].resize(0);
        }
        printf("%d\n", res);
    }
    return 0;
}
