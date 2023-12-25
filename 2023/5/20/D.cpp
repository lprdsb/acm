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
#define maxn 66000
#define maxm 200
using namespace std;

int d, k, cnt[maxn + 5], pw[maxn + 5], a[maxn + 5];
LL f[maxn + 5][maxm + 5], pwi[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

vector<int> as;
int main(){
	// freopen("in.txt", "r", stdin);
    read(d); read(k);
    For(i, 1, d) read(a[i]);
    sort(a + 1, a + d + 1);
    pw[0] = pwi[0] = 1;
    For(i, 1, d){
        pw[i] = pw[i - 1] * 10 % k;
        pwi[i] = pwi[i - 1] * 10;
    }
    For(i, 0, (1 << d) - 1) cnt[i] = cnt[i >> 1] + (i & 1);
    memset(f, -1, sizeof f);
    f[0][0] = 0;
    For(i, 1, (1 << d) - 1) For(j, 0, k - 1) Rof(p, d, 1) if((i & (1 << (p - 1)))){
        int toi = i ^ (1 << (p - 1)), tok = j - a[p] * pw[cnt[i] - 1] % k;
        if(tok < 0) tok += k;
        if(f[toi][tok] == -1) continue;
        f[i][j] = f[toi][tok] + a[p] * pwi[cnt[i] - 1];
        break;
    }
    Rof(i, k - 1, 0) if(f[(1 << d) - 1][i] != -1){
        printf("%lld\n", f[(1 << d) - 1][i]);
        break;
    }
	return 0;
}
