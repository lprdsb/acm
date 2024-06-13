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

#define maxn 1000000
int n, a, b, vis[maxn + 5];
pair<int, int> pos[maxn + 5];

#define LLL __int128_t

void print(LLL x) {
    vector<int> vec;
    while(x) vec.pb(x % 10), x /= 10;
    if(!vec.size()) puts("0");
    else {
        reverse(vec.begin(), vec.end());
        for(auto i : vec) printf("%d", i);
        puts("");
    }
}

int main() {
    //freopen("in", "r", stdin);
    read(n); read(a); read(b);
    For(i, 1, n) read(pos[i].fir);
    For(i, 1, n) read(pos[i].sec);
    LLL res = 0;
    LL len = 1000000001ll;
    int cnt = min(a / n, b / n);
    res += 2 * len * cnt;
    a -= cnt * n; b -= cnt * n;
    vector<pair<pair<LL, int>, int > > vec;
    For(i, 1, n) {
        if(pos[i].sec == 0) {
            vec.pb({ { pos[i].fir, 0 },   i });
            vec.pb({ { pos[i].fir + len, 1 },   i });
            vec.pb({ { pos[i].fir + 2 * len, 0 }, i });
            vec.pb({ { pos[i].fir + 3 * len, 1 },i });
        }
        else {
            vec.pb({ { len - pos[i].fir, 1 }, i });
            vec.pb({ { 2 * len - pos[i].fir, 0 }, i });
            vec.pb({ { 3 * len - pos[i].fir, 1 }, i });
            vec.pb({ { 4 * len - pos[i].fir, 0 }, i });
        }
    }
    sort(vec.begin(), vec.end());
    LL mx = 0;
    for(auto [sta, id] : vec) if(!vis[id]) {
        if(sta.sec == 0) {
            if(a) a--;
            else vis[id] = 1;
            mx = max(mx, sta.fir);
        }
        else {
            if(b) b--;
            else vis[id] = 1;
            mx = max(mx, sta.fir);
        }
    }
    print(res + mx);
    return 0;
}
