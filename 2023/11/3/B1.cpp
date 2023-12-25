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

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

LL get_dis(int x, int y){
    return (x - 114) * (x - 114) + (y - 114) * (y - 114);
}

LL f[2 * maxn + 5][2 * maxn + 5];
int px = 0, py = 0, tot = 0;
LL get_f(int x, int y){
    if(f[maxn + x][maxn + y]) return f[maxn + x][maxn + y];
    printf("%d %d\n", x - px, y - py);
    px = x; py = y;
    tot++;
    if(tot > 30) exit(0);
    fflush(stdout);
    LL res;
    // res = get_dis(x, y);
    read(res);
    if(!res){
        // cout << tot << endl;
        exit(0);
    }
    return f[maxn + x][maxn + y] = res;
}

int tot1 = 0;
void sol(int x1, int x2, int y1, int y2){
    // cout << "ASD" << x1 << " " << x2 << " " << y1 << " " << y2 << endl;
    // tot1++;
    // if(tot1 >= 1000000) exit(0);
    if(x1 != x2){
        int mid = floor(((DD)x1 + x2) / 2);
        if(get_f(x1, y1) <= get_f(x2, y1)) sol(x1, mid, y1, y2);
        else sol(mid + 1, x2, y1, y2);
    }
    else{
        int mid = floor(((DD)y1 + y2) / 2);
        if(get_f(x1, y1) <= get_f(x1, y2)) sol(x1, x1, y1, mid);
        else sol(x1, x1, mid + 1, y2);
    }
}

int main(){
	//freopen("in", "r", stdin);
    LL pre = get_dis(0, 0);
    read(pre);
    if(!pre){
        return 0;
    }
    f[maxn][maxn] = pre;
    sol(-maxn, maxn, -maxn, maxn);
    return 0;
}
