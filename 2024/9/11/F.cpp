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
int T, n, a[maxn + 5], A[maxn + 5], m, b[maxn + 5], B[maxn + 5];

int tp = 0;
pair<int, int> st[2 * maxn + 5];

void mian() {
    read(n);
    For(i, 1, n) read(a[i]);
    For(i, 1, n) read(A[i]);
    read(m);
    For(i, 1, m) read(b[i]);
    For(i, 1, m) read(B[i]);
    int nn = 1, nm = 1;
    int tp = 0;
    while(nn <= n || nm <= m) {
        if(nn == n + 1) {
            st[++tp] = { b[nm], B[nm] };
            nm++;
        }
        else if(nm == m + 1) {
            st[++tp] = { a[nn], A[nn] };
            nn++;
        }
        else {
            if(A[nn] == B[nm]) {
                st[++tp] = { b[nm] + a[nn], A[nn] };
                nn++; nm++;
            }
            else if(A[nn] < B[nm]) {
                st[++tp] = { a[nn], A[nn] };
                nn++;
            }
            else {
                st[++tp] = { b[nm], B[nm] };
                nm++;

            }
        }
        // cout << nn << " " << nm << endl;
        // if(nn >= 10 || nm >= 10) break;
    }
    printf("%d\n", tp);
    For(i, 1, tp) cout << st[i].fir << " "; cout << endl;
    For(i, 1, tp) cout << st[i].sec << " "; cout << endl;
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
