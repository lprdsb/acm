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

int n, m, tot = 0, hd[maxn + 5];
char s[maxn + 5][20];
int ss;
struct Poi{
    int ch[2], mx;
    set<int> se;
} poi[40 * maxn + 5];
int tt;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

void ins(vector<int> &rt, int l, int r, int x, int val, int ty){
    if(l == r){
        if(ty){
            for(auto i : rt){
                poi[i].se.insert(-val);
                poi[i].mx = -*poi[i].se.begin();
            }
        }
        else{
            for(auto i : rt){
                poi[i].se.erase(-val);
                if(poi[i].se.begin() != poi[i].se.end()) poi[i].mx = -*poi[i].se.begin();
                else poi[i].mx = 0;
            }
        }
        return;
    }
    int mid = l + r >> 1;
    vector<int> rti;
    if(x <= mid){
        for(auto i : rt){
            if(!poi[i].ch[0]) poi[poi[i].ch[0] = ++tot] = {{0, 0}, 0};
            rti.pb(poi[i].ch[0]);
        }
        ins(rti, l, mid, x, val, ty);
    }
    else{
        for(auto i : rt){
            if(!poi[i].ch[1]) poi[poi[i].ch[1] = ++tot] = {{0, 0}, 0};
            rti.pb(poi[i].ch[1]);
        }
        ins(rti, mid + 1, r, x, val, ty);
    }
    for(auto i : rt) poi[i].mx = max(poi[poi[i].ch[0]].mx, poi[poi[i].ch[1]].mx);
}

void ins1(int rt, int l, int r, int x, int val, int ty){
    if(l == r){
        if(ty){
            poi[rt].se.insert(-val);
            poi[rt].mx = -*poi[rt].se.begin();
        }
        else{
            poi[rt].se.erase(-val);
            if(poi[rt].se.begin() != poi[rt].se.end()) poi[rt].mx = -*poi[rt].se.begin();
            else poi[rt].mx = 0;
        }
        return;
    }
    int mid = l + r >> 1;
    if(x <= mid){
        if(!poi[rt].ch[0]) poi[poi[rt].ch[0] = ++tot] = {{0, 0}, 0};
        ins1(poi[rt].ch[0], l, mid, x, val, ty);
    }
    else{
        if(!poi[rt].ch[1]) poi[poi[rt].ch[1] = ++tot] = {{0, 0}, 0};
        ins1(poi[rt].ch[1], mid + 1, r, x, val, ty);
    }
    poi[rt].mx = max(poi[poi[rt].ch[0]].mx, poi[poi[rt].ch[1]].mx);
}

int que(vector<int> &rt, int l, int r, int ql, int qr){
    if(ql <= l && qr >= r){
        int asi = 0;
        for(auto i : rt) asi = max(asi, poi[i].mx);
        return asi;
    }
    int mid = l + r >> 1, asi = 0;
    vector<int> rti;
    if(ql <= mid){
        rti.clear();
        for(auto i : rt) if(poi[i].ch[0]) rti.pb(poi[i].ch[0]);
        asi = max(asi, que(rti, l, mid, ql, qr));
    }
    if(qr > mid){
        rti.clear();
        for(auto i : rt) if(poi[i].ch[1]) rti.pb(poi[i].ch[1]);
        asi = max(asi, que(rti, mid + 1, r, ql, qr));
    }
    return asi;
}

int que1(int rt, int l, int r, int ql, int qr){
    // cout << l << " " << r << " " << ql << " " << qr << " " << poi[rt].mx << endl;
    if(!poi[rt].mx) return 0;
    if(ql <= l && qr >= r) return poi[rt].mx;
    int mid = l + r >> 1, asi = 0;
    if(ql <= mid) asi = max(asi, que1(poi[rt].ch[0], l, mid, ql, qr));
    if(qr > mid) asi = max(asi, que1(poi[rt].ch[1], mid + 1, r, ql, qr));
    return asi;
}

int ll[maxn + 5], rr[maxn + 5];
int main(){
	// freopen("in.txt", "r", stdin);
    // cout << ((&tt - &ss) >> 19) << endl;
    read(n); read(m);
    poi[++tot] = {{0, 0}, 0};
    For(i, 1, n) poi[hd[i] = ++tot] = {{0, 0}, 0};
    For(i, 1, m){
        int op; read(op);
        if(op == 1){
            scanf("%s", s[i] + 1);
            int l, r; read(l); read(r); l++; r++;
            ll[i] = l; rr[i] = r;
            vector<int> rt;
            rt.clear();
            int tem = l;
            while(tem <= n) rt.pb(hd[tem]), tem += tem & -tem;
            ins(rt, 1, n, r, i, 1); ins1(1, 1, n, l, i, 1);
        }
        else{
            int l, r, asi = 0; read(l); read(r); l++; r++;
            vector<int> rt;
            rt.clear();
            int tem = l;
            while(tem) rt.pb(hd[tem]), tem -= tem & -tem;
            asi = max(que(rt, 1, n, l, n), que1(1, 1, n, l, r));
            if(asi){
                rt.clear();
                tem = ll[asi];
                while(tem <= n) rt.pb(hd[tem]), tem += tem & -tem;
                ins(rt, 1, n, rr[asi], asi, 0); ins1(1, 1, n, ll[asi], asi, 0);
                printf("%s\n", s[asi] + 1);
            }
            else puts(">_<");
        }
    }
	return 0;
}
