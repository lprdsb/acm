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
int T, n, q, a[maxn + 5][2];
int pre[4][4], to[maxn + 5][2];

void mian() {
    read(n); read(q);
    For(i, 1, n) {
        char c[2]; cin >> c[0] >> c[1];
        For(o, 0, 1) {
            if(c[o] == 'B') a[i][o] = 0;
            if(c[o] == 'G') a[i][o] = 1;
            if(c[o] == 'R') a[i][o] = 2;
            if(c[o] == 'Y') a[i][o] = 3;
        }
    }
    For(o1, 0, 3) For(o2, 0, 3) pre[o1][o2] = -1;
    For(i, 1, n) {
        For(o1, 0, 3) For(o2, 0, 3) if(pre[o1][o2] != -1) {
            int cnt = 0;
            For(o, 0, 1) cnt += o1 == a[i][o];
            For(o, 0, 1) cnt += o2 == a[i][o];
            if(cnt == 1 && (to[i][0] == -1 || to[i][0] < pre[o1][o2])) to[i][0] = pre[o1][o2];
        }
        pre[a[i][0]][a[i][1]] = i;
    }

    For(o1, 0, 3) For(o2, 0, 3) pre[o1][o2] = -1;
    Rof(i, n, 1) {
        For(o1, 0, 3) For(o2, 0, 3) if(pre[o1][o2] != -1) {
            int cnt = 0;
            For(o, 0, 1) cnt += o1 == a[i][o];
            For(o, 0, 1) cnt += o2 == a[i][o];
            if(cnt == 1 && (to[i][1] == -1 || to[i][1] > pre[o1][o2])) to[i][1] = pre[o1][o2];
        }
        pre[a[i][0]][a[i][1]] = i;
    }
    // cout << to[1][0] << " " << to[1][1] << endl;
    while(q--) {
        int l, r; read(l); read(r);
        if(l > r) swap(l, r);
        int fl = 0;
        For(o1, 0, 1) For(o2, 0, 1) if(a[l][o1] == a[r][o2]) {
            fl = 1;
            break;
        }
        if(fl) printf("%d\n", r - l);
        else {
            int res = inf;
            For(o, 0, 1) if(to[l][o] != -1) res = min(res, abs(l - to[l][o]) + abs(r - to[l][o]));
            if(res == inf) puts("-1");
            else printf("%d\n", res);
        }
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    memset(to, -1, sizeof to);
    read(T);
    while(T--) {
        mian();
        For(i, 1, n) For(o, 0, 1) to[i][o] = -1;
    }
}
