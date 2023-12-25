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

int n, m, as = 0;
vector<vector<int> > zero, a;
vector<int> ok[2][maxn + 5];
class Hash{
    public:
        int mod, bas[maxn + 5];
        vector<vector<int> > val[4];//L R U D
        Hash(int _mod, int _bas){mod = _mod; bas[1] = _bas;}
        void init(){
            bas[0] = 1;
            For(i, 2, maxn) bas[i] = 1ll * bas[i - 1] * bas[1] % mod; 
            For(i, 0, 3) val[i] = zero;
            For(i, 1, n){
                For(j, 1, m) val[0][i][j] = (1ll * bas[1] * val[0][i][j - 1] + a[i][j]) % mod;
                Rof(j, m, 1) val[1][i][j] = (1ll * bas[1] * val[1][i][j + 1] + a[i][j]) % mod;
            }
            For(i, 1, m){
                For(j, 1, n) val[2][j][i] = (1ll * bas[1] * val[2][j - 1][i] + a[j][i]) % mod;
                Rof(j, n, 1) val[3][j][i] = (1ll * bas[1] * val[3][j + 1][i] + a[j][i]) % mod;
            }
        }
        int sol(int x){
            if(x < 0) x += mod;
            return x;
        }
        int get_val(int x1, int y1, int x2, int y2){
            if(x1 == x2){
                if(y1 <= y2) return sol(val[1][x1][y1] - 1ll * bas[y2 - y1 + 1] * val[1][x1][y2 + 1] % mod);
                else return sol(val[0][x1][y1] - 1ll * bas[y1 - y2 + 1] * val[0][x1][y2 - 1] % mod);
            }
            else{
                if(x1 <= x2) return sol(val[3][x1][y1] - 1ll * bas[x2 - x1 + 1] * val[3][x2 + 1][y1] % mod);
                else return sol(val[2][x1][y1] - 1ll * bas[x1 - x2 + 1] * val[2][x2 - 1][y1] % mod);
            }
        }
} hsh[2] = {Hash(99843353, 1331), Hash(998244353, 13331)};

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

bool chk(int x1, int y1, int x2, int y2){
    For(o, 0, 0){
        int v1 = hsh[o].get_val(x1, y1, x1, y2);
        int v2 = hsh[o].get_val(x1, y2, x2, y2);
        if(v1 != v2) return 0;
        int v3 = hsh[o].get_val(x2, y2, x2, y1);
        if(v3 != v2) return 0;
        int v4 = hsh[o].get_val(x2, y1, x1, y1);
        if(v4 != v3) return 0;
    }
    return 1;
}

int main(){
	// freopen("in.txt", "r", stdin);
    read(n); read(m);
    vector<int> col;
    col.resize(m + 5, 0);
    For(i, 0, n + 5) zero.pb(col);
    a = zero;
    For(i, 1, n) For(j, 1, m){
        char c; cin >> c;
        a[i][j] = c - 'a' + 1;
    }
    hsh[0].init();// hsh[1].init();
    int o = 1;
    For(i, 1, n){
        For(j, 1, m){
            ok[o][j].clear();
            ok[o][j].pb(0);
            ok[o][j].pb(1); as++;
            if(i >= 2 && j >= 2){
                for(auto p : ok[o ^ 1][j - 1]) if(i - p - 1 >= 1 && j - p - 1 >= 1){
                    int pre_i = i - p - 1, pre_j = j - p - 1;
                    if(chk(pre_i, pre_j, i, j)) ok[o][j].pb(p + 2), as++;
                }
            }
        }
        o ^= 1;
    }
    printf("%d\n", as);
	return 0;
}
