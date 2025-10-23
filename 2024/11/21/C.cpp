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
int n, a[2 * maxn + 5], f[2 * maxn + 5];
char s[maxn + 5];

vector<int> vec[maxn + 5];

int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%s", s + 1); n = strlen(s + 1);
    For(i, 1, n) a[2 * i] = s[i] - 'a' + 1;
    int now = 0;
    For(i, 1, 2 * n + 1) {
        int k = 0;
        if(now + f[now] - 1 >= i) {
            if(i + f[2 * now - i] - 1 <= now + f[now] - 1) k = f[2 * now - i];
            else k = now + f[now] - 1 - i + 1;
        }
        while(i - k > 0 && i + k <= 2 * n + 1 && a[i + k] == a[i - k]) k++;
        f[i] = k;
        if(i + k - 1 > now + f[now] - 1) now = i;
    }
    For(i, 1, 2 * n + 1) if(f[i] >= 2) {
        // int l = (i - f[i] + 2) / 2, r = (i + f[i] - 2) / 2;
        // if(r - l > 2) r = l + (r - l) % 2 + 2;
        // vec[l].pb(r);
        if(i & 1) vec[(i - 1) / 2].pb((i + 1) / 2);
        else if(f[i] >= 3) vec[(i - 2) / 2].pb((i + 2) / 2);
    }
    int mn[2] = { n + 1, n + 1 };
    LL res = 0;
    Rof(i, n, 1) {
        for(auto v : vec[i]) if(v - i + 1 >= 2) {
            // cout << i << " " << v << endl;
            For(o, 0, 1) if(v < mn[o]) swap(v, mn[o]);
        }
        // cout << i << " " << mn[0] << " " << mn[1] << endl;
        res += mn[1] - mn[0];
    }
    printf("%lld\n", res);
}
