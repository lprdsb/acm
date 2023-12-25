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
#define maxn 10000
#define mod 998244353
using namespace std;

int pri[maxn + 5], vis[maxn + 5], cnt = 0, to[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int n, w, ok[maxn + 5], res = 1;
multiset<int> se[maxn + 5];

int main(){
	// freopen("in.txt", "r", stdin);
    For(i, 2, maxn){
        if(!vis[i]) pri[++cnt] = i, to[i] = i;
        for(int j = 1; j <= cnt && pri[j] * i <= maxn; ++j){
            vis[i * pri[j]] = 1;
            to[i * pri[j]] = pri[j];
            if(i % pri[j] == 0) break;
        }
    }
    read(n); read(w);
    while(w != 1) ok[to[w]]++, w /= to[w];
    For(i, 1, n){
        int x; read(x);
        while(x != 1){
            int tem = to[x], cnt = 0;
            while(x % tem == 0){
                x /= tem;
                cnt++;
            }
            if(!ok[tem]) res = 1ll * res * (cnt + 1) % mod;
            else se[tem].insert(cnt + 1);
        }
    }
    For(i, 2, maxn) if(ok[i]){
        while(se[i].size() < n) se[i].insert(1);
        // if(i == 2){
        //     for(auto j : se[i]) cout << j << " "; cout << endl;
        // }
        while(ok[i]){
            auto it = se[i].begin();
            int tem = *it + 1;
            se[i].erase(it);
            se[i].insert(tem);
            ok[i]--;
        }
        for(auto j : se[i]) res = 1ll * res * j % mod;
    }
    printf("%d\n", res);
    return 0;
}
