#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<bits/stdc++.h>
#define For(i, a, b) for(LL i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define LL long long
#define UI unsigned int
#define maxn 800000
#define maxm 1000000
using namespace std;

UI r;
int n;

#define LD long double

LD tmp = (sqrt((LD)5) - 1) / 2;

LL f[maxn + 5];
LL st[maxm + 5], tp = 0;

LL get_f(LL x) {
    // printf("%u\n", x);
    if(x < 0) return 0;
    if(x <= maxn) return f[x];
    Rof(i, tp, 0) if(x >= st[i]) return st[i - 1] + get_f(x - st[i]);
}

LL get_f1(LL x) {
    return (x + 1) * tmp;
}

LD tmp1 = 0.61803398874989484821;

int main() {

    printf("%.20Lf\n", tmp1);
    // LL x = 998244353;
    // cout << get_f(x) << endl << get_f1(x) << endl;
    // printf("%lld\n", get_f(-1));
}