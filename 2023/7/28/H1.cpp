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
#define maxn 1000
using namespace std;

int n, f[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

bool chk(int x, int y){
    int cnt = 0;
    while(y){
        int z = x % y;
        cnt += x / y;
        x = y;
        y = z;
    }
    return cnt <= 24;
}

struct Data{
    int x, y, c;
};
vector<Data> as;
void dfs(int x, int y, int a, int b){
    // cout << x << " " << y << " " << a << " " << b << endl;
    if(a == b){
        if(a <= 1) return;
        if(a <= 7){
            as.pb({x, y, a});
            return;
        }
        int i = f[a];
            dfs(x, y, i, i);
            dfs(x + i, y + i, a - i, a - i);
            dfs(x + i, y, a - i, i);
            dfs(x, y + i, i, a - i);
            as.pb({x, y, a});
    }
    else if(a > b){
        if(b <= 1) return;
        for(int i = 1; i + b - 1 <= a; i += b) dfs(x + i - 1, y, b, b);
        dfs(x + a - a % b, y, a % b, b);
    }
    else{
        if(a <= 1) return;
        for(int i = 1; i + a - 1 <= b; i += a) dfs(x, y + i - 1, a, a);
        dfs(x, y + b - b % a, a, b % a);
    }
}

int main(){
	//freopen("in", "r", stdin);
    read(n);
    For(i, 2, n) For(j, 1, i / 2){
        if(chk(j, i - j)){
            f[i] = j;
            break;
        }
    }
    dfs(1, 1, n, n);
    printf("%d\n", as.size());
    for(auto i : as) printf("%d %d %d\n", i.x, i.y, i.c);
    return 0;
}
