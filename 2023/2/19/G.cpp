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

int n, a[2 * maxn + 5], tot = 0, pos[2 * maxn + 5], pre[2 * maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

bool chk(int x){
    int sum = 0;
    For(i, 1, 2 * n - 1){
        int tem = 0;
        For(j, i, 2 * n - 1){
            tem += a[j];
            if(tem == x && j - i + 1 >= n){
                sum++;
                // cout << i << " " << j << endl;
                if(sum == n) return 1;
            }
        }
    }
    return 0;
}

int main(){
	freopen("in.txt", "r", stdin);
    freopen("out", "w", stdout);
    read(n);
    int res = 0;
    For(i, 1, 2 * n - 1){
        char c; cin >> c;
        if(c == 'W') a[i] = 1, pos[++tot] = i, pos[i] = res, res = 0;
        else res++;
    }
    // cout << tot << endl;
    int tem = 0, asi = inf;
    For(i, 1, n - 1) tem += a[i];
    For(i, n, 2 * n - 1) tem += a[i] - a[i - n], asi = min(asi, tem);
    // cout << asi << endl;
    For(i, 0, 2 * n - 1){
        if(chk(i)) cout << i << endl;
    }
    // cout << chk(3) << endl;
    return 0;
}
