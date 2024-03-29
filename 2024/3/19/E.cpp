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
int T, n, k, a[maxn + 5];
LL f[maxn + 5];

bool chk(vector<int> vec) {
    sort(vec.begin(), vec.end());
    if(!vec[0]) return 1;
    int now = 0;
    LL sum = 0;
    For(i, 1, vec.size() - 1) {
        sum += vec[i];
        while((sum - 1ll * vec[now + 1] * (i - now) + k - 1) / k > now + 1) sum -= vec[++now];
        if(f[i - now] >= sum - 1ll * (now + 1) * k) return 1;
    }
    return 0;
}

void mian() {
    read(n); k = 1;
    f[1] = 0;
    For(i, 2, n) {
        f[i] = 0;
        Rof(o, 60, 0) {
            LL to = f[i] + (1ll << o);
            if(to - (to / i) - k <= f[i - 1]) f[i] = to;
        }
    }
    // For(i, 0, n) read(a[i]);
    For(i, 1, n) {
        int x; read(x);
        a[x]++;
    }
    // cout << chk(vector<int>(a, a + 2 + 1)) << endl;
    int l = 0, r = n + 1;
    while(l < r) {
        int md = l + r >> 1;
        if(chk(vector<int>(a, a + md + 1))) r = md;
        else l = md + 1;
    }
    printf("%d\n", l);
    For(i, 0, n + 1) a[i] = 0;
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
