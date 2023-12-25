#include<bits/stdc++.h>
#define For(i, a, b) for(LL i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(LL i = (a), en = (b); i >= en; --i)
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
#define maxn 1000000
#define maxm 1000000000ll
using namespace std;

int pri[maxn + 5], cnt = 0, vis[maxn + 5];

class Sieve{
    public:
        int to[maxn + 5], tot = 0, k_n[maxn + 5];
        LL N, sum_f_p[maxn + 5];
        map<int, int> id;
        vector<LL> F[maxn + 5], vF[maxn + 5], G[maxn + 5], vG[maxn + 5];
        LL get_f(LL x){
            //
        }
        LL get_g(LL x){
            //
        }
        Sieve(){}
        LL sol(LL _N){
            N = _N;
            tot = 0;
            For(i, 1, N){
                ++tot;
                id[to[tot] = N / i] = tot;
                i = N / (N / i);
            }
            int now = cnt;
            For(i, 1, tot){
                while(1ll * pri[now] * pri[now] > to[i]) now--;
                F[i].clear();
                F[i].resize(now + 5, 0);
                vF[i].clear();
                vF[i].resize(now + 5, 0);
                G[i].clear();
                G[i].resize(now + 5, 0);
                vG[i].clear();
                vG[i].resize(now + 5, 0);
                k_n[i] = now;
            }
            For(i, 1, cnt) sum_f_p[i] = sum_f_p[i - 1] + get_g(pri[i]);
            return get_F(1, 1);
        }
        LL get_G(int n_id, int k){
            if(pri[k] > to[n_id]) return get_g(1);
            if(k == 1) return to[n_id];
            if(1ll * pri[k - 1] * pri[k - 1] > to[n_id]) return get_G(n_id, k_n[n_id] + 1) - (sum_f_p[k - 1] - sum_f_p[k_n[n_id]]);
            if(vG[n_id][k]) return G[n_id][k];
            vG[n_id][k] = 1;
            LL asi = get_G(n_id, k - 1) - get_g(pri[k - 1]) * get_G(id[to[n_id] / pri[k - 1]], k - 1);
            return G[n_id][k] = asi;
        }
        LL get_F(int n_id, int k){
            if(1ll * pri[k] * pri[k] > to[n_id]) return 2 - get_G(n_id, k);
            if(vF[n_id][k]) return F[n_id][k];
            vF[n_id][k] = 1;
            LL now = 1, asi = 0;
            For(i, 0, inf){
                if(!(to[n_id] / now)) break;
                asi += get_f(now) * get_F(id[now], k + 1);
                now *= pri[k];
            }
            return F[n_id][k] = asi;
        }
} sieve;

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
    For(i, 2, maxn){
        if(!vis[i]) pri[++cnt] = i;
        for(int j = 1; j <= cnt && i * pri[j] <= maxn; ++j){
            vis[i * pri[j]] = 1;
            if(i % pri[j] == 0) break;
        }
    }
	return 0;
}
