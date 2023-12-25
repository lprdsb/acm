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

int n, m;
LL s[maxn + 5], v[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int b[maxn + 5], cnt = 0;
LL tr[2][maxn + 5];
void ins(int o, int x, LL y){
    while(x <= cnt) tr[o][x] += y, x += x & -x;
}
LL que(int o, int x){
    if(!x) return 0;
    LL res = 0;
    while(x) res += tr[o][x], x -= x & -x;
    return res;
}

__int128_t get_s(LL x){
    int to = lower_bound(b + 1, b + cnt + 1, x + 1) - b - 1;
    return (__int128_t)que(0, to) * x - que(1, to);
}

int main(){
	//freopen("in", "r", stdin);
    read(n); read(m);
    For(i, 1, n) read(s[i]), read(v[i]), b[++cnt] = s[i];
    sort(b + 1, b + cnt + 1);
    cnt = unique(b + 1, b + cnt + 1) - b - 1;
    For(i, 1, n){
        int to = lower_bound(b + 1, b + cnt + 1, s[i]) - b;
        ins(0, to, v[i]);
        ins(1, to, s[i] * v[i]);
    }
    // cout << get_s(10) << endl;
    LL res = 0;
    For(i, 1, n){
        int to = lower_bound(b + 1, b + cnt + 1, s[i]) - b;
        ins(0, to, -v[i]);
        ins(1, to, -s[i] * v[i]);
        LL l = 0, r = Inf;
        while(l < r){
            LL mid = l + r >> 1;
            if(get_s(mid) >= m) r = mid;
            else l = mid + 1;
        }
        res = max(res, l);
        ins(0, to, v[i]);
        ins(1, to, s[i] * v[i]);
    }
    printf("%lld\n", res == Inf ? -1 : res);
    return 0;
}
