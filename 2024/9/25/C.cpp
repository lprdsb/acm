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

int n;
priority_queue<int> q;

int main() {
    // freopen("in.txt", "r", stdin);
    read(n);
    For(i, 1, n) {
        int op; read(op);
        if(op == 1) {
            int x; read(x);
            q.push(x);
        }
        if(op == 2) q.pop();
        if(op == 3) printf("%d\n", q.top());
    }
    while(q.size()) {
        printf("%d ", q.top());
        q.pop();
    }
}
