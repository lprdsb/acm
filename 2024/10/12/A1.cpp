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

#define maxn 10000
int T, n;
LL A, a[maxn + 5], b[maxn + 5];

void mian() {
    read(n); read(A);
    For(i, 1, n) read(a[i]);
    For(i, 1, n) read(b[i]);
    For(i, 1, n) {
        LL sum = 0, fl = 0;
        if(a[i] > b[i]) swap(a[i], b[i]);
        if(A >= b[i]) {
            sum += b[i];
            fl = 1;
        }
        if(A >= a[i]) {
            if(a[i] >= 0) sum += a[i], fl = 1;
            else if(!fl) sum += a[i];
        }
        else {
            printf("%d\n", i - 1);
            return;
        }
        A += sum;
    }
    printf("%d\n", n);

}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
