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
int T, n, num[3];
char s[maxn + 5];
void mian() {
    num[0] = num[1] = num[2] = 0;
    scanf("%s", s + 1); n = strlen(s + 1);
    For(i, 1, n) {
        if(s[i] == '3') num[0]++;
        if(i >= 11 && s[i - 10] == '3') num[0]--;
        if(num[0] == 10) {
            puts("invalid");
            return;
        }

        if(s[i] == '5' || s[i] == 'U') {
            num[1]++;
            if(s[i] == '5' && num[2] == 1) {
                puts("invalid");
                return;
            }
            num[2] = s[i] == '5' ? 1 : 2;
        }
        if(i >= 91 && (s[i - 90] == '5' || s[i - 90] == 'U')) num[1]--;
        if(i >= 90 && !num[1]) {
            puts("invalid");
            return;
        }
    }
    puts("valid");
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
