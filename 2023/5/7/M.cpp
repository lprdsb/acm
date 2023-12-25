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
#define mod 1000000007
using namespace std;

int n, q;
struct Poi{
    LL x, y, id, xi, yi;
} poi[maxn + 5];
bool operator < (cst Poi &x, cst Poi &y){
    if(x.xi != y.xi) return x.xi < y.xi;
    return x.yi < y.yi;
}
int hd[maxn + 5], tot = 0;
struct Node{
    int ls, rs, l, r, cnt;
    vector<int> vec;
} nod[40 * maxn + 5];


template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int cnt[2] = {0, 0};
LL b[2][maxn + 5]; 
int find(int ty, LL x){
    int l = 1, r = cnt[ty];
    while(l < r){
        int mid = l + r >> 1;
        if(b[ty][mid] >= x) r = mid;
        else l = mid + 1;
    }
    return l;
}

int build(int rt1, int rt2, int l, int r, int qx, int val){
    nod[rt2] = nod[rt1];
    nod[rt2].l = l; nod[rt2].r = r;
    nod[rt2].cnt++;
    if(l == r){
        nod[rt2].vec.pb(val);
        return rt2;
    }
    int mid = l + r >> 1;
    if(qx <= mid) nod[rt2].ls = build(nod[rt1].ls, ++tot, l, mid, qx, val);
    else nod[rt2].rs = build(nod[rt1].rs, ++tot, mid + 1, r, qx, val);
    return rt2;
}
vector<int> st;
void sol(int rt, int qx){
    if(!nod[rt].cnt) return;
    if(nod[rt].l == nod[rt].r){
        for(auto i : nod[rt].vec) st.pb(i);
        return;
    }
    int mid = nod[rt].l + nod[rt].r >> 1;
    if(qx <= mid) sol(nod[rt].ls, qx);
    sol(nod[rt].rs, qx);
}

int as = 0, pw[maxn + 5];
int main(){
	// freopen("in.txt", "r", stdin);
    pw[0] = 1;
    For(i, 1, maxn) pw[i] = 1ll * pw[i - 1] * 5782344 % mod;
	read(n); read(q);
    For(i, 1, n){
        LL x, y; read(x); read(y); 
        poi[i] = {2 * y - x, 2 * y + x, i};
        b[0][++cnt[0]] = poi[i].x;
        b[1][++cnt[1]] = poi[i].y;
    }
    sort(b[0] + 1, b[0] + cnt[0] + 1); cnt[0] = unique(b[0] + 1, b[0] + cnt[0] + 1) - b[0] - 1;
    sort(b[1] + 1, b[1] + cnt[1] + 1); cnt[1] = unique(b[1] + 1, b[1] + cnt[1] + 1) - b[1] - 1;
    For(i, 1, n){
        poi[i].xi = find(0, poi[i].x);
        poi[i].yi = find(1, poi[i].y);
    }
    sort(poi + 1, poi + n + 1);
    For(i, 1, n) hd[i] = build(hd[i - 1], ++tot, 1, cnt[1], poi[i].yi, poi[i].id);
    while(q--){
        LL aa, bb; read(aa); read(bb);
        aa = -1 - (as + aa) % mod;
        bb = (as + bb) % mod;
        LL x = 2 * bb - aa, y = 2 * bb + aa;
        int l = 1, r = n;
        while(l < r){
            int mid = l + r >> 1;
            if(poi[mid].x > x) r = mid;
            else l = mid + 1;
        }
        if(poi[l].x > x) l--;
        int tem = find(1, y);
        st.clear();
        sol(hd[l], tem);
        // cout << nod[hd[l]].vec.size() << endl;
        sort(st.begin(), st.end());
        as = 0;
        For(i, 0, st.size() - 1){
            as = (as + 1ll * pw[i] * st[i] % mod) % mod;
            // cout << st[i] << " ";
        }
        // cout << endl;
        printf("%d\n", as);
    }
    return 0;
}
