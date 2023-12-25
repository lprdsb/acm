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
#define Inf 0x3f3f3f3f3f3f3f3f
#define eps 1e-12
#define maxn 1000
using namespace std;

int n;
LL r1, r2, R, r[maxn + 5], a[maxn + 5], inf = 1000000000000000;
LL as = -Inf;
DD Pi = acos(-1.0);

struct Vec{
    LL x, y;
    DD len(){return sqrt((DD)x * x + (DD)y * y);}
} poi[maxn + 5];
Vec operator - (Vec _x, Vec _y){return {_x.x - _y.x, _x.y - _y.y};}

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

map<DD, LL> ma;

int main(){
	// freopen("in.txt", "r", stdin);
    read(n); read(r1); read(r2); read(R); read(poi[0].x); read(poi[0].y);
    r[0] = r1 + r2;
    a[0] = inf;
    For(i, 1, n) read(a[i]), r[i] = R;
    For(i, 1, n) read(poi[i].x), read(poi[i].y);
    For(i, 0, n){
        LL now = a[i];
        ma.clear();
        For(j, 0, n) if(i != j){
            DD len = (poi[i] - poi[j]).len();
            if(len > r[i] + r[j]) continue;
            if(len <= abs(r[i] - r[j])){
                if(r[j] >= r[i]) now += a[j];
                continue;
            }
            DD theta = atan2(poi[j].y - poi[i].y, poi[j].x - poi[i].x), alpha = acos((DD)(r[i] * r[i] + len * len - r[j] * r[j]) / (2 * r[i] * len));
            DD l = theta - alpha, r = theta + alpha;
            if(l < 0) l += 2 * Pi;
            if(r < 0) r += 2 * Pi;
            ma[l] += a[j];
            ma[r] -= a[j];
            if(l > r) now += a[j];
        }
        as = max(as, now);
        for(auto i : ma) now += i.sec, as = max(as, now);
        // val.resize(0);
        // for(auto j : vec) val.pb({j.l, j.val}), val.pb({j.r + eps, -j.val});
        // sort(val.begin(), val.end());
        // if(val.size() == 0) as = max(as, now);
        // else{
        //     DD T = atan2(poi[i].y, poi[i].x), A;
        //     if(poi[i].len() + R < r1) A = -100;
        //     else A = acos((R * R + poi[i].len() * poi[i].len() - r1 * r1) / (R * poi[i].len()));
        //     For(j, 0, val.size() - 1){
        //         if((j > 0 && fabs(val[j].fir - val[j - 1].fir) > eps) && fabs(val[j].fir - eps - T) - A > eps) as = max(as, now);
        //         now += val[j].sec;
        //         if((j == val.size() - 1 || fabs(val[j].fir - val[j + 1].fir) > eps) && fabs(val[j].fir - T) - A > eps) as = max(as, now);
        //     }
        // }
    }
    printf("%lld\n", as - inf);
    return 0;
}
