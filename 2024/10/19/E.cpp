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
int n;
LL len[maxn + 5];
struct Opt {
    int op, x;
    vector<int> vec;
} opt[maxn + 5];

int main() {
    // freopen("in.txt", "r", stdin);
    read(n);
    int tp = 0;
    opt[0].vec.pb(1);
    opt[0].op = 1;
    len[0] = 1;
    For(i, 1, n) {
        int op, x; read(op); read(x);
        if(op == 1) {
            if(opt[tp].op == 1) {
                opt[tp].vec.pb(x);
                len[tp]++;
                if(len[tp] > inf) len[tp] = inf;
            }
            else {
                opt[++tp] = { 1, 0, {x} };
                len[tp] = len[tp - 1] + 1;
                if(len[tp] > inf) len[tp] = inf;
            }
        }
        else if(op == 2) {
            opt[++tp] = { 2, x };
            len[tp] = len[tp - 1] * 2;
            if(len[tp] > inf) len[tp] = inf;
        }
        else {
            if(x > len[tp]) puts("-1");
            else {
                Rof(j, tp, 0) {
                    if(opt[j].op == 1) {
                        if(x > opt[j].vec.size()) x -= opt[j].vec.size();
                        else {
                            printf("%d\n", opt[j].vec[opt[j].vec.size() - x]);
                            break;
                        }
                    }
                    else {
                        if(x % 2 == 1) {
                            printf("%d\n", opt[j].x);
                            break;
                        }
                        else x /= 2;
                    }
                }
            }
        }
    }
}
