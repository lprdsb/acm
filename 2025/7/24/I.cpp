#include<bits/stdc++.h>

using namespace std;

const int N = 60;

struct Step {
    int x, y;
    char d;
    bool f;
};

int n, m;
char c[N];
int a[N][N];
vector<pair<int, int>> b;
vector<Step> ans;
bool v[N][N];

bool search(int x, int y) {
    if(v[x][y]) {
        return false;
    }
    v[x][y] = true;
    if(a[x][y] == 4) {
        a[x][y] = 6;
        return true;
    }
    if((a[x][y] & 2) && (x != b.back().first || y != b.back().second)) {
        ans.back().f = true;
    }
    if(x > 1 && a[x - 1][y] != 1) {
        ans.push_back({ x,y,'U' });
        if(search(x - 1, y)) {
            return true;
        }
        ans.pop_back();
    }
    if(x < n && a[x + 1][y] != 1) {
        ans.push_back({ x,y,'D' });
        if(search(x + 1, y)) {
            return true;
        }
        ans.pop_back();
    }
    if(y > 1 && a[x][y - 1] != 1) {
        ans.push_back({ x,y,'L' });
        if(search(x, y - 1)) {
            return true;
        }
        ans.pop_back();
    }
    if(y < m && a[x][y + 1] != 1) {
        ans.push_back({ x,y,'R' });
        if(search(x, y + 1)) {
            return true;
        }
        ans.pop_back();
    }
    return false;
}

int prtans(int i) {
    int r = i + 1;
    if(ans[i].f) {
        r = prtans(i + 1);
    }
    printf("%d %d %c\n", ans[i].x, ans[i].y, ans[i].d);
    return r;
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1;i <= n;i++) {
        scanf("%s", c);
        for(int j = 1;j <= m;j++) {
            switch(c[j - 1]) {
                case '.':
                    a[i][j] = 0;
                    break;
                case '#':
                    a[i][j] = 1;
                    break;
                case '@':
                    a[i][j] = 2;
                    b.push_back({ i,j });
                    break;
                case '*':
                    a[i][j] = 4;
                    break;
                case '!':
                    a[i][j] = 6;
                    break;
                default:
                    break;
            }
        }
    }
    while(!b.empty()) {
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= m;j++) {
                v[i][j] = false;
            }
        }
        if(!search(b.back().first, b.back().second)) {
            printf("-1");
            return 0;
        }
        a[b.back().first][b.back().second] = 0;
        b.pop_back();
    }
    printf("%d\n", ans.size());
    for(int i = 0;i < ans.size();i = prtans(i));
    return 0;
}