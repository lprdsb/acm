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
int n;
map<string, int> ma[2];
pair<int, int> score[2][maxn + 5];
string s[2][maxn + 5];

int main() {
    //freopen("in", "r", stdin);
    For(o, 0, 1) {
        read(n);
        For(i, 1, n) {
            cin >> s[o][i];
            int p, t; read(p); read(t);
            ma[o][s[o][i]] = i;
            score[o][i] = { p, t };
        }
    }
    int res = -1;
    For(o, 0, 1) {
        int idx = ma[o]["lzr010506"];
        int rk = 1;
        for(auto [name, id] : ma[o]) {
            if(ma[!o].count(name)) continue;
            if(score[o][id].fir > score[o][idx].fir || (score[o][id].fir == score[o][idx].fir && score[o][id].sec < score[o][idx].sec)) rk++;
        }
        if(res == -1 || rk < res) res = rk;
    }
    printf("%d\n", res);
}
