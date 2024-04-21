#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define cst const
#define DD double

#define P 998244353
#define Hash_P 9982457
#define bas 13331
#define maxn 9982457
#define maxm 2048

int a[10] = { 1, 2, 3 }, b[9] = { 2, 3, 4 };

int main() {
    memcpy(a + 1, b + 1, sizeof (b + 1));
    For(i, 0, 9) printf("%d\n", a[i]);
}
/*
312157659
*/