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

int n, m, a[maxn + 5];

int poi_tot = 0;
struct Poi{
    Poi *ch[2];
    int sz, val, ok;
} poi[500 * maxn + 5];
Poi *get_new(){
    poi[++poi_tot] = {};
    return &poi[poi_tot];
}
Poi *get_o(Poi *rt, int o){
    assert(rt);
    if(!rt->ch[o]) rt->ch[o] = get_new();
    return rt->ch[o];
}
void upd(Poi *rt){
    rt->sz = rt->val = 0;
    For(o, 0, 1) if(rt->ch[o]) rt->sz += rt->ch[o]->sz, rt->val += rt->ch[o]->val;
}
Poi *merge(int dep, Poi *rt1, Poi *rt2){
    if(!rt1) return rt2;
    if(!rt2) return rt1;
    rt1->sz += rt2->sz;
    rt1->val += rt2->val;
    rt1->ok += rt2->ok;
    if(dep != 20){
        rt1->ch[0] = merge(dep + 1, rt1->ch[0], rt2->ch[0]);
        rt1->ch[1] = merge(dep + 1, rt1->ch[1], rt2->ch[1]);
    }
    return rt1;
}

struct Tree{
    Poi *Rt;
    int rev;
    Tree(){Rt = get_new();}
    void ins(int x, int y){
        Poi *now = Rt;
        Rt->sz = 1;
        Rt->val = y;
        Rof(i, 19, 0){
            now = get_o(now, (x >> i) & 1);
            now->sz = 1;
            now->val = y;
        }
        now->ok = y;
    }
    Poi *Split(int dep, Poi *rt, int x){
        if(dep == 20){
            if(x == rt->sz) return 0;
            Poi *res = get_new();
            res->sz = rt->sz - x;
            if(rev){
                res->val = rt->val;
                res->ok = rt->ok;
                rt->val = rt->ok = 0;
            }
            rt->sz = x;
            return res;
        }
        Poi *res = get_new();
        if(rt->ch[0] && x <= rt->ch[0]->sz){
            res->ch[1] = rt->ch[1];
            rt->ch[1] = 0;
            res->ch[0] = Split(dep + 1, rt->ch[0], x);
        }
        else{
            if(rt->ch[0]) x -= rt->ch[0]->sz;
            res->ch[0] = 0;
            res->ch[1] = Split(dep + 1, rt->ch[1], x);
        }
        upd(rt); upd(res);
        return res;
    }
    Poi *spilt(int x){
        if(rev){
            Poi *tem = Rt;
            Rt = Split(0, tem, tem->sz - x);
            return tem;
        }
        return Split(0, Rt, x);
    }
    int Que(int dep, Poi *rt, int x){
        if(!x) return 0;
        if(dep == 20){
            if(!rev || x == rt->sz) return rt->val;
            return 0;
        }
        int res = 0;
        if(rt->ch[0]){
            if(rt->ch[0]->sz >= x){
                return Que(dep + 1, rt->ch[0], x);
            }
            res += rt->ch[0]->val;
            x -= rt->ch[0]->sz;
        }
        return res + Que(dep + 1, rt->ch[1], x);
    }
    int que(int x){
        return rev ? Rt->val - Que(0, Rt, Rt->sz - x) : Que(0, Rt, x);
    }
};

struct Seg{
    int l, r, cnt;
    Tree tr;
};
bool operator < (Seg _x, Seg _y){return _x.l < _y.l;}
set<Seg> se;

template <class T>
void read(T &x){
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

void cut(int x){
    if(!x) return;
    auto it = --se.lower_bound({x + 1});
    if(it->r == x) return;
    Seg tem = *it;
    se.erase(it);
    Tree tem1 = tem.tr;
    tem1.Rt = tem.tr.spilt(x - tem.l + 1);
    se.insert({tem.l, x, tem.cnt, tem.tr});
    se.insert({x + 1, tem.r, tem.cnt + tem.tr.Rt->val, tem1});
}

int vis[maxn + 5];
int main(){
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    read(n); read(m);
    int cnt = 0;
    For(i, 1, n){
        read(a[i]);
        Tree tem;
        tem.ins(a[i], !vis[a[i]]);
        se.insert({i, i, cnt, tem});
        cnt += !vis[a[i]];
        vis[a[i]] = 1;
    }
    int c = 0;
    For(o, 1, m){
        int l, r, x; read(l); read(r); read(x); l ^= c; r ^= c; x ^= c;
        int rev = 0;
        if(l > r) swap(l, r), rev = 1;
        cut(l - 1); cut(r);
        vector<Seg> vec;
        auto it = --se.lower_bound({l + 1});
        while(it != se.end() && it->l <= r){
            vec.pb(*it);
            it++;
        }
        if(vec.size() != 1 || vec[0].tr.rev != rev){
            for(auto i : vec) se.erase(i);
            For(i, 1, vec.size() - 1) vec[0].tr.Rt = merge(0, vec[0].tr.Rt, vec[i].tr.Rt);
            vec[0].r = r;
            vec[0].tr.rev = rev;
            se.insert(vec[0]);
        }
        it = --se.lower_bound({x + 1});
        Seg tem = *it;
        printf("%d\n", c = tem.cnt + tem.tr.que(x - tem.l + 1));
    }
    return 0;
}
