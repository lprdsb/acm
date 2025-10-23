#include<bits/stdc++.h>
using namespace std;
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define LL long long
#define LLL __int128_t

int T;

void out(LLL x) {
    if(x < 0) printf("-"), x *= -1;
    vector<int> vec;
    while(x) vec.push_back(x % 10), x /= 10;
    reverse(vec.begin(), vec.end());
    for(auto v : vec) printf("%d", v);
}

void mian() {
    LL x; scanf("%lld", &x);
    LLL res = x;
    if(res == 0) puts("10");
    else {
        LLL tmp = res, pw = 1, fl = 0;
        For(i, 1, 25) {
            if(abs(tmp) < pw / 10) break;
            if(x < 0) {
                LLL l = tmp / pw, r = tmp % pw;
                LLL now = l * 10 * pw - pw + r;
                if(!fl || now > res) {
                    res = now;
                    fl = 1;
                }
            }
            else {
                LLL l = tmp / pw, r = tmp % pw;
                LLL now = l * 10 * pw + pw + r;
                // cout << (LL)l << " " << (LL)r << endl;
                if(!fl || now > res) {
                    res = now;
                    fl = 1;
                }
            }
            pw *= 10;
        }
        out(res); puts("");
    }
}

int main() {
    scanf("%d", &T);
    while(T--) {
        mian();
    }
}