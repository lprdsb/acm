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
#define maxn 2000000
using namespace std;

int n, a[maxn + 5], b[maxn + 5], bb[maxn + 5], cnt = 0;
LL as = 0;
vector<int> to[2][maxn + 5];

template <class T>
void read(T &x){
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

int main(){
    // freopen("in.txt", "r", stdin);
    read(n);
    For(i, 1, n) read(a[i]), bb[++cnt] = a[i];
    For(i, 1, n) read(b[i]), bb[++cnt] = b[i];
    sort(bb + 1, bb + cnt + 1);
    cnt = unique(bb + 1, bb + cnt + 1) - bb - 1;
    For(i, 1, n) a[i] = lower_bound(bb + 1, bb + cnt + 1, a[i]) - bb;
    For(i, 1, n) b[i] = lower_bound(bb + 1, bb + cnt + 1, b[i]) - bb;
    // For(i, 1, n) cout << a[i] << " "; cout << endl;
    For(i, 1, n){
        as += abs(bb[a[i]] - bb[b[i]]);
        if(a[i] <= b[i]) to[0][a[i]].pb(b[i]);
        else to[1][b[i]].pb(a[i]);
    }
    int mx[2] = {0, 0};
    LL asi = 0;
    For(i, 1, cnt){
        For(o, 0, 1) for(auto j : to[o][i]) mx[o] = max(mx[o], j);
        // if(i == 1) cout << bb[mx[0]] << " " << bb[mx[1]] << endl;
        if(mx[0] && mx[1]) asi = max(asi, 1ll * bb[min(mx[0], mx[1])] - bb[i]);
    }
    printf("%lld\n", as - 2 * asi);
    return 0;
}
