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

int n, m, d[maxn + 5], B = 600, q;

struct Node{
    Node *lhs, *rhs;
    int id;
} e1[maxn + 5], e2[maxn + 5];

Node hd[maxn + 5][2], to[maxn + 5];
pair<int, int> pa[maxn + 5];
int col[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

void add(Node &p, Node *e){
    e->rhs = p.rhs;
    if(p.rhs) p.rhs->lhs = e;
    
    p.rhs = e;
    e->lhs = &p;
}
void del(Node *p){
    if(p->lhs) p->lhs->rhs = p->rhs;
    if(p->rhs) p->rhs->lhs = p->lhs;
}

set<int> se;

int main(){
    cout << "asd" << endl;
	//freopen("in", "r", stdin);
    read(n); read(m);
    For(i, 1, m){
        int u, v; read(u); read(v);
        pa[i] = {u, v};
        d[u]++; d[v]++;
        e1[i].id = e2[i].id = i;
    }
    For(i, 1, m){
        if(d[pa[i].fir] > d[pa[i].sec]) swap(pa[i].fir, pa[i].sec);
        int u = pa[i].fir, v = pa[i].sec;
        add(hd[v][0], &e1[i]);
        add(to[u], &e2[i]);
    }
    read(q);
    while(q--){
        int x;
        char c; cin >> c;
        if(c == '+' || c == '-'){
            read(x);
            Node *now = to[x].rhs;
            while(now){
                int id = now->id, tem = pa[id].sec;
                se.erase(tem);
                del(&e1[id]);
                add(hd[tem][!col[x]], &e1[id]);
                if(hd[tem][!col[tem]].rhs) se.insert(tem);
                now = now->rhs;
            }
            se.erase(x);
            col[x] ^= 1;
            if(hd[x][!col[x]].rhs) se.insert(x);
        }
        if(c == '?'){
            while(se.size() && !hd[*se.begin()][!col[*se.begin()]].rhs) se.erase(se.begin());
            if(!se.size()) puts("0");
            else{
                int now = *se.begin(), id = hd[now][!col[now]].rhs->id;
                printf("%d\n", id);
                del(&e1[id]); del(&e2[id]);
            }
        }
    }
    return 0;
}
