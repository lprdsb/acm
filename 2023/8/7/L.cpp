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

int n, m, to[maxn + 5], ok = 0;
LL a[maxn + 5], res = 0, lres = 0, d[maxn + 5], b, pwb = 1, p;

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
    read(n); read(m); read(b); read(p);
    For(i, 1, n) read(a[i]);
    while(m--){
        int op; read(op);
        if(op == 1){
            int x;
            LL c;
            read(x); read(c); x = (x ^ lres) % n + 1; c = c ^ lres;
            a[x] = c;
            ok = 0;
        }
        else{
            pwb = 1ll * pwb * b % p;
            int len; read(len);
            For(i, 1, len) read(d[i]), d[i] ^= lres;
            if(len < n) lres = 0;
            else{
                if(!ok){
                    ok = 1;
                    For(i, 2, n){
                        to[i] = to[i - 1];
                        while(to[i] && a[to[i] + 1] != a[i]) to[i] = to[to[i]];
                        if(a[to[i] + 1] == a[i]) to[i]++;
                    }
                }
                int x = 0, y = to[n];
                int now = 0;
                // cout << to[n] << endl;
                For(i, 1, len){
                    while(now && (now == n || d[i] != a[now + 1])) now = to[now];
                    if(d[i] == a[now + 1]) now++;
                    if(now == n) x++;
                }
                // cout << x << " " << y << endl;
                res = (res + x * y % p * pwb % p) % p;
                lres = x * y;
            }
        }
    }
    printf("%lld\n", res);
    return 0;
}
