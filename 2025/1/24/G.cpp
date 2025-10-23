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

int T, n, m, ma[25][25], vis[25], cnt[2000005];
vector<int> ok[25];

void mian() {
    read(n); read(m);
    if(n >= 20) {
        For(i, 1, m) {
            int x; read(x); read(x);
        }
        printf("%d\n", n);
        For(i, 1, n) printf("%d ", i); puts("");
    }
    else {
        For(i, 1, n) For(j, 1, n) ma[i][j] = 0;
        For(i, 1, m) {
            int u, v; read(u); read(v);
            ma[u][v] = 1;
        }
        for(auto o : ok[n]) {
            int fl = 1;
            For(i, 1, n) For(j, 1, n) if(ma[i][j] && ((o >> (i - 1)) & 1) && !((o >> (j - 1)) & 1)) {
                fl = 0;
                break;
            }
            // if(o == 23)cout << fl << endl;
            if(fl) {
                // cout << o << " " << cnt << endl;
                printf("%d\n", cnt[o]);
                For(i, 1, n) if((o >> (i - 1)) & 1) printf("%d ", i);
                puts("");
                return;
            }
        }
        puts("-1");
    }
}

int mask[26], sta[2000005];

int main() {
    //freopen("in", "r", stdin);
    For(i, 1, (1 << 20)) cnt[i] = cnt[i >> 1] + (i & 1);
    For(i, 1, 20) {
        int now = i;
        while(now <= 20) {
            mask[i] |= 1 << (now - 1);
            now += i;
        }
    }
    For(i, 1, (1 << 20) - 1) {
        For(o, 0, 19) if((i >> o) & 1) sta[i] ^= mask[o + 1];
    }
    For(i, 1, 20) For(j, 1, (1 << i) - 1) if(cnt[sta[j] & ((1 << i) - 1)] <= i / 5) ok[i].pb(j);
    // For(i, 1, 20) cout << ok[i].size() << endl;
    read(T);
    while(T--) {
        mian();
    }
}
