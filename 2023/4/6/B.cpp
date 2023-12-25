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

int n, q;
struct Node{int ch[2], cnt[2], fa, lpr;};
class Lct_Tree{
    public:
        int tot = 0;
        Node poi[maxn + 5];
        Lct_Tree(){}
        void init(int _tot){
            tot = _tot;
            For(i, 1, tot) poi[i].cnt[0] = poi[i].cnt[1] = 1;
        }
        void upd(int rt){poi[rt].cnt[1] = poi[rt].cnt[0] + poi[poi[rt].ch[0]].cnt[1] + poi[poi[rt].ch[1]].cnt[1];}
        void mson(int rt){
            swap(poi[rt].ch[0], poi[rt].ch[1]);
            poi[rt].lpr ^= 1;
        }
        void spr(int rt){
            if(poi[rt].lpr){
                mson(poi[rt].ch[0]);
                mson(poi[rt].ch[1]);
                poi[rt].lpr = 0;
            }
        }
        void chk(){
            cout << "asd" << endl;
            For(i, 1, n) cout << i << " " << is_rt(i) << " " << poi[i].fa << " " << poi[i].cnt[0] << endl;
        }
        void rot(int rt){
            int fa = poi[rt].fa;
            spr(fa); spr(rt);
            int is_ls = poi[fa].ch[0] == rt;
            if(!is_rt(fa)) poi[poi[fa].fa].ch[poi[poi[fa].fa].ch[1] == fa] = rt;
            poi[rt].fa = poi[fa].fa;
            poi[poi[fa].ch[!is_ls] = poi[rt].ch[is_ls]].fa = fa;
            poi[poi[rt].ch[is_ls] = fa].fa = rt;
            upd(fa); upd(rt);
        }
        bool is_rt(int rt){return poi[poi[rt].fa].ch[0] != rt && poi[poi[rt].fa].ch[1] != rt;}
        void spy(int x){while(!is_rt(x)) rot(x); spr(x);}
        void acc(int x){
            int now = x, pre = 0;
            while(now){
                spy(now);
                poi[now].cnt[0] += poi[poi[now].ch[1]].cnt[1] - poi[pre].cnt[1];
                poi[now].ch[1] = pre;
                pre = now;
                now = poi[now].fa;
            }
            spy(x);
        }
        void mkrt(int x){acc(x); mson(x);}
        void link(int u, int v){
            mkrt(u); mkrt(v);
            poi[v].fa = u;
            poi[u].cnt[0] += poi[v].cnt[1];
            poi[u].cnt[1] += poi[v].cnt[1];
        }
        void cut(int u, int v){
            mkrt(u); acc(v);
            poi[v].cnt[1] -= poi[u].cnt[1];
            poi[v].ch[0] = poi[u].fa = 0;
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
    tr.init(n);
    while(q--){
        char c; cin >> c;
        int x, y; read(x); read(y);
        if(c == 'A') tr.link(x, y);
        else{
            tr.mkrt(x); tr.acc(y);
            printf("%lld\n", 1ll * tr.poi[x].cnt[1] * (tr.poi[y].cnt[1] - tr.poi[x].cnt[1]));
        }
    }
    return 0;
}
