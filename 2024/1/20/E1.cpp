#include<bits/stdc++.h>
#define For(i, a, b) for(LL i = (a), en = (b); i <= en; ++i)
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

LL x;
vector<pair<int, LL> > vec;
vector<LL> a[50];

int main() {
    //freopen("in", "r", stdin);
    read(x);
    if(x == 1) {
        puts("-1");
        return 0;
    }
    For(_, 2, x) {
        if(_ * _ > x) break;
        if(x % _ == 0) {
            int cnt = 0;
            while(x % _ == 0) cnt++, x /= _;
            vec.pb({ cnt, _ });
        }
    }
    if(x != 1) vec.pb({ 1, x });
    sort(vec.begin(), vec.end());
    reverse(vec.begin(), vec.end());
    int sum = 0;
    For(i, 1, vec.size() - 1) sum += vec[i].fir;
    if(sum < vec[0].fir - 1) puts("-1");
    else {
        int now = 0;
        For(i, 1, vec.size() - 1) {
            LL t1 = vec[i].fir, t2 = vec[i].sec;
            while(t1--) {
                a[now].pb(t2);
                now = now + 1;
                if(now == vec[0].fir) now = 0;
            }
        }
        printf("%d\n%lld ", sum + vec[0].fir, vec[0].sec);
        For(i, 0, vec[0].fir - 1) {
            for(auto j : a[i]) printf("%lld ", j);
            if(i != vec[0].fir - 1) printf("%lld ", vec[0].sec);
        }
    }
    return 0;
}
