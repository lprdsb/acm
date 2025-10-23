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

#define maxn 1000000
int n, m, ch[maxn + 5][26], a[maxn + 5], tot = 0;
char s[maxn + 5];

int main() {
    //freopen("in", "r", stdin);
    read(n); read(m);
    For(i, 1, n) {
        scanf("%s", s + 1); int len = strlen(s + 1);
        int now = 0;
        For(j, 1, len) {
            if(!ch[now][s[j] - 'a']) ch[now][s[j] - 'a'] = ++tot;
            now = ch[now][s[j] - 'a'];
        }
        a[now] = 1;
    }
    Rof(i, tot, 1) {
        For(o, 0, 25) a[i] += a[ch[i][o]];
    }
    For(i, 1, m) {
        scanf("%s", s + 1); int len = strlen(s + 1);
        int now = 0;
        For(j, 1, len) {
            now = ch[now][s[j] - 'a'];
            if(!now) break;
        }
        printf("%d\n", a[now]);
    }

}
