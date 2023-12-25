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

int n, m, q, a[maxn + 5], as[maxn + 5], bas = 700;
struct Que{
    int l, r, id;
} que[maxn + 5];
bool operator < (cst Que &x, cst Que &y){
    if(x.l / bas != y.l / bas) return x.l / bas < y.l / bas;
    return x.r < y.r;
}
class Trie{
    public:
        int tot = 1;
        class Node{
            public:
                int ch[2], sum;
                bool cnt;
                Node(){ch[0] = ch[1] = 0, sum = 0, cnt = 0;}
        } poi[20 * maxn + 5];
        Trie(){}
        void ins(int x){
            int now = 1;
            poi[now].cnt ^= 1;
            poi[now].sum ^= x;
            For(i, 0, 19){
                int to = x & 1;
                if(!poi[now].ch[to]) poi[now].ch[to] = ++tot;
                x >>= 1;
                now = poi[now].ch[to];
                poi[now].cnt ^= 1;
                poi[now].sum ^= x;
            }
        }
        void add(int rt){
            // return;
            if(!rt) return;
            int &ls = poi[rt].ch[0], &rs = poi[rt].ch[1];
            add(rs);
            swap(ls, rs);
            poi[rt].sum = ((poi[ls].sum ^ poi[rs].sum) << 1) ^ (poi[rs].cnt & 1);
        }
        void del(int rt){
            // return;
            if(!rt) return;
            int &ls = poi[rt].ch[0], &rs = poi[rt].ch[1];
            del(ls);
            swap(ls, rs);
            poi[rt].sum = ((poi[ls].sum ^ poi[rs].sum) << 1) ^ (poi[rs].cnt & 1);
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

int L = 1, R = 0;
int sol(int l, int r){
    while(L > l){
        tr.add(1);
        L--;
        if(a[L]) tr.ins(0);
    }
    while(R < r){
        R++;
        if(a[R]) tr.ins(R - L);
    }
    while(L < l){
        if(a[L]) tr.ins(0);
        tr.del(1);
        L++;
    }
    while(R > r){
        if(a[R]) tr.ins(R - L);
        R--;
    }
    return tr.poi[1].sum;
}

int main(){
	freopen("in.txt", "r", stdin);
    LL T = clock();
    read(n); read(m);
    For(i, 1, n){
        int x; read(x);
        a[x] ^= 1;
    }
    read(q);
    For(i, 1, q){
        int l, r; read(l); read(r);
        que[i] = {l, r, i};
    }
    sort(que + 1, que + q + 1);
    For(i, 1, q){
        int l = que[i].l, r = que[i].r, id = que[i].id;
        as[id] = sol(l, r);
    }
    // For(i, 1, q) printf(as[i] ? "A" : "B");
    cout << clock() - T << endl;
    return 0;
}
