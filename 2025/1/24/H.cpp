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
int n, f[maxn + 5], g[maxn + 5];

int main() {
    //freopen("in", "r", stdin);
    f[3] = 1;
    For(i, 4, 100) {
        vector<int> vec;
        int cnt = 0;
        // cout << i << " :";
        For(o1, 0, i - 3) For(o2, 0, i - 3 - o1) {
            int tmp = f[o1] ^ f[o2] ^ f[i - 3 - o1 - o2];
            vec.pb(tmp);
            if(tmp == 0) {
                cnt += i + 1 - (1 + o1 + 1 + o2 + 1);
                // if(o1 >= o2 && o2 >= i - 3 - o1 - o2) cout << o1 << " " << o2 << " " << i - 3 - o1 - o2 << endl;
            }
        }
        sort(vec.begin(), vec.end());
        int now = 0;
        For(j, 0, inf) {
            if(vec.size() <= now || vec[now] != j) {
                f[i] = j;
                break;
            }
            while(now < vec.size() && vec[now] == j) now++;
        }
        g[i] = cnt;
        if(i >= 15 && i % 3 == 0) cout << i << " " << cnt << " " << g[i] / g[i / 3] << " " << g[i] % g[i / 3] << endl;
        // cout << i << " " << f[i] << " " << cnt << endl;
    }
}
