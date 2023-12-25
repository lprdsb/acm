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

int t, n, m;
char s[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int to[maxn + 5];

int main(){
	//freopen("in", "r", stdin);
    read(t);
    while(t--){
        read(n); scanf("%s", s + 1); m = strlen(s + 1);
        int cnt = 0;
        For(i, 1, m) to[i] = 0;
        int now = 0;
        For(i, 2, m){
            while(now && s[now + 1] != s[i]) now = to[now];
            if(s[now + 1] == s[i]) to[i] = ++now;
            else to[i] = 0;
        }
        now = to[m];
        if(2 * now >= m){
            while(to[now]) now = to[now];
        }
        if(s[now + 1] == '1'){
            For(i, 1, n) printf("0"); 
            puts("");
        }
        else{
            For(i, 1, n) printf("1"); 
            puts("");
        }
    }
    return 0;
}
