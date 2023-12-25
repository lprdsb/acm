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
#define maxn 2000
using namespace std;

int n;
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
    scanf("%s", s + 1);
    n = strlen(s + 1);
    int cnt = 0;
    For(i, 1, n) cnt += s[i] - '0';
    if(n & 1){
        if(cnt <= n / 2){
            For(i, 1, n) cout << 1; cout << endl;
        }
        else{
            For(i, 1, n) cout << 0; cout << endl;
        }
    }
    else{
        if(cnt < n / 2){
            For(i, 1, n) cout << 1; cout << endl;
        }
        else if(cnt == n / 2){
            cout << !(s[1] - '0');
            For(i, 2, n) cout << (s[1] - '0');
        }
        else{
            For(i, 1, n) cout << 0; cout << endl;
        }
    }
    return 0;
}
