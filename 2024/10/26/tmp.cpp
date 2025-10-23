#include<bits/stdc++.h>

using namespace std;

int l, r;
int p[30], q[30];
vector<vector<pair<int, int>>> ans;

int getp(int i) {
    if(i == 0) {
        return 0;
    }
    if(p[i] == 0) {
        p[i] = ans.size();
        ans.push_back({});
        ans[p[i]].push_back({ getp(i - 1), 0 });
        ans[p[i]].push_back({ getp(i - 1), 1 });
    }
    return p[i];
}

int main() {
    freopen("in.txt", "r", stdin);
    scanf("%d%d", &r, &l);
    ans.push_back({});
    ans.push_back({});
    int lb = 0;
    while(l >= (1 << lb + 1)) {
        lb++;
    }
    int rb = 0;
    while(r >= (1 << rb + 1)) {
        rb++;
    }
    for(int i = lb, lst = 1; i >= 0; i--) {
        int cur;
        if((l + 1) % (1 << i) == 0 && l + 1 - (1 << i) >= r) {
            cur = getp(i);
        }
        else {
            cur = ans.size();
            ans.push_back({});
        }
        q[i] = cur;
        ans[lst].push_back({ cur, (l >> i) & 1 });
        if(cur == p[i]) {
            break;
        }
        if(((l >> i) & 1) == 1 && l - l % (1 << i) - (1 << i) >= r) {
            printf("asd%d\n", ans[lst].size());
            // cout << getp(i) << endl;
            // cout << lst << " " << cur << endl;
            ans[lst].push_back({ getp(i), 0 });
            printf("asd%d\n", ans[lst].size());
        }
        lst = cur;
    }
    bool f = lb == rb;
    for(int i = rb, lst = 1; i >= 0; i--) {
        int cur;
        if(f && (l >> i) == (r >> i)) {
            cur = q[i];
        }
        else {
            f = false;
            if(r % (1 << i) == 0 && r + (1 << i) <= l + 1) {
                cur = getp(i);
            }
            else {
                cur = ans.size();
                ans.push_back({});
            }
            ans[lst].push_back({ cur, (r >> i) & 1 });
        }
        if(cur == p[i]) {
            break;
        }
        if(((r >> i) & 1) == 0 && r - r % (1 << i) + (1 << i + 1) < l + 1) {
            ans[lst].push_back({ getp(i), 1 });
        }
        lst = cur;
    }
    for(int i = rb + 1; i < lb; i++) {
        ans[1].push_back({ getp(i), 1 });
    }
    printf("%d\n", ans.size());
    for(int i = 1; i < ans.size(); i++) {
        printf("%d ", ans[i].size());
        for(auto pr : ans[i]) {
            printf("%d %d ", pr.first == 0 ? ans.size() : pr.first, pr.second);
        }
        printf("\n");
    }
    printf("0\n");
    return 0;
}