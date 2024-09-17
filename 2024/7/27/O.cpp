#include<bits/stdc++.h>

int t;
int n;
bool c[22][361];
bool s[22][361];
bool v[22][361];
std::queue<std::pair<int, int> > q;

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 0;i <= 21;i++) {
            for(int j = 0;j < 360;j++) {
                c[i][j] = i == 0 || i == 21;
                s[i][j] = 0;
                v[i][j] = 0;
            }
        }
        for(int i = 0;i < n;i++) {
            char ch;
            int x, y, z;
            scanf("\n%c%d%d%d", &ch, &x, &y, &z);
            if(ch == 'C') {
                for(int i = y;i != z;i = (i + 1) % 360) {
                    c[x][i] = 1;
                }
            }
            else {
                for(int i = x;i < y;i++) {
                    s[i][z] = 1;
                }
            }
        }
        while(!q.empty())q.pop();
        q.push({ 20, 0 });
        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            int r = cur.first, a = cur.second;
            if(v[r][a]) {
                continue;
            }
            v[r][a] = 1;
            if(!s[r][a]) {
                q.push({ r,(a + 359) % 360 });
            }
            if(!s[r][(a + 1) % 360]) {
                q.push({ r,(a + 1) % 360 });
            }
            if(!c[r][a]) {
                q.push({ r - 1,a });
            }
            if(!c[r + 1][a]) {
                q.push({ r + 1,a });
            }
        }
        puts(v[0][0] ? "YES" : "NO");
    }
    return 0;
}