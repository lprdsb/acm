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
#define maxn 8000
using namespace std;

int n, as[maxn + 5];
struct Opt{
    int x1, y1, x2, y2, c;
} opt[maxn + 5];
struct Set{
    int fa[maxn + 5];
    Set(){For(i, 1, maxn) fa[i] = i;}
    int find(int x){return fa[x] == x ? x : fa[x] = find(fa[x]);}
} se[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int b[2][maxn + 5], cnt[2];
int lower_bound(int ty, int x){
    int l = 1, r = cnt[ty];
    while(l < r){
        int mid = l + r >> 1;
        if(b[ty][mid] >= x) r = mid;
        else l = mid + 1;
    }
    return l;
}

int main(){
	// freopen("in.txt", "r", stdin);
    read(n);
    For(i, 1, n){
        read(opt[i].x1), read(opt[i].y2), read(opt[i].x2), read(opt[i].y1), read(opt[i].c);
        b[0][++cnt[0]] = opt[i].x1; b[0][++cnt[0]] = opt[i].x2;
        b[1][++cnt[1]] = opt[i].y1; b[1][++cnt[1]] = opt[i].y2;
    }
    For(o, 0, 1){
        sort(b[o] + 1, b[o] + cnt[o] + 1);
        cnt[o] = unique(b[o] + 1, b[o] + cnt[o] + 1) - b[o] - 1;
    }
    For(i, 1, n){
        opt[i].x1 = lower_bound(0, opt[i].x1);
        opt[i].y1 = lower_bound(1, opt[i].y1);
        opt[i].x2 = lower_bound(0, opt[i].x2);
        opt[i].y2 = lower_bound(1, opt[i].y2);
    }
    // For(i, 1, cnt[0]) cout << b[0][i] << " "; cout << endl;
    Rof(o, n, 1){
        For(i, opt[o].x1, opt[o].x2 - 1){
            int now = se[i].find(opt[o].y2 - 1);
            while(now >= opt[o].y1){
                int tem = se[i].fa[now] = se[i].find(now - 1);
                now = tem;
                as[opt[o].c] = 1;
                // cout << o << " " << i << endl;
            }
        }
    }
    For(i, 1, n) as[0] += as[i];
    printf("%d\n", as[0]);
	return 0;
}
