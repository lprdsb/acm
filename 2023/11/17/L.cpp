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

int T, n, m;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

vector<pair<int, int> > vec;
int mul[105];

void exgcd(LL a, LL &x, LL b, LL &y){
    if(!b){
        x = 1;
        y = 0;
        return;
    }
    LL xx, yy;
    exgcd(b, xx, a % b, yy);
    x = yy;
    y = xx - a / b * yy;
}

vector<int> as;
void dfs(int pos, int now){
    // if(now == 3) cout << "asd" << endl;
    if(pos == vec.size()){
        LL x, y;
        exgcd(now, x, m / now, y);
        x %= (m / now);
        if(x < 0) x += m / now;
        while(1ll * x * now < m){
            as.pb(x * now);
            x += m / now;
            // cout << 1ll * x * now * (x * now - 1) % m << endl;
        }
        return;
    }
    dfs(pos + 1, now);
    LL tem = 1ll * now * mul[pos];
    if(tem >= m) return;
    dfs(pos + 1, tem);
}

int main(){
	// freopen("in.txt", "r", stdin);
    read(T);
    while(T--){
        read(n); m = n;
        For(i, 2, inf){
            if(i * i > n) break;
            if(n % i == 0){
                int cnt = 0, tem = 1;
                while(n % i == 0){
                    cnt++;
                    n /= i;
                    tem *= i;
                }
                vec.pb({i, cnt});
                mul[vec.size() - 1] = tem;
            }
        }
        if(n != 1){
            vec.pb({n, 1});
            mul[vec.size() - 1] = n;
        }
        // for(auto [u, v] : vec) cout << u << " " << v << endl;
        // cout << mul[1] << endl;
        dfs(0, 1);
        sort(as.begin(), as.end());
        printf("%d\n", as.size() + (as[0] != 0));
        if(as[0]) printf("0 ");
        for(auto i : as) printf("%d ", i); puts("");
        as.resize(0);
        vec.resize(0);
    }
    return 0;
}
