#include<bits/stdc++.h>

using std::pair;
using std::sort;

const int N = 1e6 + 10;

int n, m;
pair<int, int> pr[N];
int hd[N], nxt[N << 1], to[N << 1], cnte;
int ans;

void init() {
    for(int i = 0;i <= n;i++) {
        hd[i] = -1;
    }
}

void add_edge(int u, int v) {
    to[cnte] = v;
    nxt[cnte] = hd[u];
    hd[u] = cnte;
    cnte++;
}

bool cmp(pair<int, int> p1, pair<int, int> p2) {
    return p1.second < p2.second || (p1.second == p2.second && p1.first > p2.first);
}

int main() {
    scanf("%d%d", &n, &m);
    init();
    for(int i = 0;i < m;i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        if(u > v) {
            pr[i] = { v,u };
        }
        else {
            pr[i] = { u,v };
        }
    }
    sort(pr, pr + m, cmp);
    ans = n;
    for(int i = 1, j = 1, l = 0, k = 0;i <= n && k < m;i++) {
        while(pr[k].second < i) {
            k++;
        }
        j = i - 1;
        while(pr[k].second == i) {
            if(k >= m || pr[k].first != j || j < l) {
                l = j + 1;
                break;
            }
            else {
                ans++;
                k++;
                j--;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}