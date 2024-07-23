#include<bits/stdc++.h>

using std::pair;
using std::map;

typedef long long ll;

const int N = 2e5 + 10;

int n, x, y;
char s[N];

map<pair<int, int>, ll> m;

int main() {
    scanf("%d%d%d", &n, &x, &y);
    scanf("%s", s);
    if(x == 0 && y == 0) {
        printf("%lld\n", (ll)(n + 1) * n / 2);
        return 0;
    }
    int cx = 0, cy = 0;
    for(int i = 0;i < n;i++) {
        switch(s[i]) {
            case 'W':
                cy++;
                y++;
                break;
            case 'S':
                cy--;
                y--;
                break;
            case 'A':
                cx--;
                x--;
                break;
            case 'D':
                cx++;
                x++;
                break;
        }
    }
    ll ans = 0;
    for(int i = n - 1;i >= 0;i--) {
        if(m.find({ cx,cy }) == m.end()) {
            m.insert({ {cx,cy},0 });
        }
        m[{cx, cy}] = n - i;
        switch(s[i]) {
            case 'W':
                cy--;
                y--;
                break;
            case 'S':
                cy++;
                y++;
                break;
            case 'A':
                cx++;
                x++;
                break;
            case 'D':
                cx--;
                x--;
                break;
        }
        if(m.find({ x,y }) != m.end()) {
            ans += m[{x, y}];
        }
    }
    printf("%lld\n", ans);
    return 0;
}