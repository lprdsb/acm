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

#define maxn 400000
int n;
vector<int> vec;
cst int B = 2000;
struct Opt {
    int op, x, id;
} opt[maxn + 5];
bool operator < (cst Opt &x, cst Opt &y) {
    if(x.x != y.x) return x.x < y.x;
    return x.id < y.id;
}

LL a[maxn + 5];
LL res = 0;
struct Block {
    int l, r, now;
    LL a0 = 0, sum = 0, bas = 0;
    LL w[B], sw[B], to[B], id[B];
    void upd() {
        while(now < B && a[now] + a0 <= 0) {
            sum += w[now] * (a[now] + a0);
            now++;
        }
        while(now && a[now - 1] + a0 > 0) {
            sum -= w[now - 1] * (a[now - 1] + a0);
            now--;
        }
    }
    void build_w() {
        For(i, 0, B - 1) w[i] = vec[to[i] + l] - vec[to[i] + l - 1];
        sw[0] = w[0];
        For(i, 1, B - 1) sw[i] = sw[i - 1] + w[i];

    }
    void init() {
        a0 = a[l];
        For(i, l, r) id[i - l] = i, to[i - l] = i - l;
        build_w();
        now = sum = 0;
        upd();
    }
    void mdy(int idx, int val) {
        res -= sum + bas;
        if(val < 0) bas += vec[idx] - vec[l - 1];
        For(i, 0, B - 1) a[pa[i].sec] = a0 + pa[i].fir;
        For(i, l, idx) a[i] += val;
        init();
        res += sum + bas;
    }
    void add(int val) {
        res -= sum + bas;
        if(val < 0) bas += vec[r] - vec[l - 1];
        a0 += val;
        if(now) sum += 1ll * val * sw[now - 1];
        upd();
        res += sum + bas;
    }
} block[B + 5];

int tp = 0;

void ins(int idx, int val) {
    For(i, 0, tp) {
        if(block[i].r <= idx) {
            block[i].add(val);
            if(block[i].r == idx) break;
        }
        else {
            block[i].mdy(idx, val);
            break;
        }
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(n);
    tp = n / B + 10;
    For(i, 1, n) {
        int op, x; read(op); read(x);
        opt[i] = { op == 1 ? 1 : -1, x, i };
        vec.pb(x);
    }
    vec.pb(0);
    sort(vec.begin(), vec.end()); vec.erase(unique(vec.begin(), vec.end()), vec.end());
    For(i, 1, n) opt[i].x = lower_bound(vec.begin(), vec.end(), opt[i].x) - vec.begin();
    // sort(opt + 1, opt + n + 1);
    while(vec.size() <= tp * B + 10) vec.pb(vec.back() + 1);
    For(i, 0, tp) {
        block[i].l = i * B + 1, block[i].r = (i + 1) * B;
        block[i].init();
    }
    LL sum = 0;
    For(i, 1, n) {
        if(opt[i].op == 1) sum += vec[opt[i].x];
        ins(opt[i].x, opt[i].op);
        printf("%lld\n", res + sum);
    }
}
