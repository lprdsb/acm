#include<bits/stdc++.h>

const long double PI = acos(-1.0);

#define eps 1e-8

int t[2], d[2], l[2], e[2];

int main() {
    // freopen("in.txt", "r", stdin);
    for(int i = 0;i < 2;i++) {
        char tmp[10];
        if(i == 0) {
            scanf("%s%d%d", tmp, &d[i], &l[i]);
        }
        else {
            scanf("\n%s%d%d", tmp, &d[i], &l[i]);
        }
        t[i] = tmp[0] - 'A';
        long double y = cos((d[i] - 30) * PI / 180) * l[i];
        long double x = sin((d[i] - 30) * PI / 180) * l[i] + y / sqrt(3);
        long double h = sqrt(3) / 2;
        int u = (int)(y / h + eps);
        y -= u * h;
        x -= (int)(x / 2 + eps) * 2;
        // printf("%d %lf %lf\n", u, y, x);
        if(u % 2 == 0) {
            if(x < y / h) {
                e[i] = t[i];
            }
            else if(x < 1) {
                e[i] = t[i] % 3 + 1;
            }
            else if(x < 1 + y / h) {
                e[i] = 0;
            }
            else {
                e[i] = t[i] % 3 + 2;
            }
        }
        else {
            if(x < y / h) {
                e[i] = t[i] % 3 + 2;
            }
            else if(x < 1) {
                e[i] = 0;
            }
            else if(x < 1 + y / h) {
                e[i] = t[i] % 3 + 1;
            }
            else {
                e[i] = t[i];
            }
        }
    }
    puts(e[0] == e[1] ? "YES" : "NO");
    return 0;
}