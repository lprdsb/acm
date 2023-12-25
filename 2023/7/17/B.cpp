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
#define maxn 1000000
using namespace std;

int n;
class Poi{
    public:
        LL x, y;
} poi[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

LL get_s(int x, int y, int z){
    return abs((poi[y].x - poi[x].x) * (poi[z].y - poi[x].y) - (poi[y].y - poi[x].y) * (poi[z].x - poi[x].x));
}

int pre(int x){
    return x == 1 ? n : x - 1;
}
int suf(int x){
    return x == n ? 1 : x + 1;
}

int main(){
	// freopen("in.txt", "r", stdin);
    read(n);
    For(i, 1, n) read(poi[i].x), read(poi[i].y);
    int a = 1, b = 2, c = 3;
    while(666){
        int fl = 0;
        while(get_s(pre(a), b, c) > get_s(a, b, c)) a = pre(a), fl = 1;
        while(get_s(suf(a), b, c) > get_s(a, b, c)) a = suf(a), fl = 1;
        while(get_s(a, pre(b), c) > get_s(a, b, c)) b = pre(b), fl = 1;
        while(get_s(a, suf(b), c) > get_s(a, b, c)) b = suf(b), fl = 1;
        while(get_s(a, b, pre(c)) > get_s(a, b, c)) c = pre(c), fl = 1;
        while(get_s(a, b, suf(c)) > get_s(a, b, c)) c = suf(c), fl = 1;
        if(!fl) break;
    }
    printf("%d %d %d\n", a, b, c);
}
