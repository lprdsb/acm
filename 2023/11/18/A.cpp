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
#define maxn 500
using namespace std;

int T, n, m, a[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int main(){
	//freopen("in", "r", stdin);
    read(T);
    while(T--){
        read(n); read(m);
        For(i, 1, n) read(a[i]);
        LL as = Inf;
        For(i, 1, n){
            int now = a[i];
            while(now){
                vector<int> vec;
                For(j, 1, n){
                    int tem = a[j], cnt = 0, resi = inf;
                    while(tem / 2 > now) tem >>= 1, cnt++;
                    if(tem > now) resi = min(resi, min(tem - now, now - (tem / 2) + 1));
                    else resi = now - tem;
                    resi += cnt;
                    vec.pb(resi);
                }
                sort(vec.begin(), vec.end());
                LL res = 0;
                For(j, 0, n - m - 1) res += vec[j];
                as = min(as, res);
                now >>= 1;
            }
        }
        printf("%lld\n", as);
    }
    return 0;
}
