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
#define maxn 100
#define maxm 10000
using namespace std;

int n, a[maxn + 5];
char s[maxn + 5];
bitset<maxm + 5> f[2][maxn + 5];

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
    scanf("%s", s + 1); n = strlen(s + 1);
    For(i, 1, n) a[i] = s[i] - '0';
    f[0][0][0] = f[1][0][0] = 1;
    For(i, 1, n){
        int o = s[i] - '0';
        Rof(j, n, 1) f[o][j] |= f[o][j - 1] << i;
    }
    int cnt = 0, res = 0;
    For(i, 1, n){
        if(a[i]) res += cnt;
        else{
            cnt++;
            res -= i - cnt; 
        }
    }
    // cout << res << endl;
    if(!res) puts("0");
    else{
        int fl = 0;
        res /= 2;
        if(res < 0){
            For(i, 1, n){
                For(j, 0, maxm + res) if(f[1][i][j] && f[0][i][j - res]){
                    fl = 1;
                    printf("%d\n", i);
                    // cout << j - res << " " << j << endl;
                    break;
                }
                if(fl) break;
            }
        }
        else{
            For(i, 1, n){
                For(j, 0, maxm - res) if(f[0][i][j] && f[1][i][j + res]){
                    fl = 1;
                    printf("%d\n", i);
                    break;
                }
                if(fl) break;
            }
        }
    }
}
