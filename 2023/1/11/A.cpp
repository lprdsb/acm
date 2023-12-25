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

int t, n, a[maxn + 5];
char s[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

void out(int a1, int a2){
    For(i, 1, a1 - 1) printf("%c", a[i] + 'a');
    printf(" ");
    For(i, a1, a2 - 1) printf("%c", a[i] + 'a');
    printf(" ");
    For(i, a2, n) printf("%c", a[i] + 'a');
    puts(""); 
}

int main(){
	//freopen("in.txt", "r", stdin);
    read(t);
    while(t--){
        scanf("%s", s + 1); n = strlen(s + 1);
        For(i, 1, n) a[i] = s[i] - 'a';
        int a1 = -1, a2 = -1;
        For(i, 1, n - 1) if(a[i] != a[i + 1]){
            if(a1 == -1) a1 = i;
            else if(a2 == -1) a2 = i;
            else break;
        }
        if(a1 == -1) out(2, 3);
        else if(a2 == -1){
            if(a1 == n - 1){
                if(a[n]) out(n - 1, n);
                else out(2, n);
            }
            else out(n - 1, n);
        }
        else out(a1 + 1, a2 + 1);
    }
    return 0;
}
