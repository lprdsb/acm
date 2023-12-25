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
#define maxn 200
using namespace std;

int n, k, a[maxn + 5], ok[maxn + 5], pre[maxn + 5][maxn + 5], f[maxn + 5][maxn + 5];
vector<int> as[maxn + 5];
pair<int, int> s[maxn + 5];

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
    read(n); read(k);
    For(i, 1, n) read(a[i]);
    For(i, 1, k) read(s[i].fir), s[i].sec = i;
    sort(s + 1, s + k + 1);
    For(o, 1, k - 1){
        memset(f, 0, sizeof f);
        f[0][0] = 1;
        For(i, 1, n) if(!ok[i]) Rof(j, s[o].fir - 1, 0) For(p, 0, s[o].fir - 1) if(f[j][p]){
            int tem = (p + a[i]) % s[o].fir;
            if(!f[j + 1][tem]) pre[j + 1][tem] = i, f[j + 1][tem] = 1;
        }
        // if(o == 2) cout << s[o].sec << endl;
        int now = 0;
        Rof(i, s[o].fir, 1){
            as[s[o].sec].pb(a[pre[i][now]]);
            ok[pre[i][now]] = 1;
            now = (now - a[pre[i][now]] % s[o].fir + s[o].fir) % s[o].fir;
        }
    }
    int now = 0;
    For(i, 1, n) if(!ok[i]){
        as[s[k].sec].pb(a[i]);
        now = (now + a[i]) % s[k].fir;
    }
    as[s[k].sec].pb(s[k].fir - now);
    printf("%d\n", s[k].fir - now);
    For(o, 1, k){
        for(auto i : as[o]) printf("%d ", i);
        puts("");
    }
    return 0;
}
