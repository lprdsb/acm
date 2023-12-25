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

int n, k, a[maxn + 5][maxn + 5];
LL f[3][2][maxn + 5][maxn * maxn + 5], mx[maxn + 5][maxn + 5], sum[maxn + 5][maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

bool vis[3][2][maxn + 5][maxn * maxn + 5];
vector<int> sta[3][2][maxn + 5];

void chkmx(LL &x, LL y){
    if(x < y) x = y;
}

void upd(int o, int ty, int i, int p, LL val){
    chkmx(f[o][ty][i][p], val);
    sta[o][ty][i].pb(p);
}

int main(){
	// freopen("in.txt", "r", stdin);
	// freopen("out1.txt", "w", stdout);
    read(n); read(k);
    For(i, 1, n) For(j, 1, n){
        read(a[i][j]);
        mx[i][j] = a[i][j];
        sum[i][j] = a[i][j];
    }
    For(j, 1, n){
        For(i, 3, n) sum[i][j] += sum[i - 2][j];
        Rof(i, n, 1) chkmx(mx[i][j], mx[i + 2][j]);
    }
    memset(f, -1, sizeof f);
    int o = 0;
    upd(0, 0, 0, 0, 0);
    upd(1, 0, 0, 0, 0);
    upd(1, 1, 2, 1, a[2][1]);
    upd(1, 1, 0, 1, mx[2][1]);
    For(j, 0, n){
        int to = o + 1, tto = o + 2;
        if(to == 3) to = 0;
        if(tto >= 3) tto -= 3;
        For(i, 0, n){
            For(ty, 0, k){
                for(auto p : sta[o][ty][i]) if(!vis[o][ty][i][p]){
                    vis[o][ty][i][p] = 1;
                    if(i) upd(to, ty, i - 1, p + i / 2, f[o][ty][i][p] + sum[i - 1][j + 1]);
                    else upd(tto, ty, 0, p, f[o][ty][i][p]);
                    if(i + 1 <= n) upd(to, ty, i + 1, p + i / 2 + 1, f[o][ty][i][p] + sum[i + 1][j + 1]);
                    if(ty == k) continue;

                    if(i) upd(to, 1, i - 1, p + i / 2 + 1, f[o][0][i][p] + sum[i - 1][j + 1] + mx[i + 1][j + 1]);
                    else{
                        upd(tto, 1, 0, p + 1, f[o][0][i][p] + max(mx[2][j + 2], mx[1][j + 1]));
                        upd(tto, 1, 2, p + 1, f[o][0][i][p] + a[2][j + 2]);
                    }
                    if(i + 1 <= n) upd(to, 1, i + 1, p + i / 2 + 1 + 1, f[o][0][i][p] + sum[i + 1][j + 1] + mx[i + 3][j + 1]);
                    if(i >= 3) upd(to, 1, i - 3, p + i / 2 - 1, f[o][0][i][p] + sum[i - 3][j + 1]);
                    if(i == 2) upd(tto, 1, 0, p, f[o][0][i][p]);

                    if(i + 3 <= n) upd(to, 1, i + 3, p + i / 2 + 2, f[o][0][i][p] + sum[i + 3][j + 1]);
                }
            }
            if(j != n){
                For(ty, 0, k){
                    for(auto p : sta[o][ty][i]){
                        f[o][ty][i][p] = -1;
                        vis[o][ty][i][p] = 0;
                    }
                    sta[o][ty][i].resize(0);
                }
            }
        }
        if(j != n){
            o++;
            if(o == 3) o = 0;
        }
    }
    int to = o + 1;
    if(to == 3) to = 0;
    for(auto p : sta[o][0][2]) upd(o, 1, 0, p, f[o][0][2][p]);
    For(i, 1, n * n){
        LL as = -1;
        For(ty1, 0, k) For(j, 0, i) if(f[o][ty1][0][j] != -1) For(ty2, 0, 1) if(ty1 + ty2 <= k && f[to][ty2][0][i - j] != -1)
            chkmx(as, f[o][ty1][0][j] + f[to][ty2][0][i - j]);
        printf("%lld\n", as);
    }
    return 0;
}
