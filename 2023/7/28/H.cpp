#include <bits/stdc++.h>

using std::vector;

struct data {
    int x;
    int y;
    int k;
};

int n, m;
vector<data> v;
double p = 0.618;

int a[50] = { 407,
    412,
    428,
    433,
    454,
    475,
    496,
    517,
    625,
    633,
    658,
    659,
    659,
    666,
    667,
    667,
    692,
    693,
    693,
    700,
    701,
    701,
    727,
    734,
    735,
    735,
    761,
    768,
    769,
    769,
    795,
    802,
    803,
    803,
    829,
    836,
    837,
    837,
    863,
    871,
    897,
    905,
    931,
    939,
    956,
    965,
    969,
    973,
    999 };
int b[5] = { 692,727,803,931 };

void solve(int x, int y, int k) {
    int cnt = 0;
    if(k == 1) {
        return;
    }
    int a = int(k * p + 0.5);
    int b = k - a;
    solve(x, y, a);
    cnt++;
    solve(x + a, y + a, b);
    cnt++;
    int x1 = x + a, y1 = y;
    int x2 = x, y2 = y + a;
    while(a > 0 && b > 0) {
        if(a >= b) {
            solve(x1, y1, b);
            cnt++;
            solve(x2, y2, b);
            cnt++;
            y1 += b;
            x2 += b;
            a -= b;
        }
        else {
            solve(x1, y1, a);
            cnt++;
            solve(x2, y2, a);
            cnt++;
            x1 += a;
            y2 += a;
            b -= a;
        }
    }
    // if(cnt > 50)
    //     printf("%d\n", m);
    v.push_back((data) { x, y, k });
}

int main() {
    // for(int i = 1; i <= 1000; i++) {
    //     m = i;
    //     v.clear();
    //     solve(1, 1, i);
    // }
    scanf("%d", &n);
    for(int i = 0; i < 49; i++) {
        if(n == a[i])
            p = 0.629;
    }
    for(int i = 0; i < 4; i++) {
        if(n == b[i])
            p = 0.610;
    }
    solve(1, 1, n);
    printf("%d\n", v.size());
    for(int i = 0; i < v.size(); i++) {
        printf("%d %d %d\n", v[i].x, v[i].y, v[i].k);
    }
    return 0;
}

