#include<bits/stdc++.h>
#define fs(i,x,y) for(int i=(x),_=(y);i<=_;++i)
#define fn(i,x,y) for(int i=(x),_=(y);i>=_;--i)
#define pi pair<int,int>
#define mpi(x,y) make_pair(x,y)
using namespace std;

const int N = 1e5 + 7;
int n, d;
int a[N], b[N];
int p[N];
vector<pi>wt[20];

// void chk() {
//     bool ok = true;
//     fs(i, 1, 3) {
//         if(a[i] > a[i + 1])ok = false;
//     }
//     fs(i, 5, 7) {
//         if(a[i] > a[i + 1])ok = false;
//     }
//     if(!ok)return;
//     fs(i, 1, 8)cout << a[i] << " ";
//     cout << endl;
//     fs(i, 1, 8)b[i] = a[i];
//     fs(i, 1, 4)if(b[i] > b[9 - i])swap(b[i], b[9 - i]);
//     fs(i, 1, 4)cout << b[i] << " ";
//     cout << endl;
// }

// void dfs(int u) {
//     if(u == 9) {
//         chk();
//         return;
//     }
//     fs(i, 1, 8) {
//         if(!vis[i]) {
//             vis[i] = true;a[u] = i;
//             dfs(u + 1);
//             vis[i] = false;
//         }
//     }
// }

void sol(int l, int r, int dep) {
    // cout << "//" << l << ' ' << r << ' ' << dep << endl;
    if(l == r)return;
    int len = r - l + 1;d = max(d, dep);
    sol(l, l + p[len] - 1, dep + 1);sol(l + p[len], r, dep + 1);
    int lim = p[len];
    int sum = l + lim - 1 + l + lim;
    fs(i, l, l + lim - 1) {
        if((sum - i) <= r)wt[dep].emplace_back(mpi(i, sum - i));
    }
}

void solve() {
    // dfs(1);
    fs(i, 0, 14)p[(1 << i) + 1] = (1 << i);
    fs(i, 2, 10000)p[i] = max(p[i], p[i - 1]);
    scanf("%d", &n);
    sol(0, n - 1, 1);
    // cout << d * (d + 1) / 2 << endl;
    printf("%d\n", d * (d + 1) / 2);
    fn(i, d, 1) {
        fs(j, i, d) {
            printf("%d ", (int)wt[j].size());
            for(auto [u, v] : wt[j])printf("%d %d ", u, v);
            printf("\n");
        }
    }
}

signed main() {
    // freopen("hh.txt", "w", stdout);
    solve();
}