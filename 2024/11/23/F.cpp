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
void read(T & x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

#define maxn 100
LL T, n, p, q, a, b;
char s[maxn + 5];

void mian() {
    read(n); read(p); read(q);
    scanf("%s", s + 1);
    if(!p && !q) {
        puts("0");
        return;
    }
    a = b = 0;
    For(i, 1, n) {
        if(s[i] == 'U') b++;
        if(s[i] == 'D') b--;
        if(s[i] == 'R') a++;
        if(s[i] == 'L') a--;
    }
    LL na = 0, nb = 0;
    LL res = -1;
    For(i, 1, n) {
        if(s[i] == 'U') nb++;
        if(s[i] == 'D') nb--;
        if(s[i] == 'R') na++;
        if(s[i] == 'L') na--;
        if(!a && na != p) continue;
        if(!b && nb != q) continue;
        if((a && (p - na) % a) || (b && (q - nb) % b)) continue;
        if((a && (p - na) / a < 0) || (b && (q - nb) / b < 0)) continue;
        if(!a || !b || (p - na) / a == (q - nb) / b) {
            LL tmp;
            if(a) tmp = i + (p - na) / a * n;
            else if(b) tmp = i + (q - nb) / b * n;
            else tmp = i;
            if(res == -1 || res > tmp) res = tmp;
        }
    }
    printf("%lld\n", res);
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
