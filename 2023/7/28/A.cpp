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

int ch[maxn + 5][2], fail[maxn + 5], ok[maxn + 5];
int main(){
	//freopen("in", "r", stdin);
    memset(ch, 0, sizeof ch);
    memset(fail, 0, sizeof fail);
    For(i, 0, maxn) ok[i] = 1;
    read(t);
    while(t--){
        read(n); scanf("%s", s + 1); m = strlen(s + 1);
        For(i, 1, m) ch[i - 1][s[i] - '0'] = i;
        For(i, 1, m){
            if(i != m) fail[i + 1] = ch[fail[i]][s[i + 1] - '0'];
            // else fail[i + 1] = ch[fail[i]][s[i + 1] - '0'];
            ch[i][!(s[i + 1] - '0')] = ch[fail[i]][!(s[i + 1] - '0')];
            if(i == m) ch[i][s[i + 1] - '0'] = ch[fail[i]][s[i + 1] - '0'];
        }
        For(o, 0, m){
            int now = o;
            For(i, 1, m){
                now = ch[now][s[i] - '0'];
                if(now == m){
                    ok[o] = 0;
                    break;
                }
            }
        }
        For(i, 0, m){
            ch[i][0] = ch[i][1] = fail[i] = 0;
            ok[i] = 1;
        }
    }
}
