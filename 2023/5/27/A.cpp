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
#define mod 1000000007
using namespace std;

int n, q;
LL a[maxn + 5];
struct Poi{
    int fa, ch[2], sz;
    LL lpr[2], val[2];
};
class Tree{
    public:
        Poi poi[maxn + 5];
        void mson(int rt, LL x1, LL x2){
            a[rt] += x1;
            a[rt] %= mod;
            poi[rt].val[0] += x1 * poi[rt].sz;
            poi[rt].val[0] %= mod;
            poi[rt].lpr[0] += x1;
            poi[rt].lpr[0] %= mod;

            poi[rt].val[1] += x2;
            poi[rt].val[1] %= mod;
            poi[rt].lpr[1] += x2;
            poi[rt].lpr[1] %= mod;
        }
        void spr(int rt){
            if(poi[rt].lpr[0] || poi[rt].lpr[1]){
                For(o, 0, 1) if(poi[rt].ch[o]) mson(poi[rt].ch[o], poi[rt].lpr[0], poi[rt].lpr[1]);
                poi[rt].lpr[0] = poi[rt].lpr[1] = 0;
            }
        }
        void upd(int rt){
            poi[rt].val[0] = (poi[poi[rt].ch[0]].val[0] + poi[poi[rt].ch[1]].val[0] + a[rt]) % mod;
            poi[rt].sz = poi[poi[rt].ch[0]].sz + poi[poi[rt].ch[1]].sz + 1;
        }
        void rot(int rt){
            int fa = poi[rt].fa, ffa = poi[fa].fa, to = poi[fa].ch[1] == rt;
            spr(fa); spr(rt);
            if(ffa) poi[poi[ffa].ch[poi[ffa].ch[1] == fa] = rt].fa = ffa;
            else poi[rt].fa = 0;
            if(poi[rt].ch[!to]) poi[poi[fa].ch[to] = poi[rt].ch[!to]].fa = fa;
            else poi[fa].ch[to] = 0;
            poi[poi[rt].ch[!to] = fa].fa = rt;
            upd(fa); upd(rt);
        }
        void splay(int rt){while(poi[rt].fa) rot(rt);}
        void mer(int tim, int rt1, int rt2){
            splay(rt1); splay(rt2);
            mson(rt1, 0, tim * poi[rt1].val[0] % mod);
            mson(rt2, 0, tim * poi[rt2].val[0] % mod);
            int now = rt1;
            while(poi[now].ch[1]) now = poi[now].ch[1];
            splay(now);
            spr(now);
            poi[poi[now].ch[1] = rt2].fa = now;
            poi[now].val[0] += poi[rt2].val[0];
            mson(now, 0, mod - tim * poi[now].val[0] % mod);
        }
        void mdy(int tim, int rt, int x){
            splay(rt);
            mson(rt, 0, tim * poi[rt].val[0] % mod);
            mson(rt, x, 0);
            mson(rt, 0, mod - tim * poi[rt].val[0] % mod);
        }
        int que(int tim, int rt){
            splay(rt);
            return (tim * poi[rt].val[0] % mod + poi[rt].val[1]) % mod;
        }
} tr;

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
    read(n); read(q);
    For(i, 1, n){
        read(a[i]);
        tr.poi[i].val[0] = a[i];
        tr.poi[i].sz = 1;
    }
    For(i, 1, q){
        int op; read(op);
        if(op == 1){
            int u, v; read(u); read(v);
            tr.mer(i, u, v);
        }
        if(op == 2){
            int u, v; read(u); read(v);
            tr.mdy(i, u, v);
        }
        if(op == 3){
            int u; read(u);
            printf("%d\n", tr.que(i, u));
        }
    }
	return 0;
}
