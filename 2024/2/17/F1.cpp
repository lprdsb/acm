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

#define maxn 3000000
int T, n, q, a[maxn + 5], N;

int cnt[25][2], as[25], now = -1;
vector<int> vec[2][25][2];

void sol(int s) {
    For(o, 0, s - 1) For(o1, 0, 1) For(o2, 0, 1) vec[o1][o][o2].resize(0);
    Rof(o, s, 0) {
        vector<int> vv[2];
        as[o] = as[o + 1];
        if(vec[1][o][1].size() && vec[0][o][0].size()) {
            as[o] |= 1 << o;
            vv[0] = vec[0][o][0];
            vv[1] = vec[1][o][1];
        }
        else {
            For(o1, 0, 1) {
                vv[o1] = vec[o1][o][0];
                for(auto i : vec[o1][o][1]) vv[o1].pb(i);
            }
        }
        if(o) {
            For(o1, 0, 1) {
                for(auto i : vv[o1]) vec[o1][o - 1][(i >> (o - 1)) & 1].pb(i);
            }
        }
    }
}

void mian() {
    read(n); read(q); N = 0;
    now = -1;
    For(_, 1, q) {
        int x, fl = 0; read(x); x = (x + as[0]) % n;
        a[++N] = x;
        if(N != 1) {
            Rof(o, 21, now + 1) if(!cnt[o][(x >> o) & 1]) {
                now = o;
                fl = 1;
                break;
            }
        }
        For(o, 0, 21) cnt[o][(x >> o) & 1]++;
        if(fl) {
            For(i, 1, N) vec[(a[i] >> now) & 1][now][(a[i] >> now) & 1].pb(a[i]);
            sol(now);
        }
        else if(now != -1) {
            int to = (x >> now) & 1, fl = -1;
            Rof(o, now - 1, 0) {
                vec[to][o][(x >> o) & 1].pb(x);
                if(((x >> o) & 1) == to) {
                    if(vec[to][o][to].size() == 1 && vec[!to][o][!to].size()) {
                        fl = o;
                        break;
                    }
                }
                else {
                    if((as[o] >> o) & 1) break;
                }
            }
            if(fl != -1) sol(fl);
        }
        printf("%d ", as[0]);
    }
    puts("");
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
        For(o, 0, 21) {
            as[o] = 0;
            For(o1, 0, 1) {
                cnt[o][o1] = 0;
                For(o2, 0, 1) vec[o1][o][o2].resize(0);
            }
        }
    }
}
