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

int n, a[2][2 * maxn + 5], b[2][2 * maxn + 5];
char s[maxn + 5], t[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int to[2][2 * maxn + 5], ok[2][2 * maxn + 5];

int main(){
	//freopen("in", "r", stdin);
    read(n);
    scanf("%s", s + 1); scanf("%s", t + 1);
    For(i, 1, n){
        if(s[i] >= 'a' && s[i] <= 'z'){
            a[0][i] = s[i] - 'a';
            a[1][i] = 1;
        }
        else{
            a[0][i] = s[i] - 'A';
            a[1][i] = 0;
        }
        if(t[i] >= 'a' && t[i] <= 'z'){
            b[0][i] = t[i] - 'a';
            b[1][i] = 0;
        }
        else{
            b[0][i] = t[i] - 'A';
            b[1][i] = 1;
        }
    }
    For(o, 0, 1) For(i, 1, n) a[o][n + i] = a[o][i];
    For(o, 0, 1){
        For(i, 2, n){
            to[o][i] = to[o][i - 1];
            while(to[o][i] && b[o][i] != b[o][to[o][i] + 1]) to[o][i] = to[o][to[o][i]];
            if(b[o][i] == b[o][to[o][i] + 1]) to[o][i]++;
        }
    }
    b[0][n + 1] = b[1][n + 1] = 114514;
    For(o, 0, 1){
        int now = 0;
        For(i, 1, 2 * n){
            while(now && a[o][i] != b[o][now + 1]) now = to[o][now];
            if(a[o][i] == b[o][now + 1]) now++;
            if(now == n) ok[o][i - n + 1] = 1;
        }
    }
    int mn = inf;
    For(i, 1, n) if(ok[0][i] && ok[1][i]){
        mn = min(mn, min(i - 1, n + 1 - i));
        break;
    }
    if(mn == inf) puts("No");
    else printf("Yes\n%d\n", mn);
    return 0;
}
