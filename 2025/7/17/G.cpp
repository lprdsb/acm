#include<bits/stdc++.h>
#define fs(i,x,y) for(int i=(x),_=(y);i<=_;++i)
#define fn(i,x,y) for(int i=(x),_=(y);i>=_;--i)
using namespace std;
typedef long long ll;
typedef double db;

const int N = 5e5 + 7;
const db pai = 3.14159265358979323846;
struct Vec {
    ll x, y;
    db tha;
    ll len;
    void init() {
        len = x * x + y * y;
        tha = atan2(y, x);
    }
    Vec() {}
    Vec(ll _x, ll _y) {
        x = _x, y = _y;
    }
    ll operator * (Vec &rhs) {
        return (x * rhs.x + y * rhs.y);
    }
    Vec operator - (Vec &rhs) {
        return Vec(x - rhs.x, y - rhs.y);
    }
    ll operator ^(Vec rhs) {
        return x * rhs.y - y * rhs.x;
    }
}p[N];
ll sx, sy;
int n;

db ang(Vec lhs, Vec rhs) {
    return acos((db)(lhs * rhs) / (sqrt(lhs.len) * sqrt(rhs.len)));
}

void solve() {
    scanf("%d", &n);
    scanf("%lld%lld", &sx, &sy);
    fs(i, 1, n)scanf("%lld%lld", &p[i].x, &p[i].y), p[i].x -= sx, p[i].y -= sy, p[i].init();
    p[0] = Vec(0, 0);
    p[n + 1] = p[1];
    bool ok = false;
    fs(i, 1, n) {
        if(((p[0] - p[i]) ^ (p[i + 1] - p[i])) > 0)ok = true;
    }
    if(ok) {
        db ans = 2 * pai;
        // sort(p + 1, p + n + 1, [&](Vec &lhs, Vec &rhs) {
        //     return lhs.len < rhs.len;
        //     });
        // int r = 1;
        // while(r < n && p[r + 1].len == p[1].len)++r;
        // if(r == 1) ans = max(ans, 2 * pai);
        // sort(p + 1, p + r + 1, [&](Vec &lhs, Vec &rhs) {
        //     return lhs.tha < rhs.tha;
        //     });
        // fs(i, 1, r - 1)ans = max(ans, p[i + 1].tha - p[i].tha);
        // ans = max(2 * pai + p[1].tha - p[r].tha, ans);
        // int l = n;
        // while(l > 1 && p[l - 1].len == p[n].len)--l;
        // if(l == n)ans = max(ans, 2 * pai);
        // sort(p + l, p + n + 1, [&](Vec &lhs, Vec &rhs) {
        //     return lhs.tha < rhs.tha;
        //     });
        // fs(i, l, n - 1)ans = max(ans, p[i + 1].tha - p[i].tha);
        // ans = max(2 * pai + p[l].tha - p[n].tha, ans);
        printf("%.12lf\n", ans);
    }
    else {
        sort(p + 1, p + n + 1, [&](Vec &lhs, Vec &rhs) {
            return lhs.len > rhs.len;
            });
        int r = 1;
        while(r < n && p[r + 1].len == p[1].len)++r;
        // cout<<""
        if(r == 1) {
            printf("%.12lf\n", 2 * pai);
            return;
        }
        sort(p + 1, p + r + 1, [&](Vec &lhs, Vec &rhs) {
            return lhs.tha < rhs.tha;
            });
        db ans = 0;
        fs(i, 1, r - 1)ans = max(ans, p[i + 1].tha - p[i].tha);
        ans = max(2 * pai + p[1].tha - p[r].tha, ans);
        printf("%.12lf\n", ans);
    }
}

signed main() {
    int T;scanf("%d", &T);
    while(T--) {
        solve();
    }
}