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
#define maxn 500000
using namespace std;

int T, n, a[maxn + 5];
int fa[maxn + 5];
vector<int> pos[2 * maxn + 5];

template <class T>
void read(T &x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        read(n);
        For(i, 1, n) {
            read(a[i]), pos[a[i]].pb(i);
            fa[i] = i;
        }
        int fl = 1;
        For(i, 1, n + 50) {
            if(pos[i].size() == 1) break;
            // cout << i << endl;
            // for(auto j : pos[i]) cout << j << " "; cout << endl;
            sort(pos[i].begin(), pos[i].end());
            vector<int> tem;
            Rof(j, pos[i].size() - 1, 0) {
                if(pos[i][j] != 1 && a[find(pos[i][j] - 1)] == i) tem.pb(pos[i][j]);
                else {
                    tem.pb(pos[i][j]);
                    if(tem.size() == 1) {
                        fl = 0;
                        break;
                    }
                    reverse(tem.begin(), tem.end());
                    for(int j = 1; j < tem.size(); j += 2) fa[tem[j]] = find(tem[j] - 1);
                    fa[tem[tem.size() - 1]] = find(tem[tem.size() - 2]);
                    for(int j = 0; j < tem.size() - 1; j += 2) {
                        a[tem[j]] = i + 1;
                        pos[i + 1].pb(tem[j]);
                    }
                    tem.resize(0);
                }
            }
            if(!fl) break;
            pos[i].resize(0);
        }
        if(fl) {
            int sum = 0;
            For(i, 1, n + 50) sum += pos[i].size();
            if(sum == 1) puts("Yes");
            else puts("No");
        }
        else puts("No");
        For(i, 1, 2 * n) pos[i].resize(0);
    }
}
