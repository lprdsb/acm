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
#define eps 1e-15
#define eeps 1e-9
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

DD get_val(DD x, DD b){
    if(x <= eps) return 0;
    DD bx = b / x, sq = sqrt(1 + bx * bx);
    return (b * x * sq + x * x * log(sq + bx)) / 2;
}

DD get_simp1(DD l, DD r, DD b){
    return (get_val(l, b) * 41 + get_val((5 * l + r) / 6.0, b) * 216 + get_val((2 * l + r) / 3.0, b) * 27 +
            get_val((l + r) / 2.0, b) * 272 + get_val((l + 2 * r) / 3.0, b) * 27 +
            get_val((l + r * 5) / 6.0, b) * 216 + get_val(r, b) * 41) *
           (r - l) / 840.0;
}

DD simp1(DD l, DD r, DD b, DD now){
    DD mid = (l + r) / 2, teml = get_simp1(l, mid, b), temr = get_simp1(mid, r, b);
    if(fabs(now - teml - temr) <= eeps) return teml + temr;
    return simp1(l, mid, b, teml) + simp1(mid, r, b, temr);
}

DD get_g(DD x, DD y){
    y = fabs(y);
    if(x <= eps || y <= eps) return 0;
    return simp1(0, x, y, get_simp1(0, x, y));
}

DD get_f(DD x, DD y1, DD y2){
    x = fabs(x);
    if(y1 * y2 < 0) return get_g(x, y1) + get_g(x, y2);
    return fabs(get_g(x, y1) - get_g(x, y2));
}

int main(){
	// freopen("in.txt", "r", stdin);
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
    // cout << (DD)clock() / 1000 << "s" << endl;
    return 0;
}
