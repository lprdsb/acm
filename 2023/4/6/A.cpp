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

int t;

struct Node{int val, ch[2], cnt[2], fa;};
class Splay_Tree{
    public:
        int tot = 1;
        Node poi[maxn + 5];
        Splay_Tree(){poi[1].val = inf;}
        void upd(int rt){poi[rt].cnt[1] = poi[rt].cnt[0] + poi[poi[rt].ch[0]].cnt[1] + poi[poi[rt].ch[1]].cnt[1];}
        void rot(int rt){
            int fa = poi[rt].fa, is_ls = poi[fa].ch[0] == rt;
            poi[poi[poi[fa].fa].ch[poi[poi[fa].fa].ch[1] == fa] = rt].fa = poi[fa].fa;
            poi[poi[fa].ch[!is_ls] = poi[rt].ch[is_ls]].fa = fa;
            poi[poi[rt].ch[is_ls] = fa].fa = rt;
            upd(fa); upd(rt);
        }
        void spy(int x){while(poi[x].fa != 1) rot(x);}
        int find(int x){
            int now = 1;
            while(poi[now].val != x){
                int to = x > poi[now].val;
                if(!poi[now].ch[to]) poi[poi[now].ch[to] = ++tot] = {x, {0, 0}, {0, 0}, now};
                now = poi[now].ch[to];
            }
            spy(now);
            return now;
        }
        void add(int x, int val){
            poi[1].cnt[1] += val;
            int now = find(x);
            poi[now].cnt[0] += val;
            poi[now].cnt[1] += val; 
        }
        int find_rank(int x){return poi[poi[find(x)].ch[0]].cnt[1] + 1;}
        int find_index(int x){
            int now = 1;
            while(666){
                if(x > poi[poi[now].ch[0]].cnt[1]){
                    x -= poi[poi[now].ch[0]].cnt[1];
                    if(x > poi[now].cnt[0]){
                        x -= poi[now].cnt[0];
                        now = poi[now].ch[1];
                    }
                    else break;
                }
                else now = poi[now].ch[0];
            }
            spy(now);
            return now;
        }
        int find_pre(int x){return find_index(find_rank(x) - 1);}
        int find_suf(int x){
            int now = find(x);
            return find_index(poi[poi[now].ch[0]].cnt[1] + poi[now].cnt[0] + 1);
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
    read(t);
    while(t--){
        int opt, x; read(opt); read(x);
        if(opt == 1) tr.add(x, 1);
        if(opt == 2) tr.add(x, -1);
        if(opt == 3) printf("%d\n", tr.find_rank(x));
        if(opt == 4) printf("%d\n", tr.poi[tr.find_index(x)].val);
        if(opt == 5) printf("%d\n", tr.poi[tr.find_pre(x)].val);
        if(opt == 6) printf("%d\n", tr.poi[tr.find_suf(x)].val);
    }
    return 0;
}
