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
#define maxn 2000000
using namespace std;

int t, n, k, a[maxn + 5], b[maxn + 5], ok[maxn + 5][2];
vector<int> vec[maxn + 5][2];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int gcd(int x, int y){return y ? gcd(y, x % y) : x;}

int f[maxn + 5][2], pre[maxn + 5][2];
int main(){
	// freopen("in.txt", "r", stdin);
    read(t);
    while(t--){
        read(n); read(k);
        For(i, 0, n){
            ok[i][0] = ok[i][1] = 0;
            vec[i][0].clear();
            vec[i][1].clear();
            f[i][0] = f[i][1] = inf;
        }
        For(i, 0, n - 1){
            read(a[i]);
            if(i) b[i] = a[i] ^ a[i - 1];
        }
        b[0] = a[0] ^ a[n - 1];
        int gc = gcd(n, k), fl = 0;
        For(i, 0, gc - 1){
            int now = i, ty = 0;
            For(j, 1, n / gc){
                ty ^= b[now];
                vec[i][ty].pb(now);
                if(!now || now + k - 1 >= n) ok[i][ty] ^= 1;
                now = (now + k) % n;
            }
            if(ty){
                fl = 1;
                break;
            }
        }
        if(fl){
            puts("-1");
            continue;
        }
        f[0][0] = 0;
        For(i, 0, gc - 1) For(j, 0, 1) For(p, 0, 1){
            int to = j ^ ok[i][p];
            if(f[1 + i - 1][to] + vec[i][p].size() < f[1 + i][j]){
                f[1 + i][j] = f[1 + i - 1][to] + vec[i][p].size();
                pre[i][j] = p;
            }
        }
        int now = !a[0];
        if(f[gc][now] == inf){
            puts("-1");
            continue;
        }
        printf("%d\n", f[gc][now]);
        Rof(i, gc - 1, 0){
            for(auto j : vec[i][pre[i][now]]) printf("%d ", j);
            now ^= ok[i][pre[i][now]];
        }
        puts("");
    }
}
