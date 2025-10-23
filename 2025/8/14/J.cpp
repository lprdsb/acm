#include<bits/stdc++.h>
#define fs(i,x,y) for(int i=(x),_=(y);i<=_;++i)
#define fn(i,x,y) for(int i=(x),_=(y);i>=_;--i)
#define pi pair<int,int>
#define mpi(x,y) make_pair(x,y)
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef double db;

const int N = 1e6 + 7;
// const int inf = 1e9 + 7;
int n;
struct Point {
    db x, y, z;
    Point() {}
    Point(db _x, db _y, db _z) {
        x = _x, y = _y, z = _z;
    }
    Point operator + (Point rhs) {
        return Point(x + rhs.x, y + rhs.y, z + rhs.z);
    }
    Point operator -(Point rhs) {
        return Point(x - rhs.x, y - rhs.y, z - rhs.z);
    }
    db operator * (Point rhs) {
        return x * rhs.x + y * rhs.y + z * rhs.z;
    }
    db len() {
        return sqrt(x * x + y * y + z * z);
    }
}o[N], e[N], p[N];

void solve() {
    scanf("%d", &n);
    if(n == 2 || n == 3 || n == 5 || n == 7)printf("-1\n");
    else {
        int nn = n;
        if(n % 2 == 0) {
            fs(i, 0, n / 2 - 1) {
                db dta = (i / 4) * 2;
                p[i + 1] = e[i % 4] + Point(dta, 0, 0);
                p[i + 1 + n / 2] = p[i + 1] + Point(0, 1, 0);
            }
            reverse(p + n / 2 + 1, p + n + 1);
            fs(i, 1, nn)printf("%.12lf %.12lf %.12lf\n", p[i].x, p[i].y, p[i].z);
            if(nn == 4)printf("1\n");
            else if(nn == 6)printf("2\n");
            else printf("inf\n");
        }
        else {
            n -= 7;
            fs(i, 0, n / 2 - 1) {
                db dta = (i / 4) * 2;
                p[i + 1] = e[i % 4] + Point(dta, 0, 0);
                p[i + 1 + n / 2] = p[i + 1] + Point(0, 1, 0);
            }
            reverse(p + n / 2 + 1, p + n + 1);
            fs(i, 1, 7)p[n + i] = o[i];
            fs(i, 1, nn)printf("%.12lf %.12lf %.12lf\n", p[i].x, p[i].y, p[i].z);
            printf("inf\n");
        }
        p[nn + 1] = p[1];p[nn + 2] = p[2];
        // cout << "////";
        // fs(i, 1, nn)cout << (p[i + 1] - p[i]).len() << ' ';
        // cout << endl;
        // cout << "////";
        // fs(i, 1, nn)cout << (p[i + 2] - p[i + 1]) * (p[i + 1] - p[i]) << ' ';
        // cout << endl;
    }
}

signed main() {
    // freopen("innnn", "r", stdin);
    // freopen("hhhh", "w", stdout);
    e[0] = Point(0, 0, 0);
    e[1] = Point(1, 0, 0);
    e[2] = Point(1, 0, -1);
    e[3] = Point(2, 0, -1);
    db l0 = (sqrt(2) - 1) / 2, l1 = sqrt(1 - l0 * l0);
    o[1] = Point(0, 1, -1);
    o[2] = Point(-l1, 1 + l0, -1);
    o[3] = Point(-l1, 1 + l0, 0);
    o[4] = Point(-l1 - sqrt(2) / 2, 1 + l0 - sqrt(2) / 2, 0);
    o[5] = Point(-l1, 1 + l0 - sqrt(2), 0);
    o[6] = Point(-l1, 1 + l0 - sqrt(2), -1);
    o[7] = Point(0, 0, -1);
    int T;scanf("%d", &T);
    while(T--) {
        solve();
    }
}