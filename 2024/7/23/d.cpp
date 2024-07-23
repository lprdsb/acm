#include<bits/stdc++.h>

using std::sort;
using std::unique;
using std::lower_bound;
using std::vector;

const int N = 2e5 + 10;

int n;
int x[N], y[N];
int cnts, cntd;
int s[N * 2], t[N * 2];
int maxi;
int a[N * 2], la;

int main() {
    scanf("%d", &n);
    for(int i = 0;i < n;i++) {
        scanf("%d%d", &x[i], &y[i]);
        a[la++] = x[i];
        a[la++] = y[i];
    }
    sort(a, a + la);
    la = unique(a, a + la) - a;
    for(int i = 0;i < n;i++) {
        if(x[i] == y[i]) {
            s[lower_bound(a, a + la, x[i]) - a]++;
            cnts++;
        }
        else {
            t[lower_bound(a, a + la, x[i]) - a]++;
            t[lower_bound(a, a + la, y[i]) - a]++;
            cntd++;
        }
    }
    for(int i = 1;i < la;i++) {
        if(s[i] > s[maxi]) {
            maxi = i;
        }
    }
    if(s[maxi] <= cnts - s[maxi] + 1) {
        puts("Yes");
        vector<int> v[s[maxi]];
        for(int i = 0, cur = 0;i < la;i++) {
            if(i == maxi) {
                continue;
            }
            for(int j = 0;j < s[i];j++) {
                v[cur].push_back(i);
                cur = (cur + 1) % s[maxi];
            }
        }
        int lst;
        for(int i = 0;i < s[maxi];i++) {
            printf("%d %d\n", a[maxi], a[maxi]);
            lst = a[maxi];
            for(int j = 0;j < v[i].size();j++) {
                printf("%d %d\n", a[v[i][j]], a[v[i][j]]);
                lst = a[v[i][j]];
            }
        }
        for(int i = 0;i < n;i++) {
            if(x[i] == y[i]) {
                continue;
            }
            if(x[i] != lst) {
                printf("%d %d\n", x[i], y[i]);
                lst = y[i];
            }
            else {
                printf("%d %d\n", y[i], x[i]);
                lst = x[i];
            }
        }
    }
    else if(s[maxi] * 2 - cnts - 1 <= cntd - t[maxi]) {
        puts("Yes");
        for(int i = 0, cur = 0;i < cnts - s[maxi];i++) {
            printf("%d %d\n", a[maxi], a[maxi]);
            while(cur == maxi || s[cur] == 0) {
                cur++;
            }
            printf("%d %d\n", a[cur], a[cur]);
            s[cur]--;
        }
        printf("%d %d\n", a[maxi], a[maxi]);
        int lst = a[maxi];
        s[maxi] -= cnts - s[maxi] + 1;
        for(int i = 0;i < n;i++) {
            if(x[i] == y[i]) {
                continue;
            }
            if(x[i] != lst) {
                printf("%d %d\n", x[i], y[i]);
                lst = y[i];
            }
            else {
                printf("%d %d\n", y[i], x[i]);
                lst = x[i];
            }
            if(s[maxi] > 0 && lst != a[maxi]) {
                printf("%d %d\n", a[maxi], a[maxi]);
                s[maxi]--;
                lst = a[maxi];
            }
        }
    }
    else {
        puts("No");
    }
    return 0;
}