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
int n, a[maxn + 5], s[maxn + 5];

int main() {
    //freopen("in", "r", stdin);
    read(n);
    For(i, 1, n) read(a[i]);
    For(i, 1, n) s[i] = s[i - 1] + a[i];
    // For(i, 1, n) {
    //     For(j, 1, n) {
    //         if(j >= i) cout << (s[j] - s[i - 1] > 20) << " ";
    //         else cout << -1 << " ";
    //     } cout << endl;
    // }
    int q; read(q);
    while(q--) {
        int S; read(S);
        int l = 1, r = n;
        while(l < r) {
            int md = l + r >> 1;
            if(s[n - md] - s[md] <= S) r = md;
            else l = md + 1;
        }
        r = n - l + 1;
        int l1 = l - 1, r1 = r;
        while(l1 < r1) {
            int md = l1 + r1 >> 1;
            if(s[md] - s[l - 1] > S) r1 = md;
            else l1 = md + 1;
        }
        int l2 = l, r2 = r + 1;
        while(l2 < r2) {
            int md = l2 + r2 >> 1;
            if(s[r] - s[md - 1] <= S) r2 = md;
            else l2 = md + 1;
        }
        l2--;
        // cout << l << " " << r << " " << l1 << " " << l2 << endl;
        if(!((r - l1) & 1) && !((l2 - l) & 1)) puts("Bob");
        else puts("Alice");
    }
}
