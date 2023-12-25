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
#define maxn 100
using namespace std;

int n, f[maxn + 5][maxn + 5], col[maxn + 5], ma[maxn + 5][maxn + 5][maxn + 5], d[maxn + 5], id[maxn + 5];
vector<int> ch[maxn + 5];

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
    read(n);
    For(i, 1, n) For(j, 1, n) read(f[i][j]);
    For(i, 1, n) For(j, 1, n) For(p, 1, n) f[j][p] |= f[j][i] & f[i][p];
    int cnt = 0;
    For(i, 1, n) if(!col[i]){
        col[i] = ++cnt;
        For(j, 1, n) if(f[i][j] && f[j][i]) col[j] = cnt;
    }
    // For(i, 1, n){
    //     For(j, 1, n) cout << f[i][j] << " "; cout << endl;
    // }
    // cout << cnt << endl;
    // For(i, 1, n) cout << col[i] << " "; cout << endl;
    For(i, 1, n) For(j, 1, n) if(col[i] != col[j] && f[i][j]) ch[col[i]].pb(col[j]), d[col[j]]++;
    queue<int> q;
    For(i, 1, cnt) if(!d[i]) q.push(i);
    int tot = 10;
    while(q.size()){
        int u = q.front(); q.pop();
         tot += 2; id[u] = tot;
        for(auto i : ch[u]){
            d[i]--;
            if(!d[i]) q.push(i);
        }
    }
    // cout << tot << endl;
    For(i, 1, n) For(j, 1, n) if(f[i][j] && col[i] != col[j] && id[col[i]] < id[col[j]]){
        For(p, id[col[i]], id[col[j]]) ma[p][id[col[i]]][id[col[j]]] = 1;
    }
    For(i, 1, cnt){
        For(j, 1, id[i]) ma[id[i]][j][id[i]] = 1;
        // ma[i][i][i] = 1;
        // For(j, id[i], tot) ma[id[i]][id[i]][j] = 1;
        For(j, id[i], tot) ma[id[i]][id[i] + 1][j] = 1;
    }
    int num[maxn + 5];
    For(i, 1, tot) num[i] = i;
    For(i, 1, n) ma[id[col[i]]][num[id[col[i]]]--][id[col[i]]] = i + 1;
    printf("%d %d %d\n", tot, tot, tot);
    For(i, 1, tot){
        For(j, 1, tot){
            For(p, 1, tot){
                if(ma[i][j][p] == 1) printf(".");
                else if(ma[i][j][p] == 0) printf("#");
                else printf("%d", ma[i][j][p] - 1);
            }
            puts("");
        }
        puts("");
    }
    return 0;
}
