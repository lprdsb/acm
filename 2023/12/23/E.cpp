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
template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

int n, m, num[maxn + 5];
int ma[25], sta[25];

bool chk(int mask) {
    int fl = 1;
    For(o, 0, n - 1) if((mask >> o) & 1) {
        if((~mask) & ma[o + 1]) {
            fl = 0;
            break;
        }
    }
    if(fl) {
        For(i, 1, n) num[i] = 0;
        int s = 0;
        For(i, 1, n) if((mask >> (i - 1)) & 1) s ^= sta[i];
        int tot = __builtin_popcount(s & ((1 << n) - 1));
        if(tot <= n / 5) {
            // cout << mask << endl;
            int tem = 0;
            For(i, 0, n - 1) tem += (mask >> i) & 1;
            printf("%d\n", tem);
            For(i, 0, n - 1) if((mask >> i) & 1) printf("%d ", i + 1);
            puts("");
            return 1;
        }
    }
    return 0;
}

int get_mask(int s) {
    int res = 0, ss = 0;
    For(i, 1, n) if(((ss ^ s) >> (i - 1)) & 1) ss ^= sta[i], res |= 1 << (i - 1);
    return res;
}

void sol() {
    For(i, 1, n) {
        if(chk(get_mask(1 << (i - 1)))) return;
    }
    For(i, 1, n) For(j, i + 1, n) {
        if(chk(get_mask((1 << (i - 1)) | (1 << (j - 1))))) return;
    }
    For(i, 1, n) For(j, i + 1, n) For(p, j + 1, n) {
        if(chk(get_mask((1 << (i - 1)) | (1 << (j - 1)) | (1 << (p - 1))))) return;
    }
    puts("-1");
}

int main() {
    // freopen("in.txt", "r", stdin);
    For(i, 1, 20) for(int j = i; j <= 20; j += i) sta[i] |= (1 << (j - 1));
    int T; read(T);
    while(T--) {
        read(n); read(m);
        For(i, 1, m) {
            int u, v; read(u); read(v);
            if(n <= 20) ma[u] |= 1 << (v - 1);
        }
        if(n >= 20) {
            printf("%d\n", n);
            For(i, 1, n) printf("%d ", i);
            puts("");
        }
        else {
            sol();
        }
        if(n <= 20) {
            For(i, 1, n) ma[i] = 0;
        }
    }
}
