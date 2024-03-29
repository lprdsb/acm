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
int n, a[maxn + 5], b[maxn + 5], ok[maxn + 5];

int main() {
    //freopen("in", "r", stdin);
    read(n);
    For(i, 1, n) {
        read(a[i]);
        ok[a[i]] = 1;
    }
    vector<int> vec[2];
    For(i, 1, n) if(!ok[i]) {
        if(!a[i]) vec[0].pb(i);
        else vec[1].pb(i);
    }
    For(i, 1, n) if(!a[i]) {
        if(vec[0].size()) {
            if(vec[0].back() == i) {
                vec[1].pb(vec[0].back());
                vec[0].pop_back();
            }
            if(vec[0].size()) {
                a[i] = vec[0].back();
                vec[0].pop_back();
            }
            else {
                swap(vec[1][0], vec[1][vec[1].size() - 1]);
                a[i] = vec[1].back();
                vec[1].pop_back();
            }
        }
        else a[i] = vec[1].back(), vec[1].pop_back();
    }
    For(i, 1, n) printf("%d ", a[i]);
    return 0;
}
