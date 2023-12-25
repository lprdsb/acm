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
    int now = 1, cnt = x - (x != 0), sum = 0;
    For(i, pos[x], 2 * n - 1){
        cnt += a[i];
        while(cnt - a[now] >= x && i - now + 1 > n) cnt -= a[now++];
        if(i - now + 1 >= n && cnt == x) sum += pre[now];
        // cout << i << " " << now << " " << sum << endl;
        if(sum >= n) return 1;
    }
    return 0;
}

int main(){
	// freopen("in.txt", "r", stdin);
    // freopen("out", "w", stdout);
    read(n);
    int res = 0;
    pos[0] = 1;
    For(i, 1, 2 * n - 1){
        char c; cin >> c;
        if(c == 'W') a[i] = 1, pos[++tot] = i, pre[i] = res + 1, res = 0;
        else pre[i] = ++res;
    }
    int l = max(tot / 2, 0), r = min(tot, tot / 2 + 25);
    // cout << chk(0) << endl;
    For(i, l, r) if(chk(i)){
        printf("%d\n", i);
        break;
    }
    return 0;
}
