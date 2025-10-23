#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define For(i, a, b) for(LL i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define LL long long
#define UI unsigned int
#define ULL unsigned LL
#define maxn 5000000
#include<bits/stdc++.h>

using namespace std;

bitset<maxn + 1> bit, pp;

int vis[maxn + 5], pri[maxn + 5], cnt = 0;

int main() {
    // freopen("tmp.txt", "r", stdin);
    For(i, 2, maxn) {
        if(!vis[i]) pri[++cnt] = i, pp[i] = 1;
        for(int j = 1; j <= cnt && i * pri[j] <= maxn; ++j) {
            vis[i * pri[j]] = 1;
            if(i % pri[j] == 0) break;
        }
    }
    // For(i, 1, cnt) printf("%d ", pri[i]);
    printf("%d\n", cnt);
    For(i, 1, cnt) {
        if(i % 1000 == 0) cout << i << endl;
        bit |= pp << pri[i];
    }
    // ofstream fout("tmp.txt");
    FILE* out = fopen("tmp.txt", "w");
    fprintf(out, "a[%d]={", maxn / 64 + 1);
    for(int i = 0; i <= maxn; i += 64) {
        ULL tmp = 0;
        For(o, 0, 63) tmp |= bit[i + o] << o;
        if(i) fprintf(out, ", ");
        fprintf(out, "%u", tmp);
    }
    fprintf(out, "}");
}