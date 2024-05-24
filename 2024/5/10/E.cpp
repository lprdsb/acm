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

#define maxn 100
int n, m, k;
int ma[maxn + 5][maxn + 5][maxn + 5];
struct Node {
    int x, y, z, c;
};
vector<Node> as;

void draw(int x, int y, int z, int c) {
    assert(!ma[x][y][z]);
    ma[x][y][z] = c;
    as.pb({ x, y, z, c });
}

void sol(int x0, int y0, int z0, int x, int y, int z, int c) {
    if(x0 == x && y0 == y && z0 == z) return;
    if(x0 != x) {
        if(!ma[x0 + 1][y0][z0]) {
            draw(x0 + 1, y0, z0, c);
            sol(x0 + 1, y0, z0, x, y, z, c);
            return;
        }
    }
    if(y0 != y) {
        if(!ma[x0][y0 + 1][z0]) {
            draw(x0, y0 + 1, z0, c);
            sol(x0, y0 + 1, z0, x, y, z, c);
            return;
        }
    }
    if(z0 != z) {
        if(!ma[x0][y0][z0 + 1]) {
            draw(x0, y0, z0 + 1, c);
            sol(x0, y0, z0 + 1, x, y, z, c);
            return;
        }
    }
    assert(0);
}

int main() {
    // freopen("in.txt", "r", stdin);
    n = m = k = 50;
    read(n); read(m); read(k);
    For(i, 1, n) For(j, 1, m) ma[i][j][1] = rand() % 50 + 1;
    For(i, 1, n) For(j, 1, m) read(ma[i][j][1]);
    Rof(i, n, 1) Rof(j, m, 1) {
        sol(i, j, 1, 2 * i - 1, j, 50 + ma[i][j][1], ma[i][j][1]);
    }
    For(z, 50 + 1, 50 + k) {
        For(x, 1, 2 * n) if(!ma[x][m + 1][z]) draw(x, m + 1, z, z - 50);
        For(x, 1, n) {
            int fl = 0;
            For(y, 1, m) if(ma[2 * x - 1][y][z] == z - 50) fl = 1;
            if(!fl) continue;
            For(y, 1, m) if(!ma[2 * x][y][z]) draw(2 * x, y, z, z - 50);
        }
    }
    // For(i, 1, 2 * n - 1) {
    //     For(j, 1, m + 1) cout << ma[i][j][50 + 3] << " ";
    //     cout << endl;
    // }
    printf("%d\n", as.size());
    for(auto [x, y, z, c] : as) printf("%d %d %d %d\n", x, y, z, c);
    return 0;
}
