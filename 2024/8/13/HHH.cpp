#include<bits/stdc++.h>
#define fs(i,x,y) for(int i=(x),_=(y);i<=_;++i)
#define fn(i,x,y) for(int i=(x),_=(y);i>=_;--i)
using namespace std;
typedef long double ll;
// typedef double db;

const int N = 2e6 + 7;
const ll pai = 3.141592653589793238462643383279;
const ll eps = 1e-12;
int n, m;

int dcmp(ll x) {
    return (x < -eps) ? -1 : ((x < eps) ? 0 : 1);
}

struct Point {
    ll x, y;
    Point() {}
    Point(ll x, ll y) :x(x), y(y) {}
    Point operator +(const Point &rhs) {
        return Point(x + rhs.x, y + rhs.y);
    }
    Point operator -(const Point &rhs) {
        return Point(x - rhs.x, y - rhs.y);
    }
    ll operator ^ (const Point &rhs) {
        return x * rhs.y - y * rhs.x;
    }
    ll Len2() {
        return x * x + y * y;
    }
    ll Len() {
        return sqrt(Len2());
    }
}a[N], b[N];

void solve() {
    scanf("%d", &n);
    fs(i, 1, n)scanf("%Lf%Lf", &a[i].x, &a[i].y);
    scanf("%d", &m);
    fs(i, 1, m)scanf("%Lf%Lf", &b[i].x, &b[i].y);
    fs(i, m + 1, 2 * m)b[i] = b[i - m];
    ll res = (b[m] - b[1]).Len();
    int j = 3;
    fs(i, 1, m) {
        while(dcmp(((b[i % m + 1] - b[i]) ^ (b[j % m + 1] - b[i])) - ((b[i % m + 1] - b[i]) ^ (b[j] - b[i]))) > 0) {
            res = max(res, max((b[j] - b[i]).Len(), (b[j] - b[i % m + 1]).Len()));
            j = j % m + 1;
            res = max(res, max((b[j] - b[i]).Len(), (b[j] - b[i % m + 1]).Len()));
        }
    }
    res = 2 * pai * res;
    ll ans = 0;
    fs(i, 1, n) {
        ans = ans + (a[i % n + 1] - a[i]).Len();
    }
    printf("%.18Lf\n", res + ans);
}

signed main() {
    int T;scanf("%d", &T);
    while(T--) {
        solve();
    }
}