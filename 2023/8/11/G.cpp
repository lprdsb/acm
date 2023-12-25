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

struct Vec{
    LL x, y;
    LL get_len2(){return x * x + y * y;}
    DD get_len(){return sqrt(get_len2());}
} p[2][2];
LL operator ^ (Vec _x, Vec _y){
    return _x.x * _y.y - _x.y * _y.x;
}
Vec operator - (Vec _x, Vec _y){return {_x.x - _y.x, _x.y - _y.y};}

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

DD get_g(DD x, DD y){
    y = fabs(y);
    if(x <= eps || y <= eps) return 0;
    DD sq = sqrt(x * x + y * y);
    return x * y * sq / 3 + (x * x * x * log((sq + y) / x) + y * y * y * log((sq + x) / y)) / 6;
}

DD get_f(DD x, DD y1, DD y2){
    x = fabs(x);
    if(y1 * y2 < 0) return get_g(x, y1) + get_g(x, y2);
    return fabs(get_g(x, y1) - get_g(x, y2));
}

int main(){
	freopen("in.txt", "r", stdin);
    read(t);
    while(t--){
        For(o1, 0, 1) For(o2, 0, 1) read(p[o1][o2].x), read(p[o1][o2].y);
        DD l1 = ((p[0][1] - p[0][0]) ^ (p[1][0] - p[0][0])) / (p[0][1] - p[0][0]).get_len();
        DD r1 = ((p[0][1] - p[0][0]) ^ (p[1][1] - p[0][0])) / (p[0][1] - p[0][0]).get_len();
        DD l2 = ((p[1][1] - p[1][0]) ^ (p[0][0] - p[1][0])) / (p[1][1] - p[1][0]).get_len();
        DD r2 = ((p[1][1] - p[1][0]) ^ (p[0][1] - p[1][0])) / (p[1][1] - p[1][0]).get_len();
        DD as;
        if(l1 * r1 < 0) as = get_f(l1, l2, r2) + get_f(r1, l2, r2);
        else as = fabs(get_f(l1, l2, r2) - get_f(r1, l2, r2));
        printf("%.20lf\n", as / (p[0][1] - p[0][0]).get_len() / (p[1][1] - p[1][0]).get_len());
    }
    return 0;
}
