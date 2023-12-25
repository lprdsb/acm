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

int T, n, m;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int main(){
	// freopen("in.txt", "r", stdin);
	read(T);
	For(_, 1, T){
		read(n); read(m);
		// if(_ == 1891){
		// 	cout << n << " " << m << endl;
		// 	return 0;
		// }
		// else if(T >= 100) continue;
		if(n <= 2){
			if(n == 1) puts("NO");
			else{
				if(m % 2 == 0) printf("YES\n%d %d\n", m / 2, m / 2);
				else{
					if(m == 3) puts("NO");
					else{
						if(((m / 2) ^ (m / 2 + 1)) < m / 2) printf("YES\n%d %d\n", m / 2, m / 2 + 1);
						else puts("NO");
					}
				}
			}
		}
		else{
			if(m % 2 == 0){
				if(n % 2 == 0){
					puts("YES");
					For(i, 1, n - 2) printf("1 ");
					printf("%d %d\n", (m - n + 2) / 2, (m - n + 2) / 2);
				}
				else{
					int res = m - n + 3;
					if(res != (res & -res)){
						puts("YES");
						For(i, 1, n - 3) printf("1 ");
						printf("%d %d %d\n", (res - (res & -res)) / 2, res / 2, (res & -res) / 2);
					}
					else{
						if(n >= 5){
							if(m == n + 1) puts("NO");
							else{
								printf("YES\n2 2 ");
								For(i, 3, n - 3) printf("1 ");
								res -= 2;
								printf("%d %d %d\n", (res - (res & -res)) / 2, res / 2, (res & -res) / 2);
							}
						}
						else{
							if(res < 16) puts("NO");
							else printf("YES\n%d %d %d\n", 3 * m / 16, 6 * m / 16, 7 * m / 16); 
						}
					}
				}
			}
			else{
				if(m < 2 * n) puts("NO");
				else{
					if(n % 2 == 0){
						printf("YES\n 3 2 ");
						For(i, 3, n - 2) printf("2 ");
						printf("%d %d\n", (m - 1 - 2 * (n - 2)) / 2, (m - 1 - 2 * (n - 2)) / 2);
					}
					else{
						int res = m - 1 - 2 * (n - 3);
						if(res == (res & -res)){
							if(n >= 5){
								if(res <= 8) puts("NO");
								else{
									printf("YES\n3 3 ");
									For(i, 3, n - 3) printf("2 ");
									res -= 2;
									int l1 = res & -res, l2 = (res - l1) & -(res - l1);
									printf("%d %d %d\n", (res - l1 - l2) / 2 + 1, res / 2, (l1 + l2) / 2);
								}
							}
							else{
								if(res <= 16) puts("NO");
								else printf("YES\n%d %d %d\n", 3 * res / 16, 6 * m / 16 + 1, 7 * m / 16); 
							}
						}
						else if(res % 4 == 2){
							if(res <= 10) puts("NO");
							else{
								if(n == 3){
									if(res - 2 != ((res - 2) & -(res - 2))){
										int l1 = res & -res, l2 = (res - l1) & -(res - l1);
										printf("YES\n%d %d %d\n", (res - l1 - l2) / 2 + 1, res / 2, (l1 + l2) / 2);
									}
									else{
										if(res <= 18) puts("NO");
										else printf("YES\n%d %d %d\n", 7, (res - 6) / 2 + 1, (res - 6) / 2 - 1);
									}
								}
								else{
									if(res <= 8) puts("NO");
									else{
										if(res - 2 != ((res - 2) & -(res - 2))){
											printf("YES\n3 3 ");
											For(i, 3, n - 3) printf("2 ");
											res -= 2;
											printf("%d %d %d\n", (res - (res & -res)) / 2 + 1, res / 2, (res & -res) / 2);
										}
										else{
											printf("YES\n4 4 ");
											For(i, 3, n - 3) printf("2 ");
											res -= 4;
											int l1 = res & -res, l2 = (res - l1) & -(res - l1);
											printf("%d %d %d\n", (res - l1 - l2) / 2 + 1, res / 2, (l1 + l2) / 2);
										}
									}
								}
							}
						}
						else{
							puts("YES");
							For(i, 1, n - 3) printf("2 ");
							printf("%d %d %d\n", (res - (res & -res)) / 2 + 1, res / 2, (res & -res) / 2);
						}
					}
				}
			}
		}
	}
	return 0;
}
