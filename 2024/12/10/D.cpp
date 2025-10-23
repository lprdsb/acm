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

#define maxn 300
int n, ch[maxn + 5][26], a[maxn + 5];
char s[maxn + 5];

int main() {
    //freopen("in", "r", stdin);
    scanf("%s", s + 1);
    n = strlen(s + 1);
    For(i, 0, n - 1) ch[i][s[i + 1] - 'a'] = i + 1;
    For(i, 1, n) {
        For(o, 0, 25) {
            if(ch[i][o]) a[ch[i][o]] = ch[a[i]][o];
            else ch[i][o] = ch[a[i]][o];
        }
    }
    // cout << ch[a[1]][0] << endl;
    int res = 0;
    For(i, 0, n) For(o, 0, 25) res += ch[i][o];
    printf("%d\n", res);
}
