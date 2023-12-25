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
#define maxn 20000
using namespace std;

int t, n;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x; 
}

pair<int, int> st[maxn + 5];
int top = 0;

bool chk(){
	For(i, 2, top) if(st[i].fir == st[i - 1].fir) return 0;
	return 1;
}

int que(int x, int y){
	printf("? %d %d\n", x, y);
	fflush(stdout);
	int as; 
	scanf("%d", &as);
	return as;
} 

int main(){
	//freopen("in", "r", stdin);
	srand(time(0));
	read(t);
	while(t--){
		read(n);
		top = n;
		For(i, 1, n) st[i] = mp(rand() % 11451419, i);
		sort(st + 1, st + n + 1);
		if(n >= 1000){
			int o = min(n, 20);
			For(i, 2, o){
				int fl = 0;
				For(j, 1, i - 1){
					int tem = que(j, i);
					if(tem == -1) return 0;
					if(tem != 1){
						swap(st[i], st[1]);
						fl = 1;
						break;
					} 
				}
				if(fl) break;
			}
		}
		while(666){
			st[0] = mp(1, st[1].sec);
			For(i, 2, top){
				st[i - 1].fir = que(st[0].sec, st[i].sec);
				if(st[i - 1].fir == -1) return 0;
				st[i - 1].fir *= -1;
				st[i - 1].sec = st[i].sec;
			}
			top--;
			sort(st + 1, st + top + 1);
			if(chk()){
				printf("! %d %d\n", st[0].sec, st[1].sec);
				fflush(stdout);
				break;
			}
			top = 2;
			while(st[top].fir == st[1].fir) top++;
			top--;
		}
		int as; scanf("%d", &as);
		if(as == -1) break;
	}
	return 0;
}
