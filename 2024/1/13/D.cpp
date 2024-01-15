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
int T, n, q;
using i128 = __int128_t;
struct Node {
    int op, x;
    i128 len;
} a[maxn + 5];

int as[maxn + 5];
void mian() {
    read(n); read(q);
    int now = 0;
    For(i, 1, n) read(a[i].op), read(a[i].x);
    For(i, 1, n) {
        if(a[i].op == 1) a[i].len = a[i - 1].len + 1;
        else {
            i128 tem = (i128)a[i - 1].len * (a[i].x + 1);
            a[i].len = tem;
            if(tem > Inf) {
                n = i;
                break;
            }
        }
    }
    set<pair<LL, int> > se;
    For(i, 1, q) {
        LL k; read(k);
        se.insert({ k, i });
    }
    Rof(i, n, 1) {
        if(a[i].op == 1) {
            auto it = se.lower_bound({ a[i].len, 0 });
            vector<pair<LL, int> > vec;
            while(it != se.end()) {
                vec.pb(*it);
                it++;
            }
            for(auto [k, id] : vec) {
                as[id] = a[i].x;
                se.erase({ k, id });
            }
        }
        else {
            auto it = se.lower_bound({ a[i - 1].len + 1, 0 });
            vector<pair<LL, int> > vec;
            while(it != se.end()) {
                vec.pb(*it);
                it++;
            }
            for(auto [k, id] : vec) {
                se.erase({ k, id });
                se.insert({ (k - 1) % a[i - 1].len + 1, id });
            }
        }
    }
    For(i, 1, q) printf("%d ", as[i]);
    puts("");
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
