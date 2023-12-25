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

struct Poi{
    DD x, y;
    void print(){printf("%.10lf %.10lf ", x, y);}
} poi[5];
struct Vec{
    DD x, y;
    DD len(){return sqrt(x * x + y * y);}
};
Vec operator - (Poi _x, Poi _y){
    return {_x.x - _y.x, _x.y - _y.y};
} 
DD operator * (Vec _x, Vec _y){
    return _x.x * _y.y - _x.y * _y.x;
}

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

Poi get_ac(Poi x1, Vec l1, Poi x2, Vec l2){
    Vec tem = x1 - x2;
    DD t1 = (tem.x * l2.y - tem.y * l2.x) / (l2.x * l1.y - l1.x * l2.y);
    return {x1.x + t1 * l1.x, x1.y + t1 * l1.y};
}

int sol(){
    poi[4] = poi[0];
    Vec ac = poi[2] - poi[0], bd = poi[3] - poi[1];
    DD si = fabs(ac * bd) / ac.len() / ac.len();
    Vec v;

    if(fabs(ac.x) < eps) v = {si, sqrt(1 - si * si)};
    else if(fabs(1 - si) < eps) v = {ac.y, -ac.x};
    else{
        DD t1 = ac.y / ac.x, t2 = si / (sqrt(1 - si * si));
        if(fabs(1 - t1 * t2) < eps) v = {0, 1};
        else v = {1, (t1 + t2) / (1 - t1 * t2)};
    }
    if(((poi[0] - poi[3]) * v) * ((poi[1] - poi[0]) * v) < eps 
    && ((poi[2] - poi[1]) * v) * ((poi[3] - poi[2]) * v) < eps){
        puts("1");
        get_ac(poi[0], v, poi[1], ac).print();
        get_ac(poi[2], v, poi[1], ac).print();
        get_ac(poi[2], v, poi[3], ac).print();
        get_ac(poi[0], v, poi[3], ac).print();
        puts("");
        return 1;
    }
    
    if(fabs(ac.x) < eps) v = {-si, sqrt(1 - si * si)};
    else if(fabs(1 - si) < eps) v = {ac.y, -ac.x};
    else{
        DD t1 = ac.y / ac.x, t2 = si / (sqrt(1 - si * si));
        if(fabs(1 + t1 * t2) < eps) v = {0, 1};
        else v = {1, (t1 - t2) / (1 + t1 * t2)};
    }
    if(((poi[0] - poi[3]) * v) * ((poi[1] - poi[0]) * v) < eps 
    && ((poi[2] - poi[1]) * v) * ((poi[3] - poi[2]) * v) < eps){
        puts("1");
        get_ac(poi[0], v, poi[1], ac).print();
        get_ac(poi[2], v, poi[1], ac).print();
        get_ac(poi[2], v, poi[3], ac).print();
        get_ac(poi[0], v, poi[3], ac).print();
        puts("");
        return 1;
    }
    return 0;
}

int main(){
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
    read(t);
    cout << t << endl;
    while(t--){
        For(i, 0, 3){
            DD x, y;
            scanf("%lf %lf", &x, &y);
            poi[i] = {x, y};
            printf("%.10lf %.10lf ", x, y);
        }
        cout << endl;
        if(sol()) continue;
        Poi tem = poi[0];
        For(i, 0, 2) poi[i] = poi[i + 1];
        poi[3] = tem;
        if(sol()) continue;
        puts("-1");
    }
    return 0;
}
