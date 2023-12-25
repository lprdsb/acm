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
#define maxn 500
using namespace std;

int t, n, m, a[maxn + 5], b[maxn + 5], as[maxn + 5][maxn + 5];
char cc[maxn + 5][maxn + 5];

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
        read(n); read(m);
        For(i, 1, n) For(j, 1, m) cin >> cc[i][j];
        For(i, 1, n) For(j, 1, m){
            char c; c = cc[i][j];
            if(c == 'U'){
                if(a[i]){
                    as[i][j] = 1;
                    as[i + 1][j] = 2;
                    a[i + 1] = 1;
                }
                else{
                    as[i][j] = 2;
                    as[i + 1][j] = 1;
                    a[i + 1] = 0;
                }
                a[i] ^= 1;
            }
        }
        For(j, 1, m) For(i, 1, n){
            char c; c = cc[i][j];
            if(c == 'L'){
                if(b[j]){
                    as[i][j] = 1;
                    as[i][j + 1] = 2;
                    b[j + 1] = 1;
                }
                else{
                    as[i][j] = 2;
                    as[i][j + 1] = 1;
                    b[j + 1] = 0;
                }
                b[j] ^= 1;
            }
        }
        int fl = 1;
        For(i, 1, n){
            int cnt = 0;
            For(j, 1, m){
                if(as[i][j] == 1) cnt++;
                if(as[i][j] == 2) cnt--;
            }
            if(cnt) fl = 0;
        }
        For(i, 1, m){
            int cnt = 0;
            For(j, 1, n){
                if(as[j][i] == 1) cnt++;
                if(as[j][i] == 2) cnt--;
            }
            if(cnt) fl = 0;
        }
        if(fl){
            For(i, 1, n){
                For(j, 1, m){
                    if(as[i][j] == 1) printf("W");
                    else if(as[i][j] == 2) printf("B");
                    else printf(".");
                }
                puts("");
            }
        }
        else puts("-1");
        For(i, 1, n) a[i] = 0;
        For(i, 1, m) b[i] = 0;
        For(i, 1, n) For(j, 1, m) as[i][j] = 0;
    }
}
