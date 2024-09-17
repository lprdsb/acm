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

#define maxn 100000
LL a[maxn + 5];
int f[maxn + 5], pre[maxn + 5];

int get_b(int idx) {
    return (__builtin_popcount(idx) & 1) - (__builtin_popcount(idx - 1) & 1) + 1;
}

int main() {
    //freopen("in", "r", stdin);
    a[0] = 0;
    For(i, 1, maxn) a[i] = a[i - 1] + i / 2;
    memset(f, inf, sizeof f); f[0] = 0;
    For(i, 0, maxn - 1) if(f[i] != inf) {
        For(j, 2, maxn) {
            if(i + a[j] <= maxn) {
                if(f[i + a[j]] > f[i] + j) {
                    pre[i + a[j]] = j;
                    f[i + a[j]] = f[i] + j;
                }
            }
            else break;
        }
    }
    // cout << "asd" << endl;
    int n, k; read(n); read(k);
    if(f[k] > n) puts("No");
    else {
        puts("Yes");
        int now = 1;
        while(k) {
            For(i, 1, pre[k]) cout << get_b(now) << " ";
            n -= pre[k];
            k -= a[pre[k]];
            now++;
        }
        while(n) cout << get_b(now++) << " ", n--;
    }
}
