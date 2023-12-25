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
#define maxn 1000000
using namespace std;

int n, m;
struct Poi1{int ch[2], mx;} uni1 = {{0, 0}, 0};
vector<Poi1> poi1;
struct Poi2{int ch[2], hd;} uni2 = {{0, 0}, 0};
vector<Poi2> poi2;
int get_ch1(int rt, int o){
    if(!poi1[rt].ch[o]){
        poi1.pb(uni1);
        poi1[rt].ch[o] = poi1.size() - 1;
    }
    return poi1[rt].ch[o];
}
int get_ch2(int rt, int o){
    if(!poi2[rt].ch[o]){
        poi2.pb(uni2);
        poi2[rt].ch[o] = poi2.size() - 1;
    }
    return poi2[rt].ch[o];
}
int get_hd(int rt){
    if(!poi2[rt].hd){
        poi1.pb(uni1);
        poi2[rt].hd = poi1.size() - 1;
    }
    return poi2[rt].hd;
}
struct Opt{
    int op, l[2];
    char s[20];
} opt[maxn + 5];


template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

vector<int> b[2];
int st[2][maxn + 5];

void upd1(int rt){poi1[rt].mx = max(poi1[poi1[rt].ch[0]].mx, poi1[poi1[rt].ch[1]].mx);}
void mdy1(int rt, int l, int r, int x, int val){
    if(l == r) return (void)(poi1[rt].mx = val);
    int mid = l + r >> 1;
    if(x <= mid) mdy1(get_ch1(rt, 0), l, mid, x, val);
    else mdy1(get_ch1(rt, 1), mid + 1, r, x, val);
    upd1(rt);
}
void mdy2(int rt, int l, int r, int x1, int x2, int val){
    mdy1(get_hd(rt), 0, b[1].size() - 1, x2, val);
    // cout << l << " " << r << " " << poi1[poi2[rt].hd].mx << endl;
    if(l == r) return;
    int mid = l + r >> 1;
    if(x1 <= mid) mdy2(get_ch2(rt, 0), l, mid, x1, x2, val);
    else mdy2(get_ch2(rt, 1), mid + 1, r, x1, x2, val);
}

int que1(int rt, int l, int r, int ql, int qr){
    if(!poi1[rt].mx) return 0;
    if(ql <= l && qr >= r) return poi1[rt].mx;
    int mid = l + r >> 1, asi = 0;
    if(ql <= mid) asi = max(asi, que1(poi1[rt].ch[0], l, mid, ql, qr));
    if(qr > mid) asi = max(asi, que1(poi1[rt].ch[1], mid + 1, r, ql, qr));
    return asi;
}
int que2(int rt, int l, int r, int ql1, int qr1, int ql2, int qr2){
    // cout << l << " " << r << endl;
    if(!poi1[poi2[rt].hd].mx) return 0;
    if(ql1 <= l && qr1 >= r) return que1(poi2[rt].hd, 0, b[1].size() - 1, ql2, qr2);
    int mid = l + r >> 1, asi = 0;
    if(ql1 <= mid) asi = max(asi, que2(poi2[rt].ch[0], l, mid, ql1, qr1, ql2, qr2));
    if(qr1 > mid) asi = max(asi, que2(poi2[rt].ch[1], mid + 1, r, ql1, qr1, ql2, qr2));
    return asi;
}

int find(int ty, int x){
    int l = 0, r = b[ty].size() - 1;
    while(l < r){
        int mid = l + r >> 1;
        if(b[ty][mid] >= x) r = mid;
        else l = mid + 1;
    }
    return l;
}

int main(){
	// freopen("in.txt", "r", stdin);
    poi1.pb(uni1); poi2.pb(uni2); poi2.pb(uni2);
    read(n); read(m);
    For(i, 1, m){
        read(opt[i].op);
        if(opt[i].op == 1){
            scanf("%s", opt[i].s + 1);
            For(o, 0, 1){
                int x; read(x);
                opt[i].l[o] = x;
                b[o].pb(x);
            }
        }
        else For(o, 0, 1){
            int x; read(x);
            opt[i].l[o] = x;
        }
    }
    For(o, 0, 1){
        sort(b[o].begin(), b[o].end());
        For(i, 0, b[o].size() - 1) st[o][b[o][i]] = i;
        For(i, 1, m) if(opt[i].op == 1) opt[i].l[o] = st[o][opt[i].l[o]]--;
    }
    For(i, 1, m){
        if(opt[i].op == 1) mdy2(1, 0, b[0].size() - 1, opt[i].l[0], opt[i].l[1], i);
        else{
            int tem1 = find(0, opt[i].l[0] + 1), tem2 = find(1, opt[i].l[0]), tem3 = find(0, opt[i].l[0]), tem4 = find(0, opt[i].l[1] + 1);
            if(b[0][tem1] > opt[i].l[0]) tem1--;
            if(b[0][tem4] > opt[i].l[1]) tem4--;
            int asi = 0;
            if(b[1][tem2] >= opt[i].l[0]) asi = max(asi, que2(1, 0, b[0].size() - 1, 0, tem1, tem2, b[1].size() - 1));
            if(b[0][tem3] >= opt[i].l[0]) asi = max(asi, que2(1, 0, b[0].size() - 1, tem3, tem4, 0, b[1].size() - 1));
            if(asi){
                mdy2(1, 0, b[0].size() - 1, opt[asi].l[0], opt[asi].l[1], 0);
                printf("%s\n", opt[asi].s + 1);
            }
            else puts(">_<");
        }
    }
	return 0;
}
