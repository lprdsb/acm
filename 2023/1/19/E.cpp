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
#define maxn 200000
using namespace std;

int n, k, a[maxn + 5];

template <class T>
void read(T &x){
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

int ok;
bool chk(int x){
    int tot1 = 0, tot2 = 0;
    For(i, 1, n){
        if(tot1 & 1){
            if(a[i] <= x) tot1++;
        }
        else tot1++;
    }
    For(i, 1, n){
        if(tot2 & 1) tot2++;
        else if(a[i] <= x) tot2++;
    }
    return max(tot1, tot2) >= k;
}

int main(){
    //freopen("in", "r", stdin);
    read(n); read(k);
    For(i, 1, n) read(a[i]);
    int l = 1, r = 1e9;
    while(l < r){
        int mid = l + r >> 1;
        if(chk(mid)) r = mid;
        else l = mid + 1;
    }
    printf("%d\n", l);
    return 0;
}
