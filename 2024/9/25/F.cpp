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

int nextRand() {
    static unsigned int rnd_num = 0x80000001;
    static int mod = 1e5 + 3;

    rnd_num ^= rnd_num >> 10;
    rnd_num ^= rnd_num << 9;
    rnd_num ^= rnd_num >> 25;
    return rnd_num % mod;
}

#define N 5000005
#define maxn  200000
int a[N], num[N];

int main() {
    int tt;
    scanf("%d", &tt);
    while(tt--) {
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) {
            a[i] = nextRand();
            num[a[i]]++;
        }
        LL res = 0;
        int now = 0;
        For(i, 0, maxn) {
            res += 1ll * (now + 1) * num[i] * i;
            now += num[i];
            num[i] = 0;
        }
        cout << res << endl;
    }
    return 0;
}