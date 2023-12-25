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
#define maxn 200000
using namespace std;

int t, n, m[3];
struct Node{
    int u, l, d, r;
} a[maxn + 5];
struct Line{
    int l, r, id;
} b[3][maxn + 5];
bool operator < (Line &x, Line &y){
    if(x.l != y.l) return x.l < y.l;
    return x.r < y.r;
}
int tot;
pair<int, int> pa[maxn + 5];

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
    read(t);
    while(t--){
        LL as = 0;
        m[0] = m[1] = m[2] = 0;
        read(n);
        For(i, 1, n){
            read(a[i].u); read(a[i].l); read(a[i].d); read(a[i].r);
            if(a[i].d == 1) b[1][++m[1]] = (Line){a[i].l, a[i].r, i};
            else if(a[i].u == 2) b[2][++m[2]] = (Line){a[i].l, a[i].r, i};
            else b[0][++m[0]] = (Line){a[i].l, a[i].r, i};
        }
        For(i, 0, 2) sort(b[i], b[i] + m[i] + 1);
        int p[3] = {1, 1, 1}, mx[3] = {0, 0, 0};
        For(i, 1, m[0]){
            For(o, 1, 2){
                while(p[o] <= m[o] && b[o][p[o]].l <= b[0][i].l){
                    mx[o] = max(mx[o], b[o][p[o]].r);
                    p[o]++;
                }
            }
            if(mx[1] >= b[0][i].r){
                a[b[0][i].id].u = 2;
                b[2][++m[2]] = (Line){b[0][i].l, b[0][i].r, b[0][i].id};
                b[0][i].id = 0;
            }
            else if(mx[2] >= b[0][i].r){
                a[b[0][i].id].d = 1;
                b[1][++m[1]] = (Line){b[0][i].l, b[0][i].r, b[0][i].id};
                b[0][i].id = 0;
            }
        }
        int tem = m[0]; m[0] = 0;
        For(i, 1, tem) if(b[0][i].id) b[0][++m[0]] = b[0][i];
        tot = 0;
        For(o, 0, 2){
            sort(b[o] + 1, b[o] + m[o] + 1);
            int now = 0, nowl = -1;
            For(i, 1, m[o]){
                // cout << b[0][i] << endl;
                if(b[o][i].r <= now) a[b[o][i].id] = (Node){0, 0, 0, 0}, b[o][i].id = 0;
                else if(b[o][i].l <= now){
                    b[o][i].l = a[b[o][i].id].l = now + 1;
                    now = b[o][i].r;
                }
                else{
                    if(nowl != -1 && !o) pa[++tot] = mp(nowl, now); 
                    nowl = b[o][i].l;
                    now = b[o][i].r;
                }
            }
            if(!o && nowl != -1) pa[++tot] = mp(nowl, now);
            int tem = m[o]; m[o] = 0;
            For(i, 1, tem) if(b[o][i].id) b[o][++m[o]] = b[o][i];
            sort(b[o] + 1, b[o] + m[o] + 1);
        }
        // For(i, 1, tot) cout << pa[i].fir << " " << pa[i].sec << endl;
        // For(i, 1, n) printf("%d %d %d %d\n", a[i].u, a[i].l, a[i].d, a[i].r);
        if(tot){
            For(o, 1, 2){
                int now = 1;
                For(i, 1, m[o]){
                    while(now < tot && pa[now].fir < b[o][i].l) now++;
                    if(pa[now].fir > b[o][i].l){
                        if(pa[now].fir <= b[o][i].r){
                            b[o][i].r = a[b[o][i].id].r = pa[now].fir - 1;
                        }
                        now--;
                    }
                    else if(pa[now].fir == b[o][i].l){
                        a[b[o][i].id] = (Node){0, 0, 0, 0};
                        continue;
                    }
                    if(!now) continue;
                    if(pa[now].sec >= b[o][i].r) a[b[o][i].id] = (Node){0, 0, 0, 0};
                    else if(pa[now].sec >= b[o][i].l){
                        b[o][i].l = a[b[o][i].id].l = pa[now].sec + 1;
                    }
                }
            }
        }
        For(i, 1, n) if(a[i].d) as += 1ll * (a[i].d - a[i].u + 1) * (a[i].r - a[i].l + 1);

        printf("%lld\n", as);
        For(i, 1, n) printf("%d %d %d %d\n", a[i].u, a[i].l, a[i].d, a[i].r);
    }
    return 0;
}
