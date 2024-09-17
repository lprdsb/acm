#include<bits/stdc++.h>
using namespace std;

void solve() {
    double x1, y1, x2, y2;
    scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
    printf("%.12lf\n", min(sqrt((x1 + x2) * (x1 + x2) + (y1 - y2) * (y1 - y2)), sqrt((x1 - x2) * (x1 - x2) + (y1 + y2) * (y1 + y2))));
}

int main() {
    int T;scanf("%d", &T);
    while(T--) {
        solve();
    }
}