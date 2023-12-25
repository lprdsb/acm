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

int t, n, m;
struct Node{
    DD a, b, c, d, e, f;
    int id;
} a[5000];
bool operator < (Node _x, Node _y){
    if(_x.f != _y.f) return _x.f < _y.f;
    return _x.id < _y.id;
}

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int main(){
	// freopen("in.txt", "r", stdin);
    read(t);
    while(t--){
        read(n); read(m);
        For(i, 1, n){
            scanf("%lf%lf%lf%lf%lf%lf", &a[i].a, &a[i].b, &a[i].c, &a[i].d, &a[i].e, &a[i].f);
            a[i].id = i;
        }
        sort(a + 1, a + n + 1);
        For(i, 1, m){
            DD aa, b, c, d, e;
            scanf("%lf%lf%lf%lf%lf", &aa, &b, &c, &d, &e);
            For(j, 1, n) if(a[j].a >= aa && a[j].b >= b && a[j].c >= c && a[j].d >= d && a[j].e >= e){
                printf("%d\n", a[j].id);
                break;
            }
        }
    }  
}
