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

int n;
DD a[15][15], b[15][15];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

DD c[15];
DD sol(){
    For(i, 0, n){
        For(j, 0, n + 1) if(fabs(b[i][j]) > eps){
            For(p, 0, n) if(p != i){
                DD tem = b[p][j] / b[i][j];
                For(q, 0, n + 1) b[p][q] -= tem * b[i][q];
            }
            break;
        }
    }
    // For(i, 0, n){
    //     For(j, 0, n + 1) cout << b[i][j] << " "; cout << endl;
    // }
    For(i, 0, n - 1) c[i] = 0;
    For(i, 0, n){
        int fl = 0;
        For(j, 0, n) if(fabs(b[i][j]) > eps){
            if(fl) return 0;
            fl = 1;
            c[j] = b[i][n + 1] / b[i][j];
            if(j != n && c[j] < -eps) return 0;
        }
        if(!fl && fabs(b[i][n + 1]) > eps) return 0;
    }
    DD res = 0;
    For(i, 0, n - 1) For(j, i + 1, n - 1) res += a[i][j] * c[i] * c[j];
    return res;
}

int main(){
	// freopen("in.txt", "r", stdin);
    read(n);
    For(i, 0, n - 1) For(j, 0, n - 1) scanf("%lf", &a[i][j]);
    For(i, 0, n - 1) a[n][i] = 1;
    For(i, 0, n - 1) a[i][n] = 1;
    a[n][n + 1] = 1;
    DD res = 0;
    For(mask, 1, (1 << n) - 1){
        For(i, 0, n){
            if(((mask >> i) & 1) || i == n){
                For(j, 0, n + 1){
                    if(((mask >> j) & 1) || (j >= n)) b[i][j] = a[i][j];
                    else b[i][j] = 0;
                }
            }
            else For(j, 0, n + 1) b[i][j] = 0;
        }
        res = max(res, sol());
    }
    printf("%.10lf\n", res);
    return 0;
}
