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

int t, n;
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
	// freopen("in.txt", "r", stdin);
    read(t);
    while(t--){
        read(n);
        scanf("%s", s + 1);
        int cnt = 0, fl1 = 1, fl2 = 1;
        For(i, 1, n){
            cnt += s[i] == '(' ? 1 : -1;
            if(cnt < 0) fl1 = 0;
            if(cnt > 0) fl2 = 0;
        }
        if(cnt){
            puts("-1");
            continue;
        }
        if(fl1 || fl2){
            printf("1\n");
            For(i, 1, n) printf("1 ");
            puts("");
        }
        else{
            printf("2\n");
            int c1 = 0, c2 = 0;
            For(i, 1, n){
                int now = s[i] == '(' ? 1 : -1;
                if(now == 1){
                    if(c2 > 0){
                        c2--;
                        printf("2 ");
                    }
                    else{
                        c1++;
                        printf("1 ");
                    }
                }
                else{
                    if(c1 > 0){
                        c1--;
                        printf("1 ");
                    }
                    else{
                        c2++;
                        printf("2 ");
                    }
                }
            }
            puts("");
        }
    }
	return 0;
}
