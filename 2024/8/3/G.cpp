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

#define maxn 5000
int n, m, k, a[maxn + 5][maxn + 5], num[maxn + 5];

vector<int> vec[maxn + 5][26];

int main() {
    // freopen("in.txt", "r", stdin);
    read(n); read(m); read(k);
    For(i, 1, n) {
        For(j, 1, m) {
            char c; cin >> c;
            if(c == '.') a[i][j] = -1;
            else a[i][j] = c - 'A';
        }
    }
    For(i, 1, n) {
        For(j, 1, m) if(a[i][j] != -1) {
            for(auto p : vec[j][a[i][j]]) num[p]++;
            vec[j][a[i][j]].pb(i);
        }
        Rof(j, i - 1, 1) {
            if(num[j] >= k) {
                printf("%d %d\n", j, i);
                return 0;
            }
            num[j] = 0;
        }
    }
    puts("-1");
    return 0;
}
