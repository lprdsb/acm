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

#define maxn 300000

int main() {
    //freopen("in", "r", stdin);
    int T; read(T);
    while(T--) {
        int n; read(n);
        set<int> se;
        For(i, 0, n + 1) se.insert(i);
        For(i, 1, n) {
            int x; read(x);
            int to = *++se.begin();
            if(to - *se.begin() == x) {
                printf("%d ", *se.begin());
                se.erase(se.begin());
            }
            else {
                printf("%d ", *se.begin() - x);
                se.erase(*se.begin() - x);
            }
        }
        puts("");
    }
}