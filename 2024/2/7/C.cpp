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

int T, n, m, k;

#define maxn 200000
int f[2][1024][11];
void chkmx(int &x, int y) { if(x < y) x = y; }
int a[maxn + 5], to[maxn + 5];
pair<int, int> opt[maxn + 5];
vector<int> vec[maxn + 5];
void mian() {
    read(n); read(m); read(k);
    For(i, 1, m) {
        read(opt[i].fir); read(opt[i].sec);
        a[opt[i].fir]++; a[opt[i].sec + 1]--;
    }
    For(i, 1, n) a[i] += a[i - 1];
    to[n + 1] = n + 1;
    Rof(i, n, 1) {
        if(a[i] <= k) to[i] = i;
        else to[i] = to[i + 1];
    }
    // cout << "asd" << endl;
    For(i, 1, m) {
        int now = to[opt[i].fir];
        while(now <= opt[i].sec) {
            vec[now].pb(i);
            now = to[now + 1];
        }
    }
    int now = to[1], o = 0, ma[10];
    f[o][0][0] = 0;
    while(now != n + 1) {
        int t = to[now + 1], mas = 0;
        For(o1, 0, (int)vec[now].size() - 1) {
            if(opt[vec[now][o1]].sec >= t) {
                For(o2, 0, (int)vec[t].size() - 1) if(vec[now][o1] == vec[t][o2]) {
                    ma[o1] = o2;
                    mas |= 1 << o2;
                    break;
                }
            }
            else ma[o1] = -1;
        }
        For(o1, 0, (1 << vec[now].size()) - 1) {
            int mt = 0, cc = 0;
            For(o2, 0, (int)vec[now].size() - 1) if((o1 >> o2) & 1) {
                cc++;
                if(ma[o2] != -1) mt |= 1 << ma[o2];
            }
            For(o2, 0, k) if(f[o][o1][o2] != -1) {
                chkmx(f[o ^ 1][mt][o2], f[o][o1][o2]);
                int tem = o2 + (int)vec[now].size() - cc;
                if(tem <= k) chkmx(f[o ^ 1][mas][tem], f[o][o1][o2] + 1);
                f[o][o1][o2] = -1;
            }
        }
        o ^= 1;
        now = t;
    }
    int res = 0;
    For(o1, 0, k) chkmx(res, f[o][0][o1]), f[o][0][o1] = -1;
    printf("%d\n", res);
}

int main() {
    // freopen("in.txt", "r", stdin);
    memset(f, -1, sizeof f);
    read(T);
    while(T--) {
        mian();
        For(i, 1, n + 1) {
            a[i] = 0;
            vec[i].resize(0);
        }
    }
}
