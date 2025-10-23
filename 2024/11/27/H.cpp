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

#define maxn 100000
int n, m, a[maxn + 5];
LL f[maxn + 5];
char s[maxn + 5];

int main() {
    //freopen("in", "r", stdin);
    read(n);
    For(i, 1, n) read(a[i]);
    read(m);
    scanf("%s", s + 1);
    For(i, 1, m) {
        f[i] = f[i - 1];
        for(int j = i - 2; j >= 1; j -= 3) {
            if(s[j] == 'a' && s[j + 1] == 'b' && s[j + 2] == 'c') {
                if((i - j + 1) / 3 <= n) f[i] = max(f[i], f[j - 1] + a[(i - j + 1) / 3]);
                else break;
            }
            else break;
        }
    }
    printf("%lld\n", f[m]);
}
