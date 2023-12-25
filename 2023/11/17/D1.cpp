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
#define maxn 30000000
#define maxm 3000000
using namespace std;

class Sieve{
    public:
        int pri[maxm + 5], cnt = 0, miu[maxn + 5];
        bool vis[maxn + 5];
        unordered_map<int, LL> sum_miu;
        Sieve(int lim){
            miu[1] = 1;
            For(i, 2, lim){
                if(!vis[i]) pri[++cnt] = i, miu[i] = -1;
                for(int j = 1; j <= cnt && i * pri[j] <= lim; ++j){
                    vis[i * pri[j]] = 1;
                    if(i % pri[j] == 0) break;
                    miu[i * pri[j]] = -miu[i];
                }
            }
            For(i, 1, lim) miu[i] += miu[i - 1];
        }
        LL get_s(LL x){
            if(x <= maxn) return miu[x];
            if(sum_miu.find(x) != sum_miu.end()) return sum_miu[x];
            LL asi = 1;
            For(i, 2, x){
                LL tem = x / i, to = x / tem;
                asi -= (to - i + 1) * get_s(tem);
                i = to;
            }
            return sum_miu[x] = asi;
        }
} sieve(maxn);

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

LL n, as = 0;

int main(){
	// freopen("in.txt", "r", stdin);
    // cout << sieve.get_s(4) << endl;
    read(n);
    LL pre = 0;
    For(i, 1, inf){
        LL tem = n / i / i;
        if(!tem) break;
        LL to = sqrt(n / tem), tem1 = sieve.get_s(to);
        cout << to << " " << tem1 << endl;
        as += tem * (tem1 - pre);
        pre = tem1;
        i = to;
    }
    printf("%lld\n", as);
	return 0;
}