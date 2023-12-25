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
using namespace std;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

#define maxn 1000

int T, n, m, a[maxn + 5][maxn + 5];
bitset<maxn> ok[maxn + 5];
vector<pair<int, int> > vec;

int vis[maxn + 5][maxn + 5], vvis[maxn + 5][maxn + 5];
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool chk(int x, int y){return x >= 1 && x <= n && y >= 1 && y <= m;}
int main(){
	// freopen("in.txt", "r", stdin);
    read(T);
    while(T--){
        read(n); read(m);
        For(i, 1, n) For(j, 1, m){
            char c; cin >> c;
            if(c == '.') a[i][j] = 0, vec.pb({i, j});
            else a[i][j] = 1;
        }
        For(x, 1, n) For(y, 1, m) if(!a[x][y]){
            queue<pair<int, int> > q;
            vvis[x][y] = 1;
            q.push({x, y});
            while(q.size()){
                auto [nx, ny] = q.front(); q.pop();
                For(i, 0, 3){
                    int tx = nx + dir[i][0], ty = ny + dir[i][1];
                    if(chk(tx, ty) && !a[tx][ty] && !vvis[tx][ty]){
                        vis[(x - 1) * m + y][(tx - 1) * m + ty] = 1;
                        vvis[tx][ty] = 1;
                        q.push({tx, ty});
                    }
                }
            }
            For(i, 1, n) For(j, 1, m) vvis[i][j] = 0;
        }
        // cout << "asd" << endl;
        For(i, -n, n) For(j, -m, m){
            bitset<maxn> bit = 0;
            For(o, 0, vec.size() - 1){
                if(!chk(vec[o].fir + i, vec[o].sec + j) || !vis[(vec[o].fir - 1) * m + vec[o].sec][(vec[o].fir + i - 1) * m + vec[o].sec + j])
                    bit[o] = 0;
                else bit[o] = 1;
            }
            For(o, 0, vec.size() - 1) if(bit[o]) ok[o] |= ~bit;
        }
        int res = 0;
        For(i, 0, vec.size() - 1){
            int fl = 1;
            For(j, 0, vec.size() - 1) if(i != j && !ok[i][j]){
                fl = 0;
                break;
            }
            if(fl) res++;
        }
        printf("%d\n", res);
        For(i, 1, n * m) For(j, 1, n * m) vis[i][j] = 0;
        For(i, 0, vec.size() - 1) ok[i] = 0;
        vec.resize(0);
    }
}
