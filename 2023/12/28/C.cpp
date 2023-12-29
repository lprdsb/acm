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

int T;
LL n, k;

template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

void sol() {
    read(k); read(n);
    int res = 0;
    if(!n) {
        puts(k ? "Yes" : "No");
        return;
    }
    while(n % 2 == 0) n >>= 1, res++;
    if(n == 1) {
        if(k < res) {
            puts("No");
            return;
        }
        if(k % 2 == res % 2) {
            puts("Yes");
            return;
        }
        if(res && res + 3 <= k) {
            puts("Yes");
            return;
        }
        if(res + 5 <= k) {
            puts("Yes");
            return;
        }
        puts("No");
        return;
    }

    int fl = res != 0;
    while(n) {
        res += 1 + !(n & 1);
        fl |= !(n & 1);
        n >>= 1;
    }
    res++;
    if(res > k) {
        puts("No");
        return;
    }
    if(res % 2 == k % 2) {
        puts("Yes");
        return;
    }
    if(fl) {
        puts("Yes");
        return;
    }
    if(res + 3 <= k) {
        puts("Yes");
        return;
    }
    puts("No");

}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        sol();
    }
}
