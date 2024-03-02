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

int T, n;

int A[1000] = { 0, 0, 1, 2, 3, 4, 5, 6, 7 };
int que(int a, int b, int c, int d) {
    printf("? %d %d %d %d\n", a, b, c, d);
    fflush(stdout);
    char cc; cin >> cc;
    // if((A[a] | A[b]) < (A[c] | A[d])) return -1;
    // if((A[a] | A[b]) == (A[c] | A[d])) return 0;
    // if((A[a] | A[b]) > (A[c] | A[d])) return 1;
    if(cc == '<') return -1;
    if(cc == '=') return 0;
    if(cc == '>') return 1;
    return 114514;
}

void mian() {
    read(n);
    if(n == (n & -n)) {
        int x = 0;
        For(i, 1, n - 1) {
            int ok = que(x, x, i, i);
            if(ok == -1) x = i;
        }
        int y = 0;
        For(i, 1, n - 1) {
            int ok = que(y, y, i, i);
            if(ok == 1) y = i;
        }
        printf("! %d %d\n", x, y);
        fflush(stdout);
    }
    else {
        int x = 0;
        For(i, 1, n - 1) {
            int ok = que(x, x, i, i);
            if(ok == -1) x = i;
        }
        int y = x;
        vector<int> vec;
        For(i, 0, n - 1) if(i != x) {
            int ok = que(x, y, x, i);
            if(ok == -1) {
                y = i;
                vec.resize(0);
            }
            else if(ok == 0) vec.pb(i);
        }
        for(auto i : vec) if(i != y) {
            int ok = que(i, i, y, y);
            if(ok == -1) y = i;
        }
        printf("! %d %d\n", x, y);
        fflush(stdout);
    }
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
