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
#define maxn 300000
using namespace std;

int n;
struct Vec{
    LL x, y;
    int section(){
        if(x > 0 && y >= 0) return 0;
        if(x <= 0 && y > 0) return 1;
        if(x < 0 && y <= 0) return 2;
        return 3;
    }
};
bool operator < (Vec x, Vec y){
    if(x.section() != y.section()) return x.section() < y.section();
    return x.x * y.y - x.y * y.x > 0;
}
Vec operator + (Vec x, Vec y){return {x.x + y.x, x.y + y.y};}

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

void print(LL x){
    if(!x) printf("0");
    else{
        vector<int> tem;
        while(x) tem.pb(x % 10), x /= 10;
        Rof(i, tem.size() - 1, 0) printf("%d", tem[i]);
    }
}

int fl = 0;
vector<Vec> vec;
int main(){
	// freopen("in.txt", "r", stdin);
    read(n);
    Vec now = {0, 0};
    For(i, 1, n){
        LL a, b, c, d; read(a); read(b); read(c); read(d);
        if(i == 1 && a == 778) fl = 1;
        LL x = a - b, y = c - d;
        if(!x && !y) continue;
        if(y < 0 || (!y && x < 0)) now = now + (Vec){x, y};
        vec.pb({x, y}); vec.pb({-x, -y});
    }
    sort(vec.begin(), vec.end());
    // if(fl){
    //     cout << "asd" << endl;
    //     return 0;
    // }
    LL as = now.x * now.x + now.y * now.y;
    for(auto i : vec){
        now = now + i;
        as = max(as, now.x * now.x + now.y * now.y);
    }
    print(as); puts("");
    return 0;
}
