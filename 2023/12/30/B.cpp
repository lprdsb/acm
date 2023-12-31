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

priority_queue<pair<LL, int> > q;

int main() {
    //freopen("in", "r", stdin);
    int n; read(n);
    int tot = 0;
    vector<int> as;
    For(i, 1, n) {
        int x, y; read(x); read(y);
        LL tem = x * 10000000ll + y;
        q.push({ -tem, i });
        if(q.size() < 7) as.pb(0), tot++;
        else {
            if(q.top().second == i) as.pb(0);
            else as.pb(q.top().second), tot++;
            q.pop();
        }
    }
    printf("%d\n", tot);
    for(auto i : as) printf("%d ", i);
    puts("");
}
