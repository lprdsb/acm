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

#define maxn 500000
int T, n, m;
LL a[maxn + 5], b[maxn + 5];
LL s[2];

void mian() {
    read(m); a[m] = b[m] = s[0] = s[1] = 0;
    For(i, 0, m - 1) read(a[i]), s[0] += a[i];
    For(i, 0, m - 1) read(b[i]), s[1] += b[i];
    if(s[0] > s[1]) b[0] += s[0] - s[1];
    else a[0] += s[1] - s[0];
    int fl = 0, now = 0, fl1 = 0;
    LL res = 0, ss = 0;
    Rof(i, m - 1, 0) {
        while(now + i < m - 1) {
            if(res) ss += b[now];
            now++;
        }
        int tmp = 0;
        while(now <= m - 1 && a[i]) {
            LL mn = min(a[i], b[now]);
            if(mn && now + i >= m) fl = 1;
            a[i] -= mn;
            b[now] -= mn;
            res += mn;
            if(mn && !tmp) {
                fl1++;
                tmp = 1;
            }
            if(!a[i]) {
                if(res == mn) {
                    if(now + i == m - 1) now++;
                }
                break;
            }
            if(res != mn) ss += b[now];
            now++;
        }
        if(a[i]) break;
    }
    while(now <= m - 1) ss += b[now], now++;
    if(fl) printf("%lld\n", res);
    else {
        if(ss) printf("%lld\n", res);
        else {
            if(fl1 >= 2 && res) printf("%lld\n", res - 1);
            else puts("0");
        }
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
