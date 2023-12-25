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

int n, k, a[maxn + 5], cnt = 0, cnt_cho = 0;
LL m;
struct Opt{LL l, r; int id;} opt[4 * maxn + 5], cho[4 * maxn + 5];
bool operator < (cst Opt &x, cst Opt &y){
    if(x.l != y.l) return x.l <= y.l;
    return x.id <= y.id;
}
bool operator == (cst Opt &x, cst Opt &y){
    return x.l == y.l && x.r == y.r && x.id == y.id;
} 

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

LL sum[4 * maxn + 5], bonus[4 * maxn + 5];

int main(){
	//freopen("in", "r", stdin);
    read(n); read(m); read(k);
    For(i, 1, n){
        read(a[i]);
        opt[++cnt] = {a[i], a[i], i};
    }
    sort(opt + 1, opt + n + 1);
    For(i, 1, n - 1) if(opt[i].r < opt[i + 1].l) opt[++cnt] = {opt[i].r + 1, opt[i + 1].l - 1, 0};
    if(opt[1].l != 0) opt[++cnt] = {0, opt[1].l - 1, 0};
    if(opt[n].r != m) opt[++cnt] = {opt[n].r + 1, m, 0};
    sort(opt + 1, opt + cnt + 1);
    For(i, 1, cnt) cho[i] = opt[i], cho[i].id = 0;
    cnt_cho = cnt;
    cnt_cho = unique(cho + 1, cho + cnt_cho + 1) - cho - 1;
    opt[0] = {-1, -1, 0};
    opt[cnt + 1] = {m + 1, m + 1, 0};

    int nowl = 1, nowr = 1, nowk = 0;
    For(i, 1, cnt_cho){
        while(opt[nowl].l < cho[i].l) nowk -= opt[nowl++].id != 0;
        while(nowr <= cnt + 1 && nowk + (opt[nowr].id != 0) <= k) nowr++;
        if(nowl <= nowr){
            LL tem = cho[i].r - cho[i].l + 1;
            sum[nowl] += tem;
            sum[nowr] -= tem;
        }
    }
    For(i, 1, cnt + 1) sum[i] += sum[i - 1];
    nowl = 1;
    For(i, 1, cnt_cho){
        while(nowl <= cnt && opt[nowl].r <= cho[i].r) nowl++;
        bonus[i] += sum[nowl];
    }

    For(i, 0, cnt + 2) sum[i] = 0;
    For(i, 1, cnt) opt[i].id *= -1;
    sort(opt + 1, opt + cnt + 1);
    nowl = nowr = cnt; nowk = 0;
    Rof(i, cnt, 1){
        while(opt[nowr].r > cho[i].r) nowk -= opt[nowr--].id != 0;
        while(nowl >= 0 && nowk + (opt[nowl].id != 0) <= k) nowl--;
        if(nowl <= nowr){
            LL tem = cho[i].r - cho[i].l + 1;
            sum[nowr] += tem;
            if(nowl >= 0) sum[nowl] -= tem;
        }
    }
    Rof(i, cnt, 0) sum[i] += sum[i + 1];
    nowl = cnt;
    Rof(i, cnt_cho, 1){
        while(nowl && opt[nowl].l >= cho[i].l) nowl--;
        bonus[i] += sum[nowl];
    }

    int as = -1;
    For(i, 1, cnt_cho) if(as == -1 || bonus[i] >= bonus[as]) as = i;
    printf("%lld %d\n", bonus[as], cho[as].l);
    return 0;
}
