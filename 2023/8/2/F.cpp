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

LL n, a, b;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

void exgcd(LL a, LL &x, LL b, LL &y){
    if(!b){
        x = 1;
        y = 0;
        return;
    }
    LL xx, yy;
    exgcd(b, xx, a % b, yy);
    // cout << a << " " << b << endl;
    x = yy;
    y = xx - (a / b) * yy;
}

LL gcd(LL x, LL y){return y ? gcd(y, x % y) : x;}

int main(){
	//freopen("in", "r", stdin);
    read(n);
    int cnt = 0;
    For(i, 2, n){
        if(1ll * i * i > n) break;
        if(n % i == 0){
            cnt++;
            LL tem = 1;
            while(n % i == 0){
                n /= i;
                tem *= i;
            }
            if(cnt == 1) a = tem, b = n;
        }
    }
    if(n != 1) cnt++;
    if(cnt <= 1) puts("No");
    else{
        puts("Yes\n2");
        LL x, y;
        exgcd(a, x, b, y);
        // cout << x << " " << y << endl;
        LL tem = x / b;
        x -= b * tem;
        y += a * tem;
        if(x > 0) x -= b, y += a;
        LL tem1 = -x * a, tem2 = a * b - 1 - tem1, gc1 = gcd(tem1, a * b), gc2 = gcd(tem2, a * b);
        printf("%lld %lld\n%lld %lld\n", tem1 / gc1, a * b / gc1, tem2 / gc2, a * b / gc2);
    }
    return 0;
}
