#include<bits/stdc++.h>
using namespace std;
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define LL long long

int n = 30, m = 4, a[105][105];

int main() {
    For(i, 1, n) {
        For(j, i - m, i - 1) {
            For(p, 1, i) a[i][p] -= a[j][p];
        }
        a[i][i] = 1;
        For(j, 1, i) {
            int tmp = 0;
            For(p, 1, i) tmp += a[p][j];
            cout << tmp << " ";
        }
        cout << endl;
    }
}