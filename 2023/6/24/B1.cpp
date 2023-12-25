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

int n, k, a[maxn + 5], cnt = 0;
LL m;
struct Opt{LL l, r; int cnt;} opt[4 * maxn + 5];
bool operator < (cst Opt &x, cst Opt &y){
    return x.l <= y.l;
}
map<LL, int> ma;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

vector<pair<int, int> > vec;

int main(){
	freopen("in.txt", "r", stdin);
    read(n); read(m); read(k);
    if(k > n){
        printf("%lld 0\n", m);
        return 0;
    }
    For(i, 1, n){
        read(a[i]);
        ma[a[i]]++;
    }
    ma[m + 1] = 0;
    int pre = 0;
    for(auto i : ma){
        if(i.fir > pre) opt[++cnt] = {pre, i.fir - 1, 0};
        opt[++cnt] = {i.fir, i.fir, i.sec};
        pre = i.sec + 1;
    }
    sort(opt + 1, opt + cnt + 1);
    
    pre = -114514;
    int now = 1, fll = -1;
    LL nowk = 0, suf = -114514, tol;
    For(i, 1, cnt){
        while(now <= cnt && nowk + opt[now].cnt < k) nowk += opt[now++].cnt;
        if(now > cnt) break;
        if(opt[i].cnt){
            LL l = pre == -114514 ? 0 : (pre + opt[now].l + 1) / 2, r = (opt[i].l + opt[now].l - 1) / 2;
            if(fll == -1){
                fll = i;
                tol = 2 * l - opt[now].l + 1;
            }
            vec.pb({i, r - l + 1});
            vec.pb({now, -(r - l + 1)});
            if(i != now && !((opt[i].l + opt[now].r) & 1)){
                bonus[i + 1]++;
                bonus[now]--;
            }
            pre = opt[i].l;
        }
        nowk -= opt[i].cnt;
    }

    now = cnt;
    nowk = 0;
    Rof(i, cnt, 1){
        while(now && nowk + opt[now].cnt < k) nowk += opt[now--].cnt;
        if(!now) break;
        if(opt[i].cnt){
            LL l = (opt[i].l + opt[now].l + 1) / 2, r = suf == -114514 ? m : (suf + opt[now].l) / 2;
            bonus[now + 1] += r - l + 1;
            bonus[i + 1] -= r - l + 1;
            suf = opt[i].l;
        }
        nowk -= opt[i].cnt;
    }
    

    int as = -1;
    For(i, 1, cnt) bonus[i] += bonus[i - 1];
    For(i, 1, cnt) cout << bonus[i] << " "; cout << endl;
    For(i, 1, cnt) if(as == -1 || bonus[i] >= bonus[as]) as = i;
    opt[fll].l = tol;
    printf("%lld %d\n", bonus[as], opt[as].l);
    return 0;
}
