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
using namespace std;

int T, n, m;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

#define maxn 100000
int cnt[maxn + 5], ok[maxn + 5], vis[maxn + 5], num[maxn + 5], vvis[maxn + 5];
vector<int> b[maxn + 5], a[maxn + 5];

int main(){
	freopen("in.txt", "r", stdin);
    read(T);
    while(T--){
        read(n); read(m);
        For(i, 1, n){
            read(cnt[i]); num[i] = cnt[i];
            b[i].resize(cnt[i] + 1);
            For(j, 1, cnt[i]){
                read(b[i][j]);
                a[b[i][j]].pb(i);
            }
        }
        vector<int> as;
        Rof(i, n, 1){
            int tem = 0;
            For(j, 1, cnt[i]) if(!vis[b[i][j]]){
                for(auto p : a[b[i][j]]){
                    num[p]--;
                    if(!vvis[p]) ok[p]++;
                    vvis[p] = 1;
                }
                for(auto p : a[b[i][j]]) vvis[p] = 0;
                tem++;
            }
            vector<int> opt;
            For(j, 1, cnt[i]) if(!vis[b[i][j]]){
                for(auto p : a[b[i][j]]) if(!num[p] && ok[p] == tem){
                    if(!vvis[p]) opt.pb(p);
                    vvis[p] = 1;
                }
            }
            sort(opt.begin(), opt.end());
            for(auto v : opt) as.pb(v);
            For(j, 1, cnt[i]) if(!vis[b[i][j]]){
                vis[b[i][j]] = 1;
                for(auto p : a[b[i][j]]){
                    vvis[p] = 0;
                    ok[p] = 0;
                }
            }
        }
        for(auto v : as) vvis[v] = 1;
        For(i, 1, n){
            if(!vvis[i]) as.pb(i);
            vvis[i] = 0;
        }
        reverse(as.begin(), as.end());
        int fl = 0;
        For(i, 0, as.size() - 1) if(as[i] != i + 1){
            fl = 1;
            break;
        } 
        if(!fl) puts("No");
        else{
            puts("Yes");
            For(i, 0, n - 1) printf("%d ", as[i]);
            puts("");
        }

        For(i, 1, m){
            a[i].resize(0);
            vis[i] = 0;
        }
    }
}
