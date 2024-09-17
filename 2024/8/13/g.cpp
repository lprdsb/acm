#include<bits/stdc++.h>

using namespace std;

int t;
int n, k;

int h;
vector<int> v;
vector<vector<int>> ans;

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &k);
        ans.resize(n + (n - 1) / k);
        v.clear();
        h = 0;
        for(int i = 1; i <= n + (n - 1) / k; i++) {
            ans[i - 1].clear();
            if(n - k * i + 1 >= 1) {
                v.push_back(n - k * i + 1 - i);
            }
            else if(n - k * (i - 1) + 1 > 1) {
                v.push_back(1 - i);
            }
            if(h < v.size() && v[h] + i> n) {
                h++;
            }
            for(int j = h; j < v.size(); j++) {
                ans[i - 1].push_back(v[j] + i);
            }
        }
        printf("%d\n", ans.size());
        for(auto i : ans) {
            printf("%d", i.size());
            for(int j = i.size() - 1;j >= 0;j--) {
                printf(" %d", i[j]);
            }
            printf("\n");
        }
        ans.resize(2 * n - 1);
        for(int i = 0;i < 2 * n - 1;i++) {
            ans[i].clear();
            for(int j = n - (i % 2);j >= 1 && j >= max(n - i, i - n + 2);j -= 2) {
                ans[i].push_back(j);
            }
        }
        printf("%d\n", ans.size());
        for(auto i : ans) {
            printf("%d", i.size());
            for(int j = i.size() - 1;j >= 0;j--) {
                printf(" %d", i[j]);
            }
            printf("\n");
        }
    }
    return 0;
}