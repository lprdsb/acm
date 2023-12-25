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

int t, x, y;
LL to[20], pw[20];

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
    pw[0] = 1;
    For(i, 1, 18) pw[i] = pw[i - 1] * 10;
    For(i, 1, 18) to[i] = sqrt(pw[i] - 1);
    read(t);
    while(t--){
        read(y);
        if(!y){
            puts("0");
            continue;
        }
        int tem = 0, yy = y, fl = 0;
        while(yy) tem++, yy /= 10;
        For(i, tem, 18){
            LL l = to[i - 1] + 1, r = to[i];
            while(l < r){
                LL mid = l + r >> 1;
                if(mid * mid / pw[i - tem] >= y) r = mid;
                else l = mid + 1;
            }
            if(l * l / pw[i - tem] == y){
                fl = 1;
                printf("%d\n", l);
                break;
            }
        }
        if(!fl) puts("-1");
    }
    return 0;
}
