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

#define maxn 2000000
int n, m, a[maxn + 5];

#define maxm 5000
int f[maxm + 5][maxm + 5];

int st[2][maxn + 5], tp[2];

int main() {
    // freopen("in.txt", "r", stdin);
    read(n); read(m);
    For(i, 1, n) read(a[i]);
    f[0][0] = 0;
    int now = 0;
    a[++n] = 0;
    For(i, 1, n) {
        if(a[i] == 0) {
            For(o, 0, 1) sort(st[o] + 1, st[o] + tp[o] + 1);
            int val = 0, p1 = 1, p2 = tp[1];
            while(st[1][p2] > now) p2--;
            val += p2;
            For(j, 0, now) {
                while(st[0][p1] <= j && p1 <= tp[0]) p1++, val++;
                while(p2 && st[1][p2] > now - j) p2--, val--;
                f[j][now - j] += val;
            }
            For(j, 0, now) {
                f[j + 1][now - j] = max(f[j + 1][now - j], f[j][now - j]);
                f[j][now - j + 1] = max(f[j][now - j + 1], f[j][now - j]);
            }
            tp[0] = tp[1] = 0;
            // if(i == 3) cout << f[0][1] << endl;
            now++;
        }
        else {
            int o = a[i] > 0;
            st[o][++tp[o]] = abs(a[i]);
        }
    }
    // For(i, 1, tp) cout << a[i] << " "; cout << endl;
    // For(i, 1, tp) cout << val[i] << " "; cout << endl;
    // cout << now << endl;
    // cout << f[3][0] << endl;
    int res = 0;
    For(i, 0, now) res = max(res, f[i][now - i]);
    printf("%d\n", res);
    return 0;
}
