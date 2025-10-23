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
int T, n, q, a[maxn + 5], sum[maxn + 5], p[maxn + 5];

int get_val(int x) {
    return sum[x] * (a[x] && !a[x - 1]);
}

void mian() {
    read(n); read(q);
    For(i, 1, n) read(p[i]);
    For(i, 1, n) {
        char c; cin >> c;
        a[i] = c == 'R';
    }
    For(i, 1, n) {
        if(p[i] < i) {
            sum[p[i] + 1]++;
            sum[i + 1]--;
        }
        else {
            sum[i + 1]++;
            sum[p[i] + 1]--;
        }
    }
    For(i, 1, n) sum[i] += sum[i - 1];
    int cnt = 0;
    For(i, 2, n) if(a[i] && !a[i - 1]) cnt += sum[i];
    while(q--) {
        int x; read(x);
        if(x > 1) cnt -= get_val(x);
        if(x < n) cnt -= get_val(x + 1);
        a[x] ^= 1;
        if(x > 1) cnt += get_val(x);
        if(x < n) cnt += get_val(x + 1);
        puts(cnt ? "NO" : "YES");
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
        For(i, 0, n + 1) sum[i] = 0;
    }
}
