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

int n, a[maxn + 5], bas = 700;
LL f[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int st[maxn + 5], top = 0;
int main(){
	//freopen("in", "r", stdin);
    memset(f, inf, sizeof f);
    f[1] = 0;
    read(n);
    For(i, 1, n){
        read(a[i]);
        {
            int mn = a[i];
            Rof(j, i - 1, 1){
                if(i - j > bas) break;
                mn = min(mn, a[j]);
                f[i] = min(f[i], f[j] + 1ll * mn * (i - j) * (i - j));
            }
        }
        if(a[i] <= bas){
            Rof(j, i - 1, 1){
                if(a[j] <= a[i]) break; 
                f[i] = min(f[i], f[j] + 1ll * a[i] * (i - j) * (i - j));
            }
        }
        For(j, 1, top) f[i] = min(f[i], f[st[j]] + 1ll * a[st[j]] * (i - st[j]) * (i - st[j]));
        if(a[i] <= bas){
            while(top && a[st[top]] >= a[i]) top--;
            st[++top] = i;
        }
    }
    For(i, 1, n) printf("%lld ", f[i]);
    return 0;
}
