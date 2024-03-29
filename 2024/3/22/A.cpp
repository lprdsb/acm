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

#define maxn 100000
int n, m, op[maxn + 5], pos[maxn + 5];
int st[2][maxn + 5], tp[2], as[maxn + 5], opt[maxn + 5], cnt = 0;

int main() {
    //freopen("in", "r", stdin);
    read(n); read(m);
    For(i, 1, m) read(op[i]), read(pos[i]);
    m++;
    op[m] = 0; pos[m] = 1;
    m++;
    op[m] = 1; pos[m] = n;
    For(i, 1, m) {
        if(op[i] == 0) {
            while(tp[0] && pos[st[0][tp[0]]] <= pos[i]) tp[0]--;
            st[0][++tp[0]] = i;
        }
        else {
            while(tp[1] && pos[st[1][tp[1]]] >= pos[i]) tp[1]--;
            st[1][++tp[1]] = i;
        }
    }
    int now[2] = { 1, 0 };
    while(now[0] <= tp[0] && now[1] <= tp[1]) {
        while(now[0] <= tp[0] && st[0][now[0]] <= st[1][now[1]]) now[0]++;
        if(now[0] > tp[0]) break;
        opt[++cnt] = pos[st[0][now[0]]];
        while(now[1] <= tp[1] && st[1][now[1]] <= st[0][now[0]]) now[1]++;
        if(now[1] > tp[1]) break;
        opt[++cnt] = pos[st[1][now[1]]];
    }
    int l = 1, r = n, o = 0, mx = n;
    For(i, 0, cnt) {
        o ^= 1;
        if(o) {
            For(j, l, opt[i] - 1) {
                as[l++] = mx--;
                if(l > r) break;
            }
        }
        else {
            Rof(j, r, opt[i] + 1) {
                as[r--] = mx--;
                if(l > r) break;
            }
        }
        if(l > r) break;
    }
    For(i, 1, n) printf("%d ", as[i]);
    return 0;
}
