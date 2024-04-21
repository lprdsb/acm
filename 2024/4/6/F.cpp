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
int T, a[maxn + 5], n;
LL k;

int tr[maxn + 5];
void ins(int x, int y) {
    while(x <= n) tr[x] += y, x += x & -x;
}
int que(int x) {
    int res = 0;
    while(x) res += tr[x], x -= x & -x;
    return res;
}

int b[maxn + 5], c[maxn + 5], as[maxn + 5];
void mian() {
    read(n); read(k);
    For(i, 1, n) tr[i] = 0;
    For(i, 1, n) read(a[i]);
    LL sum = 0;
    Rof(i, n, 1) {
        sum += b[i] = que(a[i]);
        b[i] = (n - i) - b[i];
        ins(a[i], 1);
    }
    // cout << 1ll * n * (n - 1) - sum << endl;
    For(i, 1, n) c[i] = 0;
    if(sum % 2 == k % 2 && k <= 1ll * n * (n - 1) - sum && k >= sum) {
        puts("YES");
        k -= sum;
        k /= 2;
        int now = n;
        For(i, 1, n) {
            if(k > b[i]) {
                k -= b[i];
                c[i] = now--;
            }
            else {
                For(j, i, n) c[j] = j - i + 1;
                For(j, i + 1, n) {
                    if(a[j] > a[i]) {
                        k--;
                        if(k == 0) {
                            int tem = c[j];
                            Rof(p, j, i + 1) c[p] = c[p - 1];
                            c[i] = tem;
                            break;
                        }
                    }
                }
                break;
            }
            // cout << k << endl;

        }
        // For(i, 1, n) cout << c[i] << " "; cout << endl;
        For(i, 1, n) as[a[i]] = c[i];
        For(i, 1, n) printf("%d ", as[i]); puts("");
        return;
    }
    puts("NO");
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}

