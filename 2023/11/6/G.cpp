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
#define maxn 500000
using namespace std;

int n, m, k;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

namespace c1{
    int vis[2][maxn + 5];
    void sol(){
        For(i, 1, k){
            int x1, x2, y; read(x1); read(x2); read(y);
            if(y < m - y + 1){
                if(y > maxn){
                    puts("NO");
                    return;
                }
                else vis[0][y] = 1;
            }
            else{
                y = m - y + 1;
                if(y > maxn){
                    puts("NO");
                    return;
                }
                else vis[1][y] = 1;
            }
        }
        For(i, 2, maxn) if(vis[i] && !vis[i - 1]){
            puts("NO");
            return;
        }
        puts("YES");
    }
}

namespace c2{
    vector<pair<int, int> > vec[maxn + 5];
    int poi_tot = 0;
    struct Poi{
        Poi *ch[2];
        int sum, lpr;
    } poi[4 * maxn + 5];
    Poi *get_new(){
        poi[++poi_tot] = {};
        return &poi[poi_tot];
    }
    Poi *get_o(Poi *rt, int o){
        if(!rt->ch[o]) rt->ch[o] = get_new();
        return rt->ch[o];
    }
    void mson(Poi *rt, int l, int r, int x){
        rt->sum += x * (r - l + 1);
        rt->lpr += x;
    }
    void spr(Poi *rt, int l, int r){
        if(rt->lpr){
            int mid = l + r >> 1;
            mson(get_o(rt, 0), l, mid, rt->lpr);
            mson(get_o(rt, 1), mid + 1, r, rt->lpr);
            rt->lpr = 0;
        }
    }
    void upd(Poi *rt){
        rt->sum = 0;
        For(o, 0, 1) if(rt->ch[o]) rt->sum += rt->ch[o]->sum; 
    }
    void ins(Poi *rt, int l, int r, int ql, int qr){
        if(ql <= l && qr >= r) return mson(rt, l, r, 1);
        spr(rt, l, r);
        int mid = l + r >> 1;
        if(ql <= mid) ins(get_o(rt, 0), l, mid, ql, qr);
        if(qr > mid) ins(get_o(rt, 1), mid + 1, r, ql, qr);
        upd(rt);
    }
    int que(Poi *rt, int l, int r, int ql, int qr){
        if(!rt) return 0;
        if(ql <= l && qr >= r) return rt->sum;
        spr(rt, l, r);
        int mid = l + r >> 1, res = 0;
        if(ql <= mid) res += que(rt->ch[0], l, mid, ql, qr);
        if(qr > mid) res += que(rt->ch[1], mid + 1, r, ql, qr);
        return res;
    }
    void sol(){
        if(m > maxn){
            puts("NO");
            return;
        }
        For(i, 1, k){
            int l, r, x; read(l); read(r); read(x);
            vec[x].pb({l, r});
        }
        LL res = 0;
        Poi *Rt = get_new();
        For(i, 1, m){
            int pre = 0;
            sort(vec[i].begin(), vec[i].end());
            for(auto [l, r] : vec[i]){
                if(l != pre + 1) res += 1 - que(Rt, 1, n, pre + 1, l - 1);
                pre = r;
            }
            if(pre != n) res += 1 - que(Rt, 1, n, pre + 1, n);
            poi_tot = 0;
            Rt = get_new();
            pre = 0;
            for(auto [l, r] : vec[i]){
                if(l != pre + 1) ins(Rt, 1, n, pre + 1, l - 1);
                pre = r;
            }
            if(pre != n) ins(Rt, 1, n, pre + 1, n);
        }
        if(res == 1) puts("YES");
        else puts("NO");
    }
}

int main(){
	// freopen("in.txt", "r", stdin);
    read(n); read(m); read(k);
    if(n == 1) c1::sol();
    else c2::sol();
    return 0;
}
