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
#define maxn 300000
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
	//freopen("in", "r", stdin);
    read(t);
    while(t--){
        scanf("%s", s + 1); n = strlen(s + 1);
        int st = -1;
        For(i, 1, n) if(s[i] != '?'){
            st = i;
            break;
        }
        if(st == -1){
            For(i, 1, n) s[i] = '0';
        }
        else{
            char pre = s[st];
            int tem = st - 1;
            while(tem){
                if(s[tem] == '?') s[tem] = pre;
                else pre = s[tem];
                tem--;
            }
            tem = st + 1;
            pre = s[st];
            while(tem <= n){
                if(s[tem] == '?') s[tem] = pre;
                else pre = s[tem];
                tem++;
            }
        }
        printf("%s\n", s + 1);
    }
	return 0;
}
