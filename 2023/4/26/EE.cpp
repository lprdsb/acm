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
#define maxn 1000000
using namespace std;

int n;
DD pi = acos(-1.0);
// pair<DD, DD> pa[2 * maxn + 5];
double wt[maxn*2+7];int tot;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int main(){
	//freopen("in", "r", stdin);
    read(n);bool ok=false;
    For(i, 1, n){
        int x, y, r; read(x); read(y); read(r);
        if(1ll * x * x + 1ll * y * y <= 1ll * r * r){
            // ok=true;
            puts("Yes");
            return 0;
        }
        DD tem = atan2((double)x, (double)y), tem1 = asin((double)r/sqrt((DD)x * x + (DD)y * y));
        wt[++tot]=tem-tem1;
        if(wt[tot]<-pi)wt[tot]+=pi*2;
        wt[++tot]=tem+tem1;
        if(wt[tot]>=pi)wt[tot]-=pi*2;
        // pa[i] = {tem - tem1, tem + tem1};
    }
    sort(wt+1,wt+tot+1);
    // For(i,1,tot)cout<<wt[i]/pi<<' ';
    // cout<<endl;
    For(i,1,tot-1){
        if(wt[i+1]-wt[i]>pi)ok=true;
    }
    if(wt[1]+pi-wt[tot]>0)ok=true;
    if(ok)printf("No");
    else printf("Yes");
    // sort(pa + 1, pa + n + 1);
    // For(i, 1, n) pa[n + i] = pa[i];
    // For(i, 1, n){
    //     DD tem = pa[i + n - 1].sec - pa[i].fir;
    //     while(tem < 0) tem += 2 * pi;
    //     if(tem < pi){
    //         puts("No");
    //         return 0;
    //     }
    // }
    // puts("Yes");
    return 0;
}
