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

int n, a[20][3] = {{1, 1, 1}, {1, 2, 2}, {1, 3, 3}, {1, 3, 4}, {1, 4, 4}, {2, 2, 2}, {2, 2, 3}, {2, 3, 3}, {2, 3, 4}, {2, 4, 4},
                     {3, 3, 3}, {3, 3, 4}, {3, 4, 4}, {4, 4, 4}};
int s[10], ok[10][10][10], as[100001], to[10][10][100001], sto[100001];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int que(int x, int y, int z){
    printf("? %d %d %d", x, y, z);
    fflush(stdout);
    int xx; read(xx);
    return xx;
}

int main(){
	//freopen("in", "r", stdin);
    For(i, 0, 13){
        int sum = 0, ss = 1;
        For(j, 0, 2) sum += a[i][j];
        ss = sum;
        For(j, 0, 2) ss *= (sum - 2 * a[i][j]);
        s[i] = ss;
        ok[a[i][0]][a[i][1]][a[i][2]] = 1;
        ok[a[i][0]][a[i][2]][a[i][1]] = 1;
        ok[a[i][1]][a[i][2]][a[i][0]] = 1;
        to[a[i][0]][a[i][1]][ss] = a[i][2];
        to[a[i][0]][a[i][2]][ss] = a[i][1];
        to[a[i][1]][a[i][2]][ss] = a[i][0];
        sto[ss] = i;
    }
    // For(i, 1, 4) For(j, i, 4){
    //     cout << i << " asd " << j << endl;
    //     For(p, 1, 4) if(ok[i][j][p]) cout << p << " ";
    //     cout << endl;
    // }
    read(n);
    if(n == 3){
        int x = que(1, 2, 3);
        if(x == s[0]){
            puts("! 1 1 1");
            fflush(stdout);
        }
        else if(x == s[5]){
            puts("! 2 2 2");
            fflush(stdout);
        }
        else if(x == s[10]){
            puts("! 3 3 3");
            fflush(stdout);
        }
        else if(x == s[13]){
            puts("! 4 4 4");
            fflush(stdout);
        }
        else{
            puts("! -1");
            fflush(stdout);
        }
        return 0;
    }
    int l = 1, r = 2;
    For(i, 3, n){
        int x = que(l, r, i);
        if(x == )
    }
}
