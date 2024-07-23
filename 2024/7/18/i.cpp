#include<bits/stdc++.h>

using std::vector;
using std::max;

const int N = 3e3 + 10;

int n;
int a[N << 1];
int b[N][2];
int f[N << 1];
vector<int> v;

int main() {
    scanf("%d", &n);
    for(int i = 1;i <= n * 2;i++) {
        scanf("%d", &a[i]);
        if(b[a[i]][0] > 0) {
            b[a[i]][1] = i;
        }
        else {
            b[a[i]][0] = i;
        }
    }
    v.push_back(0);
    for(int i = 1;i <= n * 2;i++) {
        if(a[v.back()] == a[i]) {
            i = v.back();
            v.pop_back();
            f[v.back()] = max(f[v.back()], f[i] + (a[i] - a[v.back()]) * (b[a[i]][1] - i + 1));
            int j = i++;
            while(i <= n * 2 && (i == b[a[i]][1] || (i < b[a[j]][1] && b[a[j]][1] < b[a[i]][1]))) {
                i++;
            }
            if(i > n * 2) {
                break;
            }
        }
        if(i == b[a[i]][0] && a[v.back()] < a[i]) {
            v.push_back(i);
        }
    }
    return 0;
}