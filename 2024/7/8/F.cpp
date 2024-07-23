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
int T, n, a[maxn + 5];
LL k;
int ch[35 * maxn][2], tot = 0, mx[35 * maxn + 5];

LL chk(LL x) {
    tot = 1;
    LL res = 0;
    int mmx = 0;
    For(i, 1, n) {
        int now = 1, now1 = 1;
        Rof(o, 30, 0) {
            int to = ((a[i] >> o) & 1) ^ ((x >> o) & 1);
            if(now1) {
                if((x >> o) & 1) mmx = max(mmx, mx[ch[now1][!to]]);
                now1 = ch[now1][to];
                if(o == 0 && now1) mmx = max(mmx, mx[now1]);
            }
            to = (a[i] >> o) & 1;
            if(!ch[now][to]) ch[now][to] = ++tot;
            now = ch[now][to];
            mx[now] = i;
        }
        res += mmx;
    }
    while(tot) {
        mx[tot] = 0;
        ch[tot][0] = ch[tot][1] = 0;
        tot--;
    }
    return res;
}

void mian() {
    read(n); read(k);
    For(i, 1, n) read(a[i]);
    LL l = 0, r = 10 * inf;
    while(l < r) {
        LL md = l + r >> 1;
        if(chk(md) >= k) r = md;
        else l = md + 1;
    }
    printf("%lld\n", l);
    // cout << chk(0) << endl;
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
