#include<bits/stdc++.h>

using namespace std;
#define LL long long
#define DD double

const double EPS = 1e-12;
int sgn(double x) { return x > EPS ? 1 : x < -EPS ? -1 : 0; }

struct Point {
    LL x, y;

    Point operator +(const Point& p) { return { x + p.x, y + p.y }; }
    Point operator -(const Point& p) { return { x - p.x, y - p.y }; }

    LL operator ^(const Point& p) { return { x * p.y - y * p.x }; }

    DD norm() { return hypot(x, y); }
};

struct Line {
    Point p, s;
};

struct Segment {
    Point p, q;

    Point vec() { return q - p; }
    Line line() { return { p, vec() }; }
};

struct Polygon {
    vector<Point> v;

    Point vert(int i) {
        while(i < 0) { i += v.size(); }
        return v[i % v.size()];
    }
    Segment edge(int i) {
        return { vert(i), vert(i + 1) };
    }
    double circ() {
        double ret = 0;
        for(int i = 0; i < v.size(); i++) {
            ret += edge(i).vec().norm();
        }
        return ret;
    }
};

double diameter(Polygon pol) {
    double ret = 0;
    int k = 1;
    for(int i = 0; i < pol.v.size(); i++) {
        while(sgn(pol.edge(i).vec() ^ pol.edge(k).vec()) > 0) { k++; }
        ret = max(ret, max(
            (pol.vert(k) - pol.vert(i)).norm(),
            (pol.vert(k) - pol.vert(i + 1)).norm()
        ));
    }
    return ret;
}

int t;
int n, m;
Polygon a, b;

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        a.v.resize(n);
        for(int i = 0; i < n; i++) {
            scanf("%Lf%Lf", &a.v[i].x, &a.v[i].y);
        }
        scanf("%d", &m);
        b.v.resize(m);
        for(int i = 0; i < m; i++) {
            scanf("%Lf%Lf", &b.v[i].x, &b.v[i].y);
        }
        double d = diameter(b);
        printf("%.12Lf\n", a.circ() + d * 2 * acos(-1));
    }
    return 0;
}