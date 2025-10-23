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
int T, n, a[maxn + 5], b[maxn + 5];

void mian() {
    read(n);
    int L = 1, R = n;
    For(i, 1, n) {
        read(a[i]);
        int l = max(1, i - a[i] + 1), r = min(n, i + a[i] - 1);
        L = max(L, l);
        R = min(R, r);
    }
    if(L > R) puts("0");
    else {
        // cout << "asd" << endl;
        For(i, 0, L - 1) b[i] = i;
        For(i, R + 1, n + 1) b[i] = i;
        For(i, 1, L - 1) {
            int l = max(1, i - a[i] + 1), r = min(n, i + a[i] - 1);
            b[r + 1] = min(b[r + 1], i);
        }
        For(i, R + 1, n) {
            int l = max(1, i - a[i] + 1), r = min(n, i + a[i] - 1);
            b[l - 1] = max(b[l - 1], i);
        }
        int res = R - L + 1;
        while(L != 1 && R != n) {
            // cout << L << " " << R << " " << b[R + 1] << endl;
            if(b[L - 1] <= R) L--;
            else if(b[R + 1] >= L) R++;
            else break;
        }
        if(L != 1 && R != n) puts("0");
        else printf("%d\n", res);
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
