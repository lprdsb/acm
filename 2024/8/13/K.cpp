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

#define maxn 4000000
int n, k, a[maxn + 5];
LL sum[maxn + 5];

int main() {
    // freopen("in.txt", "r", stdin);
    read(n); read(k);
    For(i, 1, n) read(a[i]);
    if(k == 1) {
        int ss = 0;
        For(i, 1, n) ss = max(ss, a[i]);
        printf("%lld\n", ss);
    }
    else {
        vector<int> vec;
        For(i, 1, n) {
            int tem = a[i];
            while(tem) {
                vec.pb(tem);
                tem /= k;
            }
        }
        vec.pb(0);
        sort(vec.begin(), vec.end());
        vec.erase(unique(vec.begin(), vec.end()), vec.end());
        For(i, 1, n) {
            int tem = a[i], cnt = 0;
            while(tem) {
                sum[lower_bound(vec.begin(), vec.end(), tem) - vec.begin()]--;
                cnt++;
                tem /= k;
            }
            sum[0] += cnt;
        }
        For(i, 1, vec.size() - 1) sum[i] += sum[i - 1];
        LL res = inf;
        For(i, 0, vec.size() - 1) res = min(res, vec[i] + sum[i]);
        printf("%lld\n", res);
    }
}
