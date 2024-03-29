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
char s[maxn + 5];

int main() {
    //freopen("in", "r", stdin);
    int T; read(T);
    LL sum = 0;
    while(T--) {
        fgets(s, maxn, stdin);
        int n = strlen(s);
        if(s[0] == 'i') {
            if(s[3] == '[') {
                LL now = 0;
                int fl = 0;
                For(i, 0, n) {
                    if(s[i] == '[') fl = 1;
                    if(s[i] >= '0' && s[i] <= '9') now = now * 10 + s[i] - '0';
                    else {
                        sum += now * 4 * fl;
                        now = 0;
                    }
                    if(s[i] == ']') fl = 0;
                }
            }
            else {
                if(s[4] != ';') {
                    int cnt = 1;
                    For(i, 0, n - 1) cnt += s[i] == ',';
                    sum += cnt * 4;
                }
            }
        }
        else if(s[0] == 'l') {

            if(s[4] == '[') {
                LL now = 0;
                int fl = 0;
                For(i, 0, n) {
                    if(s[i] == '[') fl = 1;
                    if(s[i] >= '0' && s[i] <= '9') now = now * 10 + s[i] - '0';
                    else {
                        sum += now * 8 * fl;
                        now = 0;
                    }
                    if(s[i] == ']') fl = 0;
                }
            }
            else {
                if(s[5] != ';') {
                    int cnt = 1;
                    For(i, 0, n - 1) cnt += s[i] == ',';
                    sum += cnt * 8;
                }
            }
        }
        else {
            int pre = -1;
            For(i, 0, n - 1) {
                if(s[i] == '"') {
                    if(pre != -1) {
                        sum += (i - pre - 1);
                        pre = -1;
                    }
                    else pre = i;
                }
            }
        }
    }
    if(sum >> 30) {
        printf("%lldGB", sum >> 30);
        sum %= 1ll << 30;
    }
    if(sum >> 20) {
        printf("%lldMB", sum >> 20);
        sum %= 1ll << 20;
    }
    if(sum >> 10) {
        printf("%lldKB", sum >> 10);
        sum %= 1ll << 10;
    }
    if(sum) printf("%lldB", sum);
}
