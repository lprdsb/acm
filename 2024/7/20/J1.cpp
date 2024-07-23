#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 998244353;
inline int add(int x, int y) {
    x += y;
    return x >= mod ? x - mod : x;
}
inline void addto(int& x, int y) {
    x += y;
    if(x >= mod) x -= mod;
}
inline int mul(int x, int y) { return 1ll * x * y % mod; }
int main() {
    freopen("in.txt", "r", stdin);
    // ll n;
    // int a=5;
    // // cin>>n>>a;
    // int cura=0,curb=1;
    // int lasta=1,lastb=0;
    // int nxta,nxtb;
    // for(int i=2;i<=mod+1;i++){
    //     nxta=(1ll*cura*a+1ll*(i-1)*lasta)%mod;
    //     nxtb=(1ll*curb*a+1ll*(i-1)*lastb)%mod;
    //     lasta=cura,lastb=curb;
    //     cura=nxta,curb=nxtb;
    // }
    // cout<<cura<<" "<<curb<<"\n";
    ll n;
    int a;
    cin >> n >> a;
    int nmod = n % mod;
    int res = 1;
    if(nmod == 0) {
        res = 1;
    }
    else if(nmod == 1) {
        res = a;
    }
    else {
        int cur = a, la = 1, t1, t2;
        int as = mul(a, a);
        int _2a = add(a, a);
        int a_i_2 = a;
        for(int i = 3; i <= nmod; i += 2) {
            t1 = (1ll * cur * a + 1ll * (i - 2) * la) % mod;
            t2 =
                (1ll * as * cur + 1ll * (i - 1) * cur + 1ll * a_i_2 * la) % mod;
            la = t1;
            cur = t2;
            addto(a_i_2, _2a);
        }
        if(nmod % 2 == 0)
            res = (1ll * cur * a + 1ll * (nmod - 1) * la) % mod;
        else
            res = cur;
    }
    while(n != nmod) {
        n -= mod;
        res = mul(res, a);
    }
    cout << res;
    return 0;
}