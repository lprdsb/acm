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
int T, n, a[maxn + 5], l[maxn + 5], r[maxn + 5];

void mian() {
    read(n);
    For(i, 1, n) {
        char c; cin >> c;
        if(c == '_') a[i] = -1;
        else a[i] = c == '(' ? 0 : 1;
    }
    l[n + 1] = r[n + 1] = 0;
    Rof(i, n, 1) {
        if(a[i] == 0) l[i] = l[i + 1] + 1, r[i] = min(0, r[i + 1] + 1);
        else if(a[i] == 1) l[i] = l[i + 1] - 1, r[i] = r[i + 1] - 1;
        else {
            l[i] = l[i + 1] - 1;
            r[i] = min(0, r[i + 1] + 1);
        }
    }
    LL res = 0;
    int now = 0;
    // cout << l[4] << " " << r[4] << endl;
    For(i, 1, n) {
        if(a[i] == 0) res -= i, now++;
        else if(a[i] == 1) res += i, now--;
        else {
            if(now - 1 + l[i + 1] <= 0 && now - 1 + r[i + 1] >= 0) res += i, now--;
            else res -= i, now++;
        }
        // cout << res << endl;
    }
    cout << res << endl;
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
