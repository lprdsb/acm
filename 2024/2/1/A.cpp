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
int T, n, k, m, vis[26];
char s[maxn + 5];

void mian() {
    read(n); read(k); read(m);
    scanf("%s", s + 1);
    int tot = 0;
    vector<char> as;
    int now = 0;
    For(i, 1, m) {
        if(s[i] - 'a' < k) now += !vis[s[i] - 'a'];
        vis[s[i] - 'a'] = 1;
        if(now == k) {
            as.pb(s[i]);
            For(o, 0, k - 1) vis[o] = 0;
            now = 0;
        }
    }
    if(as.size() < n) {
        puts("NO");
        For(i, 0, min((int)as.size(), n) - 1) printf("%c", as[i]);
        char c;
        For(o, 0, k - 1) if(!vis[o]) c = 'a' + o;
        For(i, min(n, (int)as.size()) + 1, n) printf("%c", c);
        puts("");
    }
    else puts("YES");
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        mian();
        For(o, 0, 25) {
            vis[o] = 0;
        }
    }
}
