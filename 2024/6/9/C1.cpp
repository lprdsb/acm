#include<bits/stdc++.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define Tra(u, i) for(int i = hd[u]; ~i; i = e[i].net)
#define cst const
#define LL long long
#define DD double
#define LD long double
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define inf 0x3f3f3f3f
#define Inf 0x3f3f3f3f3f3f3f3f
#define eps 1e-12
using namespace std;

template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

#define maxn 200000
int T, n, a[maxn + 5];
#define mod 998244353
void mian() {
    read(n);
    For(i, 1, n) read(a[i]);
    LL mn = 0, mx = 0, cmn = 1, cmx = 1;
    For(i, 1, n) {
        LL mni = Inf, mxi = -Inf, cmni = 0, cmxi = 0;

        LL tem = mn + a[i];
        if(tem < mni) {
            mni = tem;
            cmni = cmn;
        }
        else if(tem == mni) {
            cmni = (cmni + cmn) % mod;
        }
        if(tem > mxi) {
            mxi = tem;
            cmxi = cmn;
        }
        else if(tem == mxi) {
            cmxi = (cmxi + cmn) % mod;
        }

        tem = abs(mn + a[i]);
        if(tem < mni) {
            mni = tem;
            cmni = cmn;
        }
        else if(tem == mni) {
            cmni = (cmni + cmn) % mod;
        }
        if(tem > mxi) {
            mxi = tem;
            cmxi = cmn;
        }
        else if(tem == mxi) {
            cmxi = (cmxi + cmn) % mod;
        }

        if(mn != mx) {
            tem = mx + a[i];
            if(tem < mni) {
                mni = tem;
                cmni = cmx;
            }
            else if(tem == mni) {
                cmni = (cmni + cmx) % mod;
            }
            if(tem > mxi) {
                mxi = tem;
                cmxi = cmx;
            }
            else if(tem == mxi) {
                cmxi = (cmxi + cmx) % mod;
            }
            tem = abs(mx + a[i]);
            if(tem < mni) {
                mni = tem;
                cmni = cmx;
            }
            else if(tem == mni) {
                cmni = (cmni + cmx) % mod;
            }
            if(tem > mxi) {
                mxi = tem;
                cmxi = cmx;
            }
            else if(tem == mxi) {
                cmxi = (cmxi + cmx) % mod;
            }
        }

        mn = mni; mx = mxi;
        cmn = cmni; cmx = cmxi;
    }
    printf("%lld\n", cmx);
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
