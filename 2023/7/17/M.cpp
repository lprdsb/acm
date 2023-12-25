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

int t;
LL a, b, c, as = -1;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int exgcd(LL a, LL &x, LL b, LL &y, LL c){
    if(!b){
        if(c % a == 0){
            x = c / a;
            y = 0;
            return a;
        }
        else return -1;
    }
    LL xx, yy;
    LL gc = exgcd(b, xx, a % b, yy, c);
    if(gc == -1) return -1;
    x = yy;
    y = xx - (a / b) * yy;
    return gc;
}

void chkmn(LL &x, LL y){
    if(x == -1 || x > y) x = y;
}

void sol(LL x, LL y){
    chkmn(as, 2 * (abs(x) + abs(y)) - (x < 0 || y < 0));
}

int main(){
	// freopen("in.txt", "r", stdin);
    read(t);
    while(t--){
        read(a); read(b); read(c);
        if(a < b) swap(a, b);
        LL x, y;
        LL gc = exgcd(a, x, b, y, c);
        if(gc == -1){
            puts("-1");
            continue;
        }
        LL tem = y / (a / gc);
        x += b / gc * tem;
        y -= a / gc * tem;
        // cout << x << " " << y << endl;
        as = -1;
        sol(x, y);
        if(y > 0){
            x += b / gc;
            y -= a / gc;
        }
        else{
            x -= b / gc;
            y += a / gc;
        }
        sol(x, y);
        printf("%lld\n", as);
    }
    return 0;
}
