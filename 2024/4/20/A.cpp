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
struct Node {
    int x, y, r;
} rou[maxn + 5];
set<pair<int, int> > se;

bool chk(int id, int x, int y) {
    LL dis = 1ll * (x - rou[id].x) * (x - rou[id].x) + 1ll * (y - rou[id].y) * (y - rou[id].y);
    return dis < 1ll * rou[id].r * rou[id].r;
}

int main() {
    //freopen("in", "r", stdin);
    read(n);
    For(i, 1, n) {
        int op, x, y; read(op); read(x); read(y);
        if(op == 1) {
            rou[i] = { x, y, y };
            se.insert({ x, i });
        }
        else {
            auto it = se.lower_bound({ x, 0 });
            For(i, 1, 20) if(it != se.begin()) it--;
            int fl = 0;
            For(i, 1, 40) {
                if(it == se.end()) break;
                else if(chk(it->sec, x, y)) {
                    fl = 1;
                    printf("%d\n", it->sec);
                    se.erase(it);
                    break;
                }
                it++;
            }
            if(!fl) puts("-1");
        }
    }
}
