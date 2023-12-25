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
#define maxn 50000
using namespace std;

int n, a[maxn + 5][4], b[4], mx[2][maxn + 5];
LL s[4];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

bool cmp(pair<int, int> x, pair<int, int> y){return x.fir > y.fir;}

int main(){
	// freopen("in.txt", "r", stdin);
    read(n);
    For(i, 1, n) For(j, 0, 3) read(a[i][j]), s[j] += a[i][j];
    For(i, 0, 3) read(b[i]), s[i] += b[i];
    For(i, 1, n){
        mx[0][i] = mx[0][i - 1];
        For(j, 0, 3) mx[0][i] = max(mx[0][i], a[i][j]); 
    }
    Rof(i, n, 1){
        mx[1][i] = mx[1][i + 1];
        For(j, 0, 3) mx[1][i] = max(mx[1][i], a[i][j]);
    }
    LL tot = s[0] + s[1] + s[2] + s[3];
    tot /= n;
    // cout << tot << endl;
    For(i, 1, n){
        int tem = tot - a[i][0] - a[i][1] - a[i][2] - a[i][3];
        int as = 0;
        For(j, 0, 3){
            int tem1 = min(tem, b[j]);
            pair<int, int> pa[5];
            pa[j] = {s[j] - a[i][j] - tem1, b[j] - tem1};
            For(p, 0, 3) if(p != j) pa[p] = {s[p] - a[i][p], b[p]};
            pa[4] = {0, 0};
            sort(pa, pa + 4, cmp);
            int res = tem - tem1;
            // cout << res << endl;
            while(res){
                int fl = 0;
                For(p, 0, 3) if(p == 3 || pa[p].fir != pa[p + 1].fir){
                    int tem3 = pa[p].fir - pa[p + 1].fir, ffl = 1;
                    For(q, 0, p) if(pa[q].sec < tem3){
                        ffl = 0;
                        break;
                    }
                    if(ffl){
                        int tem2 = min(res, tem3);
                        res -= tem2;
                        For(q, 0, p) pa[q].fir -= tem2, pa[q].sec -= tem2;
                    }
                    else{
                        int tem2 = res;
                        For(q, 0, p) tem2 = min(tem2, pa[q].sec);
                        res -= tem2;
                        For(q, 0, p) pa[q].fir -= tem2;
                        fl = 1;
                        break;
                    }
                    break;
                }
                if(fl) break;
            }
            as = max(as, a[i][j] + tem1 - max(max(mx[0][i - 1], mx[1][i + 1]), (int)ceil((DD)pa[0].fir / (n - 1))));
            // if(i == 1){
                // cout << j << " " << as << endl;
            // }
        }
        printf("%d ", as);
    }
    return 0;
}
