#include<bits/stdc++.h>
#define For(i, a, b) for(LL i = (a), en = (b); i <= en; ++i)
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
#define maxn 100ll
#define maxm 5500ll
using namespace std;

int t, s;
bool f[2][maxn + 5][maxm + 5];
LL sum = 0;

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
        memset(f, 0, sizeof f); f[0][0][0] = f[1][0][0] = 1;
        sum = 0;
        read(s);
        For(o, 0, 1){
            For(i, 1, s){
                int x; read(x);
                sum += (o ? 1 : -1) * i * x;
                if(x == o + 1)
                    Rof(j, i, 1) For(p, i, maxm) f[o][j][p] |= f[o][j - 1][p - i];
            }
        }
        // cout << sum << endl;
        if(sum < 0) puts("-1");
        else if(!sum) puts("0");
        else{
            int fl = 0;
            For(i, 1, s){
                LL l = max(1ll, sum - maxm), r = min(maxm, sum);
                For(j, l, r) if(f[0][i][j] && f[1][i][sum - j]){
                    fl = 1;
                    printf("%d\n", i);
                    break;
                }
                if(fl) break;
            }
            if(!fl) puts("-1");
        }
    }
	return 0;
}
