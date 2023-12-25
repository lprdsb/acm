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

int num[5000], mx;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int main(){
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout); 
	char c;
	while(scanf("%c", &c) != EOF){
		if(c >= 'A' && c <= 'Z') num[c - 'A']++;
		else if(c >= 'a' && c <= 'z')num[c - 'a']++;
		//cout << c << endl;
	}
	For(i, 0, 25) mx = max(mx, num[i]);
	Rof(i, mx, 1){
		For(j, 0, 25){
			if(num[j] >= i) printf("*");
			else printf(" ");
			if(j != 25) printf(" ");
			else puts("");
		}
	}
	puts("A B C D E F G H I J K L M N O P Q R S T U V W X Y Z");
	return 0;
}


