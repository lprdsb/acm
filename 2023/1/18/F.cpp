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
#define maxn 1000
#define maxm 2000000
using namespace std;

int n, vx, vy, a[maxn + 5][maxn + 5], id[maxn + 5][maxn + 5], tot = 0, b[maxm + 5], cnt = 0, cnt_line = 0;
LL as = 0;
struct Vec{
    int x, y;
} vec[2 * maxm + 5];
Vec operator * (cst int &x, cst Vec &v){
    return (Vec){x * v.x, x * v.y};
}
Vec operator + (cst Vec &x, cst Vec &y){
    return (Vec){x.x + y.x, x.y + y.y};
}
struct Sqr{
    int p[5];
} sqr[maxn + 5][maxn + 5];
struct Line{
    int l, r, h, val;
} line[maxn * maxn + 5];
bool operator < (cst Line &x, cst Line &y){
    return x.h < y.h;
}

struct Tree{
    int val[4 * maxm + 5], lpr[4 * maxm + 5];
    void build(int rt, int l, int r){
        val[rt] = lpr[rt] = 0;
        if(l == r) return;
        int mid = l + r >> 1;
        build(rt << 1, l, mid);
        build(rt << 1 | 1, mid + 1, r);
    }
    int mson(int rt, int va){
        int asi = val[rt];
        if(val[rt] < va){
            val[rt] = va;
            lpr[rt] = va;
        }
        return asi;
    }
    void spr(int rt){
        if(lpr[rt]){
            mson(rt << 1, lpr[rt]);
            mson(rt << 1 | 1, lpr[rt]);
            lpr[rt] = 0;
        }
    }
    void upd(int rt){val[rt] = min(val[rt << 1], val[rt << 1 | 1]);}
    int mdy(int rt, int l, int r, int ql, int qr, int va){
        if(ql <= l && qr >= r) return mson(rt, va);
        spr(rt);
        int mid = l + r >> 1, asi = inf;
        if(ql <= mid) asi = min(asi, mdy(rt << 1, l, mid, ql, qr, va));
        if(qr > mid) asi = min(asi, mdy(rt << 1 | 1, mid + 1, r, ql, qr, va));
        upd(rt);
        return asi;
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

Vec tra(Vec x, Vec v1, Vec v2){
    return x.x * v1 + x.y * v2;
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

int main(){
	// freopen("in.txt", "r", stdin);
    read(n); read(vx); read(vy);
    For(i, 1, n) For(j, 1, n) read(a[i][j]);
    if(vx < 0){
        vx = -vx;
        For(i, 1, n / 2) For(j, 1, n) swap(a[i][j], a[n - i + 1][j]); 
    }
    if(vy < 0){
        vy = -vy;
        For(i, 1, n) For(j, 1, n / 2) swap(a[i][j], a[i][n - j + 1]);
    }
    Vec v1 = (Vec){vy, vx}, v2 = (Vec){-vx, vy};
    For(i, 0, n) For(j, 0, n) vec[id[i][j] = ++tot] = (Vec){i, j};
    For(i, 1, n) For(j, 1, n){
        sqr[i][j].p[1] = id[i - 1][j - 1];
        sqr[i][j].p[2] = id[i][j - 1];
        sqr[i][j].p[3] = id[i - 1][j];
        sqr[i][j].p[4] = id[i][j];
    }
    For(i, 1, tot) vec[i] = tra(vec[i], v1, v2);
    For(i, 1, tot) b[++cnt] = vec[i].x;
    sort(b + 1, b + cnt + 1);
    cnt = unique(b + 1, b + cnt + 1) - b - 1;
    For(i, 1, tot) vec[i].x = find(vec[i].x);
    For(i, 1, n) For(j, 1, n){
        int l = inf, r = -inf;
        For(p, 1, 4){
            l = min(l, vec[sqr[i][j].p[p]].x);
            r = max(r, vec[sqr[i][j].p[p]].x);
        }
        line[++cnt_line] = (Line){l, r - 1, vec[sqr[i][j].p[1]].y, a[i][j]};
    }
    sort(line + 1, line + cnt_line + 1);
    // For(i, 1, cnt) cout << b[i] << " "; cout << endl;
    // For(i, 1, cnt_line) cout << line[i].l << " " << line[i].r << " " << line[i].val << endl;

    // cout << "asd" << endl;
    tr.build(1, 1, cnt);
    For(i, 1, cnt_line){
        int asi = line[i].val - tr.mdy(1, 1, cnt, line[i].l, line[i].r, line[i].val);
        if(asi > 0) as += asi;
    }
    printf("%lld\n", as);
    return 0;
}
