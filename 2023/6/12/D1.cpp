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
#define maxn 4000
using namespace std;

int t, n, a[maxn + 5], b[maxn + 5], cnt, f[2][maxn + 5][2];
pair<int, int> opt[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int find(int x){
    int l = 1, r = cnt;
    while(l < r){
        int mid = l + r >> 1;
        if(b[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return l;
}

void chkmx(int &x, int y){if(x < y) x = y;}

int main(){
	// freopen("in.txt", "r", stdin);
    read(t);
    while(t--){
        read(n);
        cnt = 0;
        For(i, 1, n){
            read(opt[i].fir); read(opt[i].sec);
            b[++cnt] = opt[i].fir;
            b[++cnt] = opt[i].sec + 1;
        }
        sort(b + 1, b + cnt + 1);
        cnt = unique(b + 1, b + cnt + 1) - b - 1;
        For(i, 1, cnt) a[i] = 0;
        For(i, 1, n){
            opt[i].fir = find(opt[i].fir);
            opt[i].sec = find(opt[i].sec + 1) - 1;
        }
        sort(opt + 1, opt + n + 1);
        int o = 0;
        For(i, 0, cnt) f[o][i][0] = 0, f[o][i][1] = -inf;
        For(i, 1, n){
            For(j, 0, cnt) f[o ^ 1][j][0] = 0, f[o ^ 1][j][1] = -inf;
            For(j, 0, cnt){
                if(j < opt[i].fir){
                    chkmx(f[o ^ 1][opt[i].sec][1], f[o][j][0] + 1);
                }
                else{
                    chkmx(f[o ^ 1][max(opt[i].sec, j)][0], f[o][j][1] + 1);
                }
                chkmx(f[o ^ 1][j][0], f[o][j][0]);
                chkmx(f[o ^ 1][j][1], f[o][j][1]);
            }
            o ^= 1;
        }
        int as = 0;
        For(i, 0, cnt) chkmx(as, f[o][i][0]);
        printf("%d\n", n - as);
    }
    return 0;
}
