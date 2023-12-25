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

int n, m, a[maxn + 5];
vector<int> d[maxn + 5];
LL sum_tr[maxn + 5];
void sum_ins(int x, int val){while(x <= n) sum_tr[x] += val, x += x & -x;}
LL sum_que(int x){
    LL asi = 0;
    while(x) asi += sum_tr[x], x -= x & -x;
    return asi;
}
struct Poi{int ch[2], fa, id;};
class Tree{
    public:
        int tot = 1;
        vector<Poi> poi;
        Tree(){
            poi.pb({{0, 0}, 0, 0});
            poi.pb({{0, 0}, 0, inf});
        }
        void ins(int x){
            int now = poi[1].ch[0];
            poi[1].ch[0] = poi[now].fa = ++tot;
            poi.pb({{now, 0}, 1, x});
        }
        void rot(int rt){
            int fa = poi[rt].fa, ffa = poi[fa].fa, o = poi[fa].ch[1] == rt;
            if(ffa) poi[poi[ffa].ch[poi[ffa].ch[1] == fa] = rt].fa = ffa;
            poi[poi[fa].ch[o] = poi[rt].ch[!o]].fa = fa;
            poi[poi[rt].ch[!o] = fa].fa = rt;
        }
        void spy(int rt){while(poi[rt].fa != 1) rot(rt);}
        int lower_bound(int x){
            int now = 1, asi = 1;
            while(666){
                if(poi[now].id == x) return now;
                else if(poi[now].id > x){
                    asi = now;
                    if(poi[now].ch[0]) now = poi[now].ch[0];
                    else break;
                }
                else{
                    if(poi[now].ch[1]) now = poi[now].ch[1];
                    else break;
                }
            }
            return asi;
        }
        void del(int rt){
            spy(rt);
            int now = poi[rt].ch[1];
            while(poi[now].ch[0]) now = poi[now].ch[0];
            if(now){
                spy(now);
                poi[poi[now].ch[0] = poi[rt].ch[0]].fa = now;
            }
            else poi[poi[1].ch[0] = poi[rt].ch[0]].fa = 1;
        }
        vector<int> st;
        void sol(int l, int r, int x){
            int ll = lower_bound(l), rr = lower_bound(r + 1);
            // cout << ll << endl;
            if(ll == 1 || ll == rr) return;
            spy(ll);
            if(rr != 1) spy(rr);
            st.clear();
            st.pb(ll);
            queue<int> q;
            if(poi[ll].ch[1]) q.push(poi[ll].ch[1]);
            while(q.size()){
                int now = q.front(); q.pop();
                st.pb(now);
                For(o, 0, 1) if(poi[now].ch[o]) q.push(poi[now].ch[o]);
            }
            for(auto i : st){
                if(a[poi[i].id] % x == 0){
                    // cout << x << " " << poi[i].id << endl;
                    sum_ins(poi[i].id, -a[poi[i].id]);
                    a[poi[i].id] /= x;
                    sum_ins(poi[i].id, a[poi[i].id]);
                }
                if(a[poi[i].id] % x) del(i);
            }
        }
} tr[maxn + 5];

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
    For(i, 2, maxn) for(int j = i; j <= maxn; j += i) d[j].pb(i);
	read(n); read(m);
    For(i, 1, n){
        read(a[i]);
        sum_ins(i, a[i]);
        for(auto j : d[a[i]]) tr[j].ins(i);
    }
    // cout << sum_que(n) << endl;
    while(m--){
        int op, l, r, x; read(op);
        if(op == 1){
            read(l); read(r); read(x);
            tr[x].sol(l, r, x);
        }
        else{
            read(l); read(r);
            printf("%lld\n", sum_que(r) - sum_que(l - 1));
        }
    }
    return 0;
}
