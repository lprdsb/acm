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

#define maxn 400000
int n, m, k, xx[maxn + 5], yy[maxn + 5];
unordered_map<int, map<int, int> > ma;
unordered_map<int, int> num[2];

template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

int main() {
    //freopen("in", "r", stdin);
    read(n); read(m); read(k);
    LL sum[2] = { 0, 0 };
    For(i, 1, k) {
        int x, y; read(x); read(y);
        sum[0] += x;
        sum[1] += y;
        ma[x][y] = 1;
        num[0][x]++;
        num[1][y]++;
        xx[i] = x;
        yy[i] = y;
    }
    LL res = 0, now = 0, cnt = 0;
    For(i, 1, n) {
        if(!ma[i][1]) {
            res = max(res, sum[0] - 2 * now + (2 * cnt - k) * i + sum[1] - k);
            break;
        }
        int pos = 1, now1 = 0, cnt1 = 0;
        while(ma[i][pos]) {
            now1 += 1ll * num[1][pos] * pos;
            cnt1 += num[1][pos];
            pos++;
        }
        if(pos <= m) res = max(res, sum[0] - 2 * now + (2 * cnt - k) * i + sum[1] - 2 * now1 + (2 * cnt1 - k) * pos);
        now += 1ll * i * num[0][i];
        cnt += num[0][i];
    }
    // cout << res << endl;

    sum[0] = sum[1] = 0;
    For(i, 1, k) {
        ma[xx[i]][yy[i]] = 0;
        num[0][xx[i]] = 0;
        num[1][yy[i]] = 0;
    }
    For(i, 1, k) {
        int x = n - xx[i] + 1, y = m - yy[i] + 1;
        sum[0] += x;
        sum[1] += y;
        ma[x][y] = 1;
        num[0][x]++;
        num[1][y]++;
    }
    now = 0, cnt = 0;
    For(i, 1, n) {
        if(!ma[i][1]) {
            res = max(res, sum[0] - 2 * now + (2 * cnt - k) * i + sum[1] - k);
            break;
        }
        int pos = 1, now1 = 0, cnt1 = 0;
        while(ma[i][pos]) {
            now1 += 1ll * num[1][pos] * pos;
            cnt1 += num[1][pos];
            pos++;
        }
        if(pos <= m) res = max(res, sum[0] - 2 * now + (2 * cnt - k) * i + sum[1] - 2 * now1 + (2 * cnt1 - k) * pos);
        now += 1ll * i * num[0][i];
        cnt += num[0][i];
    }

    sum[0] = sum[1] = 0;
    For(i, 1, k) {
        ma[n - xx[i] + 1][m - yy[i] + 1] = 0;
        num[0][n - xx[i] + 1] = 0;
        num[1][m - yy[i] + 1] = 0;
    }
    For(i, 1, k) {
        int x = n - xx[i] + 1, y = yy[i];
        sum[0] += x;
        sum[1] += y;
        ma[x][y] = 1;
        num[0][x]++;
        num[1][y]++;
    }
    now = 0, cnt = 0;
    For(i, 1, n) {
        if(!ma[i][1]) {
            res = max(res, sum[0] - 2 * now + (2 * cnt - k) * i + sum[1] - k);
            break;
        }
        int pos = 1, now1 = 0, cnt1 = 0;
        while(ma[i][pos]) {
            now1 += 1ll * num[1][pos] * pos;
            cnt1 += num[1][pos];
            pos++;
        }
        if(pos <= m) res = max(res, sum[0] - 2 * now + (2 * cnt - k) * i + sum[1] - 2 * now1 + (2 * cnt1 - k) * pos);
        now += 1ll * i * num[0][i];
        cnt += num[0][i];
    }

    sum[0] = sum[1] = 0;
    For(i, 1, k) {
        ma[n - xx[i] + 1][yy[i]] = 0;
        num[0][n - xx[i] + 1] = 0;
        num[1][yy[i]] = 0;
    }
    For(i, 1, k) {
        int x = xx[i], y = m - yy[i] + 1;
        sum[0] += x;
        sum[1] += y;
        ma[x][y] = 1;
        num[0][x]++;
        num[1][y]++;
    }
    now = 0, cnt = 0;
    For(i, 1, n) {
        if(!ma[i][1]) {
            res = max(res, sum[0] - 2 * now + (2 * cnt - k) * i + sum[1] - k);
            break;
        }
        int pos = 1, now1 = 0, cnt1 = 0;
        while(ma[i][pos]) {
            now1 += 1ll * num[1][pos] * pos;
            cnt1 += num[1][pos];
            pos++;
        }
        if(pos <= m) res = max(res, sum[0] - 2 * now + (2 * cnt - k) * i + sum[1] - 2 * now1 + (2 * cnt1 - k) * pos);
        now += 1ll * i * num[0][i];
        cnt += num[0][i];
    }

    printf("%lld\n", res);
}
