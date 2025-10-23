#include<bits/stdc++.h>
using namespace std;
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define cst const
#define LL long long

#define maxn 200000
int T, n, y, M, L[maxn + 5];
vector<int> A[maxn + 5];
LL inf = 0x3f3f3f3f;

int chk(int k, int lim) {
    int now = k;
    For(i, 1, n) {
        int kk = 1, nowi = 0;
        for(auto j : A[i]) {
            if(j >= now) return 0;
            nowi = min(nowi + 1ll * kk * j, inf);
            kk = min(1ll * kk * now, inf);
        }
        now = nowi;
        // cout << now << endl;
    }
    return now >= lim;
}

int find(int x) {
    int l = 2, r = M + 1;
    while(l < r) {
        int md = l + r >> 1;
        if(chk(md, x)) r = md;
        else l = md + 1;
    }
    return l;
}

void mian() {
    scanf("%d%d%d", &n, &y, &M);
    For(i, 1, n) {
        scanf("%d", &L[i]);
        A[i].resize(L[i]);
        // cout << L[i] << endl;
        For(j, 1, L[i]) scanf("%d", &A[i][L[i] - j]);
    }
    // cout << find(y + 1) << endl;
    int L = find(y), R = find(y + 1) - 1;
    // cout << L << " " << R << endl;
    if(L <= R) cout << L << " " << R << endl;
    else puts("-1 -1");

}

int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%d", &T);
    while(T--) {
        mian();
        For(i, 1, n) A[i].resize(0);
    }
}