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
#define maxn 100000
using namespace std;

int T, n, q;
LL a[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

set<int> se[2];
LL sum[2];
void ins(int x, int v){
    if(se[0].find(x) != se[0].end()){
        auto it = se[0].find(x);
        auto pre = it, suf = it; pre--; suf++;
        sum[0] += (a[*pre] - a[x]) * (*suf - x);
        se[0].erase(it);
    }

    if(se[1].find(x) != se[1].end()){
        auto it = se[1].find(x);
        auto pre = it, suf = it; pre--; suf++;
        sum[1] += (a[*suf] - a[x]) * (x - *pre);
        se[1].erase(it);
    }

    a[x] += v;

    int pre = *(--se[0].lower_bound(x));
    while(666){
        auto it = se[0].lower_bound(x);
        if(*it == n + 1 || a[*it] > a[x]) break;
        auto suf = it; suf++;
        sum[0] += (a[pre] - a[*it]) * (*suf - *it);
        se[0].erase(it);
    }
    if(a[x] > a[pre]){
        auto it = se[0].lower_bound(x);
        sum[0] += (a[x] - a[pre]) * (*it - x);
        se[0].insert(x);
    }

    int suf = *se[1].lower_bound(x);
    while(666){
        auto it = --se[1].lower_bound(x);
        if(*it == 0 || a[*it] > a[x]) break;
        auto pre = it; pre--;
        sum[1] += (a[suf] - a[*it]) * (*it - *pre);
        se[1].erase(it);
    }
    if(a[x] > a[suf]){
        auto it = --se[1].lower_bound(x);
        sum[1] += (a[x] - a[suf]) * (x - *it);
        se[1].insert(x);
    }
}

int st[maxn + 5];
LL as[maxn + 5];
int main(){
	// freopen("in.txt", "r", stdin);
    read(T);
    while(T--){
        read(n);
        LL sa = 0, mx = 0;
        se[0].insert(0); se[0].insert(n + 1);
        se[1].insert(0); se[1].insert(n + 1);
        For(i, 1, n){
            int x; read(x);
            ins(i, x);
            sa += a[i];
            mx = max(mx, a[i]);
        }
        read(q);
        For(i, 1, q){
            int x, v; read(x); read(v);
            ins(x, v);
            sa += v;
            mx = max(mx, a[x]);
            printf("%lld\n", sum[0] + sum[1] - 1ll * n * mx - sa);
        }
        For(i, 1, n) a[i] = 0;
        se[0].clear(); sum[0] = 0;
        se[1].clear(); sum[1] = 0;
    }
}
