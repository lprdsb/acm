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

int n, m, tot = 0, hd[maxn + 5], b[maxn + 5], cnt;
struct Opt{
    int op, l, r;
    char s[20];
} opt[maxn + 5];
int ss;
struct Poi{
    int ch[2], mx;
} poi[50 * maxn + 5];
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
            for(auto i : rt) poi[i].mx = val;
        }
        else{
            for(auto i : rt) poi[i].mx = 0;
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

int bb[maxn + 5], st1[maxn + 5], cnt1 = 0;
void ins1(int rt, int l, int r, int x, int val, int ty){
    if(l == r){
        if(ty) poi[rt].mx = val;
        else poi[rt].mx = 0;
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

int find(int x){
    int l = 1, r = cnt;
    while(l < r){
        int mid = l + r >> 1;
        if(b[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return l;
}
int find1(int x){
    int l = 1, r = cnt1;
    while(l < r){
        int mid = l + r >> 1;
        if(bb[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return l;
}

int ll[maxn + 5], rr[maxn + 5], st[maxn + 5], lll[maxn + 5];
int main(){
	// freopen("in.txt", "r", stdin);
    // cout << ((&tt - &ss) >> 19) << endl;
    read(n); read(m);
    poi[++tot] = {{0, 0}, 0};
    For(i, 1, n) poi[hd[i] = ++tot] = {{0, 0}, 0};
    For(i, 1, m){
        read(opt[i].op);
        if(opt[i].op == 1){
            scanf("%s", opt[i].s + 1);
            read(opt[i].l); read(opt[i].r); opt[i].l++; opt[i].r++;
            bb[++cnt1] = opt[i].l, b[++cnt] = opt[i].r;
        }
        else read(opt[i].l), opt[i].l++, read(opt[i].r), opt[i].r++;
    }
    b[0] = -1;
    sort(b + 1, b + cnt + 1);
    For(i, 1, cnt) if(b[i] != b[i - 1]) st[b[i]] = i;
    bb[0] = -1;
    sort(bb + 1, bb + cnt1 + 1);
    For(i, 1, cnt1) if(bb[i] != bb[i - 1]) st1[bb[i]] = i;
    For(i, 1, m){
        int op = opt[i].op;
        if(op == 1){
            int l = opt[i].l, r = opt[i].r;
            r = st[r]++;
            ll[i] = l; rr[i] = r; lll[i] = st1[l]++;
            vector<int> rt;
            rt.clear();
            int tem = l;
            while(tem <= n) rt.pb(hd[tem]), tem += tem & -tem;
            ins(rt, 1, cnt, r, i, 1); ins1(1, 1, cnt1, lll[i], i, 1);
        }
        else{
            int l = opt[i].l, r = opt[i].r, asi = 0;
            vector<int> rt;
            rt.clear();
            int tem = l;
            while(tem) rt.pb(hd[tem]), tem -= tem & -tem;
            tem = find(l);
            if(tem <= cnt) asi = max(asi, que(rt, 1, cnt, tem, cnt));
            int tt1 = find1(l), tt2 = find1(r + 1);
            if(bb[tt2] > r) tt2--;
            if(tt1 <= tt2) asi = max(asi , que1(1, 1, cnt1, tt1, tt2));
            if(asi){
                rt.clear();
                tem = ll[asi];
                while(tem <= n) rt.pb(hd[tem]), tem += tem & -tem;
                ins(rt, 1, cnt, rr[asi], asi, 0); ins1(1, 1, cnt1, lll[asi], asi, 0);
                printf("%s\n", opt[asi].s + 1);
            }
            else puts(">_<");
        }
    }
	return 0;
}
