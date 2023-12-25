#include<bits/stdc++.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define Tra(u, i) for(int i = hd[u]; ~i; i = e[i].net)
#define cst const
#define LL long long
#define DD double
#define LD long double
#define fir first
#define sec second
#define inf 0x3f3f3f3f
#define Inf 0x3f3f3f3f3f3f3f3f
#define eps 1e-12
using namespace std;

int t, a, b;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int main(){
	freopen("in.txt", "r", stdin);
    read(t);
    while(t--){
        read(a); read(b);
        //c1 3.0
        if(a >= 75){
            if(a == 75){
                if(b <= 23){
                    printf("3:0\n25:%d 25:0 25:0\n", b);
                    continue;
                }
                else if(b <= 46){
                    printf("3:0\n25:23 25:%d 25:0\n", b - 23);
                    continue;
                }
                else if(b <= 69){
                    printf("3:0\n25:23 25:23 25:%d\n", b - 46);
                    continue;
                }
            }
            else{
                if(b >= a - 50 - 2 && b - (a - 50 - 2) <= 46){
                    if(b - (a - 50 - 2) <= 23){
                        printf("3:0\n%d:%d 25:%d 25:0\n", a - 50, a - 50 -2, b - (a - 50 - 2));
                        continue;
                    }
                    else if(b - (a - 50 - 2) <= 46){
                        printf("3:0\n%d:%d 25:23 25:%d\n", a - 50, a - 50 -2, b - (a - 50 - 2) - 23);
                        continue;
                    }
                }
            }

            //c2 3.1
            if(b >= 25){
                if(a - 75 <= 23 && b - 25 <= 69){
                    if(b - 25 <= 23){
                        printf("3:1\n%d:25 25:%d 25:0 25:0\n", a - 75, b - 25);
                        continue;
                    }
                    else if(b - 25 <= 46){
                        printf("3:1\n%d:25 25:23 25:%d 25:0\n", a - 75, b - 25 - 23);
                        continue;
                    }
                    else if(b - 25 <= 69){
                        printf("3:1\n%d:25 25:23 25:23 25:%d\n", a - 75, b - 25 - 46);
                        continue;
                    }
                }
                if(a - 75 > 23 && b >= a - 75 + 2){
                    if(b - (a - 75 + 2) <= 23){
                        printf("3:1\n%d:%d 25:%d 25:0 25:0\n", a - 75, a - 75 + 2, b - (a - 75 + 2));
                        continue;
                    }
                    else if(b - (a - 75 + 2) <= 46){
                        printf("3:1\n%d:%d 25:23 25:%d 25:0\n", a - 75, a - 75 + 2, b - (a - 75 + 2) - 23);
                        continue;
                    }
                    else if(b - (a - 75 + 2) <= 69){
                        printf("3:1\n%d:%d 25:23 25:23 25:%d\n", a - 75, a - 75 + 2, b - (a - 75 + 2) - 46);
                        continue;
                    }
                }
                if(b - 25 > 69 && b - 25 - 46 + 2 <= a - 50){
                    printf("3:1\n%d:25 25:23 25:23 %d:%d\n", a - 50 - (b - 25 - 46 + 2), b - 25 - 46 + 2, b - 25 - 46);
                    continue;
                }
            }

            //c3 3.2
            if(b >= 50 && a >= 65){
                if(a - 65 <= 46 && b - 50 <= 59){
                    puts("3:2");
                    if(a - 65 <= 23){
                        printf("%d:25 0:25 ", a - 65);
                    }
                    else if(a - 65 <= 46){
                        printf("23:25 %d:25 ", a - 65 - 23);
                    }

                    if(b - 50 <= 23){
                        printf("25:%d 25:0 15:0\n", b - 50);
                        continue;
                    }
                    else if(b - 50 <= 46){
                        printf("25:23 25:%d 15:0\n", b - 50 - 23);
                        continue;
                    }
                    else if(b - 50 <= 59){
                        printf("25:23 25:23 15:%d\n", b - 50 - 46);
                        continue;
                    }
                }
                int mn = min(a - 65 - 23, b - 50);
                if(mn >= 0 && a - 65 - 23 - mn <= 23 && b - 50 - mn <= 59){
                    printf("3:2\n%d:%d %d:25", 23 + mn, 25 + mn, a - 65 - 23 - mn);
                    if(b - 50 - mn <= 23){
                        printf("25:%d 25:0 15:0\n", b - 50 - mn);
                        continue;
                    }
                    else if(b - 50 - mn <= 46){
                        printf("25:23 25:%d 15:0\n", b - 50 - mn - 23);
                        continue;
                    }
                    else if(b - 50 - mn <= 59){
                        printf("25:23 25:23 15:%d\n", b - 50 - mn - 46);
                        continue;
                    }
                }
                mn = min(a - 65, b - 73);
                if(mn >= 0 && a - 65 - mn <= 46 && b - 73 - mn <= 36){
                    printf("3:2\n");
                    if(a - 65 - mn <= 23){
                        printf("%d:25 0:25 ", a - 65 - mn);
                    }
                    else if(a - 65 - mn <= 46){
                        printf("23:25 %d:25 ", a - 65 - mn - 23);
                    }
                    printf("%d:%d ", 25 + mn, 23 + mn);
                    if(b - 73 - mn <= 23){
                        printf("25:%d 15:0\n", b - 73 - mn);
                    }
                    else if(b - 73 - mn <= 36){
                        printf("25:23 15:%d\n", b - 73 - mn - 23);
                    }
                    continue;
                }
                mn = min(a - 65, b - 63);
                if(mn >= 0 && a - 65 - mn <= 46 && b - 63 - mn <= 46){
                    printf("3:2\n");
                    if(a - 65 - mn <= 23){
                        printf("%d:25 0:25 ", a - 65 - mn);
                    }
                    else if(a - 65 - mn <= 46){
                        printf("23:25 %d:25 ", a - 65 - mn - 23);
                    }
                    if(b - 63 - mn <= 23){
                        printf("25:%d 25:0\n", b - 63 - mn);
                    }
                    else if(b - 63 - mn <= 46){
                        printf("25:23 25:%d\n", b - 63 - mn - 23);
                    }
                    printf("%d:%d\n", 15 + mn, 13 + mn);
                    continue;
                }
            }
        }

    }
}
