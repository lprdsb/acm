#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define db double
#define pint pair<int,int>
#define mk make_pair
#define pb push_back
#define eb emplace_back
#define ins insert
#define fi first
#define se second
#define For(x,y,z) for(int x=(y);x<=(z);x++)
#define Rep(x,y,z) for(int x=(y);x>=(z);x--)
using namespace std;
const int MAXN = 4e5 + 5;
char buf[1<<12],*pp1=buf,*pp2=buf,nc;int ny;
// inline char gc() {return pp1==pp2&&(pp2=(pp1=buf)+fread(buf,1,1<<12,stdin),pp1==pp2)?EOF:*pp1++;}
inline char gc() {return getchar();}
inline int read(){
	int x=0;ny=1;while(nc=gc(),(nc<48||nc>57)&&nc!=EOF)if(nc==45)ny=-1;if(nc<0)return nc;
	x=nc-48;while(nc=gc(),47<nc&&nc<58&&nc!=EOF)x=(x<<3)+(x<<1)+(nc^48);return x*ny;
}
int n, Len;
char s[MAXN], t[MAXN];
int len[MAXN << 1], fa[MAXN << 1], ch[26][MAXN << 1], last = 1, tot = 1, f[MAXN << 1];
int Cnt[MAXN << 1], id[MAXN << 1], pos[MAXN << 1], ff[MAXN << 1];
int son[26][MAXN], rt = 1, N = 1, Val[MAXN], tag[MAXN], p[MAXN];

inline void Init() {
    For(i, 1, tot) {
        len[i] = fa[i] = 0, f[i] = 1e9, Cnt[i] = 0;
        For(c, 0, 25) ch[c][i] = 0;
    }
    last = tot = 1;
    For(i, 1, N) {
        tag[i] = 0, Val[i] = 1e9;
        For(c, 0 ,25) son[c][i] = 0;
    }
    rt = 1, N = 1;
}
inline void ins(int c, int val) {
    int p = last, np = last = ++tot;
    len[np] = len[p] + 1, f[np] = val;
    for(; p && !ch[c][p]; p = fa[p]) ch[c][p] = np;
    if(!p) {fa[np] = 1; return ;}
    int q = ch[c][p];
    if(len[q] == len[p] + 1) {fa[np] = q; return ;}
    int nq = ++tot; For(c, 0, 25) ch[c][nq] = ch[c][q];
    fa[nq] = fa[q], len[nq] = len[p] + 1, f[nq] = f[q], fa[np] = fa[q] = nq;
    for(; p && ch[c][p] == q; p = fa[p])  ch[c][p] = nq;
}
inline void Ins(char*s, int val) {
    int n = strlen(s + 1), x = rt;
    if(val != -1) Val[x] = min(Val[x], val);
    For(i, 1, n) {
        int c = s[i] - 'a';
        if(!son[c][x]) son[c][x] = ++N, Val[N] = 1e9;
        x = son[c][x];
        if(val != - 1) Val[x] = min(Val[x], val);
        else tag[x] = i;
    }
}
int Last[MAXN]; 
inline void build() {
    queue<int> q; Last[rt] = 1, tot = 1;
    q.push(rt);
    while(!q.empty()) {
        int x = q.front(); q.pop();
        if(tag[x]) p[tag[x]] = Last[x];
        // cerr << x << ' ' << tag[x] << '\n';
        For(c, 0, 25) if(son[c][x]){
            last = Last[x], ins(c, Val[son[c][x]]), Last[son[c][x]] = last;
            q.push(son[c][x]);
        }
    } 
}
int g[MAXN];
inline void Solve() {
    Init();
    scanf("%s", s + 1), Len = strlen(s + 1), n = read();
    Ins(s, -1);
    For(i, 1, n) {
        scanf("%s", t + 1);
        int l = strlen(t + 1);
        Ins(t, l);
    }
    build();
    For(i, 1, tot) Cnt[len[i]]++;
    For(i, 1, tot) Cnt[i] += Cnt[i -1];
    For(i, 1, tot) pos[i] = Cnt[len[i]]--, id[pos[i]] = i;
    Rep(i, tot, 1) {
        int x = id[i];
        f[fa[x]] = min(f[fa[x]], f[x]);
    } 
    For(i, 1, tot) {
        int x= id[i];
        if(f[x] != f[fa[x]]) ff[x] = x;
        else ff[x] = ff[fa[x]];
    }
    int res = 1e9;
    g[0] = 0;
    For(i, 1, Len) {
        g[i] = g[i - 1] + 2;
        for(int x = p[i]; x; x = fa[ff[x]]) {
            res = min(res, f[x] - 2 * len[x]);
            g[i] = min(g[i], f[x] + g[i - len[x]]);
        }
    }
    int ans = 0;
    For(i, 1, Len) ans = min(ans, g[i] - 2 * i);
    if(ans == 0) {
        cout << res + Len << '\n';
    } else {
        cout << ans + Len << '\n';
    }
}
int main() {
	freopen("in.txt","r",stdin);
    // freopen("out2.txt", "w", stdout);
	// freopen("A.out","w",stdout);
    for(int t = read(); t--; ) {
        Solve();
    }
    // cerr << (db)clock()/CLOCKS_PER_SEC << '\n';
	return 0;
}