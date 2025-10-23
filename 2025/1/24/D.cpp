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
int n, a[maxn + 5];
map<int, int> ma;

int main() {
    //freopen("in", "r", stdin);
    read(n);
    For(i, 1, n) read(a[i]), ma[a[i]]++;
    int cnt = 0;
    while(ma.size()) {
        auto tmp = *ma.begin();
        if(tmp.sec >= 2) ma[tmp.fir + 1] += tmp.sec / 2;
        cnt += ma[tmp.fir] & 1;
        ma.erase(tmp.fir);
    }
    if(cnt == 1) puts("1");
    else puts("2");
}
