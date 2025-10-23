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

#define maxn 200000
int T;
char s[maxn + 5];

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        int n;
        read(n);
        scanf("%s", s + 1);
        int as = n;
        For(i, 1, n) {
            if(s[i] == 'B') as--;
            else break;
        }
        For(i, 1, n) {
            if(s[n - i + 1] == 'A') as--;
            else break;
        }
        cout << max(0, as - 1) << endl;
    }
}
