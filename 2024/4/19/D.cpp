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

#define maxn 20
int n, a[maxn + 5];
vector<pair<int, int> > as;
void opt(int l, int r) {
    set<int> se;
    For(i, 0, r - l + 1) se.insert(i);
    For(i, l, r) se.erase(a[i]);
    For(i, l, r) a[i] = *se.begin();
    as.pb({ l, r });
}
void sol(int l, int r) {
    if(l == r) {
        while(a[l] != 1) opt(l, l);
        return;
    }
    For(i, l, r - 1) sol(i, r - 1);
    if(a[r]) opt(r, r);
    opt(l, r);
}

int main() {
    //freopen("in", "r", stdin);
    read(n);
    For(i, 1, n) read(a[i]);
    int mx[2] = { 0, 0 };
    For(mask, 0, (1 << n) - 1) {
        int sum = 0, now = 0;
        For(o, 0, n - 1) {
            if((mask >> o) & 1) sum += a[o + 1] + now * now, now = 0;
            else now++;
        }
        sum += now * now;
        if(sum > mx[0]) mx[0] = sum, mx[1] = mask;
    }
    printf("%d ", mx[0]);
    int now = 0;
    For(o, 0, n - 1) {
        if((mx[1] >> o) & 1) {
            if(now) sol(o + 1 - now, o);
            now = 0;
        }
        else now++;
    }
    if(now) sol(n - now + 1, n);
    printf("%d\n", as.size());
    for(auto [l, r] : as) printf("%d %d\n", l, r);
    return 0;
}
