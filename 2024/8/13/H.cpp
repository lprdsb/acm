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

#define maxn 1000000
int T, n, m;
struct Poi {
    LL x, y;
} con[2][maxn + 5];

LL get_dis2(int o, int x, int y) {
    return (con[o][x].x - con[o][y].x) * (con[o][x].x - con[o][y].x) + (con[o][x].y - con[o][y].y) * (con[o][x].y - con[o][y].y);
}
DD get_dis(int o, int x, int y) {
    return sqrt((DD)get_dis2(o, x, y));
}

DD get_len(LL x, LL y) {
    return sqrt(x * x + y * y);
}

DD sini[maxn + 5];

void mian() {
    read(n);
    For(i, 1, n) read(con[0][i].x), read(con[0][i].y);
    DD res = get_dis(0, 1, n);
    For(i, 1, n - 1) res += get_dis(0, i, i + 1);
    read(m);
    For(i, 1, m) read(con[1][i].x), read(con[1][i].y);

    con[0][0] = con[0][n];
    con[0][n + 1] = con[0][1];
    For(i, 1, n) {
        int tl = i - 1, tr = i + 1;
        LL x[2] = { con[0][i].x - con[0][tl].x, con[0][i].x - con[0][tr].x };
        LL y[2] = { con[0][i].y - con[0][tl].y, con[0][i].y - con[0][tr].y };
        sini[i] = (DD)abs(x[0] * y[1] - x[1] * y[0]) / get_len(x[0], y[0]) / get_len(x[1], y[1]);
    }
    sini[n + 1] = sini[1];

    int now = 1;
    LL mx = 0;
    For(i, 1, m) {
        while(666) {
            int tem = now % m + 1;
            if(get_dis2(1, i, tem) >= get_dis2(1, i, now)) now = tem;
            else break;
        }
        mx = max(mx, get_dis2(1, i, now));
    }

    int cnt = 0;
    DD sum1 = 0;
    DD mxr = sqrt((DD)mx);
    For(i, 1, n) {
        DD len = max((DD)0, get_dis(0, i, i + 1) - mxr / sini[i] - mxr / sini[i + 1]);
        if(len > eps) cnt++;
        sum1 += len;
    }
    if(cnt <= 2) printf("%.10lf\n", mxr * 2 * acos(-1.0) + res);
    else printf("%.10lf\n", mxr * 2 * acos(-1.0) + res + sum1);
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
