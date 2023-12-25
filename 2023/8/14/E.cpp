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

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

struct Node{
    int x, y, l;
};
vector<Node> as;

void sol(int x, int y, int l1, int l2){
    if(!l1 || !l2) return;
    if(l1 == l2){
        as.pb({x, y, l1});
        return;
    }
    if(l1 <= l2){
        for(int i = 0; i + l1 <= l2; i += l1){
            as.pb({x, y + i, l1});
        }
        sol(x, y + l2 - l2 % l1, l1, l2 % l1);
    }
    else{
        for(int i = 0; i + l2 <= l1; i += l2){
            as.pb({x + i, y, l2});
        }
        sol(x + l1 - l1 % l2, y, l1 % l2, l2);
    }
}

int main(){
	//freopen("in", "r", stdin);
    read(t);
    while(t--){
        read(n); read(m);
        as.resize(0);
        sol(0, 0, n, m);
        printf("YES\n%d\n", as.size());
        for(auto i : as) printf("%d %d %d\n", i.x, i.y, i.l);
    }
    return 0;
}
