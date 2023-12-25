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

int T, n, b[maxn + 5], cnt = 0;
struct Seg{
    int l, r;
} seg[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int sum[maxn + 5];
int mnl[maxn + 5], mxr[maxn + 5];
int main(){
	freopen("in.txt", "r", stdin);
    read(T);
    while(T--){
        read(n);
        For(i, 1, n){
            int l, r; read(l); read(r);
            seg[i] = {l, r};
            b[++cnt] = l; b[++cnt] = r + 1;
        }
        LL res = 0;
        int mx[4] = {0, 0, 0, 0}, mn[4] = {0, 0, 0, 0};
        sort(b + 1, b + cnt + 1);
        cnt = unique(b + 1, b + cnt + 1) - b - 1;
        For(i, 1, n){
            seg[i].l = lower_bound(b + 1, b + cnt + 1, seg[i].l) - b;
            seg[i].r = lower_bound(b + 1, b + cnt + 1, seg[i].r + 1) - b - 1;
            int tem = i;
            For(o, 0, 3) if(!mn[o] || seg[tem].l < seg[mn[o]].l) swap(tem, mn[o]);
            tem = i;
            For(o, 0, 3) if(!mx[o] || seg[tem].r > seg[mx[o]].r) swap(tem, mx[o]);
            sum[seg[i].l]++;
            sum[seg[i].r + 1]--;
        }
        For(i, 1, cnt) sum[i] += sum[i - 1];
        if(n >= 4){
            For(i, 1, cnt){
                if(!sum[i]){
                    if(mn[0] <= i){
                        if(mn[1] <= i) res += 1ll * (b[i + 1] - b[i]) * (b[seg[mx[0]].r + 1] - b[i]) - 1;
                        else res += 1ll * (b[i + 1] - b[i]) * (b[seg[mx[0]].r + 1] - b[seg[mn[1]].l]);
                    }
                }
                else if(sum[i] == 1){
                    if(seg[mx[0]].l <= i) res += 1ll * (b[i + 1] - b[i]) * (b[seg[mx[1]].r + 1] - b[seg[mn[1]].l]);
                    else res += 1ll * (b[i + 1] - b[i]) * (b[seg[mx[0]].r + 1] - b[seg[mn[1]].l]);
                }
                else if(sum[i] == 2){
                    res += 1ll * (b[i + 1] - b[i]) * (b[seg[mx[0]].r + 1] - b[i]) - 1;
                    if(seg[mx[0]].l <= i &&seg[mn[2]].l > seg[mx[1]].r)
                        res -= 1ll * (b[i + 1] - b[i]) * (b[seg[mn[2]].l] - b[seg[mx[1]].r + 1]);
                }
                else res += 1ll * (b[i + 1] - b[i]) * (b[seg[mx[0]].r + 1] - b[i]) - 1;
            }
        }
        else{
            if(n == 1) res = 1;
            else if(n == 2){
                if(seg[1].l > seg[2].l) swap(seg[1], seg[2]);
                if(seg[1].r >= seg[2].r){
                    int t1 = b[seg[2].l] - b[seg[1].l], t2 = b[seg[2].r + 1] - b[seg[1].l], t3 = b[seg[2].r + 1] - b[seg[1].r + 1];
                    res += 1ll * (t1 + t3) * t2 + 1ll * (t2 - 1) * t2 / 2;
                }
                else if(seg[1].r >= seg[2].l){
                    int t1 = b[seg[2].l] - b[seg[1].l], t2 = b[seg[1].r + 1] - b[seg[2].l], t3 = b[seg[2].r + 1] - b[seg[1].r + 1];
                    res += 1ll * (t1 + t3) * t2 + 1ll * (t2 - 1) * t2 / 2;
                }
                else res += 1ll * (b[seg[1].r + 1] - b[seg[1].l]) * (b[seg[2].r + 1] - b[seg[2].l]);
            }
            else{
                int vis[50][50];
                memset(vis, 0, sizeof vis);
                For(i, 1, n){
                    int l = inf, r = -inf;
                    For(j, 1, n) if(i != j) l = min(l, seg[j].l), r = max(r, seg[j].r);
                    For(j, seg[i].l, seg[i].r) For(p, l, r){
                        if(j <= p) vis[j][p] = 1;
                        else vis[p][j] = 1;
                    }
                }
                For(i, 1, cnt){
                    res += 1ll * (b[i + 1] - b[i]) * (b[i + 1] - b[i] - 1) / 2;
                    For(j, i + 1, cnt) if(vis[i][j]) res += 1ll * (b[j + 1] - b[i]) * (b[j + 1] - b[j]);
                }
            }
        }
        printf("%lld\n", res);

        For(i, 1, cnt){
            sum[i] = 0;
            mnl[i] = mxr[i] = 0;
        }
        cnt = 0;
    }
    return 0;
}
