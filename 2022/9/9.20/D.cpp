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
#define maxn 3000
using namespace std;

int t, n, x, y, a[maxn + 5], b[maxn + 5], tot, sum;
LL as;

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
		as = tot = sum = 0;
		read(n); read(x); read(y);
		For(i, 1, n){
			char c; cin >> c;
			a[i] = c - '0'; 
		}
		For(i, 1, n){
			char c; cin >> c;
			a[i] ^= c - '0';
		}
		a[n + 1] = 0;
		For(i, 1, n){
			if(a[i]){
				a[i] += a[i - 1];
				if(!a[i + 1]) sum += b[++tot] = a[i];
			}
		}
		if(sum & 1) puts("-1");
		else{
			if(x <= y){
				For(i, 1, tot){
					sum += b[i] & 1;
					as += 1ll * x * (b[i] / 2);
					sum -= b[i];
				}
				as += 1ll * y * (sum / 2);
			}
			else{
				sort(b + 1, b + tot + 1);
				int now = 1;
				while(now <= tot && b[now] <= 3) sum -= b[now++];
				as += 1ll * y * (sum / 2);
				sum = 0;
				if(now == 2 && b[1] == 2) as += x;
				else For(i, 1, now - 1) sum += b[i];
				as += 1ll * y * (sum / 2);
			}
		}
		printf("%lld\n", as);
	}
	return 0;
	
}


