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
int T, n, a[maxn + 5];

void mian() {
    read(n);
    queue<int> q;
    multiset<int> se;
    For(i, 1, n) {
        int x; read(x); a[i] = x;
        q.push(x); se.insert(x);
    }
    For(i, 1, n) {
        while(q.size() && se.size() && q.front() != *se.begin()) {
            int u = q.front(); q.pop();
            se.erase(se.lower_bound(u));
            se.insert(u + 1);
        }
        if(q.size()) q.pop();
        printf("%d ", *se.begin());
        se.erase(se.begin());
    }
    puts("");
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
