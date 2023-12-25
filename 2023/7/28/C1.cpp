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
LL r1, r2, R, a[maxn + 5], inf = 100000000000000;
LL as = -Inf;
DD Pi = acos(-1.0);

struct Vec{
    LL x, y;
    DD len(){return sqrt(x * x + y * y);}
} poi[maxn + 5], p0;
Vec operator - (Vec _x, Vec _y){return {_x.x - _y.x, _x.y - _y.y};}

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

struct Data{
    DD l, r;
    LL val;
};
vector<Data> vec;
vector<pair<DD, LL> > val;

int main(){
	// freopen("in.txt", "r", stdin);
    read(n); read(r1); read(r2); read(R); read(p0.x); read(p0.y); r1 += r2;
    For(i, 1, n) read(a[i]);
    For(i, 1, n) read(poi[i].x), read(poi[i].y), poi[i] = poi[i] - p0;
    For(i, 1, n){
        if(poi[i].len() - r1 - R > eps) continue;
        LL now = a[i];
        vec.resize(0);
        For(j, 1, n) if(i != j){
            DD len = (poi[i] - poi[j]).len();
            if(len - 2 * R > eps) continue;
            DD theta = atan2(poi[j].y - poi[i].y, poi[j].x - poi[i].x), alpha = acos(len / 2 / R);
            DD l = theta - alpha, r = theta + alpha;
            // if(i == 1) cout << l / Pi + 2 << " " << r / Pi + 2 << endl;
            if(l + Pi < 0){
                vec.pb({-Pi, r, a[j]});
                vec.pb({l + 2 * Pi, Pi, a[j]});
            }
            else if(r - Pi > -eps){
                vec.pb({l, Pi, a[j]});
                vec.pb({-Pi, r - 2 * Pi, a[j]});
            }
            else vec.pb({l, r, a[j]});
        }
        val.resize(0);
        for(auto j : vec) val.pb({j.l, j.val}), val.pb({j.r + eps, -j.val});
        sort(val.begin(), val.end());
        if(val.size() == 0) as = max(as, now);
        else{
            DD T = atan2(poi[i].y, poi[i].x), A;
            if(poi[i].len() + R < r1) A = -100;
            else A = acos((R * R + poi[i].len() * poi[i].len() - r1 * r1) / (R * poi[i].len()));
            For(j, 0, val.size() - 1){
                if((j > 0 && fabs(val[j].fir - val[j - 1].fir) > eps) && fabs(val[j].fir - eps - T) - A > eps) as = max(as, now);
                now += val[j].sec;
                if((j == val.size() - 1 || fabs(val[j].fir - val[j + 1].fir) > eps) && fabs(val[j].fir - T) - A > eps) as = max(as, now);
            }
        }
    }
    printf("%lld\n", as);
    return 0;
}
