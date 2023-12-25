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
#define maxn 400
#define mod 998244353
using namespace std;

int n, res = 0;
vector<pair<int, int> > vec[25];
vector<int> vec1[maxn + 5];
char s[maxn + 5][maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int fp(int x, int y){
    int res = 1;
    while(y){
        if(y & 1) res = 1ll * res * x % mod;
        x = 1ll * x * x % mod;
        y >>= 1;
    }
    return res;
}

int f[2][2000000];
void sol(int len){
    if(!vec1[len].size()) return;
    // cout << len << endl;
    int o = 0;
    f[0][0] = 1;
    For(i, 1, len){
        int sta0 = 0, sta1 = 0;
        For(j, 0, vec1[len].size() - 1){
            if(s[vec1[len][j]][i] == '0') sta1 |= 1 << j;
            else if(s[vec1[len][j]][i] == '1') sta0 |= 1 << j;
        }
        For(j, 0, (1 << vec1[len].size()) - 1) if(f[o][j]){
            f[o ^ 1][j | sta0] = (1ll * f[o ^ 1][j | sta0] + f[o][j]) % mod;
            f[o ^ 1][j | sta1] = (1ll * f[o ^ 1][j | sta1] + f[o][j]) % mod;
            f[o][j] = 0;
        }
        o ^= 1;
    }
    res = (1ll * res + fp(2, len) - f[o][(1 << vec1[len].size()) - 1] + mod) % mod;
    For(i, 0, (1 << vec1[len].size()) - 1) f[0][i] = f[1][i] = 0;
}

int main(){
	// freopen("in.txt", "r", stdin);
    read(n);
    For(i, 1, n){
        scanf("%s", s[i] + 1);
        int len = strlen(s[i] + 1);
        if(len <= 20){
            int tem1 = 0, tem2 = 0;
            For(j, 1, len){
                if(s[i][j] == '1') tem1 |= (1 << (j - 1));
                if(s[i][j] != '?') tem2 |= (1 << (j - 1));
            }
            vec[len].pb({tem1, tem2});
        }
        vec1[len].pb(i);
    }
    For(i, 1, 20) if(vec[i].size()){
        For(j, 0, (1 << i) - 1){
            for(auto p : vec[i]) if(!((j ^ p.fir) & (p.sec))){
                // if(j == 2) cout << p.fir << " " << p.sec << endl;
                res++;
                break;
            }
        }
    }//sol(3);
    For(i, 21, 400) sol(i);
    printf("%d\n", res);
    return 0;
}
