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

#define maxn 500000
int T, n, a[maxn + 5], L[maxn + 5], R[maxn + 5], to[maxn + 5][2];
int st[maxn + 5], tp = 0;
LL sum[maxn + 5];
vector<int> vec[maxn + 5];

void mian() {
    read(n);
    a[0] = a[n + 1] = 0;
    For(i, 1, n) read(a[i]);

    st[tp = 0] = 0;
    For(i, 1, n) {
        while(tp && a[i] <= a[st[tp]]) tp--;
        L[i] = st[tp] + 1;
        vec[L[i] - 1].pb(i);
        st[++tp] = i;
    }
    st[tp = 0] = 0;
    For(i, 1, n) {
        sort(vec[i].begin(), vec[i].end(), [](const int &x, const int &y) {return a[x] > a[y];});
        int now = 0;
        while(tp && a[i] <= a[st[tp]]) {
            while(now < vec[i].size() && a[vec[i][now]] > a[st[tp]]) to[vec[i][now]][0] = i - st[tp] - 1, now++;
            tp--;
        }
        while(now < vec[i].size() && a[vec[i][now]] > a[st[tp]]) to[vec[i][now]][0] = i - st[tp] - 1, now++;
        st[++tp] = i;
    }
    For(i, 0, n + 1) vec[i].resize(0);

    st[tp = 0] = n + 1;
    Rof(i, n, 1) {
        while(tp && a[i] <= a[st[tp]]) tp--;
        R[i] = st[tp] - 1;
        vec[R[i] + 1].pb(i);
        st[++tp] = i;
    }
    st[tp = 0] = n + 1;
    Rof(i, n, 1) {
        sort(vec[i].begin(), vec[i].end(), [](const int &x, const int &y) {return a[x] > a[y];});
        int now = 0;
        while(tp && a[i] <= a[st[tp]]) {
            while(now < vec[i].size() && a[vec[i][now]] > a[st[tp]]) to[vec[i][now]][1] = st[tp] - i - 1, now++;
            tp--;
        }
        while(now < vec[i].size() && a[vec[i][now]] > a[st[tp]]) to[vec[i][now]][1] = st[tp] - i - 1, now++;
        st[++tp] = i;
    }
    For(i, 0, n + 1) vec[i].resize(0);

    For(i, 1, n) {
        sum[L[i]] -= 1ll * a[i] * (R[i] - i + 1);
        sum[i] += 1ll * a[i] * (R[i] - i + 1);
        sum[i + 1] -= 1ll * a[i] * (i - L[i] + 1);
        sum[R[i] + 1] += 1ll * a[i] * (i - L[i] + 1);
    }
    For(i, 1, n) sum[i] += sum[i - 1];
    LL res = 0;
    For(i, 1, n) {
        res += 1ll * (R[i] - i + 1) * (i - L[i] + 1) * a[i];
        sum[L[i] - 1] += 1ll * (R[i] - i + 1) * to[i][0] * a[i];
        sum[R[i] + 1] += 1ll * (i - L[i] + 1) * to[i][1] * a[i];
    }
    For(i, 1, n) printf("%lld ", res - 1ll * (R[i] - i + 1) * (i - L[i] + 1) * a[i] + sum[i]);
    puts("");
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
        For(i, 0, n + 1) sum[i] = 0;
    }
}
