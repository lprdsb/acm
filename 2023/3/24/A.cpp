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
#define maxn 1000000
#define mod 1000000007
using namespace std;

int n, k, w[11], c[maxn + 5], d[maxn + 5], sum[11][maxn + 5], as = 0;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int l_max[maxn + 5], r_max[maxn + 5];
int que(int ind, int x){
    int asi = n;
    if(x <= min(n, w[ind])) asi = min(asi, l_max[x]);
    if(x >= w[ind] - n + 1) asi = min(asi, r_max[w[ind] - x + 1]);
    // cout << x << " " << w[ind] - n + 1 << endl;
    return asi;
}
void sol(int ind){
    int now = 1, pos = 0;
    For(i, 1, min(n, w[ind])){
        pos++;
        while(now <= n && (c[now] != ind || pos + d[now] >= 1)) pos += (c[now] == ind) * d[now], now++;
        l_max[i] = now > n ? n : now;
        // cout << i << " " << pos << " " << now << endl;
    }
    now = pos = 0;
    For(i, 1, min(n, w[ind])){
        pos++;
        while(now <= n && (c[now] != ind || pos - d[now] >= 1)) pos -= (c[now] == ind) * d[now], now++;
        r_max[i] = now > n ? n : now;
        // cout << i << " " << pos << " " << now << endl;
    }
    // cout << r_max[3] << endl;

}

void add(int &x, int y){
    LL asi = x + y;
    if(asi >= mod) asi -= mod;
    x = asi;
}

int main(){
	freopen("in.txt", "r", stdin);
    read(n); read(k);
    For(i, 1, k) read(w[i]);
    For(i, 1, n) read(c[i]), read(d[i]);
    For(i, 1, k){
        sol(i);
        if(i == 2){
            For(j, 1, w[i]) cout << que(i, j) << " "; cout << endl;
        }
        if(n < w[i] - n + 1){
            sum[i][n] = w[i] - 2 * n;
            For(j, 1, n) add(sum[i][que(i, j)], 1), add(sum[i][que(i, w[i] - j + 1)], 1);
        }
        else For(j, 1, n) add(sum[i][que(i, j)], 1);
        Rof(j, n, 1) add(sum[i][j], sum[i][j + 1]);
    }
    as = 1;
    int sum_suf = 0;
    For(i, 1, k) as = 1ll * as * sum[i][n] % mod, add(sum_suf, sum[i][n]);
    as = 1ll * n * as % mod;
    Rof(i, n - 1, 1) For(j, 1, k) if(sum[j][i] - sum[j][i + 1]){
        add(as, 1ll * i * (1ll * sum[j][i] - sum[j][i + 1] + mod) % mod * (1ll * sum_suf - (sum[j][i + 1] - sum[j][i + 1]) + mod) % mod);
        add(sum_suf, (1ll * sum[j][i] - sum[j][i + 1] + mod) % mod);
    }
    printf("%d\n", as);
    return 0;
}
