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

#define maxn 500000
int f[maxn + 5];

int main() {
    freopen("in.txt", "w", stdout);
    f[1] = 0;
    For(i, 2, 100) {
        for(int j = (i - 1) & i; j; j = (j - 1) & i) {
            if(!f[j] && !f[i ^ j]) {
                f[i] = 1;
                break;
            }
        }
    }
    For(i, 1, 100) {
        vector<int> vec;
        int tem = i, cnt = 0;
        while(tem) vec.pb(tem & 1), cnt += tem & 1, tem >>= 1;
        if(cnt == 5) {
            for(auto j : vec) printf("%d", j); printf(" %d\n", f[i]);
        }
    }
}
