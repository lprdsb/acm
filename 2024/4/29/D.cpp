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
int T, n, k;
pair<int, int> pa[maxn + 5];

void mian() {
    read(n); read(k);
    For(i, 1, n) read(pa[i].sec);
    For(i, 1, n) read(pa[i].fir);
    sort(pa + 1, pa + n + 1);
    LL res = 0, sum = 0;
    For(i, 1, n) if(pa[i].sec < pa[i].fir) sum += pa[i].fir - pa[i].sec;
    priority_queue<int> q;
    Rof(i, n, 1) {
        if(q.size() == k) res = max(res, sum);
        if(pa[i].sec < pa[i].fir) sum -= pa[i].fir - pa[i].sec;
        q.push(pa[i].sec); sum -= pa[i].sec;
        if(q.size() > k) sum += q.top(), q.pop();
    }
    if(q.size() == k) res = max(res, sum);
    printf("%lld\n", res);
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
