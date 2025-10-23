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

#define maxn 5000
int T, n, a[maxn + 5], sum[maxn + 5];

void mian() {
    read(n);
    For(i, 1, n) read(a[i]);
    For(i, 1, n) sum[i] = 0;
    int res = 0;
    For(i, 1, n) For(j, i + 1, n) {
        if(a[i] < a[j]) {
            sum[i]++;
        }
        else {
            res++;
            sum[j]--;
        }
    }
    For(i, 1, n) if(sum[i] < 0) res += sum[i];
    cout << res << endl;
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
