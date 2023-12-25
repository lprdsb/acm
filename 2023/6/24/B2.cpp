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

int n, k, cnt = 0;
LL m, a[maxn + 5];
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

int sum[4 * maxn + 5];

int main(){
	// freopen("in.txt", "r", stdin);
    read(n); read(m); read(k);
    if(k > n){
        printf("%lld 0\n", m + 1);
        return 0;
    }
    For(i, 1, n){
        read(a[i]);
        ma[a[i]]++;
    }
    ma[m + 1] = 0;
    LL pre = 0;
    for(auto i : ma){
        if(i.fir > pre) opt[++cnt] = {pre, i.fir - 1, 0};
        if(i.fir != m + 1) opt[++cnt] = {i.fir, i.fir, i.sec};
        pre = i.fir + 1;
    }
    sort(opt + 1, opt + cnt + 1);
    For(i, 1, cnt) sum[i] = sum[i - 1] + opt[i].cnt;
    // For(i, 1 ,cnt) cout << opt[i].l << " " << opt[i].r << " " << opt[i].cnt << endl;
    int nowl = 0, nowr = 1;
    LL as = -1, pos;
    For(i, 1, cnt){
        while(sum[i] - sum[nowl] >= k) nowl++;
        while(nowr <= cnt && sum[nowr] - sum[i - 1] < k) nowr++;
        LL pos1 = opt[i].l, pos2 = opt[i].l + (opt[i].r != opt[i].l), pos3 = opt[i].r, pos4 = opt[i].r - (opt[i].l != opt[i].r);
        LL as1 = max(0ll, (nowr > cnt ? m : (opt[nowr].l + pos1 + 1) / 2 - 1) - (nowl ? (opt[nowl].l + pos1) / 2 + 1 : 0) + 1);
        LL as2 = max(0ll, (nowr > cnt ? m : (opt[nowr].l + pos2 + 1) / 2 - 1) - (nowl ? (opt[nowl].l + pos2) / 2 + 1 : 0) + 1);
        LL as3 = max(0ll, (nowr > cnt ? m : (opt[nowr].l + pos3 + 1) / 2 - 1) - (nowl ? (opt[nowl].l + pos3) / 2 + 1 : 0) + 1);
        LL as4 = max(0ll, (nowr > cnt ? m : (opt[nowr].l + pos4 + 1) / 2 - 1) - (nowl ? (opt[nowl].l + pos4) / 2 + 1 : 0) + 1);
        // cout << opt[i].l << " " << opt[i].r << endl;
        // if(i == 5) cout << a[nowl] << " " << pos1 << endl;
        if(as == -1 || as1 > as) as = as1, pos = pos1;
        if(as == -1 || as2 > as) as = as2, pos = pos2;
        if(as == -1 || as4 > as) as = as4, pos = pos4;
        if(as == -1 || as3 > as) as = as3, pos = pos3;
        // if(n == 10200 && opt[i].l <= 400770 && opt[i].r >= 400770){
        //     cout << i << endl;
        //     cout << opt[i].l << " " << opt[i].r << endl;
        //     cout << nowl << " " << nowr << endl;
        //     cout << sum[i] - sum[nowl] << " " << sum[nowr] - sum[i - 1] << endl;
        //     cout << (nowr > cnt ? m : (opt[nowr].l + pos1 + 1) / 2 - 1) - (nowl ? (opt[nowl].l + pos1) / 2 + 1 : 0) + 1 << endl;
        // }
    }
    printf("%lld %lld\n", as, pos);
    return 0;
}
