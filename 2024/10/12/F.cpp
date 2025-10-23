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
int T, n, m, dis[maxn + 5], s, t;

vector<int> ma[maxn + 5];
vector<int> ch[maxn + 5];

void mian() {
    read(n); read(m);
    int tx, ty;
    read(tx); read(ty); tx--; ty--; s = tx * m + ty;
    read(tx); read(ty); tx--; ty--; t = tx * m + ty;
    For(i, 0, n - 1) {
        ma[i].resize(m + 5);
        For(j, 0, m - 1) {
            char c; cin >> c;
            if(c == '.') ma[i][j] = 1;
            else ma[i][j] = 0;
            ch[i * m + j].resize(0);
            dis[i * m + j] = inf;
        }
    }
    // cout << tx << " " << ty << endl;
    For(i, 0, n - 1) {
        int pre = i * m;
        For(j, 0, m - 1) {
            if(ma[i][j]) ch[i * m + j].pb(pre);
            if(!ma[i][j]) pre = i * m + j + 1;
            if(i * m + j == t) pre = i * m + j;
        }

        pre = i * m + m - 1;
        Rof(j, m - 1, 0) {
            if(ma[i][j]) ch[i * m + j].pb(pre);
            if(!ma[i][j]) pre = i * m + j - 1;
            if(i * m + j == t) pre = i * m + j;
        }
    }

    For(i, 0, m - 1) {
        int pre = i;
        // cout << i << endl;
        For(j, 0, n - 1) {
            if(ma[j][i]) ch[i + j * m].pb(pre);
            if(!ma[j][i]) pre = i + (j + 1) * m;
            if(i + m * j == t) pre = i + j * m;
        }

        pre = (n - 1) * m + i;
        Rof(j, n - 1, 0) {
            if(ma[j][i]) ch[i + j * m].pb(pre);
            if(!ma[j][i]) pre = i + (j - 1) * m;
            if(i + j * m == t) pre = i + j * m;
        }

    }
    // cout << "asd" << endl;

    queue<int> q;
    dis[s] = 0;

    q.push(s);
    while(q.size()) {
        int u = q.front(); q.pop();
        // cout << u << endl;
        for(auto v : ch[u]) {
            if(dis[v] > dis[u] + 1) {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }

    if(dis[t] == inf) puts("-1");
    else printf("%d\n", dis[t]);
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
