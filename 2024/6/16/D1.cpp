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
int T, n, m;
LL a[maxn + 5], sum[maxn + 5];

void mian() {
    read(n); read(m);
    For(i, 1, n) read(a[i]); a[1] += m;
    int mx = 0;
    For(i, 1, n) if(a[i] > a[mx]) mx = i;
    For(i, 1, n) sum[i] = sum[i - 1] + a[i];
    For(i, 1, n) {
        if(i != mx) {
            if(sum[i] >= a[mx]) printf("%d ", i - 1);
            else printf("%d ", i);
        }
        else printf("0 ");
    }
    puts("");
    return;
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}