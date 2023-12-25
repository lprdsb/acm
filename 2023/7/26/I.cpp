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
#define maxn 100
using namespace std;

int t, n, a[maxn + 5][maxn + 5], b[maxn + 5][maxn + 5];
struct Vec{
    LL x, y;
    Vec(){x = 0, y = 0;}
    Vec(LL _x, LL _y){x = _x, y = _y;}
};
LL operator ^ (Vec x, Vec y){return x.x * y.y - x.y * y.x;}
Vec operator + (Vec x, Vec y){return {x.x + y.x, x.y + y.y};}
Vec operator - (Vec x, Vec y){return {x.x - y.x, x.y - y.y};}
bool operator < (Vec x, Vec y){
    if(x.x == y.x) return x.y <= y.y;
    else return x.x <= y.x;
}
struct Data{
    vector<Vec> poi;
    Data(){poi.resize(0);}
} f[maxn + 5][maxn + 5], zer;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

bool chk(Vec p1, Vec p2, Vec p3){
    return ((p3 - p2) ^ (p2 - p1)) <= 0;
}

Data mer(Data x, Data y){
    int l = 0, r = 0;
    Data asi;
    while(l < x.poi.size() || r < y.poi.size()){
        Vec tem;
        if(l == x.poi.size()) tem = y.poi[r++];
        else if(r == y.poi.size()) tem = x.poi[l++];
        else if(x.poi[l] < y.poi[r]) tem = x.poi[l++];
        else tem = y.poi[r++];
        while(asi.poi.size() >= 1 && tem.y >= asi.poi[asi.poi.size() - 1].y) asi.poi.pop_back();
        asi.poi.pb(tem);
    }
    return asi;
}

int main(){
	// freopen("in.txt", "r", stdin);
    zer.poi.pb({0, 0});
    read(t);
    while(t--){
        read(n);
        For(i, 1, n) For(j, 1, n) read(a[i][j]);
        For(i, 1, n) For(j, 1, n) read(b[i][j]);
        For(i, 0, n) f[0][i] = f[i][0] = zer;
        For(i, 1, n) For(j, 1, n){
            f[i][j] = mer(f[i][j - 1], f[i - 1][j]);
            for(auto &p : f[i][j].poi) p = p + (Vec){a[i][j], b[i][j]};
        }
        // f[1][1] = mer(f[1][0], f[0][1]);
        // for(auto i : f[n][n].poi) cout << i.x + f[n][n].lpr.x << " " << i.y + f[n][n].lpr.y << endl;
        // cout << f[n][n].poi.size() << endl;
        LL as = 0;
        for(auto i : f[n][n].poi) as = max(as, i.x * i.y);
        printf("%lld\n", as);
    }
    return 0;
}
