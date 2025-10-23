#include<bits/stdc++.h>
#define fs(i,x,y) for(int i=(x),_=(y);i<=_;++i)
#define fn(i,x,y) for(int i=(x),_=(y);i>=_;--i)
typedef double db;
using namespace std;

const int N = 1e5 + 7;
const db pai = 3.14159265358979323846;
struct Vec {
    db x, y, z;
    Vec() {}
    Vec(db _x, db _y, db _z) {
        x = _x;y = _y;z = _z;
    }
    db operator *(Vec &rhs) {
        return x * rhs.x + y * rhs.y + z * rhs.z;
    }
    db len() {
        return sqrt(x * x + y * y + z * z);
    }
}p, q;

db r, d, phi, tha;
db tx, ty, tz, tl;

db ang(Vec x, Vec y) {
    return acos((x * y) / (x.len() * y.len()));
}

void solve() {
    scanf("%lf%lf", &r, &d);
    scanf("%lf%lf%lf", &tx, &ty, &tz);
    tl = sqrt(tx * tx + ty * ty + tz * tz);
    p = Vec(tx / tl, ty / tl, tz / tl);
    scanf("%lf%lf%lf", &tx, &ty, &tz);
    tl = sqrt(tx * tx + ty * ty + tz * tz);
    q = Vec(tx / tl, ty / tl, tz / tl);

    tha = ang(p, q);phi = d / r;
    db ans = 0;
    if(phi <= pai / 2) {
        ans = 2 * pai * (1 - cos(phi)) + tha * 2 * sin(phi);
    }
    else if(phi > pai) {
        ans = 4 * pai;
    }
    else {
        db l = pai - phi;
        if(tha < 2 * l) {
            db x = acos(cos(l) / cos(tha / 2));
            db y = acos(cos(l) * cos(l - (tha / 2)) / cos(tha / 2));
            ans = 2 * (x / sin(l)) * (1 - cos(l)) * 2 - (pai / 2 + ang(Vec(cos(tha / 2) * sin(x) * sin(x), -sin(tha / 2), -cos(x) * sin(x) * cos(tha / 2)), Vec(sin(x), 0, -cos(x))) + ang(Vec(sin(tha / 2) * sin(tha / 2) * cos(x), cos(tha / 2) * sin(tha / 2) * cos(x), sin(x)), Vec(sin(tha / 2), cos(tha / 2), 0)) - pai) * 4;
            // db hhh = (pai / 2 + ang(Vec(cos(tha / 2) * sin(x) * sin(x), -sin(tha / 2), -cos(x) * sin(x) * cos(tha / 2)), Vec(sin(x), 0, -cos(x))) + ang(Vec(sin(tha / 2) * sin(tha / 2) * cos(x), cos(tha / 2) * sin(tha / 2) * cos(x), sin(x)), Vec(sin(tha / 2), cos(tha / 2), 0)) - pai);
            // cout << hhh / pai << endl;
            ans = 4 * pai - ans;
        }
        else {
            ans = 4 * pai;
        }
    }
    printf("%.12lf\n", ans * r * r);
}

signed main() {
    // cout << acos(-0.5) / pai << endl;
    int T;scanf("%d", &T);
    while(T--) {
        solve();
    }
}