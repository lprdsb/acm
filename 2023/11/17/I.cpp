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
#define maxn 2000000
using namespace std;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int tr[maxn + 5], ok[maxn + 5], n, m;
void ins(int x, int y){
    ok[x] += y;
    while(x <= maxn) tr[x] += y, x += x & -x;
}
int que(int x){
    int res = 0;
    while(x) res += tr[x], x -= x & -x;
    return res;
}

struct Opt{
    int x, y, w, ty;
};

struct Que{
    int x, y, k, id;
};

int as[maxn + 5];

void sol(int l, int r, vector<Opt> &opt, vector<Que> &qq){
    if(l == r){
        For(i, 0, qq.size() - 1) as[qq[i].id] = l;
        return;
    }
    int mid = l + r >> 1;
    vector<Opt> optl, optr;
    vector<Que> ql, qr;
    int now = 0;
    for(auto [x, y, k, id] : qq){
        while(now < opt.size() && opt[now].x <= x){
            if(opt[now].w <= mid) ins(opt[now].y, opt[now].ty);
            now++;
        }
        int tem = que(y);
        if(k > tem) qr.pb({x, y, k - tem, id});
        else ql.pb({x, y, k, id});
    }
    while(now){
        now--;
        if(opt[now].w <= mid) ins(opt[now].y, -opt[now].ty);
    }
    For(i, 0, opt.size() - 1){
        if(opt[i].w <= mid) optl.pb(opt[i]);
        else optr.pb(opt[i]);
    }
    sol(l, mid, optl, ql);
    sol(mid + 1, r, optr, qr);
}


vector<Opt> opt;
vector<Que> qq;

int b[maxn + 5], cnt = 0;
int b1[maxn + 5], cnt1 = 0;
int main(){
	// freopen("in.txt", "r", stdin);
    read(n);
    For(i, 0, n - 1){
        int x1, y1, x2, y2, w; read(x1); read(y1); read(x2); read(y2); read(w);
        opt.pb({x1, y1, w, 1}); opt.pb({x1, y2 + 1, w, -1}); opt.pb({x2 + 1, y1, w, -1}); opt.pb({x2 + 1, y2 + 1, w, 1});
        b[++cnt] = w;
        b1[++cnt1] = y1;
        b1[++cnt1] = y2 + 1;
    }
    sort(b + 1, b + cnt + 1);
    cnt = unique(b + 1, b + cnt + 1) - b - 1;
    For(i, 0, opt.size() - 1) opt[i].w = lower_bound(b + 1, b + cnt + 1, opt[i].w) - b;
    // cout << cnt << endl;


    read(m);
    For(i, 0, m - 1){
        int x, y, k; read(x); read(y); read(k);
        qq.pb({x, y, k, i});
        b1[++cnt1] = y;
    }

    
    sort(b1 + 1, b1 + cnt1 + 1);
    cnt1 = unique(b1 + 1, b1 + cnt1 + 1) - b1 - 1;
    For(i, 0, opt.size() - 1) opt[i].y = lower_bound(b1 + 1, b1 + cnt1 + 1, opt[i].y) - b1;
    For(i, 0, m - 1) qq[i].y = lower_bound(b1 + 1, b1 + cnt1 + 1, qq[i].y) - b1;

    sort(qq.begin(), qq.end(), [](cst Que &_x, cst Que &_y){return _x.x < _y.x;});
    sort(opt.begin(), opt.end(), [](cst Opt &_x, cst Opt &_y){return _x.x < _y.x;});

    b[cnt + 1] = -1;
    sol(1, cnt + 1, opt, qq);
    For(i, 0, m - 1) printf("%d\n", b[as[i]]);
    return 0;
}
