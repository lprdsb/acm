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

int t, a[5], st[5], top = 0;

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
    a[0] = -1;
    while(t--){
        For(i, 1, 4){
            char c; cin >> c;
            a[i] = c - '0';
        }
        sort(a + 1, a + 5);
        int sum = 0;
        top = 0;
        For(i, 1, 4){
            if(a[i] != a[i - 1]) st[++top] = 0;
            st[top]++;
        } 
        if(top == 1) puts("-1");
        else if(top == 2){
            if(st[1] == 1 || st[1] == 3) puts("6");
            else puts("4");
        }
        else puts("4");
    }
    return 0;
}
