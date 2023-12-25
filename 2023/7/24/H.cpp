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
LL sum = 0;

template <class T>
void read(T &x){
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

bool chk(LL x){
    if(x < 2) return 0;
    For(i, 2, x){
        if(1ll * i * i > x) break;
        if(x % i == 0) return 0;
    }
    return 1;
}

int main(){
    //freopen("in", "r", stdin);
    read(n);
    For(i, 1, n){
        int x; read(x);
        sum += x;
    }
    if(n == 1){
        if(chk(sum)) puts("Yes");
        else puts("No");
        return 0;
    }
    if(sum >= 2 * n){
        if(n == 2){
            if(sum % 2 == 0 || chk(sum - 2)) puts("Yes");
            else puts("No");
        }
        else puts("Yes");
    }
    else puts("No");
    return 0;
}
