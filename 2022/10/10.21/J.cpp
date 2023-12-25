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

int n, mul = 1;
string s, s1[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int tot = 0;
int main(){
	//freopen("in", "r", stdin);
	cin >> s;
	n = s.length();
	int now = 0;
	s[0] = ',';
	if(n > 2){
		For(i, 0, n - 2){
			if(!tot) i++, now++;
			s1[now] += s[i];
			if(s[i] == '{') tot++;
			if(s[i] == '}') tot--;
		}
	}
	
	//For(i, 1, now) cout << s1[i] << endl;
	For(i, 1, now) mul = mul * 2; mul--;
	printf("{"); 
	For(i, 0, mul){
		printf("{"); 
		For(j, 0, now - 1){
			if((i >> j) & 1){
				cout << s1[j + 1];
				if(i >> (j + 1)) printf(",");
			}
		}
		printf("}");
		if(i != mul) printf(",");
	}
	printf("}");
	return 0;
}


