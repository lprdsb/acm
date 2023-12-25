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
#define maxn 15
using namespace std;

int n, k, a[maxn + 5][maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

LL sum[maxn + 5];
bool chk(int x){
    For(o, 0, (1 << (n - 1)) - 1){
        int cnt = 0;
        For(i, 0, n - 2) cnt += (o >> i) & 1;
        if(cnt > k) continue;
        int sta = o | (1 << (n - 1));
        For(i, 1, n){
            int fl = 0, now = 0;
            For(j, 1, n){
                now += a[i][j];
                if((sta >> (j - 1)) & 1){
                    if(sum[j] + now > x){
                        fl = 1;
                        break;
                    }
                    now = 0;
                }
            }
            if(fl){
                cnt++;
                if(cnt > k) break;
                For(j, 1, n) sum[j] = 0;
            }
            now = 0;
            For(j, 1, n){
                now += a[i][j];
                if((sta >> (j - 1)) & 1){
                    sum[j] += now;
                    if(now > x){
                        cnt = k + 1;
                        break;
                    }
                    now = 0;
                }
            }
            if(cnt > k) break;
        }
        For(i, 1, n) sum[i] = 0;
        if(cnt <= k) return 1;
    }
    return 0;
}

int main(){
	//freopen("in", "r", stdin);
    read(n); read(k);
    For(i, 1, n) For(j, 1, n) read(a[i][j]);
    // cout << chk(5) << endl;
    int l = 0, r = 10000000;
    while(l < r){
        int mid = l + r >> 1;
        if(chk(mid)) r = mid;
        else l = mid + 1;
    }
    printf("%d\n", l);
    return 0;
}
