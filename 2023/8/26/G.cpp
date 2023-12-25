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
#define mod 998244353
using namespace std;

int t, n, a[maxn + 5][maxn + 5], b[maxn + 5][maxn + 5], ia[maxn * maxn + 5], ib[maxn * maxn + 5], sr[maxn + 5][maxn + 5], sd[maxn + 5][maxn + 5];
int fac[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

bool chk(){
    For(i, 0, n - 1) For(j, 0, n - 1) if(a[i][j] != b[i][j]) return 0;
    return 1;
}

int ta[maxn + 5];
int visr[maxn + 5], visd[maxn + 5], visx[maxn + 5], visy[maxn + 5];
void shift_r(int x, int y){
    For(i, 0, n - 1) ta[i] = a[x][(i - y + n) % n];
    For(i, 0, n - 1) a[x][i] = ta[i];
    For(i, 0, n - 1) sr[x][i] = 0;
    For(i, 0, n - 1) ta[i] = sd[x][(i - y + n) % n];
    For(i, 0, n - 1) sd[x][i] = ta[i];
}
void shift_d(int x, int y){
    For(i, 0, n - 1) ta[i] = a[(i - y + n) % n][x];
    For(i, 0, n - 1) a[i][x] = ta[i];
    For(i, 0, n - 1) ta[i] = sr[(i - y + n) % n][x];
    For(i, 0, n - 1) sr[i][x] = ta[i];
    For(i, 0, n - 1) sd[i][x] = 0;
}

bool chkr(int x){
    if(!sr[x][0] || visr[sr[x][0]] || visx[x]) return 0;
    For(i, 1, n - 1) if(sr[x][i] != sr[x][0]) return 0;
    return 1;
}
bool chkd(int x){
    if(!sd[0][x] || visd[sd[0][x]] || visy[x]) return 0;
    For(i, 1, n - 1) if(sd[i][x] != sd[0][x]) return 0;
    return 1;
}

int main(){
	// freopen("in.txt", "r", stdin);
    fac[0] = fac[1] = 1;
    For(i, 2, maxn) fac[i] = 1ll * fac[i - 1] * i % mod;
    read(t);
    For(_, 1, t){
        read(n);
        For(i, 0, n - 1) For(j, 0, n - 1){
            read(a[i][j]); a[i][j]--;
            ia[a[i][j]] = i * n + j;
        }
        int ssr = 0, ssd = 0;
        For(i, 0, n - 1) For(j, 0, n - 1){
            int x; read(x); x--;
            b[i][j] = x;
            ib[x] = i * n + j;
            int tx = ia[x] / n, ty = ia[x] % n;
            sr[tx][ty] = (j - ty + n) % n;
            sd[tx][ty] = (i - tx + n) % n;
            ssr += sr[tx][ty];
            ssd += sd[tx][ty];
        }
        // For(i, 0, n - 1){
        //     For(j, 0, n - 1) cout << sr[i][j] << " ";
        //     cout << endl;
        // }
        // cout << endl;
        // For(i, 0, n - 1){
        //     For(j, 0, n - 1) cout << sd[i][j] << " ";
        //     cout << endl;
        // }
        // if(_ == 9769){
        //     For(i, 0, n - 1){
        //         For(j, 0, n - 1) cout << a[i][j] + 1 << " "; cout << endl;
        //     }
        //     For(i, 0, n - 1){
        //         For(j, 0, n - 1) cout << b[i][j] + 1 << " "; cout << endl;
        //     }
        // }
        int res = 1;
        vector<int> okr, okd;
        if(ssd && ssr){
            while(!chk()){
                For(i, 0, n - 1) if(chkr(i)){
                    visx[i] = 1;
                    visr[sr[i][0]] = 1;
                    okr.pb(i);
                }
                For(i, 0, n - 1) if(chkd(i)){
                    visy[i] = 1;
                    visd[sd[0][i]] = 1;
                    okd.pb(i);
                }
                if(okr.size() && okd.size()) break;
                if(okr.size()){
                    res = 1ll * res * fac[okr.size()] % mod;
                    for(auto i : okr) shift_r(i, sr[i][0]);
                }
                else if(okd.size()){
                    res = 1ll * res * fac[okd.size()] % mod;
                    for(auto i : okd) shift_d(i, sd[0][i]);
                }
                else break;
                okr.resize(0); okd.resize(0);
            }
        }
        else{
            For(i, 0, n - 1) if(chkr(i)) okr.pb(i);
            For(i, 0, n - 1) if(chkd(i)) okd.pb(i);
            if(okr.size()){
                res = 1ll * res * fac[okr.size()] % mod;
                for(auto i : okr) shift_r(i, sr[i][0]);
            }
            else if(okd.size()){
                res = 1ll * res * fac[okd.size()] % mod;
                for(auto i : okd) shift_d(i, sd[0][i]);
            }
        }
        // if(t == 20000){
        // }
        // else{
            if(chk()) printf("%d\n", res);
            else puts("0");
        // }
        For(i, 0, n - 1) visr[i] = visd[i] = visx[i] = visy[i] = 0;
    }
    return 0;
}