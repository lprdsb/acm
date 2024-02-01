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
int n, num[27];
char s[maxn + 5];

int main() {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    For(i, 1, n) num[s[i] - 'a']++;
    printf("xiaohong");
    num['x' - 'a']--;
    num['i' - 'a']--;
    num['a' - 'a']--;
    num['o' - 'a']--;
    num['h' - 'a']--;
    num['o' - 'a']--;
    num['n' - 'a']--;
    num['g' - 'a']--;
    For(i, 0, 25) For(j, 1, num[i]) printf("%c", 'a' + i);
    return 0;
}
