#include<bits/stdc++.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define Tra(u, i) for(int i = hd[u]; ~i; i = e[i].net)
#define cst const
#define LL __int128_t
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

int T;
LL bas = 1000000000;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

LL gcd(LL x, LL y){return y ? gcd(y, x % y) : x;}

LL abs(LL x){
    return x < 0 ? -x : x;
}

void exgcd(LL a, LL &x, LL b, LL &y, LL c){
    if(!b){
        x = c / a; y = 0;
        return;
    }
    LL xx, yy;
    exgcd(b, xx, a % b, yy, c);
    x = yy;
    y = xx - a / b * yy;
    LL tem = (x - bas) / b;
    x -= b * tem;
    y += a * tem;
}

int main(){
	// freopen("in.txt", "r", stdin);
    read(T);
    while(T--){
        LL x1, y1, x2, y2; read(x1); read(y1); read(x2); read(y2);
        if(x1 == x2){
            printf("%lld %lld\n", (long long)x1 + 1, 114514);
        }
        else{
            LL kp = y1 - y2, kq = x1 - x2, bp = x1 * y2 - x2 * y1, bq = x1 - x2;
            LL gc = gcd(kp, kq); kp /= gc; kq /= gc;
            gc = gcd(bp, bq); bp /= gc; bq /= gc;
            LL k = (bp * kq / bq) * bq - bq;
            if(k + bq != bp * kq && abs(k + bq - bp * kq) < abs(k - bp * kq)) k += bq;
            if(k + bq != bp * kq && abs(k + bq - bp * kq) < abs(k - bp * kq)) k += bq;
            // cout << kp << " " << kq << endl;
            k /= bq;
            LL x, y;
            exgcd(kp, x, -kq, y, -k);
            printf("%lld %lld\n", (long long)x, (long long)y);
        }
    }
    return 0;
}
