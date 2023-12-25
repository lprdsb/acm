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
#define maxn 10000000
using namespace std;

int pri[maxn + 5], cnt = 0, vis[maxn + 5], t, a[15];

template <class T>
void read(T &x){
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

bool chk(int x){
    if(x <= maxn) return !vis[x];
    else{
        For(i, 1, maxn){
            if(1ll * i * i > x) break;
            if(x % i == 0) return 0;
        }
        return 1;
    }
}

int main(){
    // freopen("in.txt", "r", stdin);
    For(i, 2, maxn){
        if(!vis[i]) pri[++cnt] = i;
        for(int j = 1; j <= cnt && i * pri[j] <= maxn; ++j){
            vis[i * pri[j]] = 1;
            if(i % pri[j] == 0) break;
        }
    }
    read(t);
    while(t--){
        For(i, 0, 8){
            char c; cin >> c;
            a[i] = c - '0';
        }
        int fl = 0;
        For(o, 0, (1 << 9) - 1){
            int cnt = 0 ;
            For(j, 0, 8) cnt += (o >> j) & 1;
            if(cnt <= 1) continue;
            int res = 0;
            For(j, 0, 8) if((o >> j) & 1) res = res * 10 + a[j];
            if(chk(res)){
                printf("%d\n", res);
                fl = 1;
                break;
            }
        }
        if(!fl) puts("-1");
    }
}
