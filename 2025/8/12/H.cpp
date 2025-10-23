#include<bits/stdc++.h>
using namespace std;
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define inf 0x3f3f3f3f
#define Inf 0x3f3f3f3f3f3f3f3f
#define LL long long

#define maxn 100000
int n, L[maxn + 5], R[maxn + 5], year[maxn + 5];
int month[13] = { 0, 31, 28, 31, 30, 31, 30, 31,31, 30, 31, 30, 31 };

int chk(int x) {
    if(x % 4 == 0) {
        if(x % 100 == 0) return x % 400 == 0;
        return 1;
    }
    return 0;
}

int id[maxn + 5];
int main() {
    // freopen("in.txt", "r", stdin);
    For(i, 0, 9999) year[i] = year[i - 1] + 365 + chk(i);
    scanf("%d", &n);
    For(i, 1, n) {
        int y, m, d, h, mm, s;
        scanf("%4d-%2d-%2d %2d:%2d:%2d", &y, &m, &d, &h, &mm, &s);
        int tmp = year[y - 1];
        For(j, 1, m - 1) tmp += month[j] + (j == 2 && chk(y));
        tmp += d; L[i] = R[i] = tmp;
        if(h < 20) L[i]--;
        if(h >= 18) R[i]++;
    }
    int to[4] = { -inf, -inf, -inf, -inf }, now = -1, mx = 0;
    For(i, 1, n) {
        // cout << L[i] << " " << R[i] << endl;
        if(now != L[i] - 1) {
            if(L[i] - 1 - now <= 5) {
                For(j, 1, L[i] - 1 - now) {
                    For(j, 0, 2) to[j] = to[j + 1];
                    to[3] = -inf;
                }
            }
            else For(j, 0, 3) to[j] = -inf;
            now = L[i] - 1;
        }
        Rof(j, R[i] - L[i], 0) {
            to[j + 1] = max(max(1, to[j] + 1), to[j + 1]);
            mx = max(mx, to[j + 1]);
        }
        // mx = max(mx, )
    }
    cout << mx << " " << 1 << endl;
}