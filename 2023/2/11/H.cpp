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

int n, q;
LL a[maxn + 5][maxn + 5];
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

bool chk(LL x, LL y){
    if(x > y) swap(x, y);
    if(x == y) return 0;
    if(!x || 2 * x >= y) return 1;
    return 0;
}

void sol(int opt){
    if(opt <= 1){
        For(i, 1, n){
            int now = dir[opt][1] == 1 ? n : 1, pre = now;
            while(now >= 1 && now <= n){
                if(a[i][now] == -1) pre = now - dir[opt][1];
                else{
                    if(a[i][now]){
                        if(pre == now) ;
                        else if(!a[i][pre]){
                            a[i][pre] = a[i][now];
                            a[i][now] = 0;
                        }
                        else if(chk(a[i][now], a[i][pre])){
                            a[i][pre] += a[i][now];
                            a[i][now] = 0;
                            pre -= dir[opt][1];
                        }
                        else{
                            pre -= dir[opt][1];
                            if(pre == now) ;
                            else{
                                a[i][pre] = a[i][now];
                                a[i][now] = 0;
                            }
                        }
                    }
                }
                now -= dir[opt][1];
            }
        }
    }
    else{
        For(i, 1, n){
            int now = dir[opt][0] == 1 ? n : 1, pre = now;
            while(now >= 1 && now <= n){
                if(a[now][i] == -1) pre = now - dir[opt][0];
                else{
                    if(a[now][i]){
                        if(pre == now) ;
                        else if(!a[pre][i]){
                            a[pre][i] = a[now][i];
                            a[now][i] = 0;
                        }
                        else if(chk(a[now][i], a[pre][i])){
                            a[pre][i] += a[now][i];
                            a[now][i] = 0;
                            pre -= dir[opt][0];
                        }
                        else{
                            pre -= dir[opt][0];
                            if(pre == now) ;
                            else{
                                a[pre][i] = a[now][i];
                                a[now][i] = 0;
                            }
                        }
                    }
                }
                now -= dir[opt][0];
            }
        }
    }
}

int main(){
	// freopen("in.txt", "r", stdin);
    read(n); read(q);
    For(i, 1, n) For(j, 1, n) read(a[i][j]);
    while(q--){
        char c; cin >> c;
        if(c == 'R') sol(0);
        if(c == 'L') sol(1);
        if(c == 'D') sol(2);
        if(c == 'U') sol(3);
    }
    For(i, 1, n){
        For(j, 1, n) printf("%lld ", a[i][j]);
        puts("");
    }
    return 0;
}
