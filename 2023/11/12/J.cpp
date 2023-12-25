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
#define maxn 1000000
using namespace std;

int T, n, m;

int poi_tot = 0;
struct Poi{
    Poi *ch[26], *to;
    int len, deg;
    vector<pair<Poi*, int> > edge;
    int ss;
} poi[2 * maxn + 5];
Poi *get_new(){
    poi[++poi_tot] = {};
    return &poi[poi_tot];
}
Poi *get_o(Poi *rt, int o){
    if(!rt->ch[o]) rt->ch[o] = get_new();
    return rt->ch[o];
}

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

vector<Poi*> used;
void add(Poi *u, Poi *v, int val){
    u->edge.pb({v, val});
    u->deg--;
    v->deg++;
    used.pb(u);
    used.pb(v);
}

char s[maxn + 5];
vector<Poi*> to[2][2][maxn + 5];

vector<int> st;
void dfs(Poi *u){
    while(u->ss < u->edge.size()){
        Poi *v = u->edge[u->ss].fir;
        int val = u->edge[u->ss].sec;
        u->ss++;
        dfs(v);
        st.pb(val);
    }
}

void work(){
    read(n); read(m);
    Poi *Rt[2] = {get_new(), get_new()};
    For(i, 1, n) For(o1, 0, 1) For(o2, 0, 1) to[o1][o2][i].resize(m + 5);
    For(i, 1, n){
        scanf("%s", s + 1);
        Poi *now = Rt[0];
        For(j, 1, m){
            now = get_o(now, s[j] - 'a');
            to[0][0][i][j] = now;
        }
        now = Rt[1];
        Rof(j, m, 1){
            now = get_o(now, s[j] - 'a');
            to[0][1][i][j] = now;
        }
        to[0][0][i][0] = Rt[0];
    }
    For(o1, 0, 1){
        queue<Poi*> q;
        For(o2, 0, 25){
            if(!Rt[o1]->ch[o2]) Rt[o1]->ch[o2] = Rt[o1];
            else{
                Rt[o1]->ch[o2]->len = 1;
                Rt[o1]->ch[o2]->to = Rt[o1];
                q.push(Rt[o1]->ch[o2]);
            }
        }
        while(q.size()){
            Poi *u = q.front(); q.pop();
            For(o2, 0, 25){
                if(!u->ch[o2]) u->ch[o2] = u->to->ch[o2];
                else{
                    u->ch[o2]->len = u->len + 1;
                    u->ch[o2]->to = u->to->ch[o2];
                    q.push(u->ch[o2]);
                }
            }
        }
    }
    For(i, 1, n){
        scanf("%s", s + 1);
        Poi *now = Rt[0];
        For(j, 1, m) now = now->ch[s[j] - 'a'];
        while(now->len){
            to[1][1][i][m - now->len + 1] = now;
            now = now->to;
        }
        now = Rt[1];
        Rof(j, m, 1) now = now->ch[s[j] - 'a'];
        while(now){
            to[1][0][i][now->len] = now;
            now = now->to;
        }
        to[1][1][i][m + 1] = Rt[0];
    }
    int fl1 = 0;
    For(o, 0, m - 1){
        int fl2 = 0;
        For(i, 1, n) add(to[0][0][i][o], to[0][1][i][o + 1], i);
        For(i, 1, n){
            if(to[1][0][i][m - o] && to[1][1][i][m - o + 1]) add(to[1][0][i][m - o], to[1][1][i][m - o + 1], i);
            else{
                fl2 = 1;
                break;
            }
        }
        if(!fl2){
            for(auto v : used) if(v->deg){
                fl2 = 1;
                break;
            }
            if(!fl2){
                dfs(used[0]);
                if(st.size() == 2 * n) fl1 = 1;
                if(fl1){
                    reverse(st.begin(), st.end());
                    for(int i = 0; i < st.size(); i += 2) printf("%d ", st[i]); puts("");
                    for(int i = 1; i < st.size(); i += 2) printf("%d ", st[i]); puts("");
                }
                st.resize(0);
            }
        }
        for(auto v : used){
            v->edge.resize(0);
            v->deg = v->ss = 0;
        }
        used.resize(0);
        if(fl1) break;
    }
    if(!fl1) puts("-1");
    poi_tot = 0;
    For(i, 1, n){
        For(o1, 0, 1) For(o2, 0, 1) to[o1][o2][i].resize(0);
    }
}

int main(){
	// freopen("in.txt", "r", stdin);
    read(T);
    while(T--) work();
    return 0;
}
