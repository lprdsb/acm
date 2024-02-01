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

#define U unsigned 

U LL A, B;

int f[105][2];
bool dfs(int pos, int ok, U LL x) {
    if(pos == -1) {
        if(!ok) {
            printf("%llu %llu\n", x, A - x);
            exit(0);
        }
        return 0;
    }
    if(f[pos][ok] != -1) return f[pos][ok];
    // cout << pos << " " << ok << " " << x << endl;
    int res = 0;
    For(o1, 0, 1) For(o2, 0, 1) if((ok && (o1 + o2 + (((B >> pos) & 1) ^ o1) >= 2)) || (!ok && (o1 + o2 + (((B >> pos) & 1) ^ o1) < 2))) {
        if((o1 ^ o2 ^ (((B >> pos) & 1) ^ o1)) == ((A >> pos) & 1)) {
            res |= dfs(pos - 1, o2, x | ((U LL)o1 << pos));
            // if(pos == 0 && x == 32) cout << o1 << " " << o2 << endl;
        }
    }
    return f[pos][ok] = res;
}

int main() {
    memset(f, -1, sizeof f);
    //freopen("in", "r", stdin);
    read(A); read(B);
    dfs(63, 0, 0);
    puts("-1");
}
