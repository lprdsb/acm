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
#define maxn 100000
using namespace std;

int T, n, m, k, cnt[maxn + 5];
LL sum[maxn + 5];
struct Node1{
    int l, r, id;
};
bool operator < (cst Node1 &_x, cst Node1 &_y){return _x.l < _y.l;}
set<Node1> line[2][maxn + 5];
map<int, map<int, int> > ma;
struct Edge{
    int u, v;
};
vector<Edge> vec[maxn + 5];
struct Data{
    int ty, x, l, r;
} dat[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int fa[maxn + 5];
int find(int x){return fa[x] == x ? x : fa[x] = find(fa[x]);}

vector<int> vecm;
int main(){
	freopen("in.txt", "r", stdin);
    For(i, 1, maxn) fa[i] = i;
    read(T);
    while(T--){
        read(n); read(m); read(k);
        For(i, 1, k){
            int x1, y1, x2, y2; read(x1); read(y1); read(x2); read(y2);
            cnt[x1]++;
            if(x1 == x2){
                dat[i] = {0, x1, y1, y2};
                sum[x1] += y2 - y1 + 1;
                sum[x1 + 1] -= y2 - y1 + 1;
                line[0][x1].insert({y1, y2, i});
                ma[x1][y1] = ma[x1][y2] = i;
            }
            else{
                dat[i] = {1, y1, x1, x2};
                sum[x1]++; sum[x2 + 1]--;
                line[1][y1].insert({x1, x2, i});
                ma[x1][y1] = ma[x2][y1] = i;
                vecm.pb(y1);
            }
        }
        For(i, 1, k){
            int ty = dat[i].ty, x = dat[i].x, l = dat[i].l, r = dat[i].r, tem;

            tem = x - 1;
            auto it = line[ty][tem].lower_bound({l + 1});
            if(it != line[ty][tem].begin()) it--;
            if(it != line[ty][tem].end() && it->l <= l && it->r >= l){
                if(!ty) vec[x].pb({i, it->id});
                else vec[l].pb({i, it->id});
            }
            it = line[ty][tem].lower_bound({r + 1});
            if(it != line[ty][tem].begin()) it--;
            if(it != line[ty][tem].end() && it->l <= r && it->r >= r){
                if(!ty) vec[x].pb({i, it->id});
                else vec[max(l, it->l)].pb({i, it->id});
            }

            tem = x + 1;
            it = line[ty][tem].lower_bound({l + 1});
            if(it != line[ty][tem].begin()) it--;
            if(it != line[ty][tem].end() && it->l <= l && it->r >= l){
                if(!ty) vec[x + 1].pb({i, it->id});
                else vec[l].pb({i, it->id});
            }
            it = line[ty][tem].lower_bound({r + 1});
            if(it != line[ty][tem].begin()) it--;
            if(it != line[ty][tem].end() && it->l <= r && it->r >= r){
                if(!ty) vec[x + 1].pb({i, it->id});
                else vec[max(l, it->l)].pb({i, it->id});
            }

            tem = l - 1;
            it = line[!ty][tem].lower_bound({x + 1});
            if(it != line[!ty][tem].begin()) it--;
            if(it != line[!ty][tem].end() && it->l <= x && it->r >= x){
                if(!ty) vec[x].pb({i, it->id});
                else vec[l].pb({i, it->id});
            }

            tem = dat[i].r + 1;
            it = line[!ty][tem].lower_bound({x + 1});
            if(it != line[!ty][tem].begin()) it--;
            if(it != line[!ty][tem].end() && it->l <= x && it->r >= x){
                if(!ty) vec[x].pb({i, it->id});
                else vec[r + 1].pb({i, it->id});
            }

            if(!dat[i].ty){
                if(ma[x][l - 1]) vec[x].pb({i, ma[x][l - 1]});
            }
            else{
                if(ma[l - 1][x]) vec[l].pb({i, ma[l - 1][x]});
            }
        }
        int res1 = 0, res2 = 0;
        For(i, 1, n){
            sum[i] += sum[i - 1];
            res1 += sum[i];
            res2 += cnt[i];
            for(auto [u, v] : vec[i]){
                if(find(u) != find(v)){
                    fa[find(u)] = find(v);
                    res2--;
                }
            }
            printf("%lld %d\n", res1, res2);
        }
        // if(m == 100){
        //     puts("asd");
        //     return 0;
        // }
        For(i, 1, n + 1){
            cnt[i] = sum[i] = 0;
            line[0][i].clear();
            ma[i].clear();
            vec[i].resize(0);
        }
        for(auto i : vecm) line[1][i].clear();
        vecm.resize(0);
        For(i, 1, k) fa[i] = i;
    }
    return 0;
}
