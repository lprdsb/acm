#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int t;
int n;
int k;
int a[N];
int b[N];
int f[N];
vector<int> v;
vector<int> u;
vector<int> w;

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &k);
        for(int i = 1;i <= n;i++) {
            scanf("%d", &a[i]);
            b[i] = i;
            f[i] = 0;
        }
        a[0] = 1;
        b[0] = 0;
        sort(b + 1, b + n + 1, [](int x, int y) {return a[x] < a[y];});
        v.clear();
        u.clear();
        w.clear();
        v.push_back(0);
        for(int i = 1;i <= n;i++) {
            if(a[b[i]] == a[v.back()] + 1) {
                v.push_back(b[i]);
            }
            else if(a[b[i]] == 2) {
                u.push_back(b[i]);
            }
            else {
                w.push_back(b[i]);
            }
        }
        if(a[v.back()] >= k) {
            if(n == 2 && k == 2 && ((a[1] == 2 && a[2] == 2) || (a[1] != 2 && a[2] != 2))) {
                printf("1\n2 1 2\n");
                continue;
            }
            puts("-1");
            continue;
        }
        if(a[v.back()] == 1) {
            printf("%d\n", n - 1);
            printf("2 1 2\n");
            for(int i = 1;i <= n - 2;i++) {
                printf("2 %d %d\n", n + 2 * i, i + 2);
            }
            continue;
        }
        if(a[v.back()] == 2) {
            if(n % 2 == 1) {
                printf("%d\n", n / 2);
                printf("3 1 2 3\n");
                for(int i = 1;i <= n / 2 - 1;i++) {
                    printf("3 %d %d %d\n", n + 2 * i, 2 * i + 2, 2 * i + 3);
                }
            }
            else {
                printf("%d\n", n / 2);
                int p = 2;
                for(;p <= n;p++) {
                    if((a[1] == 2 && a[p] == 2) || (a[1] != 2 && a[p] != 2)) {
                        printf("2 %d %d\n", 1, p);
                        break;
                    }
                }
                if(p == n + 1) {
                    printf("2 2 3\n");
                    printf("3 %d 1 4\n", n + 2 - (a[2] == 2));
                    for(int i = 2;i <= n / 2 - 1;i++) {
                        printf("3 %d %d %d\n", n + 2 * i, 2 * i + 1, 2 * i + 2);
                    }
                }
                else {
                    for(int i = 1;i <= n / 2 - 1;i++) {
                        printf("3 %d %d %d\n", n + 2 * i - (i == 1 && a[1] == 2), 2 * i + (2 * i >= p), 2 * i + 1 + (2 * i + 1 >= p));
                    }
                }
            }
            continue;
        }
        int p1 = 1, p2 = 1;
        printf("%d\n", (u.size() - w.empty()) / 2 + w.size() - u.empty() + w.empty());
        if(u.empty()) {
            p1 = w[0];
            if(w.size() > 2) {
                p2 = n + (w.size() - 2) * 2;
                printf("2 %d %d\n", w[1], w[2]);
                for(int i = 1;i <= w.size() - 3;i++) {
                    printf("2 %d %d\n", n + i * 2, w[i + 2]);
                }
            }
            else {
                p2 = w[1];
            }
        }
        else if(w.empty()) {
            p1 = u[0];
            if(u.size() == 2) {
                p2 = u[1];
            }
            else if(u.size() == 3) {
                p2 = n + 1;
                printf("2 %d %d\n", u[1], u[2]);
            }
            else {
                p2 = n + (u.size() - 1) / 2 * 2;
                if(u.size() % 2 == 0) {
                    printf("3 %d %d %d\n", u[1], u[2], u[3]);
                    for(int i = 1;i <= (u.size() - 1) / 2 - 1;i++) {
                        printf("3 %d %d %d\n", n + 2 * i, u[2 * i + 2], u[2 * i + 3]);
                    }
                }
                else {
                    printf("2 %d %d\n", u[1], u[2]);
                    for(int i = 1;i <= (u.size() - 1) / 2 - 1;i++) {
                        printf("3 %d %d %d\n", n + 2 * i - (i == 1), u[2 * i + 1], u[2 * i + 2]);
                    }
                }
            }
        }
        else {
            if(w.size() == 1) {
                p2 = w[0];
            }
            else {
                p2 = n + (w.size() - 1) * 2;
                printf("2 %d %d\n", w[0], w[1]);
                for(int i = 1;i <= w.size() - 2;i++) {
                    printf("2 %d %d\n", n + 2 * i, w[i + 1]);
                }
            }
            if(u.size() == 1) {
                p1 = u[0];
            }
            else if(u.size() == 2) {
                p1 = n + (w.size() - 1) * 2 + 1;
                printf("2 %d %d\n", u[0], u[1]);
            }
            else {
                p1 = n + (w.size() - 1 + u.size() / 2) * 2;
                if(u.size() % 2 == 1) {
                    printf("3 %d %d %d\n", u[0], u[1], u[2]);
                    for(int i = 1;i <= u.size() / 2 - 1;i++) {
                        printf("3 %d %d %d\n", n + 2 * (w.size() - 1 + i), u[2 * i + 1], u[2 * i + 2]);
                    }
                }
                else {
                    printf("2 %d %d\n", u[0], u[1]);
                    for(int i = 1;i <= u.size() / 2 - 1;i++) {
                        printf("3 %d %d %d\n", n + 2 * (w.size() - 1 + i) - (i == 1), u[2 * i], u[2 * i + 1]);
                    }
                }
            }
        }
        printf("%d ", v.size() + 1);
        for(int i = 1;i < v.size();i++) {
            printf("%d ", v[i]);
        }
        printf("%d %d\n", p1, p2);
    }
    return 0;
}