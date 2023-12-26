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

#define maxn 100000
int n;
int a[maxn + 5];
#define U unsigned
U LL val[maxn + 5], ok[maxn + 5], vali[2 * maxn + 5];

template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

U LL get_val(int pos) {
    if(pos <= -63) return 0;
    if(pos <= 0) return vali[1] << (1 - pos);
    int tem = (pos - 1) & 63;
    if(!tem) return vali[pos];
    return (vali[pos - tem] >> tem) | (vali[pos - tem + 64] << (64 - tem));
}

int st[maxn + 5];
int main() {
    // U LL tem = 2;
    // cout << (tem << 65) << endl;
    // freopen("in.txt", "r", stdin);
    read(n);
    For(i, 1, n) {
        char c; cin >> c;
        if(c == '0') a[i] = 0;
        else if(c == '1') a[i] = 1;
        else a[i] = 2;
    }
    Rof(i, n, 1) {
        val[i] = val[i + 1] << 1;
        ok[i] = ok[i + 1] << 1;
        if(a[i] == 1) val[i] |= 1;
        if(a[i] == 2) ok[i] |= 1;
    }
    For(i, 1, n) {
        int res = 0;
        if(i <= 64) {
            For(j, 1, min(i, n)) {
                st[j] = a[j] == 1;
                res += st[j];
            }
            For(j, i + 1, n) {
                if(a[j] == 2) st[j] = st[j - i];
                else st[j] = a[j];
                res += st[j];
            }
        }
        else {
            for(int j = 1; j <= n; j += 64) {
                vali[j] = val[j] | (ok[j] & get_val(j - i));
                res += __builtin_popcountll(vali[j]);
            }
        }
        printf("%d\n", res);
    }
}