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
#define maxn 400
using namespace std;

int n, x, y, tot = 0;
pair<int, int> c[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

void chkmn(LL &x, LL y){
    if(x > y) x = y;
}

LL f[maxn + 5][maxn + 5], g[maxn + 5], h[maxn + 5];
vector<int> pos;
int main(){
    cout << "asd" << endl;
	freopen("in.txt", "r", stdin);
    read(n); read(x); read(y);
    For(i, 1, n){
        int x; read(x);
        if(x == c[tot].fir) c[tot].sec++;
        else c[++tot] = {x, 1};
    }
    // cout << "asd" << endl;
    memset(f, inf, sizeof f);
    memset(g, inf, sizeof g);
    For(i, 1, tot) f[i][i] = x;
    For(len, 2, tot){
        For(l, 1, tot - len + 1){
            int r = l + len - 1;
            if(c[l].fir == c[r].fir){
                g[l] = x + 1ll * c[l].sec * y;
                h[l] = x + 2ll * c[l].sec * y;
                pos.pb(l);
            }
            For(mid, l, r - 1){
                chkmn(f[l][r], f[l][mid] + f[mid + 1][r]);
                if(mid != l && c[l].fir == c[r].fir && c[mid].fir == c[l].fir){
                    for(auto i : pos) chkmn(g[mid], g[i] + f[i + 1][mid - 1] + 1ll * c[mid].sec * y);
                    for(auto i : pos) chkmn(h[mid], h[i] + f[i + 1][mid - 1] + 2ll * c[mid].sec * y);
                    pos.pb(mid);
                }
            }
            if(c[l].fir == c[r].fir){
                for(auto i : pos){
                    chkmn(f[l][r], g[i] + f[i + 1][r - 1] + 1ll * c[r].sec * y);
                    chkmn(f[l][r], h[i] + f[i + 1][r - 1]);
                    g[i] = Inf;
                    h[i] = Inf;
                }
                pos.resize(0);
            }
        }
    }
    printf("%lld\n", f[1][tot]);
    return 0;
}
