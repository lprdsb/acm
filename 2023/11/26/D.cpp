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
#define maxn 2000000
using namespace std;

int n = 0, x;
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
    scanf("%s", s + 1); n = strlen(s + 1);
    read(x);
    if(!x){
        For(i, 1, n) printf("%d", s[i] - '0');
        return 0;
    }
    int sum = 0;
    For(i, 1, n) sum += s[i] - '0';
    Rof(i, n, 1){
        sum -= s[i] - '0';
        if(s[i] - '0'){
            if(n - i >= x - 1){
                int fl = 0;
                if(sum){
                    For(j, 1, i - 1) printf("%d", s[j] - '0');
                    printf("0");
                    fl = 1;
                }
                int tem = n - i - x + 1;
                int now = i + 1;
                while(now <= n && tem){
                    printf("1");
                    fl = 1;
                    tem -= s[now] - '0';
                    now++;
                }
                while(now <= n){
                    if(s[now] == '0') printf("1"), fl = 1;
                    else if(fl) printf("0");
                    now++;
                }
                return 0;
            }
        }
    }
    puts("-1");
}
