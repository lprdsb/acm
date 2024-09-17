#include<bits/stdc++.h>

using namespace std;
int x0[10], x1[10], lv[10], cnt[10];
int bs[10][10][10] = {
    {},
    {
        {10, 0, 5, 0, 0, 2},
        {0, 9, 0, 4, 0, 2},
        {0, 5, 8, 0, 0, 2},
        {4, 0, 4, 8, 0, 2},
        {2, 0, 0, 0, 9, 4}
    },
    {
        {11, 0, 5, 0, 0, 2},
        {0, 10, 0, 4, 0, 2},
        {0, 5, 9, 0, 0, 2},
        {4, 0, 4, 9, 0, 2},
        {2, 0, 0, 0, 10, 4},
    },
    {
        {12, 0, 5, 0, 0, 2},
        {0, 11, 0, 4, 0, 2},
        {0, 6, 10, 0, 0, 2},
        {4, 0, 4, 10, 0, 2},
        {3, 0, 0, 0, 11, 4},
    },
    {
        {13, 0, 5, 0, 0, 2},
        {0, 12, 0, 4, 0, 2},
        {0, 6, 11, 0, 0, 2},
        {4, 0, 4, 11, 0, 2},
        {3, 0, 0, 0, 12, 4},
    },
    {
        {14, 0, 5, 0, 0, 2},
        {0, 13, 0, 4, 0, 2},
        {0, 7, 12, 0, 0, 2},
        {5, 0, 5, 12, 0, 2},
        {4, 0, 0, 0, 13, 4},
    },
};
struct SC {
    int fri, drv, trn, x0[10], x1[10];
} sc[10];
int n, m;
double coef[5] = { -0.2, -0.1, 0, 0.1, 0.2 };
int sum, wgh, drv, type;
vector<pair<int, int>> p(10);

void update() {
    for(int i = wgh;i < 6;i++) {
        double delta = 1, tmp = 0;
        for(auto [j, _] : p) {
            tmp += sc[j].x1[i];
        }
        delta *= bs[max(sum * 5, lv[type])][type][i] + tmp;
        for(auto [j, f] : p) {
            delta *= 1 + 0.01 * f * sc[j].fri;
        }
        tmp = 1;
        for(auto [j, _] : p) {
            tmp += 0.01 * sc[j].trn;
        }
        delta *= tmp;
        tmp = 1;
        for(auto [j, _] : p) {
            tmp += 0.01 * sc[j].drv;
        }
        delta *= 1 + coef[drv] * tmp;
        delta *= 1 + 0.01 * x1[i];
        delta *= 1 + p.size() * 0.05;
        if(i == 5) {
            x0[i] += (int)delta;
        }
        else {
            x0[i] = (int)min(1200.0, x0[i] + delta);
        }
    }
    if(sum) {
        return;
    }
    cnt[type]++;
    if(cnt[type] == 4) {
        cnt[type] = 0;
        if(lv[type] < 5) {
            lv[type]++;
        }
    }
}

int main() {
    for(int i = 0;i < 5;i++) {
        scanf("%d", &x0[i]);
    }
    x0[5] = 120;
    for(int i = 0;i < 5;i++) {
        scanf("%d", &x1[i]);
    }
    for(int i = 0;i < 5;i++) {
        lv[i] = 1;
    }
    for(int i = 1;i <= 6;i++) {
        scanf("%d%d%d", &sc[i].fri, &sc[i].drv, &sc[i].trn);
        for(int j = 0;j < 5;j++) {
            scanf("%d", &sc[i].x0[j]);
            x0[j] = min(1200, x0[j] + sc[i].x0[j]);
        }
        for(int j = 0;j < 5;j++) {
            scanf("%d", &sc[i].x1[j]);
        }
    }
    scanf("%d", &n);
    while(n--) {
        scanf("%d%d%d%d%d", &sum, &wgh, &drv, &type, &m);
        p.clear();
        while(m--) {
            int idx, fri;
            scanf("%d%d", &idx, &fri);
            p.push_back({ idx, fri });
        }
        update();
        for(int i = 0;i < 6;i++) {
            printf("%d ", x0[i]);
        }
        printf("\n");
    }
    return 0;
}