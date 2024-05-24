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
int n;
LL a[maxn + 5];
vector<LL> as;
multiset<LL> se;

vector<LL> vec;
bool find(LL x) {
    if(se.find(x) != se.end()) {
        vec.pb(x);
        se.erase(se.find(x));
        return 1;
    }
    if(x == 1) return 0;
    if(x % 2) return find(x / 2) && find(x - x / 2);
    return 0;
}

int main() {
    //freopen("in", "r", stdin);
    read(n);
    For(i, 1, n) read(a[i]), se.insert(a[i]);
    while(se.size()) {
        auto now = *--se.end(); se.erase(--se.end());
        if(now % 2) {
            auto it = se.find(now - 1);
            if(it != se.end()) {
                as.pb(now + now - 1);
                se.erase(it);
            }
            else as.pb(now);
        }
        else {
            vec.resize(0);
            if(find(now + 1)) {
                as.pb(now + now + 1);
            }
            else {
                for(auto i : vec) se.insert(i);
                vec.resize(0);
                if(find(now - 1)) {
                    as.pb(now + now - 1);
                }
                else {
                    for(auto i : vec) se.insert(i);
                    as.pb(now);
                }
            }
        }
    }
    sort(as.begin(), as.end());
    reverse(as.begin(), as.end());
    printf("%d\n", as.size());
    for(auto i : as) printf("%lld ", i);
}
