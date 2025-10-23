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
int n, a[maxn + 5], b[maxn + 5], to[maxn + 5];

map<pair<int, int>, int> ma;
vector<pair<int, int> > vec;

void mian() {
    //freopen("in", "r", stdin);
    ma.clear();
    read(n);
    For(i, 1, n) to[i] = 0;
    For(i, 1, n) read(a[i]);
    For(i, 1, n) read(b[i]);
    int tot = 0;
    For(i, 1, n) {
        if(ma.count({ b[i], a[i] })) {
            tot++;
            to[ma[{b[i], a[i]}]] = tot;
            to[i] = n - tot + 1;
            ma.erase({ b[i], a[i] });
        }
        else ma[{a[i], b[i]}] = i;
    }
    if(ma.size() > 1) puts("-1");
    else {
        if(ma.size() == 1 && n % 2 == 0) {
            puts("-1");
            return;
        }
        else if(ma.size() == 1) {
            auto pa = ma.begin()->first;
            if(pa.fir != pa.sec) {
                puts("-1");
                return;
            }
            else to[ma[pa]] = (1 + n) / 2;
        }
        // For(i, 1, n) cout << to[i] << " ";cout << endl;
        For(i, 1, n) if(!to[i]) to[i] = i;
        vec.clear();
        For(i, 1, n) {
            while(to[i] != i) {
                vec.pb({ i,to[i] });
                swap(to[i], to[to[i]]);
            }
        }
        printf("%d\n", vec.size());
        for(auto [l, r] : vec) printf("%d %d\n", l, r);
    }

}

int main() {
    // freopen("in.txt", "r", stdin);
    int T; read(T);
    while(T--) mian();
}
