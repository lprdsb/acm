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

int t, n, m, a[maxn + 5];
char s[maxn + 5];

void chkmn(int &x, int y){
    if(x > y) x = y;
}
struct Trie{
    int tot;
    struct Node{
        int ch[26], len, to;
    } poi[maxn + 5], zero;
    void Init(){
        zero.len = 0;
    }
    void init(){
        poi[tot = 0] = zero;
    }
    int get_new(){
        poi[++tot] = zero;
        return tot;
    }
    void ins(char *s){
        int o = strlen(s + 1), now = 0;
        For(i, 1, o){
            if(!poi[now].ch[s[i] - 'a']) poi[now].ch[s[i] - 'a'] = get_new();
            now = poi[now].ch[s[i] - 'a'];
        }
        poi[now].len = o;
    }
} tr;

struct Sam{
    int tot;
    struct Node{
        int ch[26], fail[26], len, fa, mn, ok, to;
    } poi[2 * maxn + 5], zero;
    vector<int> vec[2 * maxn + 5];
    void Init(){
        zero.mn = inf;
    }
    int get_new(){
        poi[++tot] = zero;
        vec[tot].clear();
        return tot;
    }
    int ins(int x, int las){
        int p = las, np;
        if(poi[p].ch[x] && poi[p].len + 1 == poi[poi[p].ch[x]].len) return poi[p].ch[x];
        else np = get_new();
        poi[np].len = poi[p].len + 1;
        while(p && !poi[p].ch[x]) poi[p].ch[x] = np, p = poi[p].fa;
        if(!p) poi[np].fa = 1, vec[1].pb(np);
        else{
            int q = poi[p].ch[x];
            if(poi[p].len + 1 == poi[q].len) poi[np].fa = q;
            else{
                int nq = get_new(); poi[nq] = poi[q];
                poi[nq].len = poi[p].len + 1;
                poi[np].fa = poi[q].fa = nq;
                while(p && poi[p].ch[x] == q) poi[p].ch[x] = nq, p = poi[p].fa;
            }
        }
        return np;
    }
    void dfs(int u){
        for(auto v : vec[u]){
            For(i, 0, 25)
                if(!poi[v].ch[i]) poi[v].fail[i] = poi[u].fail[i];
                else poi[v].fail[i] = v;
            dfs(v);
            chkmn(poi[u].mn, poi[v].mn);
        }
    }
    void dfs1(int u){
        if(poi[u].ok) return;
        poi[u].ok = 1;
        For(o, 0, 25){
            int v = poi[u].ch[o];
            if(!v) continue;
            dfs1(v);
            chkmn(poi[u].mn, poi[v].mn);
        }
    }
    void dfs2(int u, int pre){
        poi[u].to = pre;
        for(auto v : vec[u]){
            int tem = pre;
            if(poi[u].mn != poi[v].mn) tem = u;
            dfs2(v, tem);
        }
    }
    void init(){
        tot = 0;
        queue<int> q;
        q.push(0);
        tr.poi[0].to = get_new();
        while(q.size()){
            int u = q.front(); q.pop();
            if(tr.poi[u].len) chkmn(poi[tr.poi[u].to].mn, tr.poi[u].len);
            For(o, 0, 25){
                int v = tr.poi[u].ch[o];
                if(!v) continue;
                tr.poi[v].to = ins(o, tr.poi[u].to); 
                q.push(v);
            }
        }
        For(i, 2, tot) vec[poi[i].fa].pb(i);
        For(i, 0, 25) poi[1].fail[i] = 1;
        dfs(1);
        dfs1(1);
        dfs2(1, 0);
    }
} sam;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int f[maxn + 5];
int main(){
	// freopen("in.txt", "r", stdin);
    // freopen("out1.txt", "w", stdout);
    tr.Init();
    sam.Init();
    read(t);
    while(t--){
        tr.init();
        scanf("%s", s + 1); n = strlen(s + 1);
        read(m);
        For(i, 1, n) a[i] = s[i] - 'a';
        For(i, 1, m){
            scanf("%s", s + 1);
            tr.ins(s);
        }
        sam.init();
        For(i, 0, n) f[i] = inf;
        int now = 1, len = 0;
        For(i, 1, n){
            if(!sam.poi[now].ch[a[i]]){
                now = sam.poi[now].fail[a[i]];
                len = sam.poi[now].len;
            }
            if(sam.poi[now].ch[a[i]]){
                len++;
                now = sam.poi[now].ch[a[i]];
            }
            chkmn(f[i], min(i - len, f[i - len]) + sam.poi[now].mn - len);
            int tem = sam.poi[now].to;
            while(tem){
                int to = sam.poi[tem].len;
                chkmn(f[i], min(i - to, f[i - to]) + sam.poi[tem].mn - to);
                tem = sam.poi[tem].to;
            }
            chkmn(f[i], f[i - 1] + 1);
        }
        printf("%d\n", f[n]);
    }
    return 0;
}
