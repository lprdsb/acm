#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define inf 0x3f3f3f3f
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)

#define maxn 200000
int n, m;
vector<int> vis[maxn + 5], visi[maxn + 5];


int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int chk(int lim) {
    queue<pair<int, int> >  q;
    For(i, 1, n) For(j, 1, m) {
        visi[i][j] = vis[i][j];
        if(vis[i][j]) q.push({ i, j });
    }
    while(q.size()) {
        auto [x, y] = q.front(); q.pop();
        // cout << x << " " << y << endl;
        For(o, 0, 3) {
            int tx = x + dir[o][0], ty = y + dir[o][1];
            if(tx < 1 || tx > n || ty < 1 || ty > m || visi[tx][ty]) continue;
            visi[tx][ty] = visi[x][y] + 1;
            if(visi[tx][ty] != lim + 1) {
                q.push({ tx, ty });
                // cout << tx << " " << ty << " " << visi[tx][ty]  <<< endl;
            }
        }
    }
    // For(i, 1, n) {
    //     For(j, 1, m) cout << visi[i][j] << " "; cout << endl;
    // }
    int mn[2] = { inf, inf }, mx[2] = { -inf, -inf };
    For(i, 1, n) For(j, 1, m) if(!visi[i][j]) {
        // cout << i << " " << j << endl;
        int x = i + j, y = i - j;
        mn[0] = min(mn[0], x);
        mx[0] = max(mx[0], x);

        mn[1] = min(mn[1], y);
        mx[1] = max(mx[1], y);
    }
    // cout << ((mn[0] ^ mx[0]) & 1) && ((mn[1] ^ mx[1]) & 1)) << endl;
    if(mx[0] - mn[0] == 2 * lim && mx[1] - mn[1] == 2 * lim) {
        int x = (mn[0] + mx[0]) / 2, y = (mn[1] + mx[1]) / 2;
        return !((x ^ y) & 1);

    }
    return max(mx[0] - mn[0], mx[1] - mn[1]) <= lim * 2;
}

int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    int cnt = 0;
    For(i, 1, n) {
        vis[i].resize(m + 5);
        visi[i].resize(m + 5);
        For(j, 1, m) {
            scanf("%d", &vis[i][j]);
            cnt += !vis[i][j];
        }
    }
    if(cnt <= 1) {
        puts("0");
        return 0;
    }
    // cout << chk(3) << endl;
    int l = 1, r = n + m;
    while(l < r) {
        int md = l + r >> 1;
        if(chk(md)) r = md;
        else l = md + 1;
    }
    printf("%d\n", l);
}