#include<bits/stdc++.h>
#define fs(i,x,y) for(int i=(x),_=(y);i<=_;++i)
#define fn(i,x,y) for(int i=(x),_=(y);i>=_;--i)
#define tor(i,v,u) for(int i=head[u],v=to[i];i;i=nxt[i],v=to[i])
#define pi pair<int,int>
#define fi first
#define se second
#define mpi(x,y) make_pair(x,y)
using namespace std;
typedef long long ll;

const int N = 2e5 + 7, P = 998244353;
int n;
int a[N], b[N], vis[N];
int bas[N], dim;

int qw(int a, int b) {
    int ans = 1;for(;b;a = (ll)a * a % P, b >>= 1)if(b & 1)ans = (ll)ans * a % P;
    return ans;
}

int ffl[N];
int ins(int x) {
    int tem = 1;
    fn(i, 29, 0) {
        if((x >> i) & 1) {
            if(bas[i])x ^= bas[i], tem ^= ffl[i];
            else {
                bas[i] = x;
                ffl[i] = tem;
                return 1;
            }
        }
    }
    return 0;
}

int chk(int x) {
    int cnt = 0, tem = 0;
    fn(i, 29, 0) {
        if((x >> i) & 1) {
            if(bas[i]) {
                x ^= bas[i], ++cnt;
                tem ^= ffl[i];
            }
        }
    }
    return tem;
}

void solve() {
    scanf("%d", &n);
    fs(i, 1, n) {
        scanf("%d", &a[i]);
        vis[i] = ins(a[i]);
    }
    fs(i, 0, 29)if(bas[i])++dim;
    if(dim == 0) {
        printf("1\n");
        return;
    }
    int res = 1;
    int fl = 0;
    fs(i, 1, n) if(!vis[i]) {
        if(chk(a[i]) % 2 == 1);
        else fl = 1;
    }
    if(fl) res = 1ll * res * qw(2, dim * (dim - 1) / 2 + 1ll * dim * (n - dim) % (P - 1)) % P;
    else res = 1ll * res * qw(2, dim * (dim - 1) / 2 + 1ll * (dim - 1) * (n - dim) % (P - 1)) % P;
    cout << res << endl;
}

signed main() {
    solve();
}