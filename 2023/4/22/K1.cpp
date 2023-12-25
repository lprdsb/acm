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

int t, n;
char s[10001];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int main(){
	freopen("in.txt", "r", stdin);
	read(t);
    while(t--){
        scanf("%s", s + 1); n = strlen(s + 1);
        int fl = 0;
        For(o, 1, n){
            For(i, 1, n - o + 1){
                For(j, 1, o / 2) swap(s[i + j - 1], s[i + o - j]);
                For(j, 1, n){
                    if(s[j] != s[n - j + 1]) break;
                    if(j == n) fl = 1;
                }
                For(j, 1, o / 2) swap(s[i + j - 1], s[i + o - j]);
                if(fl) break;
            }
            if(fl) break;
        }
        puts(fl ? "Yes" : "No");
    }
    return 0;
}
