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
#define maxn 500000
using namespace std;

int t, n, a[2 * maxn + 5][2];
char s[maxn + 5];

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
    read(t);
    while(t--){
        scanf("%s", s + 1); n = strlen(s + 1);
        For(i, -n, n) a[maxn + i][0] = a[maxn + i][1] = 0;
        int sum = 0;
        For(i, 1, n){
            a[maxn + sum][s[i] - '0']++;
            a[maxn + sum + (s[i] == '0' ? -1 : 1)][!(s[i] - '0')]++;
            sum += s[i] == '0' ? -1 : 1;
        }
        int now = 0;
        For(i, 1, n){
            if(a[maxn + now][1]){
                if(a[maxn + now - 1][1] >= 2){
                    printf("0");
                    a[maxn + now][0]--;
                    a[maxn + now - 1][1]--;
                    now--;
                }
                else{
                    printf("1");
                    a[maxn + now][1]--;
                    a[maxn + now + 1][0]--;
                    now++;
                }
            }
            else{
                printf("0");
                a[maxn + now][0]--;
                a[maxn + now - 1][1]--;
                now--;
            }
        }
        puts("");
    }
    return 0;
}
