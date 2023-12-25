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
#define maxn 300000
using namespace std;

int t, n, k, a[maxn + 5];
struct Poi{
    int cnt, ch[2];
    LL sum;
};
class Tree{
    public:
        vector<Poi> poi;
        void init(){
            poi.clear();
            poi.pb({});
            poi.pb({});
        }
        int get_son(int rt, int o){
            if(!poi[rt].ch[o]){
                poi.pb({});
                poi[rt].ch[o] = poi.size() - 1;
            }
            return poi[rt].ch[o];
        }
        void ins(int rt, int l, int r, int qx, int val, int ty){
            poi[rt].cnt += ty;
            poi[rt].sum += ty * val;
            if(l == r) return;
            int mid = l + r >> 1;
            if(qx <= mid) ins(get_son(rt, 0), l, mid, qx, val, ty);
            else ins(get_son(rt, 1), mid + 1, r, qx, val, ty);
        }
        int que(int rt, int l, int r, LL qx){
            // cout << l << " " << r << " " << poi[rt].sum << endl;
            if(qx >= poi[rt].sum) return poi[rt].cnt;
            if(!rt) return 0;
            int mid = l + r >> 1;
            if(poi[poi[rt].ch[0]].sum >= qx) return que(poi[rt].ch[0], l, mid, qx);
            qx -= poi[poi[rt].ch[0]].sum;
            return poi[poi[rt].ch[0]].cnt + que(poi[rt].ch[1], mid + 1, r, qx);
        }
} tr[2];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int st[maxn + 5], id[maxn + 5], b[maxn + 5], bb[maxn + 5], cnt = 0;

int find(int x){
    int l = 1, r = cnt;
    while(l < r){
        int mid = l + r >> 1;
        if(b[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return l;
}

int main(){
	// freopen("in.txt", "r", stdin);
    read(t);
    while(t--){
        read(n); read(k);
        For(i, 1, n){
            read(a[i]);
            b[i] = bb[i] = a[i];
        }
        sort(b + 1, b + n + 1);
        cnt = unique(b + 1, b + n + 1) - b - 1;
        sort(bb + 1, bb + n + 1);
        int now = 1;
        bb[n + 1] = inf;
        For(i, 1, cnt){
            while(bb[now] <= b[i]) now++;
            st[i] = now;
        }
        For(i, 1, n) id[i] = --st[find(a[i])];
        tr[0].init(); tr[1].init();
        Rof(i, n, 1) tr[1].ins(1, 1, n, id[i], a[i], 1);
        LL asi = Inf;
        For(i, 1, n){
            tr[1].ins(1, 1, n, id[i], a[i], -1);
            tr[0].ins(1, 1, n, id[i], a[i], 1);
            LL l = 0, r = Inf;
            while(l < r){
                LL mid = l + r >> 1;
                if(tr[0].que(1, 1, n, mid) + tr[1].que(1, 1, n, mid) >= k) r = mid;
                else l = mid + 1;
            }
            asi = min(asi, l);
        }
        printf("%lld\n", asi);
    }
	return 0;
}
