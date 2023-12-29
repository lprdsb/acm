// 哀太可爱辣
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T, k, n, res, ans;
inline ll Q(ll x) {
    res = 0;
    while(x != 1) {
        if(x & 1)
            x++;
        else
            x >>= 1;
        res++;
    }
    return res;
}
inline bool check(ll x) {
    if(x & 1)
        x++;
    return (x & (-x)) == x;
}
int main() {
    scanf("%lld", &T);
    while(T--) {
        scanf("%lld%lld", &k, &n);
        if(!k)
            puts(n == 1 ? "Yes" : "No");
        else if(!n)
            puts("Yes");
        else if(n == 1)
            puts(k % 2 == 0 || k >= 5 && k % 2 ? "Yes" : "No");
        else {
            ans = Q(n);
            puts(ans > k || ans + 1 == k && check(n) ? "No" : "Yes");
        }
    }
    return 0;
}