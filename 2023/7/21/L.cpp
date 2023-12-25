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
    LD x, y;
    void print(){printf("%.10Lf %.10Lf ", x, y);}
} poi[5];
struct Vec{
    LD x, y;
    LD len(){return sqrt(x * x + y * y);}
};
Vec operator - (Poi _x, Poi _y){
    return {_x.x - _y.x, _x.y - _y.y};
} 
LD operator * (Vec _x, Vec _y){
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
    LD t1 = (tem.x * l2.y - tem.y * l2.x) / (l2.x * l1.y - l1.x * l2.y);
    return {x1.x + t1 * l1.x, x1.y + t1 * l1.y};
}

int sol(int fl){
    Vec ac = poi[2] - poi[0], bd = poi[3] - poi[1];
    LD si = fabs(ac * bd) / ac.len() / ac.len();
    Vec v;
    
    if(fabs(ac.x) < eps) v = {si, sqrt(1 - si * si)};
    else if(fabs(1 - si) < eps) v = {ac.y, -ac.x};
    else{
        LD t1 = ac.y / ac.x, t2 = si / (sqrt(1 - si * si));
        if(fabs(1 - t1 * t2) < eps) v = {0, 1};
        else v = {1, (t1 + t2) / (1 - t1 * t2)};
    }
    if(((poi[0] - poi[3]) * v) * ((poi[1] - poi[0]) * v) < eps 
    && ((poi[2] - poi[1]) * v) * ((poi[3] - poi[2]) * v) < eps){
        puts("Link doesn't cut tree!");
        if(!fl){
            get_ac(poi[0], v, poi[3], ac).print();
            get_ac(poi[0], v, poi[1], ac).print();
            get_ac(poi[2], v, poi[1], ac).print();
            get_ac(poi[2], v, poi[3], ac).print();
        }
        else{
            get_ac(poi[2], v, poi[3], ac).print();
            get_ac(poi[0], v, poi[3], ac).print();
            get_ac(poi[0], v, poi[1], ac).print();
            get_ac(poi[2], v, poi[1], ac).print();
        }
        puts("");
        return 1;
    }
    
    if(fabs(ac.x) < eps) v = {-si, sqrt(1 - si * si)};
    else if(fabs(1 - si) < eps) v = {ac.y, -ac.x};
    else{
        LD t1 = ac.y / ac.x, t2 = si / (sqrt(1 - si * si));
        if(fabs(1 + t1 * t2) < eps) v = {0, 1};
        else v = {1, (t1 - t2) / (1 + t1 * t2)};
    }
    if(((poi[0] - poi[3]) * v) * ((poi[1] - poi[0]) * v) < eps 
    && ((poi[2] - poi[1]) * v) * ((poi[3] - poi[2]) * v) < eps){
        puts("Link doesn't cut tree!");
        if(!fl){
            get_ac(poi[0], v, poi[3], ac).print();
            get_ac(poi[0], v, poi[1], ac).print();
            get_ac(poi[2], v, poi[1], ac).print();
            get_ac(poi[2], v, poi[3], ac).print();
        }
        else{
            get_ac(poi[2], v, poi[3], ac).print();
            get_ac(poi[0], v, poi[3], ac).print();
            get_ac(poi[0], v, poi[1], ac).print();
            get_ac(poi[2], v, poi[1], ac).print();
        }
        puts("");
        return 1;
    }
    return 0;
}

int main(){
	freopen("in.txt", "r", stdin);
    read(t);
    while(t--){
        For(i, 0, 3){
            int x, y; read(x); read(y);
            poi[i] = {(LD)x, (LD)y};
        }
        if(sol(0)) continue;
        Poi tem = poi[0];
        For(i, 0, 2) poi[i] = poi[i + 1];
        poi[3] = tem;
        if(sol(1)) continue;
        puts("Link cut tree!");
    }
    return 0;
}
