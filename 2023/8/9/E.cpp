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

int n, m, q;
struct Vec{
    int x, y;
    // DD get_k(){return DD{y} / (x + eps);}
    DD get_atan(){return atan2(y, x);}
} art[maxn + 5], tow[maxn + 5];
Vec operator - (Vec _x, Vec _y){return {_x.x - _y.x, _x.y - _y.y};}
struct Wall{
    Vec v1, v2;
} wal[maxn + 5];

struct Cmp{
    bool operator () (DD x, DD y){
        if(fabs(x - y) <= eps) return 0;
        return x < y;
    }
} cmp;
struct Cmp1{
    bool operator () (DD x, DD y){
        if(fabs(x - y) <= eps) return 1;
        return 0;
    }
} cmp1;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int tr[maxn + 5];
void ins(int x, int y){
    x = maxn - x + 1;
    while(x <= maxn) tr[x] += y, x += x & -x;
}
int que(int x){
    x = maxn - x + 1;
    int res = 0;
    while(x) res += tr[x], x -= x & -x;
    return res;
}

int as[maxn + 5];
vector<DD> b;
struct Data{
    DD l, r;
    int id;
};
bool operator < (Data _x, Data _y){
    return cmp(_x.l, _y.l);
}
vector<Data> seg[2]; 

int main(){
	// freopen("in.txt", "r", stdin);
    read(n); read(m); read(q);
    For(i, 1, n){
        int x, y; read(x); read(y);
        art[i] = {x, y};
    }
    For(i, 1, m){
        int x1, x2, y; read(x1); read(x2); read(y);
        wal[i] = {{x1, y}, {x2, y}};
    }
    For(i, 1, q){
        int x, y; read(x); read(y);
        tow[i] = {x, y};
    }
    For(o, 0, (1 << m) - 1){
        int k = 1;
        For(i, 1, m) if((o >> (i - 1)) & 1) k = -k;
        b.resize(0);
        For(i, 0, 1) seg[i].resize(0);
        For(i, 1, n){
            DD l = -maxn, r = maxn;
            For(j, 1, m) if((o >> (j - 1)) & 1){
                if(art[i].y <= wal[j].v1.y){
                    l = 1, r = -1;
                    break;
                }
                DD li = art[i].x - (DD)(art[i].x - wal[j].v1.x) * art[i].y / (art[i].y - wal[j].v1.y);
                DD ri = art[i].x + (DD)(wal[j].v2.x - art[i].x) * art[i].y / (art[i].y - wal[j].v2.y);
                l = max(l, li);
                r = min(r, ri);
                if(cmp(r, l)) break;
            }
            if(!cmp(r, l)){
                seg[0].pb({l, r});
                b.pb(r);
            }
        }
        sort(b.begin(), b.end());
        b.resize(unique(b.begin(), b.end(), cmp1) - b.begin());
        // if(o == 1){
        //     // cout << unique(b.begin(), b.end(), cmp1) - b.begin() << endl;
        //     for(auto i : b) cout << i << " "; cout << endl;
        // }
        For(i, 1, maxn) tr[i] = 0;
        For(i, 1, q){
            DD l = -maxn, r = maxn;
            For(j, 1, m) if((o >> (j - 1)) & 1){
                DD li = tow[i].x - (DD)(tow[i].x - wal[j].v1.x) * tow[i].y / (tow[i].y - wal[j].v1.y);
                DD ri = tow[i].x + (DD)(wal[j].v2.x - tow[i].x) * tow[i].y / (tow[i].y - wal[j].v2.y);
                l = max(l, li);
                r = min(r, ri);
                if(cmp(r, l)) break;
            }
            if(!cmp(r, l)) seg[1].pb({l, r, i});
        }

        For(i, 0, 1) sort(seg[i].begin(), seg[i].end());
        int now = 0;
        for(auto i : seg[1]){
            while(now < seg[0].size() && !cmp(i.l, seg[0][now].l)){
                ins(lower_bound(b.begin(), b.end(), seg[0][now].r, cmp) - b.begin() + 1, 1);
                now++;
            }
            as[i.id] += k * que(lower_bound(b.begin(), b.end(), i.r, cmp) - b.begin() + 1);
        }
    }
    For(i, 1, q) printf("%d\n", as[i]);
    return 0;
}
