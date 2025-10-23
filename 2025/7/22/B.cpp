#include<bits/stdc++.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define LL long long
#define pb push_back
using namespace std;

int T;
LL a, b, c, ta, tb;

vector<int> as;

int up(LL x) {
    if(!x) return 0;
    // cout << 64 - __builtin_clzll((unsigned LL)x) << endl;
    return 64 - __builtin_clzll((unsigned LL)x);
}

void mian() {
    scanf("%lld%lld%lld", &a, &b, &c); ta = a; tb = b;
    if(!a && !b) {
        if(c) puts("-1");
        else puts("0");
        return;
    }
    as.resize(0);
    // cout << b << " " << up(b) << " " << 64 - __builtin_clzll(0) << endl;
    if(up(a) > up(b)) {
        as.pb(4);
        b = a ^ b;
    }
    // cout << a << " asd " << b << endl;
    if(up(c) > up(b)) {
        int k = up(c) - up(b);
        // cout << up(c) << endl;
        For(o, 1, k) {
            if(((c >> (up(c) - o)) & 1) ^ ((a >> (up(b) - 1)) & 1)) {
                as.pb(3);
                a ^= b;
                // cout << a << " " << b << endl;
            }
            as.pb(1);
            a *= 2;
        }
    }
    int k = up(b);
    Rof(o, k, 1) {
        if((((a ^ c) >> (o - 1)) & 1)) {
            as.pb(3);
            a ^= b;
        }
        as.pb(2);
        b >>= 1;
    }
    as.pb(4);
    printf("%d\n", as.size());
    for(auto o : as) {
        printf("%d ", o);
        if(o == 1) ta *= 2;
        if(o == 2) tb /= 2;
        if(o == 3) ta = ta ^ tb;
        if(o == 4) tb = ta ^ tb;
    }
    puts("");
    // cout << ta << " " << tb << endl;
    // cout << a << " " << b << endl;
}

int main() {
    // cout << up(0x3FFFFFFF) << " " << 0x3FFFFFFF << endl;
    // freopen("in.txt", "r", stdin);
    // cout << 0b001 << endl;
    scanf("%d", &T);
    while(T--) {
        mian();
    }
}