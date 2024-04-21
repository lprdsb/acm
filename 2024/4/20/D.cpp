#include<bits/stdc++.h>
#define fs(i,x,y) for(int i=(x),_=(y);i<=_;++i)
#define fn(i,x,y) for(int i=(x),_=(y);i>=_;--i)
#define mpi(x,y) make_pair(x,y)
using namespace std;

const int N = 105;
int s[10];
int id[10];
int rev[10];
bool vis[N][N];

void solve() {
    scanf("%d%d%d", &s[3], &s[2], &s[1]);
    fs(i, 1, 3)id[i] = i;
    sort(id + 1, id + 4, [&](int &lhs, int &rhs) {
        return s[lhs] < s[rhs];
        });
    fs(i, 1, 3)rev[id[i]] = i;
    sort(s + 1, s + 4);
    if(s[3] > s[1] * s[2]) {
        cout << -1 << endl;return;
    }
    // cout << "//" << rev[1] << endl;
    cout << s[3] << endl;
    fs(i, 0, s[1] - 1)vis[i][i] = true;
    fs(j, s[1], s[2] - 1)vis[s[1] - 1][j] = true;
    s[3] -= s[2];
    fs(i, 0, s[1] - 1) {
        if(!s[3])break;
        fs(j, 0, s[2] - 1) {
            if(!s[3])break;
            if(!vis[i][j]) {
                vis[i][j] = true;--s[3];
            }
        }
    }
    fs(i, 0, s[1] - 1) {
        fs(j, 0, s[2] - 1) {
            if(vis[i][j]) {
                int a[4] = { 0,j,i,0 };
                fs(k, 1, 3)cout << a[rev[k]] << ' ';
                cout << endl;
            }
        }
    }
}

int main() {
    solve();
}
