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
#define maxn 1000
using namespace std;

int n, k, a[maxn + 5], as = inf;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

multiset<int> se[2];
int main(){
	//freopen("in", "r", stdin);
    read(n); read(k);
    For(i, 1, n) read(a[i]);
    For(l, 1, n){
        se[0].clear(); se[1].clear();
        int now = 0, cnt = 0;
        For(r, l, n){
            if(a[r] >= 0) now += a[r], cnt++;
            else se[0].insert(-a[r]);
            if(se[1].size()){
                cnt--;
                se[0].insert(-*se[1].begin());
                se[1].erase(se[1].begin());
            }
            while(se[0].size() && now - *se[0].begin() >= k){
                now -= *se[0].begin();
                cnt++;
                se[1].insert(-*se[0].begin());
                se[0].erase(se[0].begin());
            }
            if(now >= k && cnt) as = min(as, (r - l) * 2 - cnt + 1);
        }
    }
    printf("%d\n", as == inf ? -1 : as);
    return 0;
}
