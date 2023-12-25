#include <bits/stdc++.h>

const int N = 210;

int t;
int n, m;
int a[N][N];
int ans;

int main() {
    freopen("in.txt", "r", stdin);
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                scanf("%d", &a[i][j]);
            }
        }
        if(n > 2 && m > 2) {
            bool f = true;
            int cnt = 0;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    if(a[i][j] % m != a[0][j] % m) {
                        f = false;
                    }
                    if((a[i][j] - 1) / m != (a[i][0] - 1) / m) {
                        f = false;
                    }
                }
            }
            for(int i = 0; i < m; i++) {
                if((a[0][i] - 1) % m != i) {
                    f = false;
                }
            }
            for(int i = 0; i < n; i++) {
                if((a[i][0] - 1) / m != i) {
                    cnt++;
                }
            }
            if(cnt != 2) {
                f = false;
            }
            puts(f ? "FOX" : "NSFW");
            continue;
        }
        ans = 0;
        if(n == 2) {
            bool f = true;
            int cnt = 0;
            for(int i = 0; i < m; i++) {
                if(a[0][i] % m != a[1][i] % m) {
                    f = false;
                }
                if((a[0][i] > a[1][i]) != (a[0][0] > a[1][0])) {
                    f = false;
                }
            }
            for(int i = 0; i < m; i++) {
                for(int j = i + 1; j < m; j++) {
                    cnt += a[0][i] > a[0][j];
                }
            }
            if((cnt % 2) != (a[0][0] > a[1][0])) {
                f = false;
            }
            if(f) {
                ans = 2;
            }
        }
        if(m == 2) {
            bool f = true;
            int cnt = 0;
            for(int i = 0; i < n; i++) {
                if((a[i][0] + 1) / 2 != (a[i][1] + 1) / 2) {
                    f = false;
                }
                if((a[i][0] > a[i][1]) != (a[0][0] > a[0][1])) {
                    f = false;
                }
            }
            for(int i = 0; i < n; i++) {
                for(int j = i + 1; j < n; j++) {
                    cnt += a[i][0] > a[j][0];
                }
            }
            if((cnt % 2) == (a[0][0] > a[0][1])) {
                f = false;
            }
            if(f) {
                ans = 1;
            }
        }
        puts(ans == 0 ? "NSFW" : (ans == 1 ? "FOX" : "CAT"));
    }
    return 0;
}