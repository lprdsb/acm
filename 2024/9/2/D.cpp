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
int T, n, a[maxn + 5];
vector<int> ch[maxn + 5];

void mian() {
    read(n);
    For(i, 1, n - 1) {
        int u, v; read(u); read(v);
        ch[u].pb(v); ch[v].pb(u);
    }
    For(i, 1, n) {
        char c; cin >> c;
        if(c == '?') a[i] = -1;
        else a[i] = c - '0';
    }
    int num[2] = { 0, 0 }, cnt = 0, ok = 0;
    For(i, 2, n) {
        if(ch[i].size() == 1) {
            if(a[i] != -1) num[a[i]]++;
            else cnt++;
            // cout << i << " " << a[i] << endl;
        }
        else if(a[i] == -1) ok++;
    }
    // cout << num[0] << " " << num[1] << endl;
    if(a[1] != -1) printf("%d\n", num[!a[1]] + (cnt + 1) / 2);
    else printf("%d\n", max(num[0], num[1]) + (cnt + ((ok & 1) && (num[0] == num[1]))) / 2);
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
        For(i, 1, n) ch[i].resize(0);
    }
}
