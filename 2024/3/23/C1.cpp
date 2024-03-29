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
int n, x, bas = maxn, a[maxn + 5];
bitset<2 * maxn + 5> f[3];

int main() {
    //freopen("in", "r", stdin);
    int T; read(T);
    while(T--) {
        read(n); read(x);
        int sum = 0, now = 0, cnt0 = 0, cnt1 = 0;
        For(i, 1, n) {
            read(a[i]);
            sum += a[i];
        }
        a[n + 1] = 0;
        For(i, 1, n + 1) {
            if(a[i] == a[i - 1]) now++;
            else {
                if(a[i - 1] == -1) cnt0 += (now + 1) >> 1;
                else cnt1 += (now + 1) >> 1;
                now = 1;
            }
        }
        if(x == sum) puts("Yes");
        else if(x < sum) puts(cnt1 >= sum - x ? "Yes" : "No");
        else puts(cnt0 >= x - sum ? "Yes" : "No");
    }
    return 0;
}
