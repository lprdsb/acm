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

int n, m, hd[maxn + 5], len = 0;
struct Edge{
    int v, net, ok;
} e[2 * maxn + 5];
int in[maxn + 5];
void add(int u, int v){
    e[len] = {v, hd[u], 1};
    hd[u] = len++;
    in[v]++;
}

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int w[maxn + 5], ok[maxn + 5], col[maxn + 5], del[maxn + 5], to[maxn + 5];
LL as = 0;

struct Line{
    int s, t;
    vector<int> vec;
    vector<pair<int, LL> > pre, suf;
    Line(){}
    Line(int _s, int _t, vector<int> _vec){
        s = _s;
        t = _t;
        vec = _vec;
        LL s1 = 0, s2 = 0;
        For(i, 0, _vec.size() - 1){
            to[_vec[i]] = i;
            s1 += w[_vec[i]];
            s2 += 1ll * i * w[_vec[i]];
            pre.pb({s1, s2});
        }
        s1 = s2 = 0;
        Rof(i, _vec.size() - 1, 0){
            s1 += w[_vec[i]];
            s2 += 1ll * (_vec.size() - 1 - i) * w[_vec[i]];
            suf.pb({s1, s2});
        }
        std::reverse(suf.begin(), suf.end());
    }
    LL get_val(int ty, int l, int r){
        r = min((int)vec.size() - 1, r);
        l = max(0, l);
        if(!ty) return pre[r].sec - pre[l].sec - 1ll * l * (pre[r].fir - pre[l].fir);
        else return suf[l].sec - suf[r].sec - 1ll * (vec.size() - 1 - r) * (suf[l].fir - suf[r].fir);
    }
} lin[maxn + 5];

int id[maxn + 5], dis[100][maxn + 5], tot = 0, iid[maxn + 5];
int pre[maxn + 5], cnt = 0;
vector<int> ch[maxn + 5];
int main(){
    memset(dis, inf, sizeof dis);
	// freopen("in.txt", "r", stdin);
    memset(hd, -1, sizeof hd);
    read(n); read(m);
    For(i, 1, n) w[i] = 1;
    For(i, 1, m){
        int u, v; read(u); read(v);
        add(u, v); add(v, u);
    }
    queue<int> q;
    For(i, 1, n) if(in[i] == 1) q.push(i);
    while(q.size()){
        int u = q.front(); q.pop();
        del[u] = 1;
        Tra(u, i) if(e[i].ok){
            int v = e[i].v;
            as += 1ll * w[u] * (n - w[u]);
            w[v] += w[u];
            e[i].ok = e[i ^ 1].ok = 0;
            in[v]--; in[u]--;
            if(in[v] == 1) q.push(v);
        }
    }
    int fl = 0;
    For(i, 1, n) if(in[i] >= 3) ok[i] = 1, fl = 1;
    if(!fl) For(i, 1, n) if(in[i] == 2){
        ok[i] = 1;
        break;
    }
    // cout << del[2] << endl;
    For(i, 1, n) if(ok[i]){
        id[i] = ++tot;
        iid[tot] = i;
        q.push(i);
        dis[tot][i] = 0;
        while(q.size()){
            int u = q.front(); q.pop();
            Tra(u, i) if(e[i].ok){
                int v = e[i].v;
                if(dis[tot][v] > dis[tot][u] + 1){
                    dis[tot][v] = dis[tot][u] + 1;
                    q.push(v);
                }
            }
        }
    }
    
    For(i, 1, n) if(!del[i] && !ok[i]) Tra(i, j) if(e[j].ok){
        int v = e[j].v;
        ch[i].pb(v);
    }
    For(i, 1, n) if(!del[i] && !ok[i] && !col[i]){
        col[i] = ++cnt;
        int now = ch[i][0], s, t;
        vector<int> vec, vec1, vec2;
        while(666){
            if(ok[now]){
                s = now;
                break;
            }
            col[now] = cnt;
            vec1.pb(now);
            now = ch[now][col[ch[now][0]] != 0];
        }
        now = ch[i][1];
        while(666){
            if(ok[now]){
                t = now;
                break;
            }
            col[now] = cnt;
            vec2.pb(now);
            now = ch[now][col[ch[now][0]] != 0];
        }
        std::reverse(vec1.begin(), vec1.end());
        for(auto j : vec1) vec.pb(j);
        vec.pb(i);
        for(auto j : vec2) vec.pb(j);
        lin[cnt] = Line(s, t, vec);
        // for(auto j : vec) cout << j << " "; cout << endl;
    }
    // cout << tot << endl;
    LL asi = 0;
    For(i, 1, n) if(!del[i]){
        LL asii = 0;
        For(j, 1, cnt) if(col[i] != j){
            int sz = lin[j].vec.size();
            int tem = (dis[id[lin[j].t]][i] - dis[id[lin[j].s]][i] + sz - 2) / 2;
            if(tem >= 0) asii += 1ll * (dis[id[lin[j].s]][i] + 1) * lin[j].pre[min(sz - 1, tem)].fir + lin[j].pre[min(sz - 1, tem)].sec;
            // if(i == 1) cout << dis[id[lin[j].s]][i] << endl;
            if(tem <= sz - 2) asii += 1ll * (dis[id[lin[j].t]][i] + 1) * lin[j].suf[min(sz - 1, tem + 1)].fir + lin[j].suf[min(sz - 1, tem + 1)].sec;
        }
        For(j, 1, tot) asii += dis[j][i] * w[iid[j]];
        if(!ok[i]){
            int c = col[i], sz = lin[c].vec.size();
            if(to[i] <= sz - 1 - to[i]){
                int d = to[i] + 1 + dis[id[lin[c].s]][lin[c].t];
                int tem = (to[i] + d + sz) / 2;
                asii += lin[c].get_val(1, 0, to[i]) + lin[c].get_val(0, to[i], tem);
                if(tem <= sz - 2) asii += 1ll * (d + 1) * lin[c].suf[min(sz - 1, tem + 1)].fir + lin[c].suf[min(sz - 1, tem + 1)].sec;
            }
            else{
                int d = sz - to[i] + dis[id[lin[c].s]][lin[c].t];
                int tem = (to[i] - d) / 2;
                asii += lin[c].get_val(1, tem, to[i]) + lin[c].get_val(0, to[i], sz - 1);
                // if(i == 1) cout << dis[] << endl;
                if(tem - 1 >= 0) asii += 1ll * (d + 1) * lin[c].pre[min(sz - 1, tem - 1)].fir + lin[c].pre[min(sz - 1, tem - 1)].sec;
            }
        }
        // if(i == 1) cout << asii << endl;
        asi += w[i] * asii;
    }
    printf("%lld\n", as + asi / 2);
    return 0;
}
