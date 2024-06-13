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

template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

#define maxn 1000
int n, ok[maxn + 5];
vector<int> as;

int main() {
    //freopen("in", "r", stdin);
    read(n);
    int now = 0;
    For(i, 1, n) {
        int x; read(x);
        if(x < 0) {
            if(ok[-x]) ok[-x]--;
            else if(now) as.pb(-x), now--;
            else {
                puts("No");
                return 0;
            }
        }
        else if(!x) now++;
        else ok[x]++;
    }
    puts("Yes");
    for(auto i : as) printf("%d ", i);
    while(now--) printf("1 ");
    return 0;
}