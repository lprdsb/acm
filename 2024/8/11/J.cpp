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

#define maxn 1000
int n, a, b, q;
pair<int, int> pa[maxn + 5];
map<int, int> ma;

int main() {
    // freopen("in.txt", "r", stdin);
    read(n); read(a); read(b); read(q);
    For(i, 1, a) {
        int x; char c; read(x); cin >> c;
        ma[x] = c;
    }
    For(i, 1, b) read(pa[i].fir), read(pa[i].sec), pa[i].sec = pa[i].fir - pa[i].sec;
    vector<pair<int, int> > vec;
    for(auto [k, v] : ma) {
        int now = b, nk = k;
        while(now) {
            while(now && pa[now].fir > nk) now--;
            if(now && pa[now].fir != pa[now].sec) {
                int tem = (nk - pa[now].fir + 1 + pa[now].sec - 1) / pa[now].sec;
                nk -= tem * pa[now].sec;
            }
            else break;
        }
        vec.pb({ nk, v });
    }
    for(auto [k, v] : vec) ma[k] = v;
    while(q--) {
        int nk; read(nk);
        int now = b;
        while(now) {
            while(now && pa[now].fir > nk) now--;
            if(now && pa[now].fir != pa[now].sec) {
                int tem = (nk - pa[now].fir + 1 + pa[now].sec - 1) / pa[now].sec;
                nk -= tem * pa[now].sec;
            }
            else break;
        }
        if(ma.count(nk)) printf("%c", ma[nk]);
        else printf("?");
    }
}
