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

int a[5], b[5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

bool chk(){
    return a[2] < 0 || a[3] < 0;
}

int main(){
	//freopen("in", "r", stdin);
    read(a[1]); read(a[2]); read(a[3]); read(a[4]);
    For(i, 1, 4) b[i] = a[i];
    a[2] -= a[1];
    a[3] -= a[4];
    // cout << a[1] << " " << a[2] << " " << a[3] << " " << a[4] << endl;
    if(chk()){
        puts("NO");
        return 0;
    }
    int tem = min(a[2], a[3]);
    a[2] -= tem;
    a[3] -= tem;
    // cout << "asd" << endl;
    if(a[2] == 0 && a[3] == 0){
        puts("YES");
        For(i, 1, b[1]) printf("0 1 ");
        For(i, 1, tem) printf("2 1 ");
        For(i, 1, b[4]) printf("2 3 ");
        return 0;
    }
    if(a[2] == 1 && a[3] == 0){
        puts("YES");
        For(i, 1, b[4]) printf("3 2 ");
        For(i, 1, tem) printf("1 2 ");
        For(i, 1, b[1]) printf("1 0 ");
        printf("1");
        return 0;
    }
    if(a[2] == 0 && a[3] == 1){
        puts("YES");
        For(i, 1, b[1]) printf("0 1 ");
        For(i, 1, tem) printf("2 1 ");
        For(i, 1, b[4]) printf("2 3 ");
        printf("2");
        return 0;
    }
    puts("NO");
    return 0;
}
