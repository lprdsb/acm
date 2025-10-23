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
int T, n, a[maxn + 5], b[maxn + 5];

void mian() {
    read(n);
    int x; read(x);
    For(i, 1, n) read(a[i]), b[i] = i;
    sort(b + 1, b + n + 1, [](int x, int y) {return a[x] < a[y];});
    int mx = x;
    For(i, -1, 1) if(x + i >= 1 && x + i <= n) {
        if(a[mx] < a[x + i]) mx = x + i;
    }
    int to = mx;
    For(i, 1, n) if(i != x && i != x + 1 && i != x - 1) {
        if(a[i] < a[to]) to = i;
    }
    swap(a[mx], a[to]);
    if(x != 1 && x != n) {
        mx = x;
        For(i, -1, 1) if(x + i >= 1 && x + i <= n) {
            if(a[mx] < a[x + i]) mx = x + i;
        }
        x = mx;
        printf("%d\n", a[x]);
    }
    else if(n == 1) {
        printf("%d\n", a[1]);
        return;
    }
    else {
        if(n == 2) b[3] = 2;
        int k = x;
        if(x == 1) k++;
        else k--;
        if(x == b[1] && k == b[2]) {
            printf("%d\n", a[b[3]]);
            return;
        }
        else if(x == b[2] && k == b[1]) {
            printf("%d\n", a[b[3]]);
            return;
        }
        else {
            printf("%d\n", max(a[x], a[k]));
            return;
        }
    }
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
