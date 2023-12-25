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
using namespace std;

int n, k, a[maxn + 5], sum[maxn + 5];
struct Node{
    int l, r, val;
} opt[maxn + 5];
vector<int> vec[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int main(){
	// freopen("in.txt", "r", stdin);
    read(n); read(k);
    For(i, 1, n) read(a[i]);
    For(i, 1, n) sum[i] = sum[i - 1] + (a[i] >= 0 ? 1 : -1);
    For(i, 1, k){
        int l, r, val; read(l); read(r); read(val);
        val -= sum[r] - sum[l - 1];
        if(val > 0){
            puts("Impossible");
            return 0;
        }
        opt[i] = {l, r, val};
    }
    sort(opt + 1, opt + k + 1, [](Node _a, Node _b){return _a.l < _b.l;});
    For(i, 1, k) vec[opt[i].r].pb(i);
    int lpr = 0;
    set<pair<int, int> > se;
    int now = 1;
    For(i, 1, n){
        while(now <= k && opt[now].l < i) now++;
        while(now <= k && opt[now].l == i){
            opt[now].val -= lpr;
            se.insert({-opt[now].val, now});
            now++;
        }
        if(a[i]) printf("%d ", a[i]);
        else{
            if(se.size() && -se.begin()->fir + lpr >= -1){
                printf("1 ");
            }
            else{
                printf("-1 ");
                lpr += 2;
            }
        }
        for(auto j : vec[i]) se.erase({-opt[j].val, j});
    }
    puts("");
    return 0;
}
