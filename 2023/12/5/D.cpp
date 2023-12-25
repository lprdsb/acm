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

int T, n;
vector<int> ch[maxn + 5];

int poi_tot = 0;
struct Poi{
    int f0, z, res;
    vector<int> dif1, dif2;
} poi[maxn + 5];
Poi *get_new(){
    poi[++poi_tot] = {};
    return &poi[poi_tot];
}

template <class T>
void read(T &x){
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

int a[maxn + 5];

int len[maxn + 5], son[maxn + 5];
void dfs(int u){
    son[u] = 0;
    for(auto v : ch[u]){
        dfs(v);
        if(!son[u] || len[son[u]] > len[v]) son[u] = v;
    }
    len[u] = len[son[u]] + 1;
}
void merge(Poi *t1, Poi *t2){
    t1->f0 += t2->f0;
    t1->res += t2->f0;
    int lim = t1->dif1.size() + t1->z + t1->dif2.size();
    // cout << lim << " " << t2->dif1.size() + t2->z + t2->dif2.size() << endl;
    vector<int> vec;
    if(t2->dif1.size() >= lim){
        For(i, 0, lim - 1) vec.pb(t2->dif1[i]);
    }
    else if(t2->dif1.size() + t2->z >= lim){
        for(auto i : t2->dif1) vec.pb(i);
        For(i, 1, lim - t2->dif1.size()) vec.pb(0);
    }
    else{
        for(auto i : t2->dif1) vec.pb(i);
        For(i, 1, t2->z) vec.pb(0);
        For(i, vec.size(), lim - 1){
            vec.pb(t2->dif2[t2->dif2.size() - 1]);
            t2->dif2.pop_back();
        }
    }
    For(i, 0, (int)t1->dif1.size() - 1) t1->dif1[i] += vec[i], t1->res += vec[i];
    For(i, t1->dif1.size(), (int)t1->dif1.size() + t1->z - 1) t1->dif1.pb(vec[i]), t1->res += vec[i];
    t1->z = 0;
    For(i, t1->dif1.size(), lim - 1) t1->dif2[t1->dif2.size() - (i - t1->dif1.size() + 1)] += vec[i];

    while(t1->dif1.size() && t1->dif1[t1->dif1.size() - 1] > 0){
        t1->dif2.pb(t1->dif1[t1->dif1.size() - 1]);
        t1->res -= t1->dif1[t1->dif1.size() - 1];
        t1->dif1.pop_back();
    }
    while(t1->dif2.size() && t1->dif2[t1->dif2.size() - 1] < 0){
        t1->res += t1->dif2[t1->dif2.size() - 1];
        t1->dif1.pb(t1->dif2[t1->dif2.size() - 1]);
        t1->dif2.pop_back();
    }
    while(t1->dif1.size() && t1->dif1[t1->dif1.size() - 1] == 0){
        t1->dif1.pop_back();
        t1->z++;
    }
    while(t1->dif2.size() && t1->dif2[t1->dif2.size() - 1] == 0){
        t1->dif2.pop_back();
        t1->z++;
    }
}
int as[maxn + 5];
void dfs1(int u, Poi *to){
    if(son[u]) dfs1(son[u], to);
    for(auto v : ch[u]) if(v != son[u]){
        Poi *tt = get_new();
        dfs1(v, tt);
        // if(u == 3) cout << u << " " << len[v] << " " << len[son[u]] << endl;
        merge(to, tt);
    }
    if(a[u] == 0) to->dif2.pb(1);
    else{
        to->f0++;
        to->dif1.pb(-1);
    }
    as[u] = to->res;
    // if(u == 6){
    //     cout << to->f0 << " ";
    //     for(auto i : to->dif1) cout << i << " ";
    //     For(i, 1, to->z) cout << "0 ";
    //     Rof(i, (int)to->dif2.size() - 1, 0) cout << to->dif2[i] << " ";
    //     cout << endl;
    // }
}

int main(){
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--){
        read(n);
        For(i, 1, n){
            char c; cin >> c;
            a[i] = c - '0';
        }
        For(i, 2, n){
            int p; read(p);
            ch[p].pb(i);
        }
        Poi *to = get_new();
        dfs(1); dfs1(1, to);
        For(i, 1, n) printf("%d ", as[i]); puts("");
        For(i, 1, n) ch[i].resize(0);
        poi_tot = 0;
    }
    return 0;
}
