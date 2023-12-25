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
} vec[5], veci[5];
Vec operator - (Vec _x, Vec _y){
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

bool chk(Vec p1, Vec p2, Vec p3){
    if(fabs((p2 - p1) * (p3 - p1)) > 1e5) return 0;
    if(p3.x < p1.x && p3.x < p2.x) return 0;
    if(p3.x > p1.x && p3.x > p2.x) return 0;
    return 1;
}

int main(){
	freopen("out.txt", "r", stdin);
    read(t);
    while(t--){
        For(i, 0, 3) scanf("%lf %lf", &vec[i].x, &vec[i].y);
        DD as = 0;
        vec[4] = vec[0];
        For(i, 0, 3) as += vec[i + 1] * vec[i];
        as = fabs(as);
        int x; read(x);
        if(x == -1) continue;

        For(i, 0, 3) scanf("%lf %lf", &veci[i].x, &veci[i].y);
        DD as1 = 0;
        veci[4] = veci[0];
        For(i, 0, 3) as1 += veci[i + 1] * veci[i];
        as1 = fabs(as1);
        
        DD tem = (veci[1] - veci[0]).len();
        // printf("%.10lf ", tem);
        For(i, 1, 3) if(fabs((veci[i + 1] - veci[i]).len() - tem) > 1e-5){
            printf("%.15lf ", fabs((veci[i + 1] - veci[i]).len() - tem));
            // cout << i << endl;
            puts("No");
            return 0;
        }

        For(i, 0, 3){
            For(j, 0, 3){
                if(chk(veci[i], veci[i + 1], vec[j])) break;
                if(j == 3){
                    For(i, 0, 3) printf("%.10lf %.10lf ", vec[i].x, vec[i].y);
                    puts("");
                    puts("No");
                    return 0;
                }
            }
        }

        if(fabs(as1 - 2 * as) < 1e-5) puts("Yes");
        else break;
        // printf("%.10lf %.10lf\n", 2 * as, as1);
    }
    return 0;
}
