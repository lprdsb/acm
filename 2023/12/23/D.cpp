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

#define maxn 200000
int T, n;
LL a[maxn + 5], k;

template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

LL gcd(LL x, LL y) {
    return y ? gcd(y, x % y) : x;
}

void sol() {
    read(n); read(k);
    For(i, 1, n) read(a[i]);
    int fl = 1;
    For(i, 1, n) fl &= a[i] == a[1];
    if(fl) {
        puts("0");
        return;
    }
    int fl1 = 0, fl2 = 0;
    For(i, 1, n) {
        fl1 |= a[i] > k;
        fl2 |= a[i] < k;
        if(a[i] == k) {
            puts("-1");
            return;
        }
    }
    if(fl1 && fl2) {
        puts("-1");
        return;
    }
    LL gc = 0;
    // cout << "asd" << endl;
    For(i, 1, n) {
        gc = gcd(gc, abs(a[i] - k));
    }
    LL res = 0;
    For(i, 1, n) res += abs(a[i] - k) / gc - 1;
    printf("%lld\n", res);
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        sol();
    }
}
