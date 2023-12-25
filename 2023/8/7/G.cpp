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

int t, n, k, a[maxn + 5], vis[maxn + 5];
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
    // cout << inf << endl;
	// freopen("in.txt", "r", stdin);
    read(t);
    while(t--){
        int cnt = 0;
        read(n); read(k);
        LL sum = 0;
        // cout << n << endl;
        For(i, 0, n - 1) read(a[i]), sum += a[i];
        if(k > n / 2){
            puts(sum ? "NO" : "YES");
            continue;
        }
        For(i, 0, n - 1) if(!vis[i]){
            int now = i;
            cnt++;
            vec[cnt].resize(0);
            while(!vis[now]){
                vis[now] = 1;
                vec[cnt].pb(now);
                now = (now + k) % n;
            }
        }
        int fl = 1;
        For(i, 1, cnt){
            LL pre = 0, l = 0, r = Inf;
            For(j, 0, vec[i].size() - 2){
                LL tem = a[vec[i][j]] - pre;
                if(j & 1) l = max(l, -tem);
                else r = min(r, tem);
                pre = tem;
            }
            if(vec[i].size() & 1){
                if((a[vec[i][vec[i].size() - 1]] - pre) % 2 == 0){
                    LL res = (a[vec[i][vec[i].size() - 1]] - pre) / 2;
                    if(res < l || res > r){
                        fl = 0;
                        break;
                    }
                }
                else{
                    fl = 0;
                    break;
                }
            }
            else{
                if(a[vec[i][vec[i].size() - 1]] - pre){
                    fl = 0;
                    break;
                }
                else if(l > r){
                    fl = 0;
                    break;
                }
            }
        }
        puts(fl ? "YES" : "NO");
        For(i, 0, n - 1) vis[i] = 0;
    }
    return 0;
}
