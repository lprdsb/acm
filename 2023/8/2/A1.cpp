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

int t, a, b, f[5][5][205][205], ok[10] = {0, 25, 25, 25, 25, 15};

template <class T>
void read(T &x){
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

void print(int s1, int s2, int p1, int p2){
    if(!s1 && !s2) return;
    int n1 = f[s1][s2][p1][p2] / maxn, n2 = f[s1][s2][p1][p2] % maxn;
    print(s1 - (n1 > n2), s2 - (n1 < n2), p1 - n1, p2 - n2);
    printf("%d:%d ", n1, n2);
}

int main(){
    // freopen("in.txt", "r", stdin);
    memset(f, -1, sizeof f);
    f[0][0][0][0] = 0;
    For(s1, 0, 3) For(s2, 0, 3){
        if(s1 == 3 || s2 == 3) continue;
        For(p1, 0, 200) For(p2, 0, 200) if(f[s1][s2][p1][p2] != -1){
            int t = ok[s1 + s2 + 1];
            For(n2, 0, t - 2) if(p1 + t <= 200 && p2 + n2 <= 200) f[s1 + 1][s2][p1 + t][p2 + n2] = t * maxn + n2;
            For(n1, 0, t - 2) if(p1 + n1 <= 200 && p2 + t <= 200) f[s1][s2 + 1][p1 + n1][p2 + t] = n1 * maxn + t;
            For(n2, t - 2, 200 - p2) if(p1 + n2 + 2 <= 200) f[s1 + 1][s2][p1 + n2 + 2][p2 + n2] = (n2 + 2) * maxn + n2;
            For(n1, t - 2, 200 - p1) if(p2 + n1 + 2 <= 200) f[s1][s2 + 1][p1 + n1][p2 + n1 + 2] =  n1 * maxn + n1 + 2;
        } 
    }
    // cout << f[3][1][20][0] << endl;
    read(t);
    while(t--){
        int fl = 0;
        read(a); read(b);
        For(i, 0, 2) if(f[3][i][a][b] != -1){
            fl = 1;
            printf("3:%d\n", i);
            print(3, i, a, b);
            puts("");
            break;
        }
        if(fl) continue;
        Rof(i, 2, 0) if(f[i][3][a][b] != -1){
            fl = 1;
            printf("%d:3\n", i);
            print(i, 3, a, b);
            puts("");
            break;
        }
        if(!fl) puts("Impossible");

    }
}
