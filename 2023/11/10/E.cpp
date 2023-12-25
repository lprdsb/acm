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

int T, n, m, ax[maxn + 5], ay[maxn + 5], bx[maxn + 5], by[maxn + 5];
int sta[maxn + 5], tpa = 0, stb[maxn + 5], tpb = 0;
int ch[2 * maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int f[2 * maxn + 5], inst[2 * maxn + 5];
int dfs(int u){
    if(f[u] != -1) return f[u];
    if(inst[u]) return 1;
    inst[u] = 1;
    f[u] = dfs(ch[u]);
    inst[u] = 0;
    return f[u];
}

int ind[maxn + 5];
int main(){
    memset(f, -1, sizeof f);
	// freopen("in.txt", "r", stdin);
    read(T);
    while(T--){
        read(n);
        For(i, 1, n) read(ax[i]);
        For(i, 1, n) read(ay[i]);
        read(m);
        For(i, 1, m) read(bx[i]);
        For(i, 1, m) read(by[i]);
        // cout << "asd" << endl;

        For(i, 1, n) ind[i] = i;
        sort(ind + 1, ind + n + 1, [](cst int &_x, cst int &_y){return ax[_x] < ax[_y];});
        For(i, 1, n){
            while(tpa && ay[sta[tpa]] <= ay[ind[i]]) tpa--;
            sta[++tpa] = ind[i];
        }

        For(i, 1, m) ind[i] = i;
        sort(ind + 1, ind + m + 1, [](cst int &_x, cst int &_y){return bx[_x] < bx[_y];});
        For(i, 1, m){
            while(tpb && by[stb[tpb]] <= by[ind[i]]) tpb--;
            stb[++tpb] = ind[i];
        }

        For(i, 1, n){
            int tem = lower_bound(stb + 1, stb + tpb + 1, ay[i], [](cst int &_x, cst int &_y){return bx[_x] <= _y;}) - stb;
            if(tem == tpb + 1) f[i] = 0;
            else ch[i] = n + stb[tem];
            // if(stb[tem] == 8) cout << i << " asd " << endl;
        }
        // cout << tpa << endl;
        // For(i, 1, tpa) cout << ax[sta[i]] << " "; cout << endl;
        // cout << ax[sta[tpa]] << endl;
        For(i, 1, m){
            int tem = lower_bound(sta + 1, sta + tpa + 1, by[i], [](cst int &_x, cst int &_y){return ax[_x] <= _y;}) - sta;
            // if(tem == tpa + 1){
            //     cout << ax[sta[tem]] << " " << by[i] << endl;
            // }
            if(tem == tpa + 1) f[n + i] = 2;
            else ch[n + i] = sta[tem];
        }
        int res[3] = {0, 0, 0};
        For(i, 1, n) res[dfs(i)]++;
        For(o, 0, 2) printf("%d ", res[o]); puts("");
        tpa = tpb = 0;
        For(i, 1, n + m){
            f[i] = -1;
            ch[i] = 0;
        }
    }
}
