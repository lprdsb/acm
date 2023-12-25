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

int n, w, k;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

#define maxn 5000
int mnw[maxn + 5];
LL f[2 * maxn + 5];
pair<int, int> a[maxn + 5];

int main(){
	//freopen("in", "r", stdin);
    read(n); read(w); read(k);
    LL sum = 0;
    For(i, 1, n) read(a[i].sec), read(a[i].fir), sum += a[i].fir;
    sort(a + 1, a + n + 1);
    multiset<int> se;
    Rof(i, n, 1){
        se.insert(a[i].sec);
        auto it = se.begin();
        For(j, 1, n - i + 1 - k){
            mnw[i] += *it;
            it++;
        }
    }
    LL res = 0;
    For(i, 0, n){
        sum -= a[i].fir;
        Rof(j, w, a[i].sec) f[j] = max(f[j], f[j - a[i].sec] + a[i].fir);
        if(mnw[i + 1] <= w) res = max(res, sum + f[w - mnw[i + 1]]);
    }
    printf("%lld\n", res);
    return 0;
}
