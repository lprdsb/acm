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

#define maxn 5000
#define ULL unsigned LL
int T, n, m, l[maxn + 5], r[maxn + 5], vis[maxn + 5][2], as[maxn + 5];
ULL sum[maxn + 5];
mt19937_64 rd(114514);
int val[maxn + 5];

void mian() {
    read(n); read(m);
    For(i, 1, m) {
        ULL tmp = rd();
        read(l[i]); read(r[i]); vis[l[i]][0] = 1; vis[r[i]][1] = 1;
        sum[l[i]] ^= tmp; sum[r[i]] ^= tmp;
    }
    ULL now = 0;
    int pre = 1, tl = 0, tr = 0;
    For(i, 1, n) {
        now ^= sum[i];
        if(vis[i][0]) tl = i;
        if(vis[i][1] && !tr) tr = i;
        if(now == 0) {
            if(pre != i) {
                if(tl >= tr) {
                    puts("-1");
                    return;
                }
                For(j, pre, tl) as[j] = 0;
                For(j, tr, i) as[j] = 1;
            }
            pre = i + 1;
            tr = 0;
        }
    }
    int res = 0;
    now = 0;
    Rof(i, n, 1) {
        if(as[i] == -1) val[i] += now;
        now += as[i] == 1;
        if(as[i] == 1) res += n - i + 1 - now;
    }
    res += now * (now - 1) / 2 + (n - now) * (n - now - 1) / 2;
    now = 0;
    For(i, 1, n) {
        if(as[i] == -1) val[i] -= now;
        now += as[i] != 1;
    }
    now = n;
    vector<int> vec;
    while(now) {
        while(now && as[now] != -1) now--;
        vec.pb(now);
        while(now && as[now] == -1) now--;
    }
    reverse(vec.begin(), vec.end());
    vector<int> vec1;
    for(auto v : vec) {
        now = v;
        while(now && as[now] == -1) {
            vec1.pb(val[now]);
            now--;
        }
    }
    int mx = res;
    now = 0;
    for(auto v : vec1) {
        res += v + now;
        mx = max(mx, res);
        now++;
    }
    printf("%d\n", mx);
    // For(i, 1, n) cout << as[i] << " "; cout << endl;
    // For(i, 1, n) cout << val[i] << " "; cout << endl;
}

int main() {
    // freopen("in.txt", "r", stdin);
    memset(as, -1, sizeof as);
    read(T);
    while(T--) {
        mian();
        For(i, 1, n) {
            sum[i] = vis[i][0] = vis[i][1] = 0;
            as[i] = -1;
            val[i] = 0;
        }
    }
}
