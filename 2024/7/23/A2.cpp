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
int n, L, R;
int sum[3], lpr[3], h[maxn + 5], num[maxn + 5];
multiset<pair<int, int> > se[3];

void move(int x, int y, int lim) {
    while(sum[x] < lim) {
        if(!sum[y]) return;
        auto it = --se[y].end(); auto pa = *it;
        se[y].erase(it); sum[y] -= pa.sec;
        int mn = min(lim - sum[x], pa.sec);
        se[x].insert({ pa.fir + lpr[y] - lpr[x], mn }); sum[x] += mn;
        if(pa.sec > mn) se[y].insert({ pa.fir, pa.sec - mn }), sum[y] += pa.sec - mn;
    }
    while(sum[x] > lim) {
        auto it = se[x].begin(); auto pa = *it;
        int mn = min(sum[x] - lim, pa.sec);
        se[x].erase(it); sum[x] -= pa.sec;
        se[y].insert({ pa.fir + lpr[x] - lpr[y], mn }); sum[y] += mn;
        if(pa.sec > mn) se[x].insert({ pa.fir, pa.sec - mn }), sum[x] += pa.sec - mn;
    }
}
void merge(int x, int y) {
    while(sum[x] && sum[y] && se[x].begin()->fir + lpr[x] < (--se[y].end())->fir + lpr[y]) {
        auto it = se[x].begin(); auto pa = *it;
        se[x].erase(it); sum[x] -= pa.sec;
        se[y].insert({ pa.fir + lpr[x] - lpr[y], pa.sec }); sum[y] += pa.sec;
    }
}

void chk() {
    if(sum[1] < L) {
        puts("No");
        exit(0);
    }
    lpr[1]--;
    if(sum[1] && se[1].begin()->fir + lpr[1] < 0) {
        puts("No");
        exit(0);
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(n); read(L); read(R);
    For(i, 1, n) read(h[i]), num[h[i]]++;
    For(i, 1, maxn) se[0].insert({ i, num[i] }), sum[0] += num[i];
    move(1, 0, R);
    chk();
    move(1, 2, L);
    while(sum[0]) {
        chk(); merge(1, 0);
        move(1, 0, R); chk();
        if(!sum[0]) {
            puts("Yes");
            return 0;
        }
        merge(1, 2);
        move(1, 2, L);
    }
    puts("Yes");
}
