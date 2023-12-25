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
#define maxn 200000
using namespace std;

int n, m, cnt_e1 = 0, fa[maxn + 5], ccnt[maxn + 5], ma[1001][1001];
LL as = 0, ww;
struct Edge{
    int u, v;
    LL w;
} e[maxn + 5], e1[maxn + 5];
vector<Edge> e2, e3, e4, e5;
bool operator < (cst Edge &x, cst Edge &y){return x.w < y.w;}
vector<int> vec[maxn + 5];
set<pair<int, int> > se;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int find(int x){return fa[x] == x ? x : fa[x] = find(fa[x]);}

int col[maxn + 5], cnt = 0, sum[maxn + 5], cnt_e2[maxn + 5];
LL mn = Inf, mnw = Inf;
int main(){
	// freopen("in.txt", "r", stdin);
    read(n); read(m);
    For(i, 1, m){
        int u, v;
        LL w;
        read(u); read(v); read(w);
        e[i] = {u, v, w};
        if(n <= 1000) ma[u][v] = ma[v][u] = w;
        vec[u].pb(v); vec[v].pb(u);
        ww ^= w;
    }
    For(i, 1, n) se.insert(mp(0, i)), ccnt[i] = 0;
    For(i, 1, n) if(!col[i]){
        se.erase(mp(0, i));
        sum[col[i] = ++cnt] = 1;
        for(auto v : vec[i]){
            auto it = se.lower_bound(mp(ccnt[v], v));
            if(it == se.end() || it->sec != v) continue;
            pair<int, int> pa = *it;
            se.erase(it);
            pa.fir++;
            ccnt[pa.sec]++;
            se.insert(pa);
        }
        while(666){
            auto it = se.begin();
            if(it == se.end() || it->fir == sum[cnt]) break;
            int u = it->sec;
            sum[col[u] = cnt]++;
            se.erase(it);
            for(auto v : vec[u]){
                auto it = se.lower_bound(mp(ccnt[v], v));
                if(it == se.end() || it->sec != v) continue;
                pair<int, int> pa = *it;
                se.erase(it);
                pa.fir++;
                ccnt[pa.sec]++;
                se.insert(pa);
            }
        }
        while(se.size()){
            auto it = se.end();
            it--;
            if(it->fir){
                pair<int, int> pa = *it;
                se.erase(it);
                pa.fir = 0;
                ccnt[pa.sec] = 0;
                se.insert(pa);
            }
            else break;
        }
    }
    For(i, 1, m){
        int u = e[i].u, v = e[i].v;
        if(col[u] != col[v]) e1[++cnt_e1] = e[i];
        else cnt_e2[col[u]]++, mn = min(mn, e[i].w);
    }
    sort(e1 + 1, e1 + cnt_e1 + 1);
    For(i, 1, cnt) fa[i] = i;
    For(i, 1, cnt_e1){
        int u = find(col[e1[i].u]), v = find(col[e1[i].v]);
        LL w = e1[i].w;
        if(u == v){
            mn = min(mn, w);
            continue;
        }
        as += w;
        fa[u] = v;
    }
    int fl = 0;
    For(i, 1, cnt) if(1ll * sum[i] * (sum[i] - 1) / 2 != cnt_e2[i] + sum[i] - 1) fl++;
    // cout << as << endl;
    if(!fl){
        as = Inf;
        For(i, 1, n) fa[i] = i;
        sort(e + 1, e + m + 1);
        For(i, 1, m){
            int u = find(e[i].u), v = find(e[i].v);
            if(u == v) continue;
            e5.pb(e[i]);
            fa[u] = v;
        }
        For(i, 1, n) For(j, i + 1, n) if(!ma[i][j]) e3.pb({i, j, 0});
        // cout << e5[0].u << " " << e5[0].v << endl;
        For(i, 0, e3.size() - 1){
            For(j, 1, n) fa[j] = j;
            LL asi = 0;
            e4 = e5;
            e4.pb({e3[i].u, e3[i].v, ww});
            For(j, 0, e3.size() - 1) if(j != i) e4.pb(e3[j]);
            sort(e4.begin(), e4.end());
            for(auto j : e4){
                int u = find(j.u), v = find(j.v);
                LL w = j.w;
                if(u == v) continue;
                asi += w;
                fa[u] = v;
            }
            as = min(as, asi);
        }
    }
    printf("%lld\n", as);
    return 0;
}
