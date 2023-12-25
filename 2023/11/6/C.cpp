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
#define maxn 300000
using namespace std;

int n, m, a[maxn + 5], b[maxn + 5], ab[maxn + 5];

char s[maxn + 5];

int poi_tot = 0;
struct Poi{
    Poi *ch[2];
    int mx;
} poi[4 * maxn + 5];
Poi* get_new(){
    poi[++poi_tot] = {};
    return &poi[poi_tot];
}
Poi *get_o(Poi *rt, int o){
    if(!rt->ch[o]) rt->ch[o] = get_new();
    return rt->ch[o];
}
void upd(Poi *rt){
    rt->mx = 0;
    For(o, 0, 1) if(rt->ch[o]) rt->mx = max(rt->mx, rt->ch[o]->mx);
}
void ins(Poi *rt, int l, int r, int qx, int val){
    if(l == r){
        rt->mx = val;
        return;
    }
    int mid = l + r >> 1;
    if(qx <= mid) ins(get_o(rt, 0), l, mid, qx, val);
    else ins(get_o(rt, 1), mid + 1, r, qx, val);
    upd(rt);
}
int que(Poi *rt, int l, int r, int ql, int qr, int x){
    if(!rt || rt->mx < x) return inf;
    // cout << l << " " << r << " " << ql << " " << qr  << " " << x << endl;
    if(l == r) return l;
    int mid = l + r >> 1, res = inf;
    if(ql <= mid) res = que(rt->ch[0], l, mid, ql, qr, x);
    if(res == inf && qr > mid) res = que(rt->ch[1], mid + 1, r, ql, qr, x);
    return res;
}

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int z[maxn + 5], w[maxn + 5], fail[maxn + 5];
LL sum_w[maxn + 5], f[maxn + 5], ssum_w[maxn + 5], sum_f[maxn + 4];

int main(){
	// freopen("in.txt", "r", stdin);
    read(n); read(m);
    scanf("%s", s + 1);
    For(i, 1, n) a[i] = s[i] - 'a' + 3;
    scanf("%s", s + 1);
    For(i, 1, n) b[i] = s[i] - 'a' + 3;
    For(i, 1, n) read(w[i]), sum_w[i] = sum_w[i - 1] + w[i];
    For(i, 1, n) ab[i] = a[i]; a[n + 1] = 2;
    For(i, 1, n) ab[n + 1 + i] = b[i];
    for(int i = 2, now = 1; i <= 2 * n + 1; ++i){
        if(now + z[now] - 1 >= i) z[i] = min(z[i - now + 1], now + z[now] - i);
        while(ab[i + z[i]] == ab[z[i] + 1]) z[i]++;
        if(i + z[i] > now + z[now]) now = i;
    }
    // For(i, 1, 2 * n + 1) cout << z[i] << " "; cout << endl;
    For(i, 1, 2 * n + 1) ssum_w[i] = ssum_w[i - 1] + sum_w[z[i]];
    f[1] = sum_f[1] = w[1];
    For(i, 2, n){
        fail[i] = fail[i - 1];
        while(fail[i] && a[i] != a[fail[i] + 1]) fail[i] = fail[fail[i]];
        if(a[i] == a[fail[i] + 1]) fail[i]++;
        f[i] = w[i] + f[fail[i]];
        sum_f[i] = sum_f[i - 1] + f[i];
    }
    Poi *Rt = get_new();
    For(i, 1, n) ins(Rt, 1, n, i, i + z[n + 1 + i] - 1);//, cout << i + z[n + 1 + i] - 1 << " "; cout << endl;
    // cout << que(Rt, 1, n, 2, 3, 3) << endl;
    For(_, 1, m){
        int l, r; read(l); read(r);
        int pos = que(Rt, 1, n, l, r, r);
        // cout << pos << endl;
        if(pos == inf) printf("%lld\n", ssum_w[n + 1 + r] - ssum_w[n + l]);
        else printf("%lld\n", ssum_w[n + pos] - ssum_w[n + l] + sum_f[r - pos + 1]);
    }
    return 0;
}
