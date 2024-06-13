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

#define maxn 1000
int T, n, a[maxn + 5], b[maxn + 5];
vector<pair<int, int> > as;

int pos;
void opt1() {
    as.pb({ 3, 1 });
    pos = (pos + 1) % n + 1;
}
int rev[2];
void opt2() {
    as.pb({ 1, 2 });
    if(pos > 1) rev[(pos - 1) % 2] -= a[pos - 1] > a[pos];
    rev[pos % 2] -= a[pos] > a[pos + 1];
    if(pos + 1 < n) rev[(pos + 1) % 2] -= a[pos + 1] > a[pos + 2];
    swap(a[pos], a[pos + 1]);
    if(pos > 1) rev[(pos - 1) % 2] += a[pos - 1] > a[pos];
    rev[pos % 2] += a[pos] > a[pos + 1];
    if(pos + 1 < n) rev[(pos + 1) % 2] += a[pos + 1] > a[pos + 2];
    pos = (pos - 2 + n) % n + 1;
}

void mian() {
    read(n);
    For(i, 1, n) read(a[i]), b[i] = a[i];
    int fl = 0;
    For(i, 1, n) if(a[i] != i) {
        fl = 1;
        break;
    }
    if(!fl) {
        printf("%d\n0\n", n);
        return;
    }
    fl = 0;
    For(i, 1, n) if((a[i] - a[1] + n) % n != i - 1) {
        fl = 1;
        break;
    }
    if(!fl) {
        printf("%d\n%d\n", n - 1, a[n] % n);
        For(i, 1, a[n] % n) puts("1 2");
        return;
    }
    rev[0] = rev[1] = 0;
    For(i, 1, n) For(j, i + 1, n) rev[0] += (a[i] > a[j]);
    if(n % 2 == 0 && rev[0] % 2 != 0) {
        printf("%d\n", n - 3);
        if(a[1] == n || a[2] == n) {
            as.pb({ 1, 4 });
            int tem[3] = { a[n - 2], a[n - 1], a[n] };
            Rof(i, n, 4) a[i] = a[i - 3];
            a[1] = tem[0]; a[2] = tem[1]; a[3] = tem[2];
        }
        while(a[n] != n) {
            as.pb({ 3, 4 });
            int tem = a[n];
            Rof(i, n, 4) a[i] = a[i - 1];
            a[3] = tem;
        }
        n--;
    }
    else printf("%d\n", n - 2);
    rev[0] = rev[1] = 0;
    For(i, 1, n - 1) rev[i % 2] += a[i] > a[i + 1];
    pos = n - 1;
    while(rev[0] + rev[1]) {
        if(pos == n) opt1();
        else {
            if(a[pos] > a[pos + 1]) opt2();
            else {
                if(n % 2 == 1) opt1();
                else {
                    if(pos == n - 1 && !rev[1]) opt2();
                    else if(pos == n - 2 && !rev[0]) opt2();
                    else opt1();
                }
            }
        }
    }
    while(pos != n - 1) opt1();
    printf("%d\n", as.size());
    for(auto [i, j] : as) printf("%d %d\n", i, j);
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        mian();
        as.resize(0);
    }
}
