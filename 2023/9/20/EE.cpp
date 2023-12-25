#include<bits/stdc++.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define Tra(u, i) for(int i = hd[u]; ~i; i = e[i].net)
#define cst const
#define LL long long
#define i128 __int128_t
#define DD double
#define LD long double
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define inf 0x3f3f3f3f
#define Inf 0x3f3f3f3f3f3f3f3f
#define eps 1e-12
#define mod 998244353
using namespace std;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

LL fp(LL x, LL y, LL P){
    LL res = 1;
    while(y){
        if(y & 1) res = (i128)res * x % P;
        x = (i128)x * x % P;
        y >>= 1;
    }
    return res;
}

LL gcd(LL x, LL y){return y ? gcd(y, x % y) : x;}

int Miller_Rabin(LL x){
    if(x < 3 || x % 2 == 0) return x == 2;
    LL u = x - 1, pri_bas[8] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    int t = 0;
    while(u % 2 == 0) u >>= 1, t++;
    For(o, 0, 6){
        LL now = fp(pri_bas[o], u, x);
        if(now <= 1) continue;
        For(i, 1, t){
            if(now == x - 1) break;
            if(i == t) return 0;
            now = (i128)now * now % x;
            if(now == 1) return 0;
        }
    }
    return 1;
}

LL Pollard_Rho(LL x){
    if(x == 4) return 2;
    if(Miller_Rabin(x)) return x;
    default_random_engine de;
    uniform_int_distribution<LL> rd(1, x - 1);
    while(666){
        LL c = rd(de);
        auto f = [&](LL _x){return ((i128)_x * _x + c) % x;};
        LL s = 0, t = 0;
        while(666){
            LL p = 1;
            For(i, 1, 128){
                s = f(s);
                t = f(f(t));
                if(s == t) break;
                LL tem = (i128)p * abs(s - t) % x;
                if(!tem) break;
                p = tem;
            }
            LL gc = gcd(p, x);
            if(gc > 1) return gc;
            if(s == t) break;
        }
    }
}

int T;
LL n;
map<LL, int> pri;
void work(LL x){
    queue<pair<LL, int> > q;
    q.push({x, 1});
    while(q.size()){
        pair<LL, int> now = q.front(); q.pop();
        LL tem = Pollard_Rho(now.fir);
        if(tem == now.fir) pri[tem] += now.sec;
        else{
            int cnt = 0;
            while(now.fir % tem == 0) now.fir /= tem, cnt++;
            if(now.fir != 1) q.push({now.fir, now.sec});
            q.push({tem, now.sec * cnt});
        }
    }
}

map<LL, bool> d;
void find(LL x){
    if(d[x]) return;
    d[x] = 1;
    for(auto [k, v] : pri) if(x % k == 0) find(x / k);
}

int get_phi(LL x){
    LL res = x;
    for(auto [k, v] : pri) if(x % k == 0) res = res / k * (k - 1);
    return res % mod;
}

map<LL, int> sum;

int main(){
    // freopen("in.txt", "r", stdin);
    read(T);
    For(_, 1, T){
        read(n);
        work(n - 1);
        find(n - 1);
        for(auto [k, v] : d) sum[k] = 1ll * k % mod * get_phi((n - 1) / k) % mod;
        for(auto [pk, pv] : pri) for(auto [sk, sv] : sum) if(sk % pk == 0)
            sum[sk] = (sum[sk] + 1ll * sum[sk / pk] % mod) % mod;
        int res = 0;
        for(auto [k, v] : d) res = (res + 1ll * get_phi((n - 1) / k) * sum[k] % mod * sum[k] % mod) % mod;
        n %= mod;
        printf("%d\n", (1ll * (n - 1) * (n - 1) % mod + res) % mod);
        pri.clear();
        d.clear();
        sum.clear();
    }
    return 0;
}
