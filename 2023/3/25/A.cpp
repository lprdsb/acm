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
#define maxn 400000
using namespace std;

int t, n, k, a[maxn + 5], b[maxn + 5], ok[maxn + 5];
LL as[maxn + 5];

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
        memset(ok, 0, sizeof ok);
        read(n); read(k);
        For(i, 1, n) read(a[i]), a[n + i] = a[i];
        For(i, 1, n) read(b[i]), b[n + i] = b[i];
        int res = 0;
        LL now = 0;
        For(i, 1, n){
            if(b[i] == 1) now += k - res, res = k - a[i];
            else{
                if(res >= a[i]) res -= a[i];
                else now += 2ll * (a[i] - res), ok[i + n] = a[i] - res, res = 0;
            }
        }
        Rof(i, n, 1){
            if(b[i] == 1){
                int tem = i + 1;
                now += k;
                int rres = k - a[i];
                while(tem <= i + n && b[tem] == 2){
                    if(rres >= a[tem]){
                        rres -= a[tem];
                        now -= 2ll * a[tem];
                        ok[tem] = 0;
                    }
                    else{
                        now -= 2ll * rres;
                        ok[tem] = a[tem] - rres;
                        break;
                    }
                    if(tem == i + n) res = rres;
                    tem++;
                }
                if(tem <= i + n && b[tem] == 1) now -= rres;
            }
            else{
                now += 2ll * a[i];
                ok[i] = a[i];
            }
            // cout << now << " " << res << endl;
            res += a[i + n];
            if(b[i + n] == 2){
                now -= 2ll * ok[i + n];
                res -= ok[i + n];
            }
            now -= res;
            res = 0;
            as[i] = now;
        }
        For(i, 1, n) printf("%lld ", as[i]); puts("");
    }
    return 0;
}
