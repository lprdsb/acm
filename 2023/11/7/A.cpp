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

int T, n, k, a[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int vis[maxn + 5];
int main(){
	// freopen("in.txt", "r", stdin);
    read(T);
    For(_, 1, T){
        read(n); read(k);
        For(i, 0, n - 1) read(a[i]);
        // if(_ == 116){
        //     cout << n << " " << k << endl;
        //     For(i, 0, n - 1) cout << a[i] << " "; cout << endl;
        // }
        int now = n - 1, tot = 0, fl = 0;
        while(666){
            if(a[now] > n) break;
            if(!vis[now]) vis[now] = ++tot;
            else{
                fl = 1;
                break;
            }
            now = (n - a[now] + now) % n;
        }
        // cout << tot << endl;
        // cout << fl << endl;
        // if(T == 10000) continue;
        if(!fl){
            if(k <= tot) puts("Yes");
            else puts("No");
        }
        else puts("Yes");
        For(i, 0, n - 1) vis[i] = 0;
    }
}
