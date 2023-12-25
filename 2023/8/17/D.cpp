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

int n, a[105], b[105];
char s[105];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int main(){
	//freopen("in", "r", stdin);
    scanf("%s", s + 1);
    n = strlen(s + 1);
    For(i, 1, n) a[i] = s[i] - '0';
    int cnt = 0, res = 0, cc;
    For(i, 1, n){
        if(a[i]){
            cc++;
            b[i] = cnt;
            res += cnt;
        }
        else cnt++;
    }
    int tem = cnt * (n - cnt) / 2 - res;
    cout << res << endl;
    if(tem > 0){
        int now = 0;
        For(i, 1, n) if(a[i]){
            cc--;
            tem -= cnt - b[i] + cc;
            now++;
            if(tem <= 0){
                printf("%d\n", now);
                return 0;
            } 
        }
    }
    else if(tem < 0){
        int now = 0;
        Rof(i, n, 1) if(a[i]){
            cc--;
            tem += b[i] + cc;
            now++;
            if(tem >= 0){
                printf("%d\n", now);
                return 0;
            }
        }
    }
    else puts("0");
}
