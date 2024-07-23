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

int n, L, R;

template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

#define maxn 500000
int h[maxn + 5], num[maxn + 5], lpr = 0, sum[3];
set<pair<int, int> > se[3];

int main() {
    freopen("in.txt", "r", stdin);
    read(n); read(L); read(R);
    For(i, 1, n) read(h[i]), num[h[i]]++;
    For(i, 1, maxn) se[2].insert({ -i, num[i] }), sum[2] += num[i];
    while(sum[0] < R) {
        auto pa = *se[2].begin();
        if(-pa.fir < 1) {
            puts("No");
            return 0;
        }
        se[2].erase(pa); sum[2] -= pa.sec;
        int mn = min(R - sum[0], pa.sec);
        se[0].insert({ pa.fir + 1, mn }); sum[0] += mn;
        if(pa.sec > mn) se[2].insert({ pa.fir, pa.sec - mn }), sum[2] += pa.sec - mn;
    }
    while(sum[1] < L) {
        auto pa = *se[0].begin();
        if(-pa.fir <= 2) {
            puts("No");
            return 0;
        }
        se[0].erase(pa); sum[0] -= pa.sec;
        int mn = min(L - sum[1], pa.sec);
        se[1].insert({ pa.fir, mn }); sum[1] += mn;
        if(pa.sec > mn) se[0].insert({ pa.fir, pa.sec - mn }), sum[0] += pa.sec - mn;
    }
    while(666) {
        if(!sum[2]) {
            puts("Yes");
            return 0;
        }
        lpr -= 1;
        while(sum[1] && sum[2] && -se[1].begin()->fir + lpr < -se[2].begin()->fir) {
            auto pa = *se[1].begin();
            se[1].erase(pa); sum[1] -= pa.sec;
            se[2].insert({ -(-pa.fir + lpr), pa.sec }); sum[2] += pa.sec;
        }
        while(sum[1] < R) {
            // cout << sum[2] << endl;
            if(!sum[2]) {
                puts("Yes");
                return 0;
            }
            auto pa = *se[2].begin();
            if(-pa.fir <= 0) {
                puts("No");
                return 0;
            }
            se[2].erase(pa); sum[2] -= pa.sec;
            int mn = min(R - sum[1], pa.sec);
            se[1].insert({ -(-pa.fir - lpr), mn }); sum[1] += mn;
            if(pa.sec > mn) se[2].insert({ pa.fir, pa.sec - mn }), sum[2] += pa.sec - mn;
        }
        if(!sum[2]) {
            puts("Yes");
            return 0;
        }
        lpr -= 1;
        while(sum[1] && -se[1].begin()->fir + lpr <= 1) {
            sum[1] -= se[1].begin()->sec;
            se[1].erase(se[1].begin());
        }
        while(sum[1] && sum[0] && -se[1].begin()->fir + lpr < -se[0].begin()->fir) {
            auto pa = *se[1].begin();
            se[1].erase(pa); sum[1] -= pa.sec;
            se[0].insert({ -(-pa.fir + lpr), pa.sec }); sum[0] += pa.sec;
        }
        while(sum[1] < L) {
            if(sum[0]) {
                auto pa = *se[0].begin();
                if(-pa.fir <= 1) {
                    puts("No");
                    return 0;
                }
                se[0].erase(pa); sum[0] -= pa.sec;
                int mn = min(pa.sec, L - sum[1]);
                se[1].insert({ -(-pa.fir - lpr), mn });
                sum[1] += mn;
                if(pa.sec > mn) se[0].insert({ pa.fir, pa.sec - mn }), sum[0] += pa.sec - mn;
            }
            else {
                puts("No");
                return 0;
            }
        }
    }
}
