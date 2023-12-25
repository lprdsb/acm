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
#define maxn 200000
using namespace std;

int T, n, a[2 * maxn + 5];
vector<int> vec;

template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for (ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if (ch == '-') ok = 1;
    for (x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if (ok) x = -x;
}

int as[4][2 * maxn + 5];

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while (T--) {
        read(n);
        For(i, 1, 2 * n) {
            char c; cin >> c;
            a[i] = c - '0';
            if (a[i] && i != 1 && i != 2 * n) vec.pb(i);
        }
        if (a[1] != a[2 * n] || (vec.size() & 1)) puts("-1");
        else {
            int cnt = 2;
            For(i, 1, 3) {
                as[i][1] = 1;
                For(j, 2, 2 * n - 1) as[i][j] = (j - 1) & 1;
                as[i][2 * n] = 0;
            }
            for (int i = 0; i < vec.size(); i += 2) {
                for (int j = vec[i] + 1; j < vec[i + 1]; j += 2) swap(as[1][j], as[1][j + 1]);
                for (int j = vec[i]; j < vec[i + 1]; j += 2) swap(as[2][j], as[2][j + 1]);
            }
            if (a[1]) cnt++;
            printf("%d\n", cnt);
            For(i, 1, cnt) {
                For(j, 1, 2 * n) putchar(as[i][j] ? '(' : ')');
                puts("");
            }
        }
        vec.resize(0);
    }
}
