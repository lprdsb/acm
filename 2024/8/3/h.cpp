#include<bits/stdc++.h>

typedef long long ll;

const int N = 1e5 + 10;

int n, cnt[N][2], tot[2];
char s[N << 1];

int main() {
    scanf("%d", &n);
    for(int i = 0;i < n;i++) {
        scanf("%s", s);
        for(int j = 0;s[j];j++) {
            if(s[j] == '0') {
                cnt[i][0]++;
            }
            else {
                cnt[i][1]++;
            }
        }
        tot[0] += cnt[i][0];
        tot[1] += cnt[i][1];
    }
    if(tot[0] == 0 || tot[1] == 0) {
        printf("0");
        return 0;
    }
    bool f = false, g = false;
    ll ans = 0;
    int fi = 0, gi = 0;
    for(int i = 0;i < n;i++) {
        if(cnt[i][0] == cnt[i][1]) {
            f = true;
            g = true;
            ans += cnt[i][0];
        }
        else if(cnt[i][0] < cnt[i][1]) {
            f = true;
            ans += cnt[i][0];
        }
        else {
            g = true;
            ans += cnt[i][1];
        }
        if(cnt[i][0] - cnt[i][1] < cnt[fi][0] - cnt[fi][1]) {
            fi = i;
        }
        if(cnt[i][1] - cnt[i][0] < cnt[gi][1] - cnt[gi][0]) {
            gi = i;
        }
    }
    if(f == false) {
        ans += cnt[fi][0] - cnt[fi][1];
    }
    if(g == false) {
        ans += cnt[gi][1] - cnt[gi][0];
    }
    printf("%lld", ans);
    return 0;
}