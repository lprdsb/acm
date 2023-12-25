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
#define maxn 200000
using namespace std;

int t, q, a[maxn + 5];

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
        read(q);
        int now = 0, nowl = 0;
        while(q--){
            int x; read(x);
            if(nowl == now){
                if(!nowl || x >= a[now]){
                    nowl++;
                    a[++now] = x;
                    printf("1");
                }
                else if(a[1] >= x){
                    a[++now] = x;
                    printf("1");
                }
                else printf("0");
            }
            else if(a[now] <= x && a[1] >= x){
                a[++now] = x;
                printf("1");
            }
            else printf("0");
        }
        puts("");
    }
    return 0;
}
