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
#define maxn 5000
#define maxm 25000000
using namespace std;

int n, m, k, ok[maxn + 5][maxn + 5], fa[maxm + 5], tot;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int find(int x){return fa[x] == x ? x : fa[x] = find(fa[x]);}
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool chk(int x, int y){return x >= 0 && x < n - 1 && y >= 0 && y < n - 1;}

int dis[maxm + 5];
int main(){
	// freopen("in.txt", "r", stdin);
    read(n); read(k); n++; tot = n * n - 1;
    For(i, 0, n - 2) For(j, 0, n - 2){
        char c; cin >> c;
        if(c == '.') ok[i][j] = 1;
    }
    For(i, 0, tot - 1) fa[i] = i;
    queue<int> q;
    q.push(0);
    if(n >= 2) fa[0] = n;
    dis[0] = 1;
    while(q.size()){
        int tem = q.front(); q.pop();
        int x = tem / n, y = tem % n;
        For(i, 0, 3){
            int tx = x + dir[i][0], ty = y + dir[i][1];
            if(!chk(tx, ty) || dis[tx * n + ty] || !ok[tx][ty]) continue;
            dis[tx * n + ty] = dis[tem] + 1;
            q.push(tx * n + ty);
            fa[find(tx * n + ty)] = find((ty + 1) * n + tx);
        }
        while(666){
            int temi = find(tem), xx = temi / n, yy = temi % n;
            if((temi / n + temi % n) - (tem / n + tem % n) > k || !chk(xx, yy) || dis[temi]) break;
            if(ok[xx][yy]){
                dis[temi] = dis[tem] + 1;
                q.push(temi);
            }
            fa[temi] = find((yy + 1) * n + xx);
        }
    }
    printf("%d\n", dis[(n - 2) * n + n - 2] ? dis[(n - 2) * n + n - 2] - 1 : -1);
    return 0;
}
