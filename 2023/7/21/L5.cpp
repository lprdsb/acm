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

int t = 10000;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int main(){
	freopen("in.txt", "w", stdout);
    cout << t << endl;
    while(t--){
        int y1 = rand() % 997 + 20, x2 = -rand() % 997-26, y2 = y1 + rand() % 997 + 20, x3 = x2 - rand() % 997 - 20, y3 = y2 - rand() % 997 - 12;
        printf("0 0 0 %d %d %d %d %d\n", y1, x2, y2, x3, y3);
    }
}
