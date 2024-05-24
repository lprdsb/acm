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
#define ULL unsigned LL

#define maxn 1000
int n, k, a[maxn + 5], num[maxn + 5], b[maxn + 5][2], cnt[2];
int f[maxn + 5];
mt19937_64 rd(time(0));
ULL hsh[maxn + 5], mask[maxn + 5];
int vis[maxn + 5][maxn + 5];
map<ULL, pair<int, int> > ma;

pair<int, int> st[maxn + 5];
int main() {
    // freopen("in.txt", "r", stdin);
    read(n); read(k);
    For(i, 1, k) hsh[i] = rd();
    For(i, 1, k) For(j, i + 1, k) ma[hsh[i] ^ hsh[j]] = { i, j };
    int sum = 0, nn = 0, bas = 0;
    For(i, 1, n / 2) {
        int x, y; read(x); read(y);
        if(x == y) bas++;
        else {
            nn++;
            b[nn][0] = x; b[nn][1] = y;
            mask[nn] = hsh[x] ^ hsh[y];
        }
    }
    n = nn;
    For(i, 1, k) num[i] = 1;
    cnt[1] = k;
    Rof(i, n, 1) {
        For(o, 0, 1) {
            cnt[num[b[i][o]] & 1]--;
            sum -= num[b[i][o]] / 2;
            num[b[i][o]]++;
            sum += num[b[i][o]] / 2;
            cnt[num[b[i][o]] & 1]++;
        }
        For(j, i + 1, n) mask[j] ^= mask[i];
        int c1 = cnt[0] * (cnt[0] - 1) / 2, c2 = cnt[0] * cnt[1], c3 = cnt[1] * (cnt[1] - 1) / 2;
        int tp = 0;
        For(j, i, n) {
            if(ma.count(mask[j])) {
                pair<int, int> pa = ma[mask[j]];
                if(!vis[pa.fir][pa.sec]) {
                    vis[pa.fir][pa.sec] = 1;
                    f[i] = max(f[i], f[j + 1] + j - i);
                    st[++tp] = pa;
                    if((num[pa.fir] ^ num[pa.sec]) & 1) c2--;
                    else if(num[pa.fir] & 1) c3--;
                    else c1--;
                }
            }
        }
        if(c1) f[i] = max(f[i], sum - 2);
        if(c2) f[i] = max(f[i], sum - 1);
        if(c3) f[i] = max(f[i], sum);
        while(tp) {
            vis[st[tp].fir][st[tp].sec] = 0;
            tp--;
        }
    }
    ULL all = 0;
    For(i, 1, k) all ^= hsh[i];
    For(i, k / 2, n) if(mask[i] == all) {
        printf("%d\n", f[i + 1] + bas + i - k / 2);
        return 0;
    }
    For(i, 1, k) num[i]--;
    sum = 0;
    For(i, 1, k) sum += num[i] / 2;
    printf("%d\n", sum + bas);
    return 0;
}
