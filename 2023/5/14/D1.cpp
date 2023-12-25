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
#define eps 1e-18
#define maxn 2000
#define maxm 10000
using namespace std;

int n, m;
LL f[2][maxn + 5][maxn + 5];
struct Edge{int u, v, w;} e[maxm + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int st[2][maxn + 5][maxn + 5], top[2][maxn + 5];
int chk(int ty, int ind, int x1, int x2, int x3){
    return (__int128_t)(f[ty][ind][x2] - f[ty][ind][x1]) * (x3 - x2) >= (__int128_t)(f[ty][ind][x3] - f[ty][ind][x2]) * (x2 - x1);
}

LD get_k(int ty, int ind, int x1, int x2){
    return (LD)(f[ty][ind][x2] - f[ty][ind][x1]) / (x2 - x1);
}

void chkmn(LL &x, LL y){if(x == -1 || x > y) x = y;}

bool sol(int u){
    int now1 = 1, now2 = 1;
    For(i, 1, top[0][u] - 1){
        LD k = get_k(0, u, st[0][u][i], st[0][u][i + 1]);
        if(k > eps) break;
        // cout << i << " " << now1 << " " << now2 << endl;
        while(now1 < top[1][u] && k - get_k(1, u, st[1][u][now1], st[1][u][now1 + 1]) >= -eps) now1++;
        while(now2 < top[0][n] && k - get_k(0, n, st[0][n][now2], st[0][n][now2 + 1]) >= -eps) now2++;
        LD c = -k;
        if(fabs(f[0][u][st[0][u][i]] + f[1][u][st[1][u][now1]] + c * (st[0][u][i] + st[1][u][now1])
                 - f[0][n][st[0][n][now2]] - c * st[0][n][now2]) <= eps) return 1; 
    }
    now1 = now2 = 1;
    For(i, 1, top[1][u] - 1){
        LD k = get_k(1, u, st[1][u][i], st[1][u][i + 1]);
        if(k > eps) break;
        // cout << i << " " << now1 << " " << now2 << endl;
        while(now1 < top[0][u] && k - get_k(0, u, st[0][u][now1], st[0][u][now1 + 1]) >= -eps) now1++;
        while(now2 < top[0][n] && k - get_k(0, n, st[0][n][now2], st[0][n][now2 + 1]) >= -eps) now2++;
        LD c = -k;
        if(fabs(f[0][u][st[0][u][now1]] + f[1][u][st[1][u][i]] + c * (st[0][u][now1] + st[1][u][i])
                 - f[0][n][st[0][n][now2]] - c * st[0][n][now2]) <= eps) return 1; 
    }
    now1 = now2 = 1;
    For(i, 1, top[0][n] - 1){
        LD k = get_k(0, n, st[0][n][i], st[0][n][i + 1]);
        if(k > eps) break;
        while(now1 < top[0][u] && k - get_k(0, u, st[0][u][now1], st[0][u][now1 + 1]) >= -eps) now1++;
        while(now2 < top[1][u] && k - get_k(1, u, st[1][u][now2], st[1][u][now2 + 1]) >= -eps) now2++;
        // cout << i << " " << f[0][u][st[0][u][now1]] << " " << f[1][u][st[1][u][now2]] << " " << f[0][n][st[0][u][now1] + st[1][u][now2]] << endl;
        cout << i << " " << now1 << " " << now2 << endl;
        LD c = -k;
        if(fabs(f[0][u][st[0][u][now1]] + f[1][u][st[1][u][now2]] + c * (st[0][u][now1] + st[1][u][now2])
                 - f[0][n][st[0][n][i]] - c * st[0][n][i]) <= eps) return 1; 
    }
    LL mn1 = -1, mn2 = -1, mn3 = -1;
    For(i, 0, n){
        if(f[0][u][i] != -1) chkmn(mn1, f[0][u][i]);
        if(f[1][u][i] != -1) chkmn(mn2, f[1][u][i]);
        if(f[0][n][i] != -1) chkmn(mn3, f[0][n][i]);
    }
    return mn1 + mn2 == mn3;
}

int as[maxm + 5];
int main(){
	freopen("in.txt", "r", stdin);
    read(n); read(m);
    For(i, 1, m){
        read(e[i].u), read(e[i].v), read(e[i].w);
        // if(n == 1496 && e[i].u != e[i].v - 1) cout << e[i].u << " " << e[i].v << " " << e[i].w << endl;
    }
    memset(f, -1, sizeof f);
    f[0][1][0] = f[1][n][0] = 0;
    For(o1, 0, 1) For(o2, 1, n) For(i, 1, m){
        int u = e[i].u, v = e[i].v, w = e[i].w;
        if(f[o1][v][o2 - 1] != -1) chkmn(f[o1][u][o2], f[o1][v][o2 - 1] + w);
        if(f[o1][u][o2 - 1] != -1) chkmn(f[o1][v][o2], f[o1][u][o2 - 1] + w);
    }
    For(o, 0, 1) For(i, 1, n) For(j, 0, n) if(f[o][i][j] != -1){
        while(top[o][i] > 1 && chk(o, i, st[o][i][top[o][i] - 1], st[o][i][top[o][i]], j)) top[o][i]--;
        st[o][i][++top[o][i]] = j; 
    }
    For(i, 2, n - 1){
        // int tem;
        if(!sol(i)) as[++as[0]] = i;
        // if(n == 1496) cout << tem << endl;
    }
    printf("%d\n", as[0]);
    For(i, 1, as[0]) printf("%d ", as[i]);
	return 0;
}
